# Toasts

Push notifications to your visitors with a toast, a lightweight and easily customizable alert message.

Toasts are lightweight notifications designed to mimic the push notifications that have been popularized by mobile and desktop operating systems.

## Examples

### Basic

To encourage extensible and predictable toasts, we recommend a header and body.

``` basic-toast-demo-xml
<w class="toast">
  <w class="toast-header">
    <img class="rounded mr-2" />
    <strong>LC Design</strong>
    <w class="toast-header-right">
      <small class="text-muted">11 mins ago</small>
      <button class="ml-2 close" data-dismiss="toast">&#215;</button>
    </w>
  </w>
  <text class="toast-body">
    Hello, world! This is a toast message.
  </text>
</w>
```

### Translucent

Toasts are slightly translucent, too, so they blend over whatever they might appear over.

``` translucent-toast-demo-xml
<w class="toast">
  <w class="toast-header">
    <img class="rounded mr-2" />
    <strong>LC Design</strong>
    <w class="toast-header-right">
      <small class="text-muted">11 mins ago</small>
      <button class="ml-2 close" data-dismiss="toast">&#215;</button>
    </w>
  </w>
  <text class="toast-body">
    Hello, world! This is a toast message.
  </text>
</w>
```

### Stacking

When you have multiple toasts, we default to vertically stacking them in a readable manner.

``` stacking-toast-demo-xml
<w class="toast">
  <w class="toast-header">
    <img class="rounded mr-2" />
    <strong>LC Design</strong>
    <w class="toast-header-right">
      <small class="text-muted">just now</small>
      <button class="ml-2 close" data-dismiss="toast">&#215;</button>
    </w>
  </w>
  <text class="toast-body">
    See? Just like this.
  </text>
</w>

<w class="toast">
  <w class="toast-header">
    <img class="rounded mr-2" />
    <strong>LC Design</strong>
    <w class="toast-header-right">
      <small class="text-muted">2 seconds ago</small>
      <button class="ml-2 close" data-dismiss="toast">&#215;</button>
    </w>
  </w>
  <text class="toast-body">
    Heads up, toasts will stack automatically
  </text>
</w>
```
