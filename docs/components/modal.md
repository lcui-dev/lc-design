# Modal

Use LCUI's modal component to add dialogs to your application for lightboxes, user notifications, or completely custom content.

## Examples

### Modal components

Below is a static modal example (meaning its `position` and `display` have been overridden). Included are the modal header, modal body (required for `padding`), and modal footer (optional). We ask that you include modal headers with dismiss actions whenever possible, or provide another explicit dismiss action.

``` static-modal-demo-xml
<w type="modal" class="modal">
  <w class="modal-dialog">
    <w class="modal-content">
      <w class="modal-header">
        <w type="h5" class="modal-title">Modal Title</w>
        <w type="button" data-dismiss="modal" class="close">&#215;</w>
      </w>
      <w class="modal-body">
        <w type="p">Modal body text goes here.</w>
      </w>
      <w class="modal-footer">
        <w type="button" class="btn">Close</w>
        <w type="button" class="btn btn-primary">Save changes</w>
      </w>
    </w>
  </w>
</w>
```

### Demo

Toggle a working modal demo by clicking the button below. It will slide down in from the top of the page.

``` modal-demo-xml
<!-- Button trigger modal -->
<w type="button" class="btn btn-primary" data-toggle="modal" data-target="example-modal">
  Launch demo modal
</w>

<!-- Modal -->
<w id="example-modal" type="modal" class="modal">
  <w class="modal-dialog">
    <w class="modal-content">
      <w class="modal-header">
        <w type="h5" class="modal-title">Modal Title</w>
        <w type="button" data-dismiss="modal" class="close">&#215;</w>
      </w>
      <w class="modal-body">
        <w type="p">Woohoo, you're reading this text in a modal!</w>
      </w>
      <w class="modal-footer">
        <w type="button" class="btn" data-dismiss="modal">Close</w>
        <w type="button" class="btn btn-primary">Save changes</w>
      </w>
    </w>
  </w>
</w>
```

### Scrolling long content

When modals become too long for the user’s viewport or device, they scroll independent of the page itself. Try the demo below to see what we mean.

``` modal-demo-xml
<!-- Button trigger modal -->
<w type="button" class="btn btn-primary" data-toggle="modal" data-target="example-modal-2">
  Launch demo modal
</w>

<!-- Modal -->
<w id="example-modal-2" type="modal" class="modal">
  <w class="modal-dialog">
    <w class="modal-content">
      <w class="modal-header">
        <w type="h5" class="modal-title">Modal Title</w>
        <w type="button" data-dismiss="modal" class="close">&#215;</w>
      </w>
      <w class="modal-body">
        <w type="p">Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</w>

        <w type="p">Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</w>

        <w type="p">Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</w>

        <w type="p">Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</w>

        <w type="p">Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</w>

        <w type="p">Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</w>

        <w type="p">Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</w>

        <w type="p">Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</w>

        <w type="p">Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</w>

        <w type="p">Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</w>

        <w type="p">Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</w>

        <w type="p">Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</w>

        <w type="p">Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</w>

        <w type="p">Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</w>

        <w type="p">Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</w>

        <w type="p">Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</w>

        <w type="p">Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</w>

        <w type="p">Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</w>
      </w>
      <w class="modal-footer">
        <w type="button" class="btn" data-dismiss="modal">Close</w>
        <w type="button" class="btn btn-primary">Save changes</w>
      </w>
    </w>
  </w>
</w>
```
