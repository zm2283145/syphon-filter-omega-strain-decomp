/*
 * SFOGame/Source/NetNPC: 21 files, 002D3070-002D3880
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D3070 */
#pragma push /* merge_units */
#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3070;
extern void cNPC_ResumeMovement(Npc3070* o);
void cNetNPC_ResumeMovement(Npc3070* o)
{
    if (NpcAuth_IsLocal())
        cNPC_ResumeMovement(o);
    cNetNPCMsgs_SendMessage(o->net, 0x16, 8, 0, 0, 0, 0);
}
static inline void merge_flush_func_002D3070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3070 */

/* merge_units: begin func_002D30E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc2D30E0;
extern void cNPC_StopMovement(Npc2D30E0* o, int x, float v);
void cNetNPC_StopMovement(Npc2D30E0* o, int x, float v)
{
    if (NpcAuth_IsLocal()) cNPC_StopMovement(o, x, v);
    cNetNPCMsgs_SendMessage(o->net, 0x15, 8, (int)v, x, 0, 0);
}
static inline void merge_flush_func_002D30E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D30E0 */

/* merge_units: begin func_002D3170 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3170;
float cNetNPC_SetFiringThreshold(Npc3170* o, float v)
{
    cNetNPCMsgs_SendMessage(o->net, 0x1A, 8, *(volatile int*)&v, 0, 0, 0);
    return v;
}
static inline void merge_flush_func_002D3170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3170 */

/* merge_units: begin func_002D31B0 */
#pragma push /* merge_units */
typedef struct { unsigned char f0 : 1; unsigned char f1 : 1; unsigned char f2 : 1; } Bits31B0;
typedef struct { char pad[0x30]; void* net; char pad2[0x10D]; Bits31B0 bits; } Npc31B0;
void cNetNPC_DeactivateDead(Npc31B0* o, unsigned char v)
{
    if (NpcAuth_IsLocal())
        cNetNPCMsgs_SendMessage(o->net, 0x18, 4, v, 0, 0, 0);
    o->bits.f2 = v;
}
static inline void merge_flush_func_002D31B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D31B0 */

/* merge_units: begin func_002D3240 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3240;
extern void cNPC_LookAround(Npc3240* o, int v);
void cNetNPC_LookAround(Npc3240* o, int v)
{
    if (NpcAuth_IsLocal())
        cNPC_LookAround(o, v);
    cNetNPCMsgs_SendMessage(o->net, 0x10, 8, v, 0, 0, 0);
}
static inline void merge_flush_func_002D3240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3240 */

/* merge_units: begin func_002D32C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc32C0;
extern void cNPC_ResumeAILookAt(Npc32C0* o, int v);
void cNetNPC_ResumeAILookAt(Npc32C0* o, int v)
{
    if (NpcAuth_IsLocal())
        cNPC_ResumeAILookAt(o, v);
    cNetNPCMsgs_SendMessage(o->net, 0x11, 8, v, 0, 0, 0);
}
static inline void merge_flush_func_002D32C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D32C0 */

/* merge_units: begin func_002D3340 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; } Tgt002D3340;
typedef struct { char pad[0x30]; void* net; } Npc002D3340;
extern void cNPC_RequestFacial(Npc002D3340* o, Tgt002D3340* t, int x, float v);
void cNetNPC_RequestFacial(Npc002D3340* o, Tgt002D3340* t, int x, float v)
{
    if (NpcAuth_IsLocal()) cNPC_RequestFacial(o, t, x, v);
    cNetNPCMsgs_SendMessage(o->net, 0xF, 8, t->id, *(int*)&v, x, 0);
}
static inline void merge_flush_func_002D3340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3340 */

/* merge_units: begin func_002D33E0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; } Tgt002D33E0;
typedef struct { char pad[0x30]; void* net; } Npc002D33E0;
extern void cNPC_RequestLookAt_cGOBJP_float_int(Npc002D33E0* o, Tgt002D33E0* t, int x, float v);
void cNetNPC_RequestLookAt_cGOBJP_float_int(Npc002D33E0* o, Tgt002D33E0* t, int x, float v)
{
    if (NpcAuth_IsLocal()) cNPC_RequestLookAt_cGOBJP_float_int(o, t, x, v);
    cNetNPCMsgs_SendMessage(o->net, 0xE, 8, t->id, *(int*)&v, x, 0);
}
static inline void merge_flush_func_002D33E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D33E0 */

/* merge_units: begin func_002D3480 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

float cNetNPC_GetRawTravelSpeed(Controller2D* self) {
    return self->unk200;
}

int cNetNPC_GetTravelSpeed_void(void) {
    return 2;
}
static inline void merge_flush_func_002D3480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3480 */

/* merge_units: begin func_002D34A0 */
#pragma push /* merge_units */
extern float D_00489DD0[];

/* Looks up a float table entry by byte index. */
float cNetNPC_GetTravelSpeed_eTravelSpeed(int unused, unsigned char i) {
    return D_00489DD0[i];
}
static inline void merge_flush_func_002D34A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D34A0 */

/* merge_units: begin func_002D34C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; char pad2[0xE4]; int i118; char pad3[0x22]; unsigned char b13E; } Npc34C0;
void cNetNPC_ResumeAIFiring(Npc34C0* o)
{
    if (NpcAuth_IsLocal()) {
        o->b13E = 1;
        o->i118 = 0;
    }
    cNetNPCMsgs_SendMessage(o->net, 0xD, 8, 0, 0, 0, 0);
}
static inline void merge_flush_func_002D34C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D34C0 */

/* merge_units: begin func_002D3510 */
#pragma push /* merge_units */
typedef struct Obj2D35 {
    char pad00[0x30];
    void* owner; /* 0x30 */
} Obj2D35;

extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void cNPC_SetFireMode(Obj2D35* self, int kind, int arg);
#if 0 /* merge_units */
extern void cNetNPCMsgs_SendMessage(void* owner, int msg, int len, int a, int b, int c, int d);
#endif /* merge_units */
#define cNetNPCMsgs_SendMessage(a0, a1, a2, a3, a4, a5, a6) (cNetNPCMsgs_SendMessage((a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */


/* Forwards to cNPC_SetFireMode when enabled, then sends message 0xC to the owner. */
void cNetNPC_SetFireMode(Obj2D35* self, int kind, int arg) {
    int enabled;
    if (g_IsMultiplayer) {
        enabled = D_005721C0;
    } else {
        enabled = 1;
    }
    if (enabled) {
        cNPC_SetFireMode(self, kind, arg);
    }
    cNetNPCMsgs_SendMessage(self->owner, 0xC, 8, (unsigned char)kind, arg, 0, 0);
}
#undef cNetNPCMsgs_SendMessage /* merge_units */
static inline void merge_flush_func_002D3510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3510 */

/* merge_units: begin func_002D35A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc35A0;
void cNetNPC_SetTravelSpeed(Npc35A0* o, float v)
{
    cNetNPCMsgs_SendMessage(o->net, 0x12, 8, *(volatile int*)&v, 0, 0, 0);
}
static inline void merge_flush_func_002D35A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D35A0 */

/* merge_units: begin func_002D35E0 */
#pragma push /* merge_units */
typedef struct { char pad[8]; int* items; } Tbl35E0;
typedef struct { char pad[0x20C]; int slot; } Obj35E0;
extern Tbl35E0* D_004FFBE0;
int cNetNPC_GetDestinationNode(Obj35E0* o)
{
    int i = o->slot;
    int r = 0;
    if (i >= 0)
        r = D_004FFBE0->items[i];
    return r;
}
static inline void merge_flush_func_002D35E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D35E0 */

/* merge_units: begin func_002D3610 */
#pragma push /* merge_units */
/* Looks up the table entry for index +0x208 (0 when negative). */
typedef struct { char pad00[8]; int *entries; } Table_002D3610;
#if 0 /* merge_units */
extern Table_002D3610 *D_004FFBE0;
#endif /* merge_units */
#define D_004FFBE0 (*(Table_002D3610 **)&D_004FFBE0) /* merge_units */

typedef struct { char pad00[0x208]; int index; } Obj_002D3610;
int cNetNPC_GetCurrentNode(Obj_002D3610 *obj) {
    int result = 0;
    int index = obj->index;
    if (index >= 0) result = D_004FFBE0->entries[index];
    return result;
}
#undef D_004FFBE0 /* merge_units */
static inline void merge_flush_func_002D3610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3610 */

/* merge_units: begin func_002D3640 */
#pragma push /* merge_units */
typedef struct Linked208 {
    char pad000[0x1E8];
    void* resolved;              /* 0x1E8 */
    char pad1EC[0x1C];
    int handle;                  /* 0x208 */
    char pad20C[8];
    unsigned char flag0 : 1;     /* 0x214 */
    unsigned char flag1 : 1;
    unsigned char linked : 1;
    unsigned char rest : 5;
} Linked208;

extern void* cAIPathData_GetNode(int handle);

/* Stores the handle, resolves it and marks the object linked. */
void cNetNPC_NetTeleport(Linked208* obj, int handle) {
    obj->handle = handle;
    obj->resolved = cAIPathData_GetNode(handle);
    obj->linked = 1;
}
static inline void merge_flush_func_002D3640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3640 */

/* merge_units: begin func_002D3690 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3690;
typedef struct { char pad[0x78]; int netId; } Gobj3690;
void cNetNPC_Teleport(Npc3690* o, Gobj3690* g)
{
    int id;
    if (g)
        id = g->netId;
    else
        id = -1;
    cNetNPCMsgs_SendMessage(o->net, 7, 8, id, 0, 0, 0);
}
static inline void merge_flush_func_002D3690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3690 */

/* merge_units: begin func_002D36C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc36C0;
typedef struct { char pad[0xC]; int id; } Arg36C0;
typedef struct { char pad[0x78]; int netId; } Gobj36C0;
extern void cNPC_CarryBodyToNode(Npc36C0* o, Arg36C0* a, Gobj36C0* g);
int cNetNPC_CarryBodyToNode(Npc36C0* o, Arg36C0* a, Gobj36C0* g)
{
    int id;
    if (NpcAuth_IsLocal())
        cNPC_CarryBodyToNode(o, a, g);
    if (g)
        id = g->netId;
    else
        id = -1;
    cNetNPCMsgs_SendMessage(o->net, 0x25, 8, a->id, id, 0, 0);
    return 1;
}
static inline void merge_flush_func_002D36C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D36C0 */

/* merge_units: begin func_002D3760 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3760;
typedef struct { char pad[0x78]; int netId; } Gobj3760;
extern void cNPC_SetMode(Npc3760* o, unsigned char a, Gobj3760* g);
void cNetNPC_SetMode(Npc3760* o, unsigned char a, Gobj3760* g)
{
    if (NpcAuth_IsLocal())
        cNPC_SetMode(o, a, g);
    cNetNPCMsgs_SendMessage(o->net, 1, 8, a, g ? g->netId : -1, 0, 0);
}
static inline void merge_flush_func_002D3760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3760 */

/* merge_units: begin func_002D3800 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3800;
typedef struct { char pad[0xC]; int id; } Gobj3800;
extern void cNPC_MoveToGobj(Npc3800* o, Gobj3800* g);
int cNetNPC_MoveToGobj(Npc3800* o, Gobj3800* g)
{
    if (NpcAuth_IsLocal())
        cNPC_MoveToGobj(o, g);
    cNetNPCMsgs_SendMessage(o->net, 0x2C, 8, g->id, 0, 0, 0);
    return 1;
}
static inline void merge_flush_func_002D3800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3800 */

/* merge_units: begin func_002D3880 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3880;
typedef struct { char pad[0x78]; int netId; } Node3880;
extern void cNPC_MoveToNode(Npc3880* o, Node3880* n);
int cNetNPC_MoveToNode(Npc3880* o, Node3880* n)
{
    if (NpcAuth_IsLocal())
        cNPC_MoveToNode(o, n);
    cNetNPCMsgs_SendMessage(o->net, 6, 8, *(volatile int*)&n->netId, 0, 0, 0);
    return 1;
}
static inline void merge_flush_func_002D3880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3880 */
