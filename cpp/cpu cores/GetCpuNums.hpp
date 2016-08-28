/*===============================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   �ļ����ƣ�get_cpu_nums.hpp
*   �� �� �� Daniel
*   �������ڣ�2016��08��28��
*   ��    �������cpu����
*   ��    ע: 
*   ������־��
*
================================================================*/
 
#ifndef _GET_CPU_NUMS_H
#define _GET_CPU_NUMS_H
#ifdef __cplusplus
extern "C"
{
#endif

    #if !defined (_WIN32) && !defined (_WIN64)
    #define LINUX
        #include <unistd.h>
    #else
    #define WINDOWS
        #include <windows.h>
    #endif

    unsigned int coreCount() {
        unsigned int count = 1; // ����һ��
    #if defined (LINUX)
        count = sysconf(_SC_NPROCESSORS_CONF);
    #elif defined (WINDOWS)
        SYSTEM_INFO si;
        GetSystemInfo(&si);
        count = si.dwNumberOfProcessors;
    #endif
        return count;
    }

#ifdef __cplusplus
}
#endif //GET_CPU_NUMS_H
#endif
