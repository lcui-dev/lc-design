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
<resource type="application/font-ttf" src="assets/fonts/iconfont.ttf"/>
```

### C Dependencies

Copy include and lib directory from the dist directory to you project vendor directory, and configure your project compiler settings.

## Starter template

``` xml
<?xml version="1.0" encoding="UTF-8" ?>
<lcui-app>
  <resource type="text/css" src="assets/stylesheets/lcui.css"/>
  <resource type="application/font-ttf" src="assets/fonts/iconfont.ttf"/>
  <ui>
    <w type="h1">Hello, world!</w>
  </ui>
</lcui-app>
```

That's all you need for overall app requirements. Visit the Layout docs or our official examples to start laying out your site’s content and components.
