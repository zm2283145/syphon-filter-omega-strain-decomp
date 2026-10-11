#include "types.h"
typedef struct { unsigned char m0; unsigned char m1; char pad[0x8E]; char data[8]; int m98; } T1660;
extern int sceUsbKbRead(unsigned int no, void* data);
extern int func_00223360(int mode, int* result);
extern void func_003D1770(T1660* kb);
int func_003D1660(T1660* kb, int flag)
{
    int v;
    if (kb->m1) {
        int r = sceUsbKbRead(0, kb->data);
        func_00223360(0, &r);
        if (r) {
            kb->m1 = 0;
            if (flag)
                func_003D1770(kb);
        }
    } else if (flag) {
        func_003D1770(kb);
    }
    v = kb->m1 ? kb->m98 : 0;
    return v != 0;
}