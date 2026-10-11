#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_003836B0(int, int, char *, int);                  
extern char *D_004FFD30;
extern char D_0055C9F0;

void func_002593B0(char * arg0) {
    int var_a0;
    unsigned char temp_a1;

    var_a0 = F_(arg0, 0x60, int);
    if (var_a0 == 0) {
        temp_a1 = F_(arg0, 0x64, unsigned char);
        if (temp_a1 != 7) {
            var_a0 = ((int *)(D_004FFD30 + 0xB8))[temp_a1];
        }
    }
    if (var_a0 != 0) {
        func_003836B0(var_a0, F_(arg0, 0x38, int), &D_0055C9F0, 1);
    }
}
