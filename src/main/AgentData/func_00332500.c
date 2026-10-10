#include "types.h"
typedef struct { int cap; int count; int* data; } PtrVec2500;
typedef struct { char pad0[0xB58]; char awards[4]; int numAwards; char pad1[0xB68 - 0xB60]; unsigned char reduced; char pad2[3]; int best; } AgentData2500;
extern int AgentData_TotalPoints(AgentData2500* a);
extern void func_003301E0(PtrVec2500* v, int pts);
extern int* func_002888B0(void* vec, int i);
extern void PtrVector_Resize(PtrVec2500* v, int n, int* fill);
#pragma opt_strength_reduction off
void AgentData_FilterAwards(AgentData2500* a, PtrVec2500* list) {
    int i;
    func_003301E0(list, AgentData_TotalPoints(a));
    for (i = 0; i < a->numAwards; i++) {
        int j;
        int last;
        int* key;
        int fill;
        key = func_002888B0(a->awards, i);
        last = list->count - 1;
        for (j = 0; last >= j; j++) {
            int* slot = &list->data[j];
            if (*slot == *key) {
                *slot = list->data[last];
                last--;
            }
        }
        fill = 0;
        PtrVector_Resize(list, last + 1, &fill);
    }
    {
        int n = list->count;
        if (a->best < 0) {
            a->best = n;
        } else if (n < a->best) {
            a->reduced = 1;
            a->best = n;
        }
    }
}