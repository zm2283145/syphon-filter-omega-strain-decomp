#include "types.h"
typedef struct { char pad[8]; char* data; unsigned int len; unsigned int pos; } Buf_8240;
int func_0042B1A0(int);
int func_0042BA00(int, char*);
int NetGame_InitLocalSlot(int*, int);
extern int D_00494178;
extern int D_00497550;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_00582B88;
extern int D_00582D30;
void func_00438240(Buf_8240* b)
{
    int t0 = func_0042B1A0(1);
    if (D_00582B88 && b && b->len) {
        unsigned int n;
        char* p = b->data;
        int a = D_00497550;
        n = 0;
        if (a == -1) a = D_005721A8;
        if (D_005721C8 && D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a);
        if (n < b->len) {
            do {
                int k = func_0042BA00(1, p + n);
                n += k;
                if (!k) break;
            } while (n < b->len);
        }
        b->pos = n;
    }
    D_00582D30 = func_0042B1A0(1) - t0;
}