#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00443E70();                                
int *func_0044F290(char * , int);                    
int memset(char * , int, int);                             
extern int D_00497848;

typedef struct { signed char a; signed char b; } P2_0CF0;
typedef struct { P2_0CF0 x[0x60]; } P192_0CF0;
static inline int* Find_0CF0(char* a, int key) {
    int n = F_(a, 0x100, int);
    int i;
    for (i = 0; i < n; i++) {
        int* p = func_0044F290(a + 0xFC, i);
        if (key == *p) return p;
    }
    return NULL;
}
int func_00450CF0(char * arg0, int arg1, char * arg2) {
    signed char temp_v0_2;
    char *var_a2;
    char * var_a1;
    int var_a0;
    int *var_s0_2;
    var_s0_2 = Find_0CF0(arg0, arg1);    if ((var_s0_2 != NULL) && (F_(var_s0_2, 0x39, unsigned char) != 0) && ((func_00443E70() - F_(var_s0_2, 0x3C, int)) < D_00497848)) {
        var_a2 = (char *)var_s0_2 + 0x68;
        var_a1 = arg2 + 0x28;
        var_a0 = 0x60;
        F_(arg2, 0x0, unsigned char) = F_(var_s0_2, 0x40, unsigned char);
        F_(arg2, 0x1, unsigned char) = F_(var_s0_2, 0x41, unsigned char);
        F_(arg2, 0x2, unsigned char) = F_(var_s0_2, 0x42, unsigned char);
        F_(arg2, 0x3, unsigned char) = F_(var_s0_2, 0x43, unsigned char);
        F_(arg2, 0x4, unsigned short) = F_(var_s0_2, 0x44, unsigned short);
        F_(arg2, 0x6, unsigned short) = F_(var_s0_2, 0x46, unsigned short);
        F_(arg2, 0x8, unsigned short) = F_(var_s0_2, 0x48, unsigned short);
        F_(arg2, 0xA, unsigned short) = F_(var_s0_2, 0x4A, unsigned short);
        F_(arg2, 0xC, unsigned short) = F_(var_s0_2, 0x4C, unsigned short);
        F_(arg2, 0xE, unsigned short) = F_(var_s0_2, 0x4E, unsigned short);
        F_(arg2, 0x10, int) = F_(var_s0_2, 0x50, int);
        F_(arg2, 0x14, int) = F_(var_s0_2, 0x54, int);
        F_(arg2, 0x18, int) = F_(var_s0_2, 0x58, int);
        F_(arg2, 0x1C, int) = F_(var_s0_2, 0x5C, int);
        F_(arg2, 0x20, int) = F_(var_s0_2, 0x60, int);
        F_(arg2, 0x24, int) = F_(var_s0_2, 0x64, int);
        *(P192_0CF0*)var_a1 = *(P192_0CF0*)var_a2;
        F_(arg2, 0xE8, int) = F_(var_s0_2, 0x128, int);
        F_(arg2, 0xEC, int) = F_(var_s0_2, 0x12C, int);
        F_(arg2, 0xF0, int) = F_(var_s0_2, 0x130, int);
        F_(arg2, 0xF4, int) = F_(var_s0_2, 0x134, int);
        F_(arg2, 0xF8, unsigned char) = F_(var_s0_2, 0x138, unsigned char);
        F_(arg2, 0xF9, unsigned char) = F_(var_s0_2, 0x139, unsigned char);
        return 1;
    }
    memset(arg2, 0, 0xFC);
    return 0;
}
