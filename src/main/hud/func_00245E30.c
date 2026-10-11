#include "types.h"
typedef struct { int cap; int count; int* data; } List245E;
typedef struct { char pad[0xD4]; List245E* list; } Mgr245E;
typedef struct { char pad[0x54]; int* ctx; char pad2[0x24]; char m7C[4]; } Obj245E;
extern Mgr245E* D_004FFD30;
extern int func_00260D50(int ctx, int id);
extern void func_00245EE0(void* set, int* h);
extern void func_003E8DE0(int h, int v);
#pragma opt_strength_reduction off
void func_00245E30(Obj245E* s) {
    int ctx = *s->ctx;
    List245E* list = D_004FFD30->list;
    int i;
    for (i = 0; i < list->count; i++) {
        int h[1];
        h[0] = func_00260D50(ctx, list->data[i]);
        func_00245EE0(s->m7C, h);
        func_003E8DE0(h[0], 0);
    }
}
#pragma opt_strength_reduction reset


