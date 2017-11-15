# Overview

Components and options for laying out your LCUI project, including wrapping containers, a simple grid system.

## Containers

Containers are the most basic layout element LCUI and are required when using our default grid system. Choose from a fixed-width container or fluid-width.

While containers can be nested, most layouts do not require a nested container.

``` layout-demo-xml
<w class="container">
  <!-- Content here -->
  <w class="docs-example-container-header"></w>
  <w class="docs-example-container-sidebar"></w>
  <w class="docs-example-container-body">
    <w class="docs-example-container-content"></w>
  </w>
</w>
```

Use `.container-fluid` for a full width container, spanning the entire width of the viewport.

``` layout-demo-xml
<w class="container-fluid">
  <!-- Content here -->
  <w class="docs-example-container-header"></w>
  <w class="docs-example-container-sidebar"></w>
  <w class="docs-example-container-body">
    <w class="docs-example-container-content"></w>
  </w>
</w>
```
