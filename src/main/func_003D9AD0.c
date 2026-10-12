
#include "types.h"
/* Group_RemoveObject */
typedef struct { int pad0; int count; int* ids; } Pt2_Group;
extern int Script_ObjectToId(void*);
extern void func_003D7930(char*);
extern void func_003E2FF0(Pt2_Group*, int, int*);

#pragma opt_strength_reduction off
void Group_RemoveObject(Pt2_Group* g, void* obj) {
    int id = Script_ObjectToId(obj);
    int n = g->count;
    int i;
    for (i = 0; i < n; i++) {
        if ((void*)g->ids[i] == (void*)id) {
            int j;
            int fill[1];
            for (j = i + 1; j < n; j++) {
                int k = j - 1;
                g->ids[k] = g->ids[j];
            }
            fill[0] = -1;
            func_003E2FF0(g, n - 1, fill);
            return;
        }
    }
    func_003D7930("warning: obj to remove is not in group");
}
