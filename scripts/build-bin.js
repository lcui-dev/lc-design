var msbuild = require('./msbuild')
var child_process = require('child_process')

if (msbuild.exists()) {
  msbuild.exec('.\\scripts\\build-bin')
} else {
  child_process.exec('xmake', function (err, stdout, stderr) {
    console.log(stdout)
    console.log(stderr)
  })
}

