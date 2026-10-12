#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Pair391020 {
    __int128 a;
    __int128 b;
};

struct App391020 {
    char pad[0x40];
    Pair391020 pairs[1];
};

struct Self391020 {
    char pad[0x20];
    char x20[0x20];
    App391020 app;
    char padX[0x22C0 - 0x40 - sizeof(App391020)];
    short x22C0[0x20];
    short x2300[0x60];
    short x23C0;
    char pad23C2[0x2C14 - 0x23C2];
    App391020* x2C14;
};

extern "C" {
extern char D_0055DDA0[];
extern char D_005711B0[];
extern char D_004BC310[];

void func_00390940(Self391020* self);
void Appearance_RemoveBlankPairs(App391020* app);
int Appearance_GetPairCount(App391020* app);
void Appearance_RequestHardMesh(App391020* app, int hard, char* out);
void TexCache_LoadPartTexture(char* cache, __int128 name, char* tex, short* a, short* b);
int func_004027E0(char* cache, __int128 name);
void func_00403940(char* cache, int slot);
int MeshCache_FindSlot(char* cache, __int128 name);
void func_00404D90(char* cache, int slot);
void Mem_Free(int pool, void* p, char* file, int line);
void Appearance_ReorderParts(Self391020* self);
void ActorModel_Setup(Self391020* self, int flag);
}

extern "C" void func_00391020(Self391020* self)
{
    int i;
    int j;
    int n;

    func_00390940(self);
    Appearance_RemoveBlankPairs(&self->app);
    self->x23C0 = Appearance_GetPairCount(&self->app);
    Appearance_RequestHardMesh(&self->app, 1, self->x20);
    for (i = 0; self->app.pairs[i].b; i++) {
        TexCache_LoadPartTexture(D_0055DDA0, self->app.pairs[i].b, D_005711B0, &self->x22C0[i], &self->x2300[i]);
    }
    self->x22C0[i] = 0;
    n = Appearance_GetPairCount(self->x2C14);
    for (j = 0; j <= n; j++) {
        int s = func_004027E0(D_0055DDA0, self->x2C14->pairs[j].b);
        if (s != -1) {
            func_00403940(D_0055DDA0, s);
        }
    }
    for (i = 0; i < n; i++) {
        int s = MeshCache_FindSlot(D_0055DDA0, self->x2C14->pairs[i].a);
        if (s != -1) {
            func_00404D90(D_0055DDA0, s);
        }
    }
    {
        App391020* p = self->x2C14;
        AllocGuard g;
        Mem_Free(0, p, D_004BC310, 0x2DA);
    }
    self->x2C14 = 0;
    Appearance_ReorderParts(self);
    ActorModel_Setup(self, 1);
}
