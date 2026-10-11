#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0010CF60(int *);                           
int func_0010CF80(int, int);                            
int func_0010CFF0(int, int);                            
extern char D_004E9B70;
extern signed char D_00533880;
extern int D_00572510;
extern int D_00572520;
extern unsigned char D_00572528;
extern char D_00572540;

int func_00429380(int arg0) {
    struct { int f10; int f14; char * f18; int f1C; char * f20; int f24[4]; int f34[2]; int f3C; } sl;

    if (D_00572528 == 0) {
        sl.f14 = arg0;
        sl.f10 = 0x10;
        sl.f18 = &D_00572540;
        sl.f34[0] = 0;
        sl.f1C = 0x10000;
        sl.f3C = 0;
        sl.f20 = &D_004E9B70;
        D_00572520 = D_00572510;
        sl.f24[0] = 5;
        func_0010CFF0(D_00572510, 0xA);
        D_00572510 = func_0010CF60(&sl.f10);
        func_0010CF80(D_00572510, 0);
        D_00533880 = 1;
        D_00572528 = 1;
    }
    return 1;
}
