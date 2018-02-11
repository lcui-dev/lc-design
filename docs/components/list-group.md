# List group

List groups are a flexible and powerful component for displaying a series of content. Modify and extend them to support just about any content within.

## Basic example

The most basic list group is an unordered list with list items and the proper classes. Build upon it with the options that follow, or with your own CSS as needed.

``` list-group-demo-xml
<w class="list-group">
  <w type="textview" class="list-group-item">Cras justo odio</w>
  <w type="textview" class="list-group-item">Dapibus ac facilisis in</w>
  <w type="textview" class="list-group-item">Morbi leo risus</w>
  <w type="textview" class="list-group-item">Porta ac consectetur ac</w>
  <w type="textview" class="list-group-item">Vestibulum at eros</w>
</w>
```

## Links and buttons

Use `a`s or `button`s to create actionable list group items with hover, disabled, and active states by adding `.list-group-item-action`. We separate these pseudo-classes to ensure list groups made of non-interactive elements don’t provide a click or tap affordance.

Be sure to **not use the standard** `.btn` **classes here**.

``` list-group-demo-xml
<w class="list-group">
  <w type="a" class="list-group-item list-group-item-action active">
    Cras justo odio
  </w>
  <w type="a" class="list-group-item list-group-item-action">Dapibus ac facilisis in</w>
  <w type="a" class="list-group-item list-group-item-action">Morbi leo risus</w>
  <w type="a" class="list-group-item list-group-item-action">Porta ac consectetur ac</w>
  <w type="a" class="list-group-item list-group-item-action disabled">Vestibulum at eros</w>
</w>
```

With `button`s, you can also make use of the `disabled` attribute instead of the `.disabled` class.

``` list-group-demo-xml
<w class="list-group">
  <w type="button" class="list-group-item list-group-item-action active">
    Cras justo odio
  </w>
  <w type="button" class="list-group-item list-group-item-action">Dapibus ac facilisis in</w>
  <w type="button" class="list-group-item list-group-item-action">Morbi leo risus</w>
  <w type="button" class="list-group-item list-group-item-action">Porta ac consectetur ac</w>
  <w type="button" class="list-group-item list-group-item-action" disabled="true">Vestibulum at eros</w>
</w>
```

## Flush

Add `.list-group-flush` to remove some borders and rounded corners to render list group items edge-to-edge in a parent container (e.g., cards).

``` list-group-demo-xml
<w class="list-group list-group-flush">
  <w type="textview" class="list-group-item">Cras justo odio</w>
  <w type="textview" class="list-group-item">Dapibus ac facilisis in</w>
  <w type="textview" class="list-group-item">Morbi leo risus</w>
  <w type="textview" class="list-group-item">Porta ac consectetur ac</w>
  <w type="textview" class="list-group-item">Vestibulum at eros</w>
</w>
```

## Contextual classes

Use contextual classes to style list items with a stateful background and color.

``` list-group-demo-xml
<w class="list-group">
  <w type="textview"class="list-group-item">Dapibus ac facilisis in</w>
  <w type="textview"class="list-group-item list-group-item-primary">This is a primary list group item</w>
  <w type="textview"class="list-group-item list-group-item-secondary">This is a secondary list group item</w>
  <w type="textview"class="list-group-item list-group-item-success">This is a success list group item</w>
  <w type="textview"class="list-group-item list-group-item-danger">This is a danger list group item</w>
  <w type="textview"class="list-group-item list-group-item-warning">This is a warning list group item</w>
  <w type="textview"class="list-group-item list-group-item-info">This is a info list group item</w>
  <w type="textview"class="list-group-item list-group-item-light">This is a light list group item</w>
  <w type="textview"class="list-group-item list-group-item-dark">This is a dark list group item</w>
</w>
```
