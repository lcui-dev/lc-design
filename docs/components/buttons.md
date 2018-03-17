# Buttons

Use LCUI's custom button styles for actions in forms, dialogs, and more with support for multiple sizes, states, and more.

## Examples

LCUI includes several predefined button styles, each serving its own semantic purpose, with a few extras thrown in for more control.

``` buttons-demo-xml
<w type="button" class="btn">Default</w>
<w type="button" class="btn btn-primary">Primary</w>
<w type="button" class="btn btn-secondary">Secondary</w>
<w type="button" class="btn btn-success">Sucesss</w>
<w type="button" class="btn btn-danger">Danger</w>
<w type="button" class="btn btn-warning">Warning</w>
<w type="button" class="btn btn-info">Info</w>
<w type="button" class="btn btn-light">Light</w>
<w type="button" class="btn btn-dark">Dark</w>
<w type="button" class="btn btn-link">link</w>
```

## Outline buttons

In need of a button, but not the hefty background colors they bring? Replace the default modifier classes with the `.btn-outline-*` ones to remove all background images and colors on any button.

``` buttons-demo-xml
<w type="button" class="btn btn-outline-primary">Primary</w>
<w type="button" class="btn btn-outline-secondary">Secondary</w>
<w type="button" class="btn btn-outline-success">Success</w>
<w type="button" class="btn btn-outline-danger">Danger</w>
<w type="button" class="btn btn-outline-warning">Warning</w>
<w type="button" class="btn btn-outline-info">Info</w>
<w type="button" class="btn btn-outline-light">Light</w>
<w type="button" class="btn btn-outline-dark">Dark</w>
```

## Sizes

Fancy larger or smaller buttons? Add `.btn-lg` or `.btn-sm` for additional sizes.

``` buttons-demo-xml
<w type="button" class="btn btn-lg">Large button</w>
<w type="button" class="btn btn-primary btn-lg">Large button</w>
<w type="button" class="btn btn-link btn-lg">Large button</w>
```

``` buttons-demo-xml
<w type="button" class="btn btn-sm">Small button</w>
<w type="button" class="btn btn-primary btn-sm">Small button</w>
<w type="button" class="btn btn-link btn-sm">Small button</w>
```

Create block level buttons—those that span the full width of a parent—by adding `.btn-block`.

``` block-buttons-demo-xml
<w type="button" class="btn btn-primary btn-lg btn-block">Block level button</w>
<w type="button" class="btn btn-lg btn-block">Block level button</w>
<w type="button" class="btn btn-link btn-lg btn-block">Block level button</w>
```
