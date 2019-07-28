# Introduction

LC Design is a UI component framework for building LCUI application, it provides basic styles for typography and elements, simple layout system, CSS components and utilities. Its CSS code is based Bootstrap, so its usage is basically the same as Boostrap.

## Installation

Install with LCPkg:

``` shell
lcpkg install github.com/lc-ui/lc-desgin
```

Or, you can download the compiled package:

``` embedded-xml
<p>
  <a class="btn" href="https://github.com/lc-ui/lcui.css/releases">Download LC Design</a>
</p>
```

### CSS

Copy the files from the dist directory to your project directory, and configure your project assets include path.

``` xml
<resource type="text/css" src="assets/stylesheets/lc-design.css" />
```

### C Dependencies

Copy **include** and **lib** directory from the **dist** directory to you project **vendor** directory, and configure your project compiler settings.

## Starter template

main.xml:

``` xml
<?xml version="1.0" encoding="UTF-8" ?>
<lcui-app>
  <resource type="text/css" src="assets/stylesheets/lc-design.css" />
  <ui>
    <h1>Hello, world!</h1>
  </ui>
</lcui-app>
```

main.c:

``` c
#include <LCUI.h>
#include <LCDesign.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/builder.h>

int main(int argc, char **argv)
{
        LCUI_Widget root, pack;

        LCUI_Init();
        LCDesgin_Init();
        root = LCUIWidget_GetRoot();
        pack = LCUIBuilder_LoadFile("main.xml");
        if(!pack) {
                return -1;
        }
        Widget_Append(root, pack);
        Widget_Unwrap(pack);
        return LCUI_Main();
}
```

That's all you need for overall app requirements. Visit the Layout docs or our official examples to start laying out your app’s content and components.
