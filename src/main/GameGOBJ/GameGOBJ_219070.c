/*
 * main/GameGOBJ: range (3 files, 00219070-00219350)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "gobj_v07_register.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "gobj_v06_update.h"
#pragma pop

/* merge_units: begin func_00219070 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Obj_00219070 { char pad[0xC]; int id; } Obj_00219070;
typedef struct { char d[0x9C]; } Str_00219070;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00219070 s78;
    Str_00219070 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_00219070;
typedef struct LiftMsg_00219070 { void* vtable; char base[0x20]; int kind; int floor; int from; int to; char pad34[0xC]; } LiftMsg_00219070;
typedef struct Notice_00219070 { void* vtable; char base[0x20]; int kind; int arg; char pad2C[4]; } Notice_00219070;
typedef struct Node_00219070 { char pad[0x49]; unsigned char type; } Node_00219070;
struct Handler_00219070 { virtual void v0(); virtual void Receive(void* ev); };
typedef struct Path_00219070 {
    char pad0[0x64]; Handler_00219070* handler; char pad68[8]; int count; char pad74[8]; Node_00219070** nodes;
    char pad80[0xDC - 0x80]; unsigned char bDC; char padDD[3]; int fE0; void* preset;
} Path_00219070;
extern int D_004F5440;
extern "C" {
extern char D_004F5450[];
extern char D_004DAE90[];
extern char D_004DAF10[];
extern char D_004DAE30[];
extern char D_004FFB50[];
extern int D_0055D4D8;
extern int D_0055D4E0;
extern int* Event_GetType(void* ev);
extern void Event_Construct(void* m, void* type);
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void SoundEvent_CtorFromPreset(Snd_00219070* e, void* preset, void* owner);
extern void FileMan_Release(Str_00219070* s, int flag);
extern int Object_HandleMessage(Path_00219070* self, void* ev);
}
static inline int ObjId_00219070(Obj_00219070* o) { return o ? o->id : 0; }
#pragma opt_strength_reduction off
extern "C" int PathObj_Receive(Path_00219070* self, void* ev)
{
    int t = *Event_GetType(ev);
    if (t == D_004F5440) {
        int i;
        Snd_00219070 s;
        LiftMsg_00219070 msg;
        Notice_00219070 n;
        {
            self->bDC = 0;
            Event_Construct(&n, D_004F5450);
            n.vtable = D_004DAE90;
            n.kind = 1;
            n.arg = -1;
            Event_Send(&n, self, 0);
            n.vtable = D_004DAE90;
            cMessage_dtor(&n, 0);
        }
        self->fE0 = 0;
        if (self->preset) {
            SoundEvent_CtorFromPreset(&s, self->preset, self);
            s.flag = 1;
            Event_Send(&s, D_004FFB50, 1);
            s.vt = D_004DAE30;
            FileMan_Release(&s.s114, -1);
            FileMan_Release(&s.s78, -1);
            cMessage_dtor(&s, 0);
        }
        for (i = 0; i < self->count; i++) {
            if (self->nodes[i]->type == 0xB) {
                LiftMsg_00219070* m = &msg;
                Event_Construct(m, &D_004F5440);
                msg.vtable = D_004DAF10;
                msg.kind = 0;
                msg.floor = 0;
                m->to = ObjId_00219070(0);
                m->from = ObjId_00219070(0);
                Event_Send(&msg, self->nodes[i], 0);
                msg.vtable = D_004DAF10;
                cMessage_dtor(&msg, 0);
            }
        }
        return 1;
    }
    t = *Event_GetType(ev);
    if (t == D_0055D4D8 || (t = *Event_GetType(ev), t == D_0055D4E0)) {
        Handler_00219070* h = self->handler;
        if (h)
            h->Receive(ev);
        return Object_HandleMessage(self, ev);
    }
    return Object_HandleMessage(self, ev);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00219070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00219070 */

/* merge_units: begin func_002192F0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 7: notify attached object, update, register. */
DEFINE_GOBJ_V07_REGISTER(cPathedGOBJ_v07)
#pragma pop /* merge_units */
/* merge_units: end func_002192F0 */

/* merge_units: begin func_00219350 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 6: notify attached object, update, call slot 47. */
DEFINE_GOBJ_V06_UPDATE(cPathedGOBJ_v06)
#pragma pop /* merge_units */
/* merge_units: end func_00219350 */
