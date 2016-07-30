/*
 ***************************************************************
 * File Name:    point.h
 * Declaration:  
 * Author:       jiaga
 * Created Time: 2014年08月03日 星期日 10时30分01秒
 ***************************************************************
 */

#ifndef __POINT_H
#define __POINT_H

typedef struct point{
        int x;
        int y;
}Point;

void * new_point(void);
void show_point(void * point_item);

#endif
