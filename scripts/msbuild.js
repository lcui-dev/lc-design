const { execSync, spawnSync } = require('child_process')

function getVisualStudioPath() {
  const options = { encoding: 'ASCII' }
  const key = 'HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\Microsoft\\VisualStudio\\SxS\\VS7'
  const lines = execSync('reg query ' + key, options).split('\n')

  for (let i = 0; i < lines.length; ++i) {
    let values = lines[i].trim().split('    ')
    if (values.length > 2) {
      if (values[0] === '15.0') {
        return values[2]
      }
    }
  }
  return null
}

function getVSDevCmdPath() {
  const path = getVisualStudioPath()

  if (path) {
    return `${path}VC\\Auxiliary\\Build\\vcvars64.bat`
  }
  return null
}

module.exports = {
  exec(filename, options) {
    const path = getVSDevCmdPath()

    if (!path) {
      return null
    }
    return spawnSync('cmd', ['/c', filename, path], { stdio: 'inherit', ...options })
  },
  exists() {
    return process.platform == 'win32' && !!getVSDevCmdPath()
  }
}
