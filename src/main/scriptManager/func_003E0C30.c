#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_00128E80(int, int);                          
int **func_003E0CD0(char * , int);                   
extern char * D_00554F28;

int func_003E0C30(int d0, int arg1) {
    int i;
    int n = F_(D_00554F28, 0x4, int);
    for (i = 0; i < n; i++) {
        if (func_00128E80(arg1, **func_003E0CD0(D_00554F28, i)) == 0) {
            return *(int *)((char *)F_(D_00554F28, 0x8, int) + (i * 4));
        }
    }
    return 0;
}
