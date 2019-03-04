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
        <w type="p">你好, こんにちは, 안녕하세요</w>

        <w type="p">Chinese (Simplified)</w>

        <w type="p">革命不是请客吃饭，不是做文章，不是绘画绣花，不能那样雅致，那样从容不迫，“文质彬彬”，那样“温良恭俭让”。革命就是暴动，是一个阶级推翻一个阶级的暴烈的行动。</w>

        <w type="p">Chinese (Tranditional)</w>

        <w type="p">山不在高，有仙則名；水不在深，有龍則靈。斯是陋室，惟吾德馨。苔痕上階綠，草色入簾青；談笑有鴻儒，往來無白丁。可以調素琴，閱金經。無絲竹之亂耳，無案牘之勞形。南陽諸葛廬，西蜀子雲亭。孔子云：「何陋之有？」</w>

        <w type="p">Japanese</w>

        <w type="p">祇園精舎の鐘の声、諸行無常の響きあり。沙羅双樹の花の色、盛者必衰の理をあらはす。おごれる人も久しからず。ただ春の夜の夢のごとし。たけき者も遂にはほろびぬ、ひとへ‌​に風の前の塵に同じ。</w>

        <w type="p">Korean</w>
        
        <w type="p">나라말이 중국과 달라, 한문・한자와 서로 통하지 아니하므로, 어리석은 백성들이 말하고자 하는 바가 있어도, 끝내 제 뜻을 펴지 못하는 사람이 많다. 내가 이를 불쌍히 여겨, 새로 스물 여덟 글자를 만드니, 사람마다 하여금 쉽게 익혀, 날마다 씀에 편하게 하고자 할 따름이다.</w>

        <w type="blockquote">
          <w type="p">The advance of technology is based on making it fit in so that you don't really even notice it, so it's part of everyday life.</w>
          <w type="cite">- Bill Gates</w>
        </w>

        <w type="alert" class="alert alert-warning alert-dismissible">
          <w type="strong">MIT License</w>

          <w type="p">Copyright (c) 2017 LC's UI</w>

          <w type="p">Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:</w>

          <w type="p">The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.</w>

          <w type="p">THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
          </w>
    
          <w type="button" class="close" data-dismiss="alert">&#215;</w>
        </w>
      </w>
      <w class="modal-footer">
        <w type="button" class="btn" data-dismiss="modal">Close</w>
        <w type="button" class="btn btn-primary">Save changes</w>
      </w>
    </w>
  </w>
</w>
```
