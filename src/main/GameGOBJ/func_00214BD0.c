#include "types.h"
typedef struct { char pad[0xFC]; int n; int* items; char pad2[0x24]; int* f128; } E214;
extern void* D_004FFC0C;
extern void func_00176160(void*, E214*);
extern void func_001761E0(void*, int);
extern void func_00176220(void*, char*);
extern void func_001761A0(void*, int);
extern void func_00176260(void*);
extern char* Loc_LookupText(char*);
#pragma opt_strength_reduction off
void cElevatorGOBJ_ChooseFloor(E214* e) {
    void* m = D_004FFC0C;
    int i;
    func_00176160(m, e);
    func_001761E0(m, *e->f128);
    func_00176220(m, Loc_LookupText("ElevChooseFloor"));
    for (i = 0; i < e->n; i++) func_001761A0(m, e->items[i]);
    func_00176260(m);
}
