/*===============================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   �ļ����ƣ�get_cpu_nums.cpp
*   �� �� ��: Daniel
*   �������ڣ�2016��08��28��
*   ��    �������Ի��cpu����
*   ��    ע: 
*   ������־��
*
================================================================*/
 
#include <iostream>

#include "GetCpuNums.hpp"

using namespace std;
// please add your code here!

int main() {
    unsigned int sz = coreCount();
    cout<<"cpu cores: "<<sz<<endl;
    return 0;
}
