# Dropdowns

Toggle contextual overlays for displaying lists of links and more with the LCUI dropdown component.

## Overview

Dropdowns are toggleable, contextual overlays for displaying lists of links and more. They’re toggled by clicking, not by hovering; this is an intentional design decision.

## Examples

``` dropdowns-demo-xml
<w class="btn" data-toggle="dropdown" data-target="dropdown-example-1">
  <text>Dropdown button</text>
  <icon name="chevron-down" />
</w>
<dropdown-menu id="dropdown-example-1">
  <text class="dropdown-item">Action</text>
  <text class="dropdown-item">Another action</text>
  <text class="dropdown-item">Something else here</text>
</dropdown-menu>
```

## Menu headers

Add a header to label sections of actions in any dropdown menu.

``` static-dropdowns-demo-xml
<w class="dropdown-menu">
  <h6 class="dropdown-header">Dropdown header</h6>
  <text class="dropdown-item">Action</text>
  <text class="dropdown-item">Another action</text>
</w>
```

## Menu dividers

Separate groups of related menu items with a divider.

``` static-dropdowns-demo-xml
<w class="dropdown-menu">
  <text class="dropdown-item">Action</text>
  <text class="dropdown-item">Another action</text>
  <text class="dropdown-item">Something else here</text>
  <w class="dropdown-divider"></w>
  <text class="dropdown-item">Separated link</text>
</w>
```
