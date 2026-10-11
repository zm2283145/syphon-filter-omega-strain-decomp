#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
typedef __int128 Q128;
#pragma mpwc_relax on
int Node_GetTranslation(Q128 *, char * );              
char * func_0015DDB0(int);                           

void func_00160C40(char * arg0, int arg1) {
    Q128 sp30;
    int temp_a0;
    int temp_v1;
    char * temp_v0;

    F_(arg0, 0x4C, int) = arg1;
    temp_a0 = F_(arg0, 0x4C, int);
    if (temp_a0 >= 0) {
        temp_v0 = func_0015DDB0(temp_a0);
        Node_GetTranslation(&sp30, temp_v0);
        { Q128* d = &F_(arg0, 0x20, Q128); V4Copy(d, &sp30); }
        temp_v1 = F_(temp_v0, 0x7C, int);
        if (temp_v1 >= 0) {
            F_(arg0, 0x5C, int) = temp_v1;
        }
        F_(arg0, 0x60, unsigned char) = (unsigned char) ((F_(arg0, 0x60, unsigned char) & ~2) | (((F_(temp_v0, 0x64, int) & 8) != 0) * 2));
    }
}
