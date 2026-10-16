#pragma cplusplus on
#include "types.h"
struct Ent2BD { char pad[0x40A]; short id; };
struct Sub2BD { char pad[0x2410]; Ent2BD* ents[10]; };
struct Mgr2BD { char pad[0x60]; Sub2BD sub; Sub2BD* S() { return &sub; } };
struct Self2BD { char pad[0x4C]; Mgr2BD* mgr; char pad50[0x920 - 0x50]; int count; int ids[1]; };
extern "C" void* D_004FFD30;
extern "C" void WeaponDb_Unload(void*, int, int);
extern "C" void func_002BDC10(Self2BD* self)
{
    int i;
    for (i = 0; i < self->count; i++) {
        int found = 0;
        int j;
        for (j = 0; j < 10; j++) {
            if (self->mgr->S()->ents[j] && self->ids[i] == self->mgr->S()->ents[j]->id) {
                found = 1;
                break;
            }
        }
        if (!found) WeaponDb_Unload(D_004FFD30, self->ids[i], 1);
    }
    self->count = 0;
}


