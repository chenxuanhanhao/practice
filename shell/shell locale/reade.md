## �鿴����
locale ����鿴���룺

locale 

> 
LANG=en_US.UTF-8
LC_CTYPE="en_US.UTF-8"
LC_NUMERIC="en_US.UTF-8"
LC_TIME="en_US.UTF-8"
LC_COLLATE="en_US.UTF-8"
LC_MONETARY="en_US.UTF-8"
LC_MESSAGES="en_US.UTF-8"
LC_PAPER="en_US.UTF-8"
LC_NAME="en_US.UTF-8"
LC_ADDRESS="en_US.UTF-8"
LC_TELEPHONE="en_US.UTF-8"
LC_MEASUREMENT="en_US.UTF-8"
LC_IDENTIFICATION="en_US.UTF-8"
LC_ALL=




## �޸�ϵͳ����
�����û�����/etc/profile

�����û���������shell��������ļ�

���Եĵ����޸�ÿ�� LC_XXX, Ҳ�����޸� LANG �� LC_ALL ʹ���е���Ч�����ȼ���ϵ��

LC_ALL > LC_XXX > LANG

vi /etc/profile

#export LC_ALL="zh_CN.GBK"
export LANG="zh_CN.GBK"

�޸Ĺ��������ļ����� /etc/profile��ʱ��ò�Ҫ���� LC_ALL����Ϊ���ȼ��Ĺ�ϵ����ʹ��ͨ�û������˲�ͬ�� LC_XXX���������Ҳ������Ч�����������ڹ��������ļ����� /etc/profile��������  LANG��

## ���������Ŀ�

�鿴ϵͳ����
locale 

> 
LANG=en_US.UTF-8
LC_CTYPE="en_US.UTF-8"
LC_NUMERIC="en_US.UTF-8"
LC_TIME="en_US.UTF-8"
LC_COLLATE="en_US.UTF-8"
LC_MONETARY="en_US.UTF-8"
LC_MESSAGES="en_US.UTF-8"
LC_PAPER="en_US.UTF-8"
LC_NAME="en_US.UTF-8"
LC_ADDRESS="en_US.UTF-8"
LC_TELEPHONE="en_US.UTF-8"
LC_MEASUREMENT="en_US.UTF-8"
LC_IDENTIFICATION="en_US.UTF-8"
LC_ALL=
 

sh lang_test.sh

���ڱ������⵼��awk��sed�����ļ������⡣
gbk.tmp ������ͬ��

echo "abc�������" | LC_ALL='zh_CN.GBK' awk '{print substr($1, 6,1)}'

�������

echo "abc�������" | LC_ALL='en_US.UTF-8' awk '{print substr($1, 6,1)}'

������հ�