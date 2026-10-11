#include "types.h"
typedef struct { char pad[0x84]; int bits[1]; } T333B10;
extern __int128 func_003FDA40(int id);
extern int Objective_Find(__int128 key);
int AgentData_IsObjectiveComplete(T333B10* t, int id) {
    int i = Objective_Find(func_003FDA40(id));
    int r;
    if (i > -1) r = ((t->bits[i / 32] >> (i & 31)) & 1) != 0;
    else { r = 0; asm { .set reorder } }
    return r;
}