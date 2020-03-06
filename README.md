<p align="center">
  <a href="http://lcui.org">
    <img src="https://lc-soft.io/static/images/logo-lcui-css.png" width=72 height=72>
  </a>

  <h3 align="center">LCDesign</h3>
  <p align="center">
    <a class="https://github.com/lc-ui/lc-design/actions"><img src="https://github.com/lc-ui/lc-design/workflows/C%2FC%2B%2B%20CI/badge.svg" alt="GitHub Actions"></a>
    <a class="https://travis-ci.org/lc-ui/lc-design"><img src="https://travis-ci.org/lc-ui/lc-design.svg?branch=develop" alt="Build Status"></a>
    <a href="http://opensource.org/licenses/MIT"><img src="https://img.shields.io/github/license/lc-ui/lc-design.svg" alt="License"></a>
    <a href="https://github.com/lc-ui/lc-design/releases"><img src="https://img.shields.io/github/release/lc-ui/lc-design/all.svg" alt="Github Release"></a>
    <a href="https://github.com/lc-ui/lc-design/releases"><img src="https://img.shields.io/github/downloads/lc-ui/lc-design/total.svg" alt="Github All Releases"></a>
    <img src="https://img.shields.io/github/repo-size/lc-ui/lc-design.svg" alt="Repo size">
    <img src="https://img.shields.io/github/languages/code-size/lc-ui/lc-design.svg" alt="Code size">
  </p>
  <p align="center">
    A UI component framework for building LCUI application.
    <br>
    <a href="docs"><strong>Explore LCDesign docs &raquo;</strong></a>
  </p>
</p>

<br>

## Table of contents

- [Introduction](#introduction)
- [Components](#components)
- [Quick start](#quick-start)
- [Build](#build)
    - [Prerequisites](#prerequisites)
    - [Build Targets](#build-targets)
- [Install](#install)
- [Design reference](#design-reference)
- [Creator](#creator)
- [Legal](#legal)

## Introduction

(**English**/[中文](README.zh-cn.md))

![LC Design Preview](docs/images/preview.png)

LCDesign (LC's Design) is a UI component framework for building [LCUI](https://github.com/lc-soft/LCUI) application, it provides basic styles for typography and elements, simple layout system, CSS components and utilities. Its CSS code is based [Bootstrap](https://github.com/twbs/bootstrap), so its usage is basically the same as Boostrap.

**Note:** This is not a component library for the web front end, you can't use the web browser to experience the effect, the correct way is to download the source code, then build it, and then run the demo.

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

- Clone and run the [lc-ui/lc-design-app](https://github.com/lc-ui/lc-design-app) repository to preview:

  ```bash
  # Clone this repository
  git clone https://github.com/lc-ui/lc-design-app

  # Go into the repository
  cd lc-design-app

  # Install NodeJS dependencies
  npm install

  # Install C/C++ dependencies for x64 CPU architecture
  lcpkg install --arch x64

  # Run the app with debug mode
  lcpkg run start --mode debug
  ```

- Install with [lcpkg](https://github.com/lc-soft/lcpkg)

  ```bash
  # Install with default options
  lcpkg install github.com/lc-ui/lc-design

  # For x64 CPU architecture
  lcpkg install github.com/lc-ui/lc-design --arch x64

  # For Universal Windows Platform (UWP) and x64 CPU architecture
  lcpkg install github.com/lc-ui/lc-design --arch x64 --platform uwp
  ```

- [Download the latest release.](https://github.com/lc-ui/lc-design/releases)

If your operating system is not Windows, please continue reading below.

## Build

LCDesign does not have a binary package for Linux, you need to manually download the source code and build it.

### Prerequisites

Building LCDesign has the following dependencies:

- [XMake](http://xmake.io) - a build tool for compiling C source code
- [NodeJS](https://nodejs.org) - a JavaScript runtime for run build tools
- [Python](https://www.python.org/) - a environment for run python build tools

After installing them, you need to run the following command to install the other dependencies:

```bash
pip install misaka pygments
npm install
```

### Build Targets

```bash
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
```

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
