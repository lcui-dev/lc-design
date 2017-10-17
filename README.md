<p align="center">
  <a href="http://lcui.org">
    <img src="https://lcui.lc-soft.io/static/images/lcui-logo-lg.png" width=72 height=72>
  </a>

  <h3 align="center">LCUI.css</h3>

  <p align="center">
    Simple CSS framework for developing LCUI application.
    <br>
    <a href="https://docs.lcui.lc-soft.io/"><strong>Explore LCUI.css docs &raquo;</strong></a>
  </p>
</p>

<br>

## Download

- [Download the latest release.](https://github.com/lc-ui/lcui.css/releases)
- Clone the repo: `https://github.com/lc-ui/lcui.css.git`

## Build

### Prerequisites

Building LCUI.css has the following dependencies:

* [NodeJS](https://nodejs.org) — a JavaScript runtime to run building tools

After installing NodeJS, please run the following command to install the NodeJS dependency packages:

    npm install


### Build Targets

    npm run build             # Build all targets.
    npm run build-css         # Compile SCSS file to CSS file.
    npm run build-font        # Build iconfont file.
    npm run build-demo        # Build demo application and it's css file.
    npm run build-demo-css    # Build css file of demo application.
    npm run build-demo-exe    # Build demo application only.

## Install

Copy the files from the **dist** directory to your project directory, and configure your project assets include path.

We recommend that you use the following directory structure, this will be able to directly copy the files from the **dist** directory to **yourapp/app/assets/** directory.

```
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

Code released under the [MIT License](https://github.com/lc-ui/lcui.css/blob/master/LICENSE).
