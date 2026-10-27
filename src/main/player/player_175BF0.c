/*
 * main/player: range (3 files, 00175BF0-00175CD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00175BF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* inv; } Hum_5BF0;
typedef struct { char pad[0x30]; Hum_5BF0* hum; } Obj_5BF0;
typedef struct { Obj_5BF0* obj; int id; } Arg_5BF0;
typedef struct { char pad[0x13C]; int ok; } Wdb_5BF0;
Wdb_5BF0* cWeaponDB_GetEntry(int, int);
int cWeapon_Add(void*, int, int, int, int, int);
extern int g_HumanActorClassKey;
extern int g_WeaponDatabase;
/* script: give the player a weapon when the weapon database entry is valid;
 * the id is staged through a stack slot (volatile) */
#pragma push
int Script_cPlayer_AddWeapon(Arg_5BF0* args)
{
    volatile int w[1];
    Hum_5BF0* h;
    int id;
    w[0] = args->id;
    h = args->obj->hum;
    id = w[0];
    if (h && h->classKey == g_HumanActorClassKey && cWeaponDB_GetEntry(g_WeaponDatabase, id)->ok)
        cWeapon_Add(h->inv, id, 1, 1, 0, 0);
    return 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175BF0 */

/* merge_units: begin func_00175C80 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char g_HumanActorClassKey[];
#endif /* merge_units */
#define g_HumanActorClassKey ((char*)&g_HumanActorClassKey) /* merge_units */

extern int cWeapon_Select(int, int);

int Script_cPlayer_ArmWeapon(int a0) {
    int loc[1];
    int a1, v0, v1;
    int cond;

    v0 = *(int*)((char*)a0 + 4);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)a0;
    a0 = *(int*)((char*)v0 + 48);
    cond = a0 == 0;
    a1 = *(int*)(char*)loc;
    if (cond) goto L00175CC0;
    v1 = *(int*)((char*)a0 + 76);
    v0 = *(int*)(char*)g_HumanActorClassKey;
    cond = v1 != v0;
    if (cond) goto L00175CC0;
    a0 = *(int*)((char*)a0 + 13604);
    v0 = cWeapon_Select(a0, a1);
L00175CC0:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
#undef g_HumanActorClassKey /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175C80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175C80 */

/* merge_units: begin func_00175CD0 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef struct { int a0; int a4; int id; int ac; } Slot_P;
typedef struct { Slot_P s[8]; char pad[4]; unsigned char cur; } Inv_P;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; Inv_P* inv; } Plr_P;
typedef struct { char pad[0x30]; Plr_P* ctl; } GObj_P;
typedef struct { char pad[0x6A4]; Plr_P* player; } Game_P;
extern Game_P* g_Hud;
static inline Plr_P* AsPlayer(GObj_P* o) { Plr_P* p = o->ctl; if (p && p->kind == g_HumanActorClassKey) return p; return 0; }
static inline int ActiveId(Inv_P* inv) { unsigned char c = inv->cur; if (c != 6) return inv->s[c].id; return -1; }
static inline int GetW(GObj_P* o)
{
    int r = -1;
    Plr_P* p = o->ctl;
    if (p && p->kind == g_HumanActorClassKey)
        r = ActiveId(p->inv);
    return r;
}
int Script_cPlayer_GetActiveWeapon(GObj_P** args)
{
    int r[1];
    r[0] = GetW(args[0]);
    return *(int*)r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175CD0 */
