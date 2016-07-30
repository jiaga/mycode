/*
 ***************************************************************
 * File Name:    list.h
 * Declaration:  
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2015年03月20日 星期五 21时12分05秒
 ***************************************************************
 */


#define _STRING(x) #x
#define PR(format,value) printf(format"\n", value)

#define INIT_LIST(type) init_##type_list(void) { *list = NULL}


void INIT_LIST(int)

int main(void)
{
        char * str = _STRING(hello);
        char * s = _STRING(jiaga);

        PR("%s", str);
        PR("%s", s);

        
        return 0;
}
