#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00134E00(char * , int);                         
int func_0017EB50(char * , int);                         
int func_0017EC70(char * , int);                         
int func_0017ED20(char * , int);                         
int func_0017EDD0(char * , int);                         
int func_0017EE80(char * , int);                         
int func_0017EEE0(char * , int);                         
int func_0017EF30(char * , int);                         
int func_0017F080(char **, int);                           
int operator_delete(char **);                            
extern char D_004DA580;
extern char D_004DCDE0;

char **func_0027D4D0(char **arg0, long long arg1) {
    if (arg0 != NULL) {
        *arg0 = &D_004DCDE0;
        if (arg0 != NULL) {
            *arg0 = &D_004DA580;
            func_00134E00((char *)arg0 + 0xC70, -1);
            func_0017EB50((char *)arg0 + 0xB20, -1);
            func_0017EC70((char *)arg0 + 0xA90, -1);
            func_0017ED20((char *)arg0 + 0x9D0, -1);
            func_0017ED20((char *)arg0 + 0x910, -1);
            func_0017ED20((char *)arg0 + 0x850, -1);
            func_0017EDD0((char *)arg0 + 0x780, -1);
            func_0017ED20((char *)arg0 + 0x6C0, -1);
            func_0017ED20((char *)arg0 + 0x600, -1);
            func_0017EDD0((char *)arg0 + 0x530, -1);
            func_0017EDD0((char *)arg0 + 0x460, -1);
            func_0017ED20((char *)arg0 + 0x3A0, -1);
            func_0017ED20((char *)arg0 + 0x2E0, -1);
            func_0017EDD0((char *)arg0 + 0x210, -1);
            func_0017EEE0((char *)arg0 + 0x1C0, -1);
            func_0017EE80((char *)arg0 + 0x170, -1);
            func_0017EEE0((char *)arg0 + 0x130, -1);
            func_0017EF30((char *)arg0 + 0x70, -1);
            func_0017F080(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
