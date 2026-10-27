/*
 * main/weapon: range (3 files, 001450F0-00145200)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001450F0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct E_00145200 { char pad[0xD8]; int xD8; char padDC[0x11C - 0xDC]; void* p11C; char pad120[0x134 - 0x120]; int x134; unsigned char x138; char p139[3]; void* p13C; };
struct I_00145200 { int a; int n; };
struct S_00145200 { int x0; I_00145200* info; char pad8[0xC]; E_00145200* arr; unsigned char x18; char pad1c[0xB8 - 0x1C]; void* pB8[7]; void* pD4; };
extern "C" void cWeaponDB_UnloadLevelSpecific(S_00145200* self); /* gsynth: defined below */
#pragma pop
extern char D_0048B2F8[];
extern char D_004FFB8C[];
typedef struct { char pad[0x10]; unsigned char loaded; char pad2[0xB]; char hog[4]; } S_HOG;
#if 0 /* merge_units */
extern void cWeaponDB_UnloadLevelSpecific(S_HOG* self);
#endif /* merge_units */
#define cWeaponDB_UnloadLevelSpecific(a0) (cWeaponDB_UnloadLevelSpecific((void *)(a0))) /* merge_units */

extern void cHogList_Close(char* a, char* b);
extern void cFileMan_Close(void* p);
void cWeaponDB_CloseWeaponsHog(S_HOG* self)
{
    if (self->loaded) {
        char buf[0x80];
        cWeaponDB_UnloadLevelSpecific(self);
        sprintf(buf, "%s\\COMMON\\WPNHOG.HOG", D_0048B2F8);
        cHogList_Close(D_004FFB8C, buf);
        cFileMan_Close(self->hog);
        self->loaded = 0;
    }
}
#undef cWeaponDB_UnloadLevelSpecific /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001450F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001450F0 */

/* merge_units: begin func_00145160 */
#pragma push /* merge_units */
extern char D_0049B210[];
extern void* cHogList_Open(char* a, char* b, int c, int d);
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(void* hog, char* name, void* arc, int z);
extern void WeaponDb_LoadShellsArchive(S_HOG* self, void* arc);
void cWeaponDB_OpenWeaponsHog(S_HOG* self)
{
    if (!self->loaded) {
        char buf[0x80];
        void* arc;
        sprintf(buf, D_0049B210, D_0048B2F8);
        arc = cHogList_Open(D_004FFB8C, buf, 0, 0);
        cFileMan_EncodeFilename_charP_cHogFileR_bool(self->hog, "DUMMY.SKL", arc, 0);
        WeaponDb_LoadShellsArchive(self, arc);
        self->loaded = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00145160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00145160 */

/* merge_units: begin func_00145200 */
#pragma push /* merge_units */
#pragma cplusplus on
struct G_00145200 { char c; };
extern "C" {
extern char D_0049B1D0[];
void cTimerDisable_ctor(G_00145200* g);
void cTimerDisable_dtor(G_00145200* g, int flag);
void cArray_charPtr_dtor_void(void* p, int flag);
void ActorModel_Release(void* p);
}



static inline void Free_00145200(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, D_0049B1D0, line); }
static inline void DelD4_00145200(void* p, int line) { G_00145200 g; cTimerDisable_ctor(&g); cArray_charPtr_dtor_void(p, -1); cMemMan_Deallocate(0, p, D_0049B1D0, line); cTimerDisable_dtor(&g, -1); }
extern "C" void cWeaponDB_UnloadLevelSpecific(S_00145200* self)
{
    int i;
    for (i = 0; i < self->info->n; i++) {
        if (self->arr[i].p13C) {
            ActorModel_Release(self->arr[i].p13C);
            Free_00145200(self->arr[i].p13C, 0x3FD);
            self->arr[i].p13C = 0;
            self->arr[i].x138 = 0;
        }
        if (self->arr[i].p11C) {
            ActorModel_Release(self->arr[i].p11C);
            Free_00145200(self->arr[i].p11C, 0x406);
            self->arr[i].p11C = 0;
        }
        self->arr[i].x134 = -1;
        self->arr[i].xD8 = -1;
    }
    { int j; for (j = 0; j < 7; j++) {
        if (self->pB8[j]) {
            ActorModel_Release(self->pB8[j]);
            Free_00145200(self->pB8[j], 0x413);
            self->pB8[j] = 0;
        }
    } }
    {
        void* p = self->pD4;
        if (p) {
            DelD4_00145200(p, 0x419);
            self->pD4 = 0;
        }
    }
    self->x18 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00145200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00145200 */
