# Alerts

Provide contextual feedback messages for typical user actions with the handful of available and flexible alert messages.

## Examples

Alerts are available for any length of text, as well as an optional dismiss button. For proper styling, use one of the eight required contextual classes (e.g., .alert-success).

``` alerts-demo-xml
<alert class="alert alert-primary">
  This is a primary alert—check it out!
</alert>
<alert class="alert alert-secondary">
  This is a secondary alert—check it out!
</alert>
<alert class="alert alert-success">
  This is a success alert—check it out!
</alert>
<alert class="alert alert-danger">
  This is a danger alert—check it out!
</alert>
<alert class="alert alert-warning">
  This is a warning alert—check it out!
</alert>
<alert class="alert alert-info">
  This is a info alert—check it out!
</alert>
<alert class="alert alert-light">
  This is a light alert—check it out!
</alert>
<alert class="alert alert-dark">
  This is a dark alert—check it out!
</alert>
```

## Dismissing

Add a dismiss button and the `.alert-dismissible` class, which adds extra padding to the right of the alert and positions the `.close` button.

On the dismiss button, add the `data-dismiss="alert"` attribute, which triggers the C functionality.

``` alerts-demo-xml
<alert class="alert alert-warning alert-dismissible">
  <strong class="mr-1">Holy guacamole!</strong>
  <text>You should check in on some of those fields below.</text>
  <button class="close" data-dismiss="alert">&#215;</button>
</alert>
```
