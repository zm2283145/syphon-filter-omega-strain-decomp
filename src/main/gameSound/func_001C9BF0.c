#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Global_SetReverb(int, int, int);                        
int func_003A6D10(int, int);                              
int func_003A80F0(int, int);                          
int func_003A8120(int, int *);                          
extern char * D_004FFD2C;

void func_001C9BF0(char * arg0) {
    struct { int f10; int f14; int f18; int f1C; int f20; int f24[3]; } sl;
    int var_a1;
    char * temp_v0;
    char * var_v1;

    var_a1 = 0;
    var_v1 = arg0;
    F_(arg0, 0x5490, int) = 0;
    F_(arg0, 0x5494, int) = 0;
    F_(arg0, 0x5498, int) = 0;
    F_(arg0, 0x549C, int) = 0;
    F_(arg0, 0x54A0, int) = 0;
    F_(arg0, 0x54A4, int) = 0;
    do {
        F_(var_v1, 0x94, signed char) = 0;
        F_(var_v1, 0x90, int) = 0;
        var_a1 += 8;
        F_(var_v1, 0x244, signed char) = 0;
        F_(var_v1, 0x240, int) = 0;
        F_(var_v1, 0x3F4, signed char) = 0;
        F_(var_v1, 0x3F0, int) = 0;
        F_(var_v1, 0x5A4, signed char) = 0;
        F_(var_v1, 0x5A0, int) = 0;
        F_(var_v1, 0x754, signed char) = 0;
        F_(var_v1, 0x750, int) = 0;
        F_(var_v1, 0x904, signed char) = 0;
        F_(var_v1, 0x900, int) = 0;
        F_(var_v1, 0xAB4, signed char) = 0;
        F_(var_v1, 0xAB0, int) = 0;
        F_(var_v1, 0xC64, signed char) = 0;
        F_(var_v1, 0xC60, int) = 0;
        var_v1 += 0xD80;
    } while (var_a1 < 0x2A);
    temp_v0 = (char *)(var_a1 * 0x1B0) + (int)(arg0);
    F_(temp_v0, 0x94, signed char) = 0;
    F_(temp_v0, 0x90, int) = 0;
    F_(temp_v0, 0x244, signed char) = 0;
    F_(temp_v0, 0x240, int) = 0;
    func_003A80F0(F_(D_004FFD2C, 0x14, int), var_a1);
    func_003A6D10(1, 4);
    Global_SetReverb(1, 0xB21, 0xB21);
    sl.f10 = 2;
    sl.f24[0] = 0;
    sl.f14 = -0xD;
    sl.f1C = 0x8000;
    sl.f18 = 0x8CCC;
    sl.f20 = 0x10000;
    func_003A8120(0, &sl.f10);
}
