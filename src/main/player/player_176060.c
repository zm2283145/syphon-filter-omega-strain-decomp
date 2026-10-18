/*
 * main/player: range (8 files, 00176060-001762C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00176060 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
char * WeaponDb_Get(int);
int WeaponInv_RemoveSlot(char * , int, int, int, int);
int WeaponInv_SlotOfItem(int);
extern int D_0049D010;
extern int D_004FFD30;

void func_00176060(char * arg0, int arg1) {
    int temp_a2;
    int temp_v0;
    int var_a1;
    char * temp_a0;
    char * temp_s1;

    temp_s1 = (char *)(F_(arg0, 0x30, int));
    if ((temp_s1 != NULL) && (F_(temp_s1, 0x4C, int) == D_0049D010) && (F_(WeaponDb_Get(D_004FFD30), 0x13C, int) != 0)) {
        temp_v0 = WeaponInv_SlotOfItem(arg1);
        temp_a0 = (char *)(F_(temp_s1, 0x3524, int));
        temp_a2 = temp_v0 & 0xFF;
        var_a1 = temp_v0;
        if (arg1 == F_((char *)(temp_a2 * 0x10) + (int)temp_a0, 0x8, int)) {
            if ((temp_a2 == 0) && (arg1 == F_(temp_a0, 0x18, int))) {
                var_a1 = 1;
            }
            WeaponInv_RemoveSlot(temp_a0, var_a1, 1, 0, 0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176060 */

/* merge_units: begin func_00176110 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef struct { int a0; int a4; int id; int ac; } Slot_P;
typedef struct { Slot_P s[8]; char pad[4]; unsigned char cur; } Inv_P;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; Inv_P* inv; } Plr_P;
typedef struct { char pad[0x30]; Plr_P* ctl; } GObj_P;
typedef struct { char pad[0x6A4]; Plr_P* player; } Game_P;
extern Game_P* D_004FFC2C;
static inline Plr_P* AsPlayer(GObj_P* o) { Plr_P* p = o->ctl; if (p && p->kind == D_0049D010) return p; return 0; }
static inline int ActiveId(Inv_P* inv) { unsigned char c = inv->cur; if (c != 6) return inv->s[c].id; return -1; }
int Player_GetHeldItem(GObj_P* o)
{
    int r = -1;
    Plr_P* p = o->ctl;
    if (p && p->kind == D_0049D010)
        r = ActiveId(p->inv);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176110 */

/* merge_units: begin func_00176160 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_004FFC2C[];
#endif /* merge_units */
#define D_004FFC2C ((char*)&D_004FFC2C) /* merge_units */

extern void GuiGameScreen_SetMenuReceiver(int, int);

void func_00176160(void) {
    int a0, a1, v1;
    int cond;

    v1 = *(int*)(char*)D_004FFC2C;
    a0 = *(int*)((char*)v1 + 1700);
    cond = a0 == 0;
    if (cond) goto L00176188;
    GuiGameScreen_SetMenuReceiver(a0, a1);
L00176188:;
    goto ret;
ret:;
}
#undef D_004FFC2C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176160 */

/* merge_units: begin func_001761A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x6A4]; void* player; } Game_P_001761A0;
#if 0 /* merge_units */
extern Game_P_001761A0* D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(Game_P_001761A0 **)&D_004FFC2C) /* merge_units */

extern void cPlayer_AddMenuChoice(void* p, int v);
void func_001761A0(int unused, int v)
{
    void* p = D_004FFC2C->player;
    if (p)
        cPlayer_AddMenuChoice(p, v);
}
#undef D_004FFC2C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001761A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001761A0 */

/* merge_units: begin func_001761E0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_004FFC2C[];
#endif /* merge_units */
#define D_004FFC2C ((char*)&D_004FFC2C) /* merge_units */

extern void GuiGameScreen_SelectMenuRow(int, int);

void func_001761E0(void) {
    int a0, a1, v1;
    int cond;

    v1 = *(int*)(char*)D_004FFC2C;
    a0 = *(int*)((char*)v1 + 1700);
    cond = a0 == 0;
    if (cond) goto L00176208;
    GuiGameScreen_SelectMenuRow(a0, a1);
L00176208:;
    goto ret;
ret:;
}
#undef D_004FFC2C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001761E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001761E0 */

/* merge_units: begin func_00176220 */
#pragma push /* merge_units */
typedef struct { char pad[0x6A4]; void* player; } Game_P_00176220;
#if 0 /* merge_units */
extern Game_P_00176220* D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(Game_P_00176220 **)&D_004FFC2C) /* merge_units */

extern void cPlayer_SetMenuTitle(void* p, int v);
void func_00176220(int unused, int v)
{
    void* p = D_004FFC2C->player;
    if (p)
        cPlayer_SetMenuTitle(p, v);
}
#undef D_004FFC2C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176220(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176220 */

/* merge_units: begin func_00176260 */
#pragma push /* merge_units */
#pragma global_optimizer off

static inline Plr_P* AsPlayer_00176260(GObj_P* o) { Plr_P* p = o->ctl; return (p && p->kind == D_0049D010) ? p : 0; }
extern void cPlayer_LaunchChooseMenu(Plr_P* pl, Plr_P* who);
void func_00176260(GObj_P* o)
{
    Plr_P* pl = D_004FFC2C->player;
    if (pl)
        cPlayer_LaunchChooseMenu(pl, AsPlayer_00176260(o));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176260 */

/* merge_units: begin func_001762C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void Pickup_PerformAction(void* o, void* c);
void* PickupMenu_Build(void* p, void* s, void* o, void* c, int a, int b);
}
typedef struct { void* first; } L_62C0;
typedef struct { char pad[0x54]; L_62C0* list; } Game_62C0;
#if 0 /* merge_units */
extern "C" Game_62C0* D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(Game_62C0 **)&D_004FFC2C) /* merge_units */

typedef struct { char pad[0x2F2]; unsigned char flag; } Obj_62C0;
typedef struct {
    char pad[0x30]; void* ctl;
    char pad2[0x178 - 0x34]; void* fx; unsigned char on;
    char pad3[0x184 - 0x17D]; int x184;
    char pad4[0x1BC - 0x188]; unsigned char reset;
} S_62C0;
extern "C" void Player_HandlePickupTrigger(S_62C0* self, Obj_62C0* o)
{
    void* c = self->ctl;
    if (self->reset) {
        self->reset = 0;
        Pickup_PerformAction(o, c);
    }
    if (self->on && !self->fx) {
        void* p;
        void* s;
        if (!o->flag)
            o->flag = 1;
        s = D_004FFC2C->list->first;
        {
            AllocGuard g;
            p = Mem_Alloc(0, 0xB8, "player.cc", 0x27A);
        }
        if (p)
            p = PickupMenu_Build(p, s, o, c, self->x184 <= 0, 0);
        self->fx = p;
    }
}
#undef D_004FFC2C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001762C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001762C0 */
