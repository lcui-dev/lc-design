# -*- coding:utf8 -*-
import os
import sys
import misaka as m
from pygments import highlight
from pygments.lexers import get_lexer_by_name
from pygments.formatters import HtmlFormatter
from xml.sax.saxutils import escape as escapeXML

# copy from pygements.css
HIGHLIGH_STYLES = {
    'hll': { 'background-color': '#ffffcc' },
    'c': { 'color': '#60a0b0', 'font-style': 'italic' }, # Comment
    'err': { 'color': '#fff', 'background-color': '#f00' }, # Error
    'k': { 'color': '#007020', 'font-weight': 'bold' }, # Keyword
    'o': { 'color': '#666666' }, # Operator
    'ch': { 'color': '#60a0b0', 'font-style': 'italic' }, # Comment.Hashbang
    'cm': { 'color': '#60a0b0', 'font-style': 'italic' }, # Comment.Multiline
    'cp': { 'color': '#007020' }, # Comment.Preproc
    'cpf': { 'color': '#60a0b0', 'font-style': 'italic' }, # Comment.PreprocFile
    'c1': { 'color': '#60a0b0', 'font-style': 'italic' }, # Comment.Single
    'cs': { 'color': '#60a0b0', 'background-color': '#fff0f0' }, # Comment.Special
    'gd': { 'color': '#A00000' }, # Generic.Deleted
    'ge': { 'font-style': 'italic' }, # Generic.Emph
    'gr': { 'color': '#FF0000' }, # Generic.Error
    'gh': { 'color': '#000080', 'font-weight': 'bold' }, # Generic.Heading
    'gi': { 'color': '#00A000' }, # Generic.Inserted
    'go': { 'color': '#888888' }, # Generic.Output
    'gp': { 'color': '#c65d09', 'font-weight': 'bold' }, # Generic.Prompt
    'gs': { 'font-weight': 'bold' }, # Generic.Strong
    'gu': { 'color': '#800080', 'font-weight': 'bold' }, # Generic.Subheading
    'gt': { 'color': '#0044DD' }, # Generic.Traceback
    'kc': { 'color': '#007020', 'font-weight': 'bold' }, # Keyword.Constant
    'kd': { 'color': '#007020', 'font-weight': 'bold' }, # Keyword.Declaration
    'kn': { 'color': '#007020', 'font-weight': 'bold' }, # Keyword.Namespace
    'kp': { 'color': '#007020' }, # Keyword.Pseudo
    'kr': { 'color': '#007020', 'font-weight': 'bold' }, # Keyword.Reserved
    'kt': { 'color': '#902000' }, # Keyword.Type
    'm': { 'color': '#40a070' }, # Literal.Number
    's': { 'color': '#4070a0' }, # Literal.String
    'na': { 'color': '#4070a0' }, # Name.Attribute
    'nb': { 'color': '#007020' }, # Name.Builtin
    'nc': { 'color': '#0e84b5', 'font-weight': 'bold' }, # Name.Class
    'no': { 'color': '#60add5' }, # Name.Constant
    'nd': { 'color': '#555555', 'font-weight': 'bold' }, # Name.Decorator
    'ni': { 'color': '#d55537', 'font-weight': 'bold' }, # Name.Entity
    'ne': { 'color': '#007020' }, # Name.Exception
    'nf': { 'color': '#06287e' }, # Name.Function
    'nl': { 'color': '#002070', 'font-weight': 'bold' }, # Name.Label
    'nn': { 'color': '#0e84b5', 'font-weight': 'bold' }, # Name.Namespace
    'nt': { 'color': '#062873', 'font-weight': 'bold' }, # Name.Tag
    'nv': { 'color': '#bb60d5' }, # Name.Variable
    'ow': { 'color': '#007020', 'font-weight': 'bold' }, # Operator.Word
    'w': { 'color': '#bbbbbb' }, # Text.Whitespace
    'mb': { 'color': '#40a070' }, # Literal.Number.Bin
    'mf': { 'color': '#40a070' }, # Literal.Number.Float
    'mh': { 'color': '#40a070' }, # Literal.Number.Hex
    'mi': { 'color': '#40a070' }, # Literal.Number.Integer
    'mo': { 'color': '#40a070' }, # Literal.Number.Oct
    'sa': { 'color': '#4070a0' }, # Literal.String.Affix
    'sb': { 'color': '#4070a0' }, # Literal.String.Backtick
    'sc': { 'color': '#4070a0' }, # Literal.String.Char
    'dl': { 'color': '#4070a0' }, # Literal.String.Delimiter
    'sd': { 'color': '#4070a0', 'font-style': 'italic' }, # Literal.String.Doc
    's2': { 'color': '#4070a0' }, # Literal.String.Double
    'se': { 'color': '#4070a0', 'font-weight': 'bold' }, # Literal.String.Escape
    'sh': { 'color': '#4070a0' }, # Literal.String.Heredoc
    'si': { 'color': '#70a0d0', 'font-style': 'italic' }, # Literal.String.Interpol
    'sx': { 'color': '#c65d09' }, # Literal.String.Other
    'sr': { 'color': '#235388' }, # Literal.String.Regex
    's1': { 'color': '#4070a0' }, # Literal.String.Single
    'ss': { 'color': '#517918' }, # Literal.String.Symbol
    'bp': { 'color': '#007020' }, # Name.Builtin.Pseudo
    'fm': { 'color': '#06287e' }, # Name.Function.Magic
    'vc': { 'color': '#bb60d5' }, # Name.Variable.Class
    'vg': { 'color': '#bb60d5' }, # Name.Variable.Global
    'vi': { 'color': '#bb60d5' }, # Name.Variable.Instance
    'vm': { 'color': '#bb60d5' }, # Name.Variable.Magic
    'il': { 'color': '#40a070' }, # Literal.Number.Integer.Long
}

VS_STYLES = {
    'hll': { 'background-color': '#ffffcc' },
    'c':  { 'color': '#008000' }, # Comment
    'k':  { 'color': '#0000ff' }, # Keyword
    'ch':  { 'color': '#008000' }, # Comment.Hashbang
    'cm':  { 'color': '#008000' }, # Comment.Multiline
    'cp':  { 'color': '#0000ff' }, # Comment.Preproc
    'cpf': { 'color': '#008000' }, # Comment.PreprocFile
    'c1':  { 'color': '#008000' }, # Comment.Single
    'cs':  { 'color': '#008000' }, # Comment.Special
    'ge':  { 'font-style': 'italic' }, # Generic.Emph
    'gh':  { 'font-weight': 'bold' }, # Generic.Heading
    'gp':  { 'font-weight': 'bold' }, # Generic.Prompt
    'gs':  { 'font-weight': 'bold' }, # Generic.Strong
    'gu':  { 'font-weight': 'bold' }, # Generic.Subheading
    'kc':  { 'color': '#0000ff' }, # Keyword.Constant
    'kd':  { 'color': '#0000ff' }, # Keyword.Declaration
    'kn': { 'color': '#0000ff' }, # Keyword.Namespace
    'kp': { 'color': '#0000ff' }, # Keyword.Pseudo
    'kr': { 'color': '#0000ff' }, # Keyword.Reserved
    'kt': { 'color': '#2b91af' }, # Keyword.Type
    's': { 'color': '#a31515' }, # Literal.String
    'nc': { 'color': '#2b91af' }, # Name.Class
    'ow': { 'color': '#0000ff' }, # Operator.Word
    'sa': { 'color': '#a31515' }, # Literal.String.Affix
    'sb': { 'color': '#a31515' }, # Literal.String.Backtick
    'sc': { 'color': '#a31515' }, # Literal.String.Char
    'dl': { 'color': '#a31515' }, # Literal.String.Delimiter
    'sd': { 'color': '#a31515' }, # Literal.String.Doc
    's2': { 'color': '#a31515' }, # Literal.String.Double
    'se': { 'color': '#a31515' }, # Literal.String.Escape
    'sh': { 'color': '#a31515' }, # Literal.String.Heredoc
    'si': { 'color': '#a31515' }, # Literal.String.Interpol
    'sx': { 'color': '#a31515' }, # Literal.String.Other
    'sr': { 'color': '#a31515' }, # Literal.String.Regex
    's1': { 'color': '#a31515' }, # Literal.String.Single
    'ss': { 'color': '#a31515' } # Literal.String.Symbol
}

XML_TEMPLATE = '''\
<?xml version="1.0" encoding="UTF-8" ?>
<lcui-app>
  <ui>
    <w type="{}-view" class="view">
      {}
    </w>
  </ui>
</lcui-app>
'''

def get_style_tags(class_name):
    def get_value(name):
        value = base_style.get(name)
        if new_style and new_style.get(name):
            value = new_style[name]
        return value

    tags = []
    if not HIGHLIGH_STYLES.get(class_name):
        return tags
    new_style = VS_STYLES.get(class_name)
    base_style = HIGHLIGH_STYLES[class_name]
    value = get_value('color')
    if value:
        tags.append({
            'name': 'color',
            'value': value
        })
    value = get_value('font-weight')
    if value:
        if value == 'bold':
            tags.append({ 'name': 'b' })
    value = get_value('font-style')
    if value:
        if value == 'italic':
            tags.append({ 'name': 'i' })
    value = get_value('background-color')
    if value:
        tags.append({
            'name': 'bgcolor',
            'value': value
        })
    return tags

def get_style_tags_str(tags):
    tags_str = ''
    for tag in tags:
        tags_str += '[%s' % tag['name']
        if tag.get('value'):
            tags_str += '=%s' % tag['value']
        tags_str += ']'
    return tags_str

def get_style_tags_end_str(tags):
    tags_str = ''
    for tag in tags:
        tags_str += '[/%s]' % tag['name']
    return tags_str

def unwrap_box(html):
    pre_tag = '<pre>'
    div_tag = '<div>'
    box_tag = '<div class="highlight">'
    if html[0:len(box_tag)] == box_tag:
        html = html[len(box_tag):-len(div_tag) - 2]
    if html[0:len(pre_tag)] == pre_tag:
        html = html[len(pre_tag):-len(pre_tag) - 2]
    return html

def convert_html(html):
    xml = ''
    stack = []
    span_end = '</span>'
    span_head = '<span'
    html = unwrap_box(html)
    while len(html) > 0:
        tags = []
        class_name = ''
        tag_left = html.find(span_head)
        if tag_left == -1:
            xml += html
            break
        xml += html[:tag_left]
        tag_right = html.find('>')
        tag = html[tag_left:tag_right]
        class_left = tag.find('class="')
        if class_left > 0:
            class_left += 7
            class_name = tag[class_left:]
            class_right = class_name.find('"')
            class_name = class_name[:class_right]
            if len(class_name) > 0:
                tags = get_style_tags(class_name)
                xml += get_style_tags_str(tags)
                stack.append(tags)
        html = html[tag_right + 1:]
        i = html.find(span_end)
        if i >= 0:
            xml += html[:i]
            if len(stack) > 0:
                tags = stack.pop()
                xml += get_style_tags_end_str(tags)
            html = html[i + len(span_end):]
    return xml

class XMLRenderer(m.HtmlRenderer):
    DEMO_CODE_TMPL = '''
<w class="demo-box{0}">
  <w class="demo-preview-box">{1}</w>
  <w type="code-block" class="code-block">{2}</w>
</w>
'''

    CODE_TMPL = '\n<w type="code-block" class="code-block">{}</w>\n'

    def header(self, text, level):
        return '<w type="h{0}">{1}</w>\n'.format(level, text)

    def blockcode(self, text, lang):
        code = text.strip()
        formatter = HtmlFormatter()
        i = lang.find('demo-xml')
        if lang and i >= 0:
            class_ = ''
            lexer = get_lexer_by_name('xml')
            text = convert_html(highlight(code, lexer, formatter))
            if i > 0:
                class_  = ' ' + lang[:i] + 'demo'
            return self.DEMO_CODE_TMPL.format(class_, code, text)
        if lang == 'embedded-xml':
            return code
        lexer = get_lexer_by_name(lang)
        text = convert_html(highlight(code, lexer, formatter))
        return self.CODE_TMPL.format(text)

    def emphasis(self, text):
        return '[b]{}[/b]'.format(text)

    def double_emphasis(self, text):
        return '[b]{}[/b]'.format(text)

    def triple_emphasis(self, text):
        return '[b]{}[/b]'.format(text)

    def paragraph(self, text):
        return '<w type="p">{}</w>\n'.format(text)

    def codespan(self, text):
        return '[color=#bd4147][bgcolor=#fdf4f4]'\
                ' {} [/bgcolor][/color]'.format(text.strip())

def convert_path(path):
    return path.replace('/', os.path.sep)

def replace_dirname(path, dirname, new_dirname):
    if path.find(dirname) != 0:
        return path
    return os.path.join(new_dirname, path[len(dirname)+1:])

def build_docs(docs_dir='docs', output_dir='demo/app/assets/views'):
    renderer = XMLRenderer()
    docs_dir = convert_path(docs_dir)
    output_dir = convert_path(output_dir)
    md = m.Markdown(renderer, extensions=('fenced-code',))
    for root, dirs, files in os.walk(docs_dir):
        for name in files:
            i = name.find('.md')
            if i == -1:
                continue
            doc_path = os.path.join(root, name)
            xml_path = replace_dirname(doc_path, docs_dir, output_dir)
            xml_path = xml_path[:len(xml_path) - 3] + '.xml'
            xml_dir = os.path.dirname(xml_path)
            if not os.path.exists(xml_dir):
                os.makedirs(xml_dir)
            print('build: %s' % xml_path)
            if sys.version_info > (3, 0):
                md_file = open(doc_path, 'r', encoding='utf8')
                xml_file = open(xml_path, 'w+', encoding='utf8')
            else:
                md_file = open(doc_path, 'r')
                xml_file = open(xml_path, 'w+')
            xml_content = md(md_file.read())
            xml_content = XML_TEMPLATE.format(name[:i], xml_content)
            xml_file.write(xml_content)
            xml_file.close()
            md_file.close()

if __name__ == '__main__':
    if sys.version_info < (3, 0):
        reload(sys)
        sys.setdefaultencoding('utf8')
    build_docs()
