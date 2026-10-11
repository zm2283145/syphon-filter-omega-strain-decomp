#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_003C9B20(int *, int);                        
int func_003C9B30(char *);                             
char * func_003C9B40();                           
extern char D_005435C0;
extern char D_005435C4;

int func_003C9B50(int *arg0) {
    int sp4C;
    int var_s1;
    char * temp_v0;
    char * var_s0;

    var_s1 = 0;
    var_s0 = (char *)(F_(func_003C9B40(&D_005435C4), 0x4, int));
    func_003C9B20(&sp4C, func_003C9B30(&D_005435C0));
    if ((int)(var_s0) != (int)(sp4C)) {
        do {
            temp_v0 = (char *)(F_(var_s0, 0xC, int));
            if ((temp_v0 != NULL) && (*(int *)F_(temp_v0, 0x4, int) == *arg0)) {
                var_s1 += 1;
            }
            var_s0 = (char *)(F_(var_s0, 0x4, int));
            func_003C9B20(&sp4C, func_003C9B30(&D_005435C0));
        } while ((int)(var_s0) != (int)(sp4C));
    }
    return var_s1;
}
