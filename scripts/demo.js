var child_process = require('child_process')

child_process.exec('./demo', { cwd: 'demo/app' }, function (err, stdout, stderr) {
  console.log(stdout)
  console.log(stderr)
})

