const fs = require('fs')
const fontdir = 'dist/app/assets/fonts/'

if (!fs.existsSync(fontdir)) {
  fs.mkdirSync(fontdir)
}

fs.createReadStream('./node_modules/@mdi/font/fonts/materialdesignicons-webfont.ttf')
  .pipe(fs.createWriteStream(fontdir + 'iconfont.ttf'))
