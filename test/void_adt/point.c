/*
 ***************************************************************
 * File Name:    point.c
 * Declaration:  用户自定类型 坐标 X Y 值
 * Author:       jiaga
 * Created Time: 2014年08月03日 星期日 10时37分32秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "point.h"

static int get_number(void);

void * new_point(void)
{
        Point * point;

        point = (Point *)malloc(sizeof(Point));
        if (point != NULL) {
                printf("Please input point x: ");
                point->x = get_number();
                printf("Please input point y: ");
                point->y = get_number();
                return (void *)point;
        } else
                return NULL;
}

void show_point(void * point_item)
{
        Point * point;

        point = (Point *)point_item;
        printf("X=%d Y=%d\n", point->x, point->y);
}

static int get_number(void)
{
        int number;

        while (scanf(" %d", &number) != 1) {
                printf("Please input number: ");
                while (getchar() != '\n')
                        continue;
        }

        return number;
}
