#pragma cplusplus on
#include "types.h"

struct Pair38C820 {
    __int128 a;
    __int128 b;
};

struct Self38C820 {
    char pad[0x80];
    Pair38C820 pairs[(0x2340 - 0x80) / 0x20];
    void* x2340[0x20];
    unsigned short x23C0;
};

extern "C" {
extern char D_0055DDA0[];
int func_004027E0(char* cache, __int128 name);
void func_00403940(char* cache, int slot);
int MeshCache_FindSlot(char* cache, __int128 name);
void func_00404D90(char* cache, int slot);
void func_0036CA70(void* p);
}

extern "C" void func_0038C820(Self38C820* self)
{
    int i;
    for (i = 0; i < self->x23C0; i++) {
        int s = MeshCache_FindSlot(D_0055DDA0, self->pairs[i].a);
        if (s != -1) {
            func_00404D90(D_0055DDA0, s);
        }
        if (self->x2340[i]) {
            func_0036CA70(self->x2340[i]);
            self->x2340[i] = 0;
        }
    }
    for (i = 0; i < self->x23C0; i++) {
        int s = func_004027E0(D_0055DDA0, self->pairs[i].b);
        if (s != -1) {
            func_00403940(D_0055DDA0, s);
        }
    }
}
