#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0041E470(char * );                            
int func_0043E1A0(int, char *);                          
extern char D_00587D20;
extern char D_00587D30;

void func_00455DB0(char * arg0) {
    char *var_a1;
    int temp_a0;

    temp_a0 = F_(arg0, 0x48, int);
    if (temp_a0 != 0) {
        if (F_(arg0, 0x14, unsigned short) & 4) {
            var_a1 = &D_00587D20;
        } else {
            var_a1 = &D_00587D30;
        }
        func_0043E1A0(temp_a0, var_a1);
    }
    func_0041E470(arg0);
}
