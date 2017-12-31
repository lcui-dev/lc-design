# Dropdowns

Toggle contextual overlays for displaying lists of links and more with the LCUI dropdown component.

## Overview

Dropdowns are toggleable, contextual overlays for displaying lists of links and more. They’re toggled by clicking, not by hovering; this is an intentional design decision.

## Examples

``` dropdowns-demo-xml
<w class="btn" data-toggle="dropdown" data-target="dropdown-example-1">
  <w type="textview">Dropdown button</w>
  <w type="textview" class="icon icon-chevron-down"></w>
</w>
<w type="dropdown-menu" id="dropdown-example-1">
  <w type="textview" class="dropdown-item">Action</w>
  <w type="textview" class="dropdown-item">Another action</w>
  <w type="textview" class="dropdown-item">Something else here</w>
</w>
```

## Menu headers

Add a header to label sections of actions in any dropdown menu.

``` static-dropdowns-demo-xml
<w type="dropdown-menu">
  <w type="h6" class="dropdown-header">Dropdown header</w>
  <w type="textview" class="dropdown-item">Action</w>
  <w type="textview" class="dropdown-item">Another action</w>
</w>
```

## Menu dividers

Separate groups of related menu items with a divider.

``` static-dropdowns-demo-xml
<w type="dropdown-menu">
  <w type="textview" class="dropdown-item">Action</w>
  <w type="textview" class="dropdown-item">Another action</w>
  <w type="textview" class="dropdown-item">Something else here</w>
  <w class="dropdown-divider"></w>
  <w type="textview" class="dropdown-item">Separated link</w>
</w>
```
