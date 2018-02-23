var iconv = require('iconv-lite')
var child_process = require('child_process')

function getVisualStudioPath() {
  var options = { encoding: 'ASCII' }
  var key = 'HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\Microsoft\\VisualStudio\\SxS\\VS7'
  var result = child_process.execSync('reg query ' + key, options)
  var lines = result.split('\n')

  for (var i = 0; i < lines.length; ++i) {
    var values = lines[i].trim().split('    ')
    if (values.length > 2) {
      if (values[0] === '15.0') {
        return values[2]
      }
    }
  }
  return null
}

function getVSDevCmdPath() {
  var path = getVisualStudioPath()
  if (!path) {
    return null
  }
  return path + 'Common7\\Tools\\VsDevCmd.bat'
}

module.exports = {
  exec: function (filename) {
    var path = getVSDevCmdPath()
  	if (!path) {
  		return false
  	}

	  var encoding = 'cp936'
  	var binaryEncoding = 'binary'
	  var options = { encoding: binaryEncoding }
  	var cmd = 'cmd /c ' + filename + ' "' + path + '"'
	  child_process.exec(cmd, options, function (err, stdout, stderr) {
	    console.log(iconv.decode(new Buffer(stdout, binaryEncoding), encoding))
  	  console.log(iconv.decode(new Buffer(stderr, binaryEncoding), encoding))
	  })
  },
  exists: function () {
    return process.platform == 'win32' && !!getVSDevCmdPath()
  }
}

