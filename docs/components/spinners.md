# Spinners

Indicate the loading state of a component or page with spinners.

## About

“spinners” can be used to show the loading state in your projects. They’re built only with HTML and CSS, meaning you don’t need any C code to create them. Their appearance, alignment, and sizing can be easily customized with ourutility classes.

## Border spinner

Use the border spinners for a lightweight loading indicator.

``` spinners-demo-xml
<spinner />
<spinner type="ring" />
```

## Colors

The border spinner uses `currentColor` for its `color`, meaning you can customize the color with text color utilities. You can use any of our text color utilities on the standard spinner.

``` colors-spinners-demo-xml

<w class="mb-2">
  <spinner class="text-primary" />
  <spinner class="text-secondary" />
  <spinner class="text-success" />
  <spinner class="text-danger" />
  <spinner class="text-warning" />
  <spinner class="text-info" />
  <spinner class="text-light" />
  <spinner class="text-dark" />
</w>
<w>
  <spinner type="ring" class="text-primary" />
  <spinner type="ring" class="text-secondary" />
  <spinner type="ring" class="text-success" />
  <spinner type="ring" class="text-danger" />
  <spinner type="ring" class="text-warning" />
  <spinner type="ring" class="text-info" />
  <spinner type="ring" class="text-light" />
  <spinner type="ring" class="text-dark" />
</w>
```

## Alignment

Spinners in LC Design are built with `px`, `currentColor`, and `display: inline-block`. This means they can easily be resized, recolored, and quickly aligned.

### Margin

Use margin utilities like .m-5 for easy spacing.

``` margin-spinners-demo-xml
<spinner class="m-5" />
```

### Placement

Use flexbox utilities, float utilities to place spinners exactly where you need them in any situation.

#### Flex

``` flex-spinners-demo-xml
<w class="d-flex justify-content-center">
  <spinner />
</w>
```

## Size

Set `size="small"` attribute to make a smaller spinner.

``` size-spinners-demo-xml
<spinner size="small" />
```

Or, use custom CSS or inline styles to change the dimensions as needed.

``` style-spinners-demo-xml
<spinner style="font-size: 36px" />
```
