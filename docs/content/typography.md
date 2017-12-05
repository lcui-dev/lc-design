# Typography

Typography sets default styles for headings, paragraphs, semantic text, blockquote and lists elements.

## Headings

All HTML headings, `h1` through `h6`, are available.

``` headings-demo-xml
<w type="h1">h1. LCUI heading</w>
<w type="h2">h2. LCUI heading</w>
<w type="h3">h3. LCUI heading</w>
<w type="h4">h4. LCUI heading</w>
<w type="h5">h5. LCUI heading</w>
<w type="h6">h6. LCUI heading</w>
```

`.h1` through `.h6` classes are also available, for when you want to match the font styling of a heading but cannot use the associated HTML element.

``` headings-demo-xml
<w type="p" class="h1">h1. LCUI heading</w>
<w type="p" class="h2">h2. LCUI heading</w>
<w type="p" class="h3">h3. LCUI heading</w>
<w type="p" class="h4">h4. LCUI heading</w>
<w type="p" class="h5">h5. LCUI heading</w>
<w type="p" class="h6">h6. LCUI heading</w>
```

## Paragraphs

``` paragraphs-demo-xml
<w type="p">你好, こんにちは, 안녕하세요</w>
<w type="p">Chinese (Simplified)</w>
<w type="p">革命不是请客吃饭，不是做文章，不是绘画绣花，不能那样雅致，那样从容不迫，“文质彬彬”，那样“温良恭俭让”。革命就是暴动，是一个阶级推翻一个阶级的暴烈的行动。</w>
<w type="p">Chinese (Tranditional)</w>
<w type="p">山不在高，有仙則名；水不在深，有龍則靈。斯是陋室，惟吾德馨。苔痕上階綠，草色入簾青；談笑有鴻儒，往來無白丁。可以調素琴，閱金經。無絲竹之亂耳，無案牘之勞形。南陽諸葛廬，西蜀子雲亭。孔子云：「何陋之有？」</w>
<w type="p">Japanese</w>
<w type="p">祇園精舎の鐘の声、諸行無常の響きあり。沙羅双樹の花の色、盛者必衰の理をあらはす。おごれる人も久しからず。ただ春の夜の夢のごとし。たけき者も遂にはほろびぬ、ひとへ‌​に風の前の塵に同じ。</w>
<w type="p">Korean</w>
<w type="p">나라말이 중국과 달라, 한문・한자와 서로 통하지 아니하므로, 어리석은 백성들이 말하고자 하는 바가 있어도, 끝내 제 뜻을 펴지 못하는 사람이 많다. 내가 이를 불쌍히 여겨, 새로 스물 여덟 글자를 만드니, 사람마다 하여금 쉽게 익혀, 날마다 씀에 편하게 하고자 할 따름이다.</w>
```

## Blockquote

``` blockquote-demo-xml
<w type="blockquote">
  <w type="p">The advance of technology is based on making it fit in so that you don't really even notice it, so it's part of everyday life.</w>
  <w type="cite">- Bill Gates</w>
</w>
```
