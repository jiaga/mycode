/*
 ***************************************************************
 * File Name:    pet.h
 * Declaration:  用户自定的数据结构类型及其输入输出操作。
 * Author:       jiaga
 * Created Time: 2014年08月03日 星期日 10时20分11秒
 ***************************************************************
 */

#ifndef __PET_H
#define __PET_H

#define LEN 20

typedef struct pet {
        char petname[LEN];
        char petkind[LEN];
}Pet;

/* 
 * 获取类该型数据输入，
 * 强制转换数据的指针为(void *)作为返回值 
 * 若申请存储空间失败则返回NULL
 */
void * new_pet(void);

/* 
 * 输出该类型数据 
 * 从参数获取(void *)指针并做强制转换后使用
 */
void show_pet(void * pet_item);

char *get_string(char *str);

#endif

