/*
 ***************************************************************
 * File Name:    time.c
 * Declaration:  
 *      Linux 下获得微秒时间
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2014年07月13日 星期日 22时35分53秒
 ***************************************************************
 */

#include <sys/time.h>

unsigned long get_time(void)
{
        unsigned long now_time;

        struct timeval start;
        struct timeval end;
        gettimeofday(&start, NULL);
        gettimeofday(&end, NULL);

        now_time = tv.sec * 10000
        /*
        run_time = 1000000*(dwEnd.tv_sec - start.tv_sec)
                + (end.tv_usec - start.tv_usec);
        */

        return now_time;
}
