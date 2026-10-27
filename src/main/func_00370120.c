#include "types.h"
typedef struct { char pad[0x78]; int prog[30]; int cur; char pad2[0x50]; int uploads; } D2_Vu1Ctx;
extern char D_00477AF0[];
extern char D_0047BA70[];
extern char D_0047DB00[];
extern char D_0047DBA0[];
extern char D_00481030[];
extern char D_00482110[];
extern char D_00482BC0[];
extern char D_00485E50[];
void * const D_004932C0[8] = { (void*)D_00477AF0, (void*)D_0047BA70, (void*)D_0047DBA0, (void*)D_00482110, (void*)D_00482BC0, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004932E0[8] = { (void*)D_0047BA70, (void*)D_0047DB00, (void*)D_00481030, (void*)D_00482BC0, (void*)D_00485E50, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char D_00537F80[];
extern void cDmaMan_InsertChain(void* dma, int n, int start, int end);
void cVU1Man_RequestProg(D2_Vu1Ctx* c, int slot) {
    int p = c->prog[slot];
    if (p != c->cur) {
        cDmaMan_InsertChain(D_00537F80, 1, ((int*)D_004932C0)[p], ((int*)D_004932E0)[p]);
        c->cur = p;
    }
    c->uploads++;
}