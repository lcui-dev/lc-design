<p align="center">
  <a href="http://lcui.org">
    <img src="https://lc-soft.io/static/images/logo-lcui-css.png" width=72 height=72>
  </a>

  <h3 align="center">LCUI.css</h3>

  <p align="center">
    一个适用于 LCUI 应用程序的 UI 组件库
    <br>
    <a href="docs"><strong>浏览 LCUI.css 的文档 &raquo;</strong></a>
  </p>
</p>

<br>

## 介绍

LCUI.css 是一个 UI 组件库，主要用于构建 [LCUI](https://github.com/lc-soft/LCUI) 应用程序，它提供了用于文本排版和常用元素的基本样式、简单的布局系统、CSS 组件和实用工具。它的 CSS 代码基于 [Bootstrap](https://github.com/twbs/bootstrap)，其用法和 Bootstrap 大致一样，但受限于 LCUI 现有特性以及对 CSS 标准的支持程度，并未完全实现 Boostrap 中的功能。

## 构建

### 先决条件

构建 LCUI.css 需要如下的依赖项：

* [Xmake](http://xmake.io) - 一个构建工具，用于编译 C 源代码
* [NodeJS](https://nodejs.org) - 一个 JavaScript 运行时，用于运行 JavaScript 写的构建工具
* [Python](https://www.python.org/) - 一个环境，用于运行 Python 写的构建工具

在安装完 NodeJS 后，你需要运行以下命令来安装相关依赖包：

    npm install

### 构建目标

    npm run build               # 构建所有目标
    npm run build-bin           # 构建 LCUI.css 的二进制文件，包括静态库（.lib/.a）或动态库（.dll/.so）
    npm run build-css           # 构建 CSS 文件，这些文件由 src/scss/ 中的文件编译而成
    npm run build-font          # 构建图标字体文件，图标来自 Material Design Icons
    npm run build-demo          # 构建演示程序，主要功能是呈现文档
    npm run build-demo-assets   # 构建演示程序的资源文件，包括 CSS 文件和文档
    npm run build-demo-bin      # 构建演示程序的二进制文件
    npm run build-demo-css      # 构建演示程序的 CSS 文件，这些文件由 demo/src/scss/ 中的文件编译而成
    npm run build-demo-docs     # 构建演示程序的文档
    npm run demo                # 运行演示程序

## 安装

从 **dist** 目录中复制文件到你的项目目录，然后配置你的项目资源包含路径。

我们建议你使用如下的目录结构，这样你就能直接从 **dist/assets/** 目录中复制文件到 **yourapp/app/** 目录。

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

## 作者

**Liu Chao**

- <https://lc-soft.io>
- <https://github.com/lc-soft>

## 许可

代码基于 [MIT 许可协议](LICENSE) 发布。
