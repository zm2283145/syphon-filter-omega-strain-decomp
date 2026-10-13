#include "types.h"
typedef struct { unsigned char m0; unsigned char m1; unsigned char m2; char pad3; char f4[4]; char info[8]; unsigned char m10; } T1770;
extern int sceUsbKbInit(void* p);
extern int sceUsbKbGetInfo(void* info);
extern int sceUsbKbSetLEDStatus(int no, int s);
extern int sceUsbKbSetLEDMode(int no, int m);
extern int func_00223360(int mode, int* result);
extern int func_00223278(int i, int a, int b);
extern int func_00223FF0(int i);
extern int func_002232C0(int i, unsigned int v);
extern int func_00223310(int a, int b);
extern int func_00223F80(int a, int b);
void func_003D1770(T1770* kb)
{
    int r;
    int i = kb->m0 ? 49999 : 0;
    if (!kb->m0) {
        r = sceUsbKbInit(kb->f4);
        if (r == 0)
            kb->m0 = 1;
        else
            kb->m0 = 0;
    }
    do {
        r = sceUsbKbGetInfo(kb->info);
        func_00223360(0, &r);
    } while (!kb->m10 && ++i < 50000);
    if (kb->m10 && i < 50000) {
        r = sceUsbKbSetLEDStatus(0, 1);
        func_00223360(0, &r);
        r = sceUsbKbSetLEDMode(0, 1);
        func_00223360(0, &r);
        func_00223278(0, 30, 2);
        func_00223FF0(0);
        if (kb->m2 == 1)
            func_002232C0(0, 0);
        else
            func_002232C0(0, 1);
        func_00223310(0, 0);
        func_00223F80(0, 0);
        kb->m1 = 1;
    } else {
        kb->m1 = 0;
    }
}
