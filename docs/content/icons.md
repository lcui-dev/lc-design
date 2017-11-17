# Icons

Icons are single-element and pure CSS icons, LCUI's icons are from the Material Design Icons. Before using the icon, you need to import the icon font file.

``` xml
<resource type="application/font-ttf" src="assets/fonts/iconfont.ttf"/>
```

``` c
#include <LCUI/font.h>
...
LCUIFont_LoadFile("assets/fonts/iconfont.ttf");
...
```

## Examples

Icon and text are the same, we can use the `textview` widget to display it,  just as in the example below. For highlight the icons effect, the icons example has been increased in size, and added a border.

``` icons-demo-xml
<w type="textview" class="icon icon-apple"></w>
<w type="textview" class="icon icon-android"></w>
<w type="textview" class="icon icon-windows"></w>
<w type="textview" class="icon icon-apple-finder"></w>
<w type="textview" class="icon icon-apple-ios"></w>
<w type="textview" class="icon icon-apple-safari"></w>
<w type="textview" class="icon icon-bluetooth"></w>
<w type="textview" class="icon icon-bike"></w>
<w type="textview" class="icon icon-bing"></w>
<w type="textview" class="icon icon-stackoverflow"></w>
<w type="textview" class="icon icon-internet-explorer"></w>
<w type="textview" class="icon icon-google-maps"></w>
<w type="textview" class="icon icon-github-box"></w>
<w type="textview" class="icon icon-car"></w>
<w type="textview" class="icon icon-cancel"></w>
<w type="textview" class="icon icon-chart-bar"></w>
<w type="textview" class="icon icon-comment-multiple-outline"></w>
<w type="textview" class="icon icon-delete-forever"></w>
<w type="textview" class="icon icon-fingerprint"></w>
<w type="textview" class="icon icon-flask-outline"></w>
<w type="textview" class="icon icon-google-keep"></w>
<w type="textview" class="icon icon-google-translate"></w>
<w type="textview" class="icon icon-heart-box-outline"></w>
<w type="textview" class="icon icon-itunes"></w>
<w type="textview" class="icon icon-language-cpp"></w>
<w type="textview" class="icon icon-language-python"></w>
<w type="textview" class="icon icon-language-javascript"></w>
<w type="textview" class="icon icon-language-html5"></w>
<w type="textview" class="icon icon-language-css3"></w>
<w type="textview" class="icon icon-language-php"></w>
<w type="textview" class="icon icon-language-typescript"></w>
<w type="textview" class="icon icon-json"></w>
<w type="textview" class="icon icon-qqchat"></w>
<w type="textview" class="icon icon-lightbulb-on-outline"></w>
<w type="textview" class="icon icon-map-marker-radius"></w>
<w type="textview" class="icon icon-emoticon"></w>
<w type="textview" class="icon icon-thumb-up-outline"></w>
<w type="textview" class="icon icon-telegram"></w>
<w type="textview" class="icon icon-tooth"></w>
<w type="textview" class="icon icon-ghost"></w>
```
