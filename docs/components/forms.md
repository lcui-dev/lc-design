# Forms

Examples and usage guidelines for form control styles, layout options, and custom components for creating a wide variety of forms.

## Examples

Here’s a quick example to demonstrate Bootstrap’s form styles. Keep reading for documentation on required classes, form layout, and more.

``` forms-demo-xml
<w class="form">
  <w class="form-group">
    <w type="label" for="example-input-email-1">Email address</w>
    <w type="textedit" class="form-control" id="example-input-email-1" placeholder="Enter email" />
    <w type="small" class="form text text-muted">We'll never share your email with anyone else.</w>
  </w>
  <w class="form-group">
    <w type="label" for="example-input-password-1">Password</w>
    <w type="password" class="form-control" id="example-input-password-1" placeholder="Passowrd" />
  </w>
  <w class="form-group">
    <w type="button" class="btn btn-primary">Submit</w>
  </w>
</w>
```

## Sizing

Set heights using classes like `.form-control-lg` and `.form-control-sm`.

``` forms-sizing-demo-xml
<textedit class="form-control form-control-lg" placeholder=".form-control-lg" />
<textedit class="form-control" placeholder="Default input" />
<textedit class="form-control form-control-sm" placeholder=".form-control-sm" />
```
