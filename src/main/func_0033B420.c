#include "types.h"
typedef struct { char pad[0x14]; } G4_E14;
typedef struct { int x; int size; G4_E14* data; } G4_Vec;
extern void cAgentData_tAchievement_dtor(G4_E14* e, int f);
void std_vector_deleter_tAchievement_clear(G4_Vec* v)
{
    G4_E14* b = v->data;
    G4_E14* e = b + v->size;
    while (b < e) {
        --e;
        cAgentData_tAchievement_dtor(e, -1);
    }
    v->size = 0;
}