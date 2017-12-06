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
  <w type="textview" class="dropdown-item" id="debug-dropdown-item">Action</w>
  <w type="textview" class="dropdown-item">Another action</w>
  <w type="textview" class="dropdown-item">Something else here</w>
</w>
```
