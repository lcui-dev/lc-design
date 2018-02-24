<p align="center">
  <a href="http://lcui.org">
    <img src="https://lc-soft.io/static/images/logo-lcui-css.png" width=72 height=72>
  </a>

  <h3 align="center">LCUI.css</h3>

  <p align="center">
    A UI component framework for building LCUI application.
    <br>
    <a href="docs"><strong>Explore LCUI.css docs &raquo;</strong></a>
  </p>
</p>

<br>

## Introduction

LCUI.css is a UI component framework for building [LCUI](https://github.com/lc-soft/LCUI) application, it provides basic styles for typography and elements, simple layout system, CSS components and utilities. Its CSS code is based [Bootstrap](https://github.com/twbs/bootstrap), so its usage is basically the same as Boostrap.

## Build

### Prerequisites

Building LCUI.css has the following dependencies:

* [Xmake](http://xmake.io) - a build tool for compiling C source code
* [NodeJS](https://nodejs.org) - a JavaScript runtime to run build tools
* [Python](https://www.python.org/) - a environment for run python build tools

After installing NodeJS, please run the following command to install the NodeJS dependency packages:

    npm install

### Build Targets

    npm run build               # Build all targets.
    npm run build-bin           # Build binary files.
    npm run build-css           # Build css file.
    npm run build-font          # Build iconfont file.
    npm run build-demo          # Build demo application.
    npm run build-demo-assets   # Build assets of demo application.
    npm run build-demo-bin      # Build binary file of demo application.
    npm run build-demo-css      # Build css file of demo application.
    npm run build-demo-docs     # Build documentations of demo application.
    npm run demo                # Run demo application.

## Install

Copy the files from the **dist** directory to your project directory, and configure your project assets include path.

We recommend that you use the following directory structure, this will be able to directly copy the files from the **dist/assets/** directory to **yourapp/app/** directory.

``` text
yourapp/
├── app/
│   ├── assets/
│   │   ├── stylesheets/
│   │   │   ├── app.css
│   │   │   └── lcui.css
│   │   ├── views/
│   │   │   ├── app.xml
│   │   │   └── ...
│   │   ├── fonts/
│   │   │   └── iconfont.ttf
│   │   ├── images/
│   │   └── ...
│   └── ...
├── src/
│   ├── scss/
│   ├── lib/
│   ├── ui/
│   └── ...
└── ...
```

## Creator

**Liu Chao**

- <https://lc-soft.io>
- <https://github.com/lc-soft>

## Legal

Code released under the [MIT License](LICENSE).
