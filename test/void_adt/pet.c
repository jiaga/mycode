/*
 ***************************************************************
 * File Name:    pet.c
 * Declaration:  用户自定类型 宠物名及种类名
 * Author:       jiaga
 * Created Time: 2014年08月03日 星期日 10时19分50秒
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pet.h" 

char *get_string(char *str);

void * new_pet(void)
{
        Pet *pet;

        pet = (Pet *)malloc(sizeof(Pet));
        if (pet != NULL) {
                printf("Please input pet's name: ");
                get_string(pet->petname);
                printf("Please input pet's kind: ");
                get_string(pet->petkind);
                return (void *)pet;
        } else
                return NULL;
}

void show_pet(void * pet_item)
{
        Pet *pet;

        pet = (Pet *)pet_item;
        printf("name: %-20s  kind: %-20s\n", pet->petname, pet->petkind);
}

/*
Pet *fine_pet(char *pet_name)
{
        Pet pet;

        strcpy(pet.petname, pet_name);
        return (Pet *)find_node(pets, (void *)pet, cmp_pet_name);
}
*/

Pet *cmp_pet_name(void *vp_item, void *key)
{
        Pet * pet_in_list;
        Pet * pet_key;

        pet_in_list = (Pet *)vp_item;
        pet_key = (Pet *)key;
        
        if (strncmp(pet_in_list->petname, pet_key->petname, LEN))
                return pet_in_list;
        else
                return NULL;
}

char *get_string(char *str)
{
        char *find;

        if (fgets(str, LEN, stdin) != NULL) {
                find = strchr(str, '\n');
                if (find)
                        *find = '\0';
                return str;
        } else {
                return NULL;
        }
}
