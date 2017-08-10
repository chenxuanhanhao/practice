#!/bin/bash - 
#===============================================================================
#                                 DEFINITIONS
#===============================================================================
set -o nounset

sys_corpus='corpus.utf8.txt'

#===============================================================================
#                                 FUNCTIONS
#===============================================================================
function process(){
    local tmp="gbk.tmp"
	export LANG="zh_CN.GBK"
    # 0: dos2unix
    dos2unix $sys_corpus
	
    # 1: ת���ַ����롢ȥ��ƴ���ָ�����ȥ���ļ�����ӵ�Ӣ�ĵ�
    iconv -f utf-8 -t gbk ${sys_corpus} | sed "s/'//g" | awk 'length($0)>1' | \
    sed '/[A-Z]/'d | awk '($1!~/[0-9]/){OFS = "\t"; print $2, $1, $3}' > $tmp
}


#===============================================================================
#                                 CALLS
#===============================================================================
l=`locale`
echo $l
process




#===============================================================================
#                                 REFRENCES
#===============================================================================
#  [ -a FILE ]  ��� FILE ������Ϊ�档  #{{{
#  [ -b FILE ]  ��� FILE ��������һ���������ļ���Ϊ�档  
#  [ -c FILE ]  ��� FILE ��������һ���������ļ���Ϊ�档  
#  [ -d FILE ]  ��� FILE ��������һ��Ŀ¼��Ϊ�档  
#  [ -e FILE ]  ��� FILE ������Ϊ�档  
#  [ -f FILE ]  ��� FILE ��������һ����ͨ�ļ���Ϊ�档  
#  [ -g FILE ]  ��� FILE �������Ѿ�������SGID��Ϊ�档  
#  [ -h FILE ]  ��� FILE ��������һ������������Ϊ�档  
#  [ -k FILE ]  ��� FILE �������Ѿ�������ճ��λ��Ϊ�档  
#  [ -p FILE ]  ��� FILE ��������һ�����ֹܵ�(F���O)��Ϊ�档  
#  [ -r FILE ]  ��� FILE �������ǿɶ�����Ϊ�档  
#  [ -s FILE ]  ��� FILE �����Ҵ�С��Ϊ0��Ϊ�档  
#  [ -t FD ]    ����ļ������� FD ����ָ��һ���ն���Ϊ�档  
#  [ -u FILE ]  ��� FILE ������������SUID (set user ID)��Ϊ�档  
#  [ -w FILE ]  ��� FILE ��� FILE �������ǿ�д����Ϊ�档  
#  [ -x FILE ]  ��� FILE �������ǿ�ִ�е���Ϊ�档  
#  [ -O FILE ]  ��� FILE ����������Ч�û�ID��Ϊ�档  
#  [ -G FILE ]  ��� FILE ����������Ч�û�����Ϊ�档  
#  [ -L FILE ]  ��� FILE ��������һ������������Ϊ�档  
#  [ -N FILE ]  ��� FILE ���� and has been mod���ied since it was last read��Ϊ�档  
#  [ -S FILE ]  ��� FILE ��������һ���׽�����Ϊ�档 
#  
#  [ -z STRING ]  ��STRING�� �ĳ���Ϊ����Ϊ�档  
#  [ -n STRING ] or [ STRING ]  ��STRING�� �ĳ���Ϊ���� non-zero��Ϊ�档  
#  [ STRING1 == STRING2 ]  ���2���ַ�����ͬ�� ��=�� may be used instead of ��==�� for strict POSIX compliance��Ϊ�档  
#  [ STRING1 != STRING2 ]  ����ַ����������Ϊ�档 
#  [ STRING1 < STRING2 ]  ��� ��STRING1�� sorts before ��STRING2�� lexicographically in the current locale��Ϊ�档  
#  [ STRING1 > STRING2 ]  ��� ��STRING1�� sorts after ��STRING2�� lexicographically in the current locale��Ϊ�档  
#
#  [ ARG1 OP ARG2 ] ��OP�� is one of -eq, -ne, -lt, -le, -gt or -ge. ��ARG1�� and ��ARG2�� are integers}
#
#  var=$[$var op INT] ����������������������б�����#}}}

