# coding:gb18030
# ��ȡ�Լ���д��html�����е�PDF�ĵ�,��ַ��file:///E:/ZjuTH/Documents/pythonCode/pythontest.html
import urllib2
import urllib
import re
import os

main_url = 'http://www.szse.cn/'
url='http://www.szse.cn/szseWeb/FrontController.szse?randnum=0.5234713626559824'
download='http://www.szse.cn/UpFiles/jgsy/'
#��Ҫ�ύ������ֵ��
query = {'ACTIONID':'7','TABKEY':'tab1','AJAX':'AJAX-TRUE','tab1PAGENO':'1','CATALOGID':'1800_jgxxgk','tab1PAGECOUNT':'69','REPORT_ACTION':'navigate'}


#urllib.urlencode(query[, doseq])����dict���߰�������Ԫ�ص�Ԫ���б�ת����url��
#�������� �ֵ�{'name': 'dark-bull', 'age': 200}����ת��Ϊ"name=dark-bull&
#age=200"
def getPage(url, query):
    date = urllib.urlencode(query)
    #��������˷�������
    post = urllib2.Request(url,date)
    # #���շ���˷��ص�����
    response  = urllib2.urlopen(post)
    # #ת��Ϊҳ�����
    page = response.read()
    return page

def getPdfUrl(html):
    reg = r'gkxx_jgsy_\d+\.PDF' #pdf
    url_re = re.compile(reg)
    url_lst = url_re.findall(html.decode('gb2312')) #����ƥ�������
    return(url_lst)


def getFile(url, file_name):
    u =  urllib2.urlopen(url)
    f = open(file_name, 'wb')
    block_sz = 8192
    while True:
        buffer = u.read(block_sz)
        if not buffer:
            break
        f.write(buffer)
    f.close()

download_dir = os.path.join(os.getcwd(),'pdf_download')

if not os.path.isdir(download_dir):
    print download_dir
    os.mkdir('pdf_download')
os.chdir(download_dir)

page_start=20
while page_start < 21:
    query['tab1PAGENO'] = str(page_start)
    page_start += 1
    page = getPage(url, query)
    #print page.decode('gb2312')
    pdf_urls = getPdfUrl(page)
    for pdf in pdf_urls:
        getFile(download  + pdf, str(page_start) + '_' + pdf)
   # with open(str(page_start)+ '.html', 'w') as f:
    #    f.write(page)
