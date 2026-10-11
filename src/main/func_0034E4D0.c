#include "types.h"
typedef struct { char* key; int id; int pad[7]; } R34E4D0;
typedef struct { int a0; int count; R34E4D0* data; } T34E4D0;
typedef struct { int pad0; int id; } C34E4D0;
typedef struct { char pad[0xB50]; C34E4D0* cur; } A34E4D0;
typedef struct { char pad[0x48]; int a48; } S34E4D0;
extern char D_004FFB50[];
extern T34E4D0 D_00532B50;
extern A34E4D0* Agent_GetSelected(void* list, int idx);
extern char* Loc_LookupText(char* key);
extern void func_00421290(int list, char* name, int idx, int state);
#pragma opt_strength_reduction off
void func_0034E4D0(S34E4D0* o)
{
    A34E4D0* ag = Agent_GetSelected(D_004FFB50, -1);
    T34E4D0* t = &D_00532B50;
    C34E4D0* cur = ag->cur;
    int i;
    for (i = 0; i < t->count; i++) {
        R34E4D0* r = &t->data[i];
        char* txt = Loc_LookupText(r->key);
        int sel = 0;
        if (cur->id != r->id) sel = 1;
        func_00421290(o->a48, txt, i, sel);
    }
}
#pragma opt_strength_reduction reset

