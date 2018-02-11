# Introduction

LCUI.css is a simple CSS framework for building LCUI application, it provides basic styles for typography and elements, simple layout system, CSS components and utilities.

## Installation

Download the compiled LCUI.css package:

``` embedded-xml
<w type="p">
  <w type="a" class="btn" href="https://github.com/lc-ui/lcui.css/releases">Download LCUI.css</w>
</w>
```

### CSS

Copy the files from the dist directory to your project directory, and configure your project assets include path.

``` xml
<resource type="text/css" src="assets/stylesheets/lcui.css"/>
```

### C Dependencies

Copy **include** and **lib** directory from the **dist** directory to you project **vendor** directory, and configure your project compiler settings.

## Starter template

main.xml:

``` xml
<?xml version="1.0" encoding="UTF-8" ?>
<lcui-app>
  <resource type="text/css" src="assets/stylesheets/lcui.css"/>
  <ui>
    <w type="h1">Hello, world!</w>
  </ui>
</lcui-app>
```

main.c:

``` c
#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/builder.h>

int main( int argc, char **argv )
{
        LCUI_Widget root, pack;

        LCUI_Init();
        LCUIEx_Init();
        root = LCUIWidget_GetRoot();
        pack = LCUIBuilder_LoadFile( "main.xml" );
        if( !pack ) {
                return -1;
        }
        Widget_Append( root, pack );
        Widget_Unwrap( pack );
        return LCUI_Main();
}
```

That's all you need for overall app requirements. Visit the Layout docs or our official examples to start laying out your site’s content and components.
