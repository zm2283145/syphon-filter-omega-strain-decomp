/*
 * main/GameGOBJ: range (3 files, 0021B830-0021B970)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop

/* merge_units: begin func_0021B830 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_004DAEB0[];
extern char D_004D9DE0[];
void operator_delete(void* allocation);
}

struct Obj0021B830 {
    int pad[2];
    void* vtable;
};

extern "C" Obj0021B830* cDamageCallback_dtor(Obj0021B830* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DAEB0;
        if (self)
            self->vtable = D_004D9DE0;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021B830(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021B830 */

/* merge_units: begin func_0021B890 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cDamageCallback_Call: deliver blast damage to the target through its damage vcall */
struct Pt1BdTarget {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual void TakeDamage(float amount, Pt1BdTarget* source, int kind, int type, int a, int b, void* pos);
    char pad[0x8];
    int serial;
};
struct Pt1BdHandle { Pt1BdTarget* target; int serial; };
static inline Pt1BdTarget* Pt1Bd_Get(Pt1BdHandle* h)
{
    Pt1BdTarget* t = h->target;
    bool ok = !t || t->serial == h->serial;
    return ok ? t : 0;
}
static inline Pt1BdTarget* Pt1Bd_Get2(Pt1BdHandle* h)
{
    Pt1BdTarget* t = h->target;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if (t->serial != h->serial)
            ok = false;
    return ok ? t : 0;
}
struct Pt1BdEvent {
    char pad0[0xC];
    Pt1BdHandle target;
    int damage;
    Pt1BdHandle source;
    signed char type;
    char pad21[0xF];
    char pos[0x10];
};
extern "C" void cDamageCallback_Call(Pt1BdEvent* e)
{
    if (Pt1Bd_Get(&e->target)) {
        Pt1BdTarget* src = Pt1Bd_Get2(&e->source);
        Pt1Bd_Get(&e->target)->TakeDamage((float)e->damage, src, 1, e->type, 0, 0, e->pos);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021B890(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021B890 */

/* merge_units: begin func_0021B970 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DAED0[];

struct Msg_0021B970 : ClonedMessageBase {
    int a24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DAED0; p->a24 = s->a24; p->a28 = s->a28;

extern "C" {
char D_004A4A58[] = "gamegobj.hh";
}
DEFINE_MESSAGE_CLONE(cElevatorNotice_Clone, Msg_0021B970, 44, D_004A4A58, 49, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021B970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021B970 */
