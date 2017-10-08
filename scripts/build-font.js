var fs = require('fs');
var fontdir = 'dist/fonts/';

if (!fs.existsSync(fontdir)) {
  fs.mkdirSync(fontdir);
}

fs.createReadStream('./node_modules/mdi/fonts/materialdesignicons-webfont.ttf')
  .pipe(fs.createWriteStream(fontdir + 'iconfont.ttf'));
