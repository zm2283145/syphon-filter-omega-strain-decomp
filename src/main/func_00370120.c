#include "types.h"
typedef struct { char pad[0x78]; int prog[30]; int cur; char pad2[0x50]; int uploads; } D2_Vu1Ctx;
extern int D_004932C0[];
extern int D_004932E0[];
extern char D_00537F80[];
extern void func_00375A30(void* dma, int n, int start, int end);
void Vu1_UploadMicrocode(D2_Vu1Ctx* c, int slot) {
    int p = c->prog[slot];
    if (p != c->cur) {
        func_00375A30(D_00537F80, 1, D_004932C0[p], D_004932E0[p]);
        c->cur = p;
    }
    c->uploads++;
}