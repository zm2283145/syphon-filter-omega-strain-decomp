/*
 * main/player: range (4 files, 00175D60-00175E20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00175D60 */
#pragma push /* merge_units */
extern char D_004FFC2C[];
extern int Script_ValueToObj(int);
extern void func_0045BEB0(int, int);

int Script_cPlayer_SetMenuReceiver(int a0) {
    int a1, v0, v1;
    int cond;

    a0 = *(int*)((char*)a0 + 4);
    v0 = Script_ValueToObj(a0);
    v1 = *(int*)(char*)D_004FFC2C;
    a0 = *(int*)((char*)v1 + 1700);
    cond = a0 == 0;
    a1 = v0;
    if (cond) goto L00175D90;
    func_0045BEB0(a0, a1);
L00175D90:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175D60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175D60 */

/* merge_units: begin func_00175DA0 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef struct { char pad[0x6A4]; void* player; } Game_P;
#if 0 /* merge_units */
extern Game_P* D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(Game_P **)&D_004FFC2C) /* merge_units */

extern void cPlayer_SetMenuTitle(void* p, int v);
static inline void Call_00175DA0(int v)
{
    void* p = D_004FFC2C->player;
    if (p)
        cPlayer_SetMenuTitle(p, v);
}
int Script_cPlayer_SetMenuTitle(int* args)
{
    int v[1];
    v[0] = args[1];
    Call_00175DA0(*(int*)v);
    return 0;
}
#undef D_004FFC2C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175DA0 */

/* merge_units: begin func_00175DE0 */
#pragma push /* merge_units */
#pragma global_optimizer off

#if 0 /* merge_units */
extern Game_P* D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(Game_P **)&D_004FFC2C) /* merge_units */

extern void cPlayer_AddMenuChoice(void* p, int v);
static inline void Call_00175DE0(int v)
{
    void* p = D_004FFC2C->player;
    if (p)
        cPlayer_AddMenuChoice(p, v);
}
int Script_cPlayer_AddMenuChoice(int* args)
{
    int v[1];
    v[0] = args[1];
    Call_00175DE0(*(int*)v);
    return 0;
}
#undef D_004FFC2C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175DE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175DE0 */

/* merge_units: begin func_00175E20 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef struct { int a0; int a4; int id; int ac; } Slot_P;
typedef struct { Slot_P s[8]; char pad[4]; unsigned char cur; } Inv_P;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; Inv_P* inv; } Plr_P;
typedef struct { char pad[0x30]; Plr_P* ctl; } GObj_P;
typedef struct { char pad[0x6A4]; Plr_P* player; } Game_P_00175E20;
#if 0 /* merge_units */
extern Game_P_00175E20* D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(Game_P_00175E20 **)&D_004FFC2C) /* merge_units */

extern int D_0049D010;
static inline Plr_P* AsPlayer(GObj_P* o) { Plr_P* p = o->ctl; return (p && p->kind == D_0049D010) ? p : 0; }
extern void cPlayer_LaunchChooseMenu(Plr_P* pl, Plr_P* who);
int Script_cPlayer_LaunchChooseMenu(GObj_P** args)
{
    GObj_P* o = args[0];
    Plr_P* pl = D_004FFC2C->player;
    if (pl)
        cPlayer_LaunchChooseMenu(pl, AsPlayer(o));
    return 0;
}
#undef D_004FFC2C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175E20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175E20 */
