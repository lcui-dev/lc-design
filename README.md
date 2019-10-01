<p align="center">
  <a href="http://lcui.org">
    <img src="https://lc-soft.io/static/images/logo-lcui-css.png" width=72 height=72>
  </a>

  <h3 align="center">LCDesign</h3>

  <p align="center">
    A UI component framework for building LCUI application.
    <br>
    <a href="docs"><strong>Explore LCDesign docs &raquo;</strong></a>
  </p>
</p>

<br>

## Introduction

LCDesign (LC's Design) is a UI component framework for building [LCUI](https://github.com/lc-soft/LCUI) application, it provides basic styles for typography and elements, simple layout system, CSS components and utilities. Its CSS code is based [Bootstrap](https://github.com/twbs/bootstrap), so its usage is basically the same as Boostrap.

[中文版说明文档](README.zh-cn.md)

![LC's Design](https://lcui.lc-soft.io/static/images/screenshot-lcui-css.gif)

## Components

- General
  - [Button](docs/components/buttonss.md)
  - [Icon](docs/content/icons.md)
  - [Typography](docs/content/typography.md)
    - h1, h2, h3, h4, h5, h6
    - p
    - span
    - blockquote
    - cite
    - ...
- Navigation
  - [Dropdown](docs/components/dropdowns.md)
- Data Entry
  - [Checkbox](docs/components/checkbox.md)
  - [Radio](docs/components/radio.md)
  - [Rate](docs/components/rate.md)
  - [Switch](docs/components/switch.md)
- Data Display
  - [Tooltip](docs/components/tooltips.md)
- Feedback
  - [Alert](docs/components/alerts.md)
  - [Modal](docs/components/modal.md)
  - [Message](docs/components/message.md)
  - [Notification](docs/components/notification.md)
  - [Spinner](docs/components/spinners.md)

## Quick start

Several quick start options are available:

- [Download the latest release.](https://github.com/lc-ui/lc-design/releases)
- Install with [lcpkg](https://github.com/lc-soft/lcpkg): `lcpkg install github.com/lc-ui/lc-design`

If your operating system is not Windows, please continue reading below.

## Build

LCDesign does not have a binary package for Linux, you need to manually download the source code and build it.

### Prerequisites

Building LCDesign has the following dependencies:

- [Xmake](http://xmake.io) - a build tool for compiling C source code
- [NodeJS](https://nodejs.org) - a JavaScript runtime to run build tools
- [Python](https://www.python.org/) - a environment for run python build tools

After installing them, you need to run the following command to install the other dependencies:

    pip install misaka pygments
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

## Design reference

- [Bootstrap](https://github.com/twbs/bootstrap)
- [Ant Design](https://github.com/ant-design/ant-design)
- [Element UI](https://github.com/ElemeFE/element)

## Creator

**Liu Chao:**

- <https://lc-soft.io>
- <https://github.com/lc-soft>

## Legal

Code released under the [MIT License](LICENSE).
