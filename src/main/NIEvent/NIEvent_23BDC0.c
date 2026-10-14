/*
 * main/NIEvent: range (3 files, 0023BDC0-0023BEE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0023BDC0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Msg_23BDC0 { void* vtable; char pad04[0x18]; int size; int pad20; int target; char pad28[0x8]; };
struct Obj_23BDC0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void Toggle(int x);
    char pad[0xC];
    int id;
};
extern "C" {
extern unsigned char D_005721C8;
void Event_Construct(Msg_23BDC0* msg, void* type);
void cMessage_dtor(Msg_23BDC0* msg, int flags);
extern char g_cDisableMsgClass[];
extern char D_004E0860[];
void func_003FF650(Msg_23BDC0* msg, int id, int x);
}
extern "C" void cNIEventOBJ_v18(Obj_23BDC0* self)
{
    self->Toggle(-1);
    if (D_005721C8) {
        Msg_23BDC0 msg;
        Event_Construct(&msg, g_cDisableMsgClass);
        msg.vtable = D_004E0860;
        msg.target = -1;
        msg.size = 0x40;
        func_003FF650(&msg, self->id, -1);
        msg.vtable = D_004E0860;
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023BDC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023BDC0 */

/* merge_units: begin func_0023BE50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Msg_23BE50 { void* vtable; char pad04[0x18]; int size; int pad20; int target; char pad28[0x8]; };
struct Obj_23BE50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void Toggle(int x);
    char pad[0xC];
    int id;
};
extern "C" {
#if 0 /* merge_units */
void Event_Construct(Msg_23BE50* msg, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Msg_23BDC0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(Msg_23BE50* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg_23BDC0 *)(a0), (a1))) /* merge_units */

extern char g_cEnableMsgClass[];
extern char D_004E0880[];
void func_003FF930(Msg_23BE50* msg, int id);
}
extern "C" void cNIEventOBJ_v17(Obj_23BE50* self)
{
    self->Toggle(-1);
    if (D_005721C8) {
        Msg_23BE50 msg;
        Event_Construct(&msg, g_cEnableMsgClass);
        msg.vtable = D_004E0880;
        msg.target = -1;
        msg.size = 0x40;
        func_003FF930(&msg, self->id);
        msg.vtable = D_004E0880;
        cMessage_dtor(&msg, 0);
    }
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023BE50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023BE50 */

/* merge_units: begin func_0023BEE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Child_23BEE0 { char pad[0x4C]; int kind; };
class Target_23BEE0 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c) VPAD1(d)
    virtual void slot22(int arg);
};
struct Node_23BEE0 {
    void* vtable;
    char pad04[0x98];
    PtrVec children;
    char padA8[0x140 - 0xA8];
    Target_23BEE0* target;
};
extern "C" {
extern int D_004F7C60;
int* func_0023A550(PtrVec* v, int i);
void func_0023BEE0(Node_23BEE0* self, int arg);
void Object_Deactivate(Node_23BEE0* self, int arg);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void func_0023BEE0(Node_23BEE0* self, int arg)
{
    int i;
    if (self->target)
        self->target->slot22(arg);
    for (i = 0; i < self->children.count; i++) {
        Child_23BEE0* c = (Child_23BEE0*)*func_0023A550(&self->children, i);
        if (c->kind == D_004F7C60)
            func_0023BEE0((Node_23BEE0*)self->children.data[i], arg);
        else
            ((Target_23BEE0*)self->children.data[i])->slot22(arg);
    }
    Object_Deactivate(self, arg);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023BEE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023BEE0 */
