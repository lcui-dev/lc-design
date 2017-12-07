# Dropdowns

Toggle contextual overlays for displaying lists of links and more with the LCUI dropdown component.

## Overview

Dropdowns are toggleable, contextual overlays for displaying lists of links and more. They’re toggled by clicking, not by hovering; this is an intentional design decision.

## Examples

``` dropdowns-demo-xml
<w id="btn-dropdown-example-1" class="btn">
  <w type="textview">Dropdown button</w>
  <w type="textview" class="icon icon-chevron-down"></w>
</w>
<w id="dropdown-example-1" class="dropdown-menu" data-target="btn-dropdown-example-1" data-container="demo-content">
  <w type="textview" class="dropdown-item">Action</w>
  <w type="textview" class="dropdown-item">Another action</w>
  <w type="textview" class="dropdown-item">Something else here</w>
</w>
```

## Menu headers

Add a header to label sections of actions in any dropdown menu.

``` dropdowns-demo-xml
<w class="dropdown-menu">
  <w type="h6" class="dropdown-header">Dropdown header</w>
  <w type="textview" class="dropdown-item">Action</w>
  <w type="textview" class="dropdown-item">Another action</w>
</w>
```

## Menu dividers

Separate groups of related menu items with a divider.


``` dropdowns-demo-xml
<w class="dropdown-menu">
  <w type="textview" class="dropdown-item">Action</w>
  <w type="textview" class="dropdown-item">Another action</w>
  <w type="textview" class="dropdown-item">Something else here</w>
  <w class="dropdown-divider"></w>
  <w type="textview" class="dropdown-item">Separated link</w>
</w>
```
