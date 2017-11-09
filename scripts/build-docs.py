import os
import sys
import misaka as m
from pygments import highlight
from pygments.formatters import HtmlFormatter, ClassNotFound
from pygments.lexers import get_lexer_by_name
from xml.sax.saxutils import escape as escapeXML

XML_FRAME ='''\
<?xml version="1.0" encoding="UTF-8" ?>
<lcui-app>
  <ui>
    {}
  </ui>
</lcui-app>
'''

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
        i = lang.find('demo-xml')
        if lang and i >= 0:
            class_ = ''
            if i > 0:
                class_  = ' ' + lang[:i] + 'demo'
            return self.DEMO_CODE_TMPL.format(class_, code, escapeXML(code))
        if lang == 'embedded-xml':
            return code
        return self.CODE_TMPL.format(escapeXML(code))

    def paragraph(self, text):
        return '<w type="p">{}</w>\n'.format(text)
    
    def codespan(self, text):
        return '[color=#bd4147] {} [/color]'.format(text.strip())

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
            if name.find('.md') == -1:
                continue
            doc_path = os.path.join(root, name)
            xml_path = replace_dirname(doc_path, docs_dir, output_dir)
            xml_path = xml_path[:len(xml_path) - 3] + '.xml'
            xml_dir = os.path.dirname(xml_path)
            if not os.path.exists(xml_dir):
                os.makedirs(xml_dir)
            print 'build: %s' % xml_path
            md_file = open(doc_path, 'r')
            xml_file = open(xml_path, 'w+')
            xml_content = md(md_file.read())
            xml_content = XML_FRAME.format(xml_content)
            xml_file.write(xml_content)
            xml_file.close()
            md_file.close()

if __name__ == '__main__':
    reload(sys)
    sys.setdefaultencoding('utf-8')
    build_docs()
