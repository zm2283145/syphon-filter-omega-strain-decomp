/*
 * main/GameGOBJ: range (4 files, 00214BD0-00215010)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int Mem_Free();
int strlen(const char *);

/* merge_units: begin func_00214BD0 */
#pragma push /* merge_units */
typedef struct { char pad[0xFC]; int n; int* items; char pad2[0x24]; int* f128; } E214;
extern void* g_LocalPlayer;
extern void cPlayer_SetMenuReceiver(void*, E214*);
extern void cPlayer_SetMenuDefault(void*, int);
extern void cPlayer_SetMenuTitle_2(void*, char*);
extern void cPlayer_AddMenuChoice_2(void*, int);
extern void cPlayer_LaunchChooseMenu_2(void*);
extern char* Loc_LookupText(char*);
#pragma opt_strength_reduction off
void cElevatorGOBJ_ChooseFloor(E214* e) {
    void* m = g_LocalPlayer;
    int i;
    cPlayer_SetMenuReceiver(m, e);
    cPlayer_SetMenuDefault(m, *e->f128);
    cPlayer_SetMenuTitle_2(m, Loc_LookupText("ElevChooseFloor"));
    for (i = 0; i < e->n; i++) cPlayer_AddMenuChoice_2(m, e->items[i]);
    cPlayer_LaunchChooseMenu_2(m);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214BD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214BD0 */

/* merge_units: begin func_00214C90 */
#pragma push /* merge_units */
typedef struct Obj_00214C90 { char pad[0xC]; int id; } Obj_00214C90;
typedef struct LiftMsg_00214C90 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int kind; int floor; int from; int to; char pad34[0xC]; } LiftMsg_00214C90;
typedef struct Notice_00214C90 { void* vtable; char base[0x20]; int kind; int arg; char pad2C[4]; } Notice_00214C90;
typedef struct State_00214C90 { int cur; int dir; char pad8[0x18]; int target; } State_00214C90;
typedef struct Snd_00214C90 { int pad0; void* h; } Snd_00214C90;
typedef struct Lift_00214C90 {
    char pad0[0xC]; int id; char pad10[0x10C - 0x10]; int nFloors; int* locked;
    char pad114[0x128 - 0x114]; State_00214C90* state; char pad12C[0x790 - 0x12C]; Snd_00214C90* snd;
} Lift_00214C90;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char g_TriggerMsgKey[];
extern char D_004DAF10[];
extern char D_004F5448[];
extern char D_004DAED0[];
extern void Event_Construct(void* m, void* type);
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
#if 0 /* merge_units */
extern void cElevatorGOBJ_ChooseFloor(Lift_00214C90* l);
#endif /* merge_units */
#define cElevatorGOBJ_ChooseFloor(a0) (cElevatorGOBJ_ChooseFloor((void *)(a0))) /* merge_units */

extern void NetRequestObjectPrivateOwnership(void* h);
extern void Lift_DeactivateRecipients(Lift_00214C90* l);
extern unsigned char Lift_OpenDoors(Lift_00214C90* l);
static inline int IsAuth_00214C90(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline int ObjId_00214C90(Obj_00214C90* o) { return o ? o->id : 0; }
void Lift_SeekFloor(Lift_00214C90* l, int floor, int a2, int a3)
{
    if (g_IsMultiplayer && IsAuth_00214C90()) {
        LiftMsg_00214C90 msg;
        LiftMsg_00214C90* m = &msg;
        Event_Construct(m, g_TriggerMsgKey);
        msg.floor = floor;
        msg.vtable = D_004DAF10;
        msg.kind = 1;
        m->to = ObjId_00214C90((Obj_00214C90*)l);
        m->from = ObjId_00214C90(0);
        msg.b20 = 4;
        Event_Send(&msg, l, 0);
        msg.vtable = D_004DAF10;
        cMessage_dtor(&msg, 0);
    }
    if (a2 && floor < 0) {
        if (g_IsMultiplayer) {
            if (a3) {
                cElevatorGOBJ_ChooseFloor(l);
            } else {
                Snd_00214C90* s = l->snd;
                if (s)
                    NetRequestObjectPrivateOwnership(s->h);
            }
        } else {
            cElevatorGOBJ_ChooseFloor(l);
        }
    } else if (floor >= 0) {
        unsigned char blocked;
        if (floor >= 0 && floor < l->nFloors)
            blocked = l->locked[floor] != 0;
        else
            blocked = 1;
        if (!blocked) {
            State_00214C90* st;
            l->state->target = floor;
            st = l->state;
            if (st->target > st->cur) {
                Notice_00214C90 n;
                Event_Construct(&n, D_004F5448);
                n.vtable = D_004DAED0;
                n.kind = 1;
                n.arg = floor;
                Event_Send(&n, l, 0);
                n.vtable = D_004DAED0;
                cMessage_dtor(&n, 0);
                l->state->dir = 1;
                Lift_DeactivateRecipients(l);
            } else if (st->target < st->cur) {
                Notice_00214C90 n;
                Event_Construct(&n, D_004F5448);
                n.vtable = D_004DAED0;
                n.kind = 1;
                n.arg = floor;
                Event_Send(&n, l, 0);
                n.vtable = D_004DAED0;
                cMessage_dtor(&n, 0);
                l->state->dir = -1;
                Lift_DeactivateRecipients(l);
            } else {
                st->dir = 0;
                Lift_OpenDoors(l);
            }
        } else {
            Notice_00214C90 n;
            Event_Construct(&n, D_004F5448);
            n.vtable = D_004DAED0;
            n.kind = 4;
            n.arg = floor;
            Event_Send(&n, l, 0);
            n.vtable = D_004DAED0;
            cMessage_dtor(&n, 0);
        }
    }
}
#undef cElevatorGOBJ_ChooseFloor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214C90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214C90 */

/* merge_units: begin func_00214FA0 */
#pragma push /* merge_units */
typedef struct { char pad[0x28]; int state; } ElevState;
typedef struct { char pad[0x128]; ElevState* st; } ElevGobj;
extern int cElevatorGOBJ_DoorsClosed(ElevGobj* self);
extern int cElevatorGOBJ_DoorsOpen(ElevGobj* self);
int cElevatorGOBJ_GetState(ElevGobj* self)
{
    if (self->st->state == 1)
        return 1;
    if (cElevatorGOBJ_DoorsClosed(self) || cElevatorGOBJ_DoorsOpen(self))
        return 0;
    return 2;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214FA0 */

/* merge_units: begin func_00215010 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

extern "C" {
void* Mem_Alloc(int, int, char*, int);
extern char D_004A4550[];
}

typedef struct NameVec {
    int unk0;
    int count;
    char** data;
} NameVec;

extern "C" char** std_vector_charPtr_opIndex_uint(NameVec* v, int i);

typedef struct cElevatorGOBJ {
    char pad[0xF8];
    NameVec names;
} cElevatorGOBJ;

extern "C" void cElevatorGOBJ_SetFloorName(cElevatorGOBJ* self, int i, char* name) {
    char* p;
    char* q;
    char** slot;
    int n;
    char*** pd;
    if (i >= 0 && i < self->names.count) {
        pd = &self->names.data;
        if ((*pd)[i]) {
            p = *std_vector_charPtr_opIndex_uint(&self->names, i);
            AllocGuard g;
            Mem_Free(0, p, D_004A4550, 0x697);
        }
        slot = &(*pd)[i];
        n = strlen(name) + 1;
        {
            AllocGuard g;
            q = (char*)Mem_Alloc(0, n, D_004A4550, 0x699);
        }
        *slot = q;
        String_Copy((*pd)[i], name);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00215010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00215010 */
