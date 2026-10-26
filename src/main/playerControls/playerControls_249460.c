/*
 * main/playerControls: range (5 files, 00249460-00249580)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00249460 */
#pragma push /* merge_units */
typedef struct { unsigned char b0; char pad[3]; int f4; int f8; char fC; } Slot49;
typedef struct { char pad[0x13C]; void* p13C; Slot49* p140; } Owner49;
typedef struct { char pad[0x3584]; Slot49* p3584; } Ctx49;
void Player_MpAimViewExit(Owner49* self, Ctx49* ctx) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) self->p140->b0 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249460 */

/* merge_units: begin func_00249490 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } Vec49;
typedef struct { unsigned char b0; char pad[15]; Vec49 v; } Slot49c;
typedef struct { char pad[0x140]; Slot49c* p140; } Owner49c;
typedef struct { char pad[0x3584]; Slot49c* p3584; } Ctx49c;
void cPlayerControls_NetSetManualTarget(Owner49c* self, Ctx49c* ctx, Vec49* v) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) {
        Slot49c* s = self->p140;
        s->b0 = 1;
        s->v.x = v->x;
        s->v.y = v->y;
        s->v.z = v->z;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249490(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249490 */

/* merge_units: begin func_002494E0 */
#pragma push /* merge_units */
void cPlayerControls_NetSetTarget(Owner49* self, Ctx49* ctx, int a2, int* a3, char t0) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) {
        self->p140->f4 = a2;
        self->p140->f8 = *a3;
        self->p140->fC = t0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002494E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002494E0 */

/* merge_units: begin func_00249530 */
#pragma push /* merge_units */
typedef struct { unsigned short count; } Sub49b;
typedef struct { char pad[0x13C]; Sub49b* p13C; void* p140; } Owner49b;
typedef struct { char pad[0x3584]; char* p3584; } Ctx49b;
void PlayerInput_WeaponBlockHelper(Owner49b* self, Ctx49b* ctx) {
    if (!self->p13C) {
        char* q = ctx->p3584;
        if (q) q += 0x1C;
        self->p13C = (Sub49b*)q;
    }
    if (self->p13C) self->p13C->count++;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249530 */

/* merge_units: begin func_00249580 */
#pragma push /* merge_units */
typedef struct { char p[0xC]; int id; } Obj249580;
typedef struct { void* vtable; char base[0x1C]; unsigned char b20; char p21[3]; int f24; unsigned char b28; char p29[3]; int f2C; } Msg249580;
extern char g_ActorActionMsgClass[];
extern char D_004E01A0[];
extern char D_004E0840[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void PlayerInput_LookAtLockAction(void* self, Obj249580* o, void* target) {
    if (o) {
        Msg249580 m;
        int id = o->id;
        Event_Construct(&m, g_ActorActionMsgClass);
        m.f24 = 0x3E;
m.b28 = 5;
m.vtable = D_004E01A0;
m.b20 = 1;
m.f2C = id;
        Event_Send(&m, target, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    } else {
        Msg249580 m;
        Event_Construct(&m, g_ActorActionMsgClass);
        m.vtable = D_004E0840;
        m.f24 = 0x3F;
        m.b20 = 1;
        m.b28 = 0;
        Event_Send(&m, target, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249580 */
