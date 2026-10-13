#include "types.h"
typedef struct { int m0; void* base; int head; int count; int size; } T5EA0;
extern volatile int D_0055C210;
extern volatile int D_0055C218;
extern volatile int D_0055C220;
extern volatile int D_0055C228;
extern char D_0055C230[];
extern char D_0055C290[];
extern char D_0055C380[];
extern T5EA0 D_0055C460;
extern volatile int D_0055C5A8;
extern volatile unsigned char D_0055C740;
extern char D_00571CF0[];
extern int func_001037A8(int, int);
extern void func_00103B60(unsigned long draw, short cx, short cy, short half);
extern void* func_00103D40(int);
extern void func_00104070(void* d, void* tag);
extern int* func_003F5EA0(T5EA0* q);
extern void func_00411860(void* db, int i, int j);
extern void func_001036B0(void* p, int);

/* sync + ei (enable interrupts) have no C equivalent */
static inline void EI3F7060(void) { asm { sync }
    asm { ei } }

#pragma opt_propagation off
int func_003F7060(void)
{
    volatile int field;
    volatile int r;
    field = (int)((*(volatile unsigned long*)0x12001000 >> 13) & 1);
    if (D_0055C210) {
        D_0055C218++;
        r = func_001037A8(1, 0);
        if (r == 0) {
            int* buf = func_003F5EA0(&D_0055C460);
            unsigned long dma;
            T5EA0* q;
            void* d;
            int idx;
            if (!buf) {
                EI3F7060();
                return 0;
            }
            if (D_0055C740) {
                field = D_0055C228;
                D_0055C228 ^= 1;
            }
            if (field & 1)
                dma = ((unsigned long)D_0055C380 & 0x0FFFFFFF) | 0x20000000;
            else {
                unsigned long a = (unsigned long)D_0055C290;
                dma = (a & 0x0FFFFFFF) | 0x20000000;
            }
            if (!D_0055C740)
                func_00103B60(dma, 0x800, 0x800, field ^ 1);
            d = func_00103D40(2);
            q = &D_0055C460;
            { int h = q->head; idx = (q->size + (h - q->count)) % q->size; }
            if (field == 0 && *buf == 2) {
                func_00411860(D_00571CF0, idx, 0);
                func_001036B0(D_0055C230, 0);
                func_001037A8(0, 0);
                func_00104070(d, (char*)buf + 0x40);
                *buf = 1;
            } else if (field == 1 && *buf == 1) {
                func_00411860(D_00571CF0, idx, 1);
                func_001036B0(D_0055C230, 1);
                func_001037A8(0, 0);
                func_00104070(d, (char*)buf + 0x26740);
                *buf = 0;
                D_0055C220 = 1;
            }
        }
        D_0055C5A8++;
    }
    EI3F7060();
    return 0;
}





