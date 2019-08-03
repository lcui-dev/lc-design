# Rate

Rate component can be used to show evaluation, and it provide a quick rating operation on something.

## Basic

The simplest usage.

``` rate-basic-demo-xml
<rate />
```

## Readonly

Set the `disabled` attribute to disable mouse interaction.

``` rate-readonly-demo-xml
<rate value="2" disabled="disabled" />
```

## Other star count

The default number of stars is 5, you can set it with the `count` attribute.

``` rate-count-demo-xml
<rate count="10" />
```

## Other icon

Replace the default star to other iconfont.

``` rate-icon-demo-xml
<rate icon="heart" void-icon="heart-outline" />
<w class="mb-2" />
<rate icon="emoticon-happy" void-icon="emoticon-neutral-outline" />
```

## Other character

Replace the default star to other character like alphabet, digit or even Chinese word.

``` rate-character-demo-xml
<rate character="A" />
<w class="mb-2" />
<rate character="好" />
```
