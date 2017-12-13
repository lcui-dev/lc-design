# Modal

Use LCUI's modal component to add dialogs to your application for lightboxes, user notifications, or completely custom content.

## Examples

Below is a static modal example (meaning its `position` and `display` have been overridden). Included are the modal header, modal body (required for `padding`), and modal footer (optional). We ask that you include modal headers with dismiss actions whenever possible, or provide another explicit dismiss action.

``` modal-demo-xml
<w class="modal">
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
