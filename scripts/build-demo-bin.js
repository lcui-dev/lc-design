var msbuild = require('./msbuild')
var child_process = require('child_process')

if (process.platform == 'win32' && msbuild.exists()) {
  msbuild.exec('.\\scripts\\build-demo-bin')
} else {
  child_process.exec('xmake build demo', function (err, stdout, stderr) {
    console.log(stdout)
    console.log(stderr)
  })
}
