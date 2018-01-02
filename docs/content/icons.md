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
<w type="icon" name="apple"></w>
<w type="icon" name="android"></w>
<w type="icon" name="windows"></w>
<w type="icon" name="apple-finder"></w>
<w type="icon" name="apple-ios"></w>
<w type="icon" name="apple-safari"></w>
<w type="icon" name="bluetooth"></w>
<w type="icon" name="bike"></w>
<w type="icon" name="bing"></w>
<w type="icon" name="stackoverflow"></w>
<w type="icon" name="internet-explorer"></w>
<w type="icon" name="google-maps"></w>
<w type="icon" name="github-box"></w>
<w type="icon" name="car"></w>
<w type="icon" name="cancel"></w>
<w type="icon" name="chart-bar"></w>
<w type="icon" name="comment-multiple-outline"></w>
<w type="icon" name="delete-forever"></w>
<w type="icon" name="fingerprint"></w>
<w type="icon" name="flask-outline"></w>
<w type="icon" name="google-keep"></w>
<w type="icon" name="google-translate"></w>
<w type="icon" name="heart-box-outline"></w>
<w type="icon" name="itunes"></w>
<w type="icon" name="language-cpp"></w>
<w type="icon" name="language-python"></w>
<w type="icon" name="language-javascript"></w>
<w type="icon" name="language-html5"></w>
<w type="icon" name="language-css3"></w>
<w type="icon" name="language-php"></w>
<w type="icon" name="language-typescript"></w>
<w type="icon" name="json"></w>
<w type="icon" name="qqchat"></w>
<w type="icon" name="lightbulb-on-outline"></w>
<w type="icon" name="map-marker-radius"></w>
<w type="icon" name="emoticon"></w>
<w type="icon" name="thumb-up-outline"></w>
<w type="icon" name="telegram"></w>
<w type="icon" name="tooth"></w>
<w type="icon" name="ghost"></w>
```
