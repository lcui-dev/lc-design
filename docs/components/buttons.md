# Buttons

Use LCUI's custom button styles for actions in forms, dialogs, and more with support for multiple sizes, states, and more.

## Examples

LCUI includes several predefined button styles, each serving its own semantic purpose, with a few extras thrown in for more control.

``` buttons-demo-xml
<button class="btn">Default</button>
<button class="btn btn-primary">Primary</button>
<button class="btn btn-secondary">Secondary</button>
<button class="btn btn-success">Sucesss</button>
<button class="btn btn-danger">Danger</button>
<button class="btn btn-warning">Warning</button>
<button class="btn btn-info">Info</button>
<button class="btn btn-light">Light</button>
<button class="btn btn-dark">Dark</button>
<button class="btn btn-link">link</button>
```

## Outline buttons

In need of a button, but not the hefty background colors they bring? Replace the default modifier classes with the `.btn-outline-*` ones to remove all background images and colors on any button.

``` buttons-demo-xml
<button class="btn btn-outline-primary">Primary</button>
<button class="btn btn-outline-secondary">Secondary</button>
<button class="btn btn-outline-success">Success</button>
<button class="btn btn-outline-danger">Danger</button>
<button class="btn btn-outline-warning">Warning</button>
<button class="btn btn-outline-info">Info</button>
<button class="btn btn-outline-light">Light</button>
<button class="btn btn-outline-dark">Dark</button>
```

## Sizes

Fancy larger or smaller buttons? Add `.btn-lg` or `.btn-sm` for additional sizes.

``` buttons-demo-xml
<button class="btn btn-lg">Large button</button>
<button class="btn btn-primary btn-lg">Large button</button>
<button class="btn btn-link btn-lg">Large button</button>
```

``` buttons-demo-xml
<button class="btn btn-sm">Small button</button>
<button class="btn btn-primary btn-sm">Small button</button>
<button class="btn btn-link btn-sm">Small button</button>
```

Create block level buttons—those that span the full width of a parent—by adding `.btn-block`.

``` block-buttons-demo-xml
<button class="btn btn-primary btn-lg btn-block">Block level button</button>
<button class="btn btn-lg btn-block">Block level button</button>
<button class="btn btn-link btn-lg btn-block">Block level button</button>
```
