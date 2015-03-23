/*
 ***************************************************************
 * File Name:    mylist.c
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年02月07日 星期六 11时29分35秒
 ***************************************************************
 */

struct item {
        void * addr;
        size_t len;
};

struct l_node {
        struct item item;
        struct l_node * next;
        struct l_node * prev;
};

typedef struct l_node * List;

void init_list(List *list){
        *list = NULL;
}
