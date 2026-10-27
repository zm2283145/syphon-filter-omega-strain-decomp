/*
 * SFOGame/Source/GameGOBJ: 1 file, 00212540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00212540 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct Notice_00212540 { void* vtable; char base[0x20]; int kind; int arg; char pad2C[4]; } Notice_00212540;
typedef struct { int cur; int dir; int target; } Lift_00212540;
typedef struct {
    char pad0[0x98]; int count; char pad9C[0xCC - 0x9C]; int fCC; Lift_00212540* lift;
    char padD4[0xDC - 0xD4]; unsigned char bDC; char padDD[3]; int fE0;
} Obj_00212540;
typedef struct { char pad[8]; int idx; char padC[2]; unsigned short hi; unsigned short lo; } Req_00212540;
typedef struct { char pad[0x1C]; Req_00212540* req; } Src_00212540;
extern "C" {
extern char D_004F5450[];
extern char D_004DAE90[];
extern int D_004F5488;
extern unsigned char D_005723C8;
extern void cMessage_ctor_cMessageNameR(void* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern Obj_00212540* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern int NetGetObject(Src_00212540** out);
}
#pragma define_section GUARD_212540_DTOR ".dtors_drop" far_absolute RX
/* scoped busy flag; out-of-line dtor copy is weak and discarded like AllocGuard's */
struct Guard_212540 { Guard_212540() { if (!D_005723C8) D_005723C8 = 1; } __declspec(weak) __declspec(GUARD_212540_DTOR) ~Guard_212540() { D_005723C8 = 0; } };
extern "C" void cPathedGOBJ_PathedGobjUpdateCallback(void* a0, void* a1, int type)
{
    Guard_212540 g;
    Notice_00212540 n;
    Notice_00212540 m;
    Src_00212540* src;
    int id;
    if (D_004F5488 == type) {
        if (NetGetObject(&src) == 0) {
            Req_00212540* r = src->req;
            if (r->idx > -1) {
                id = r->lo | (r->hi << 16);
                Obj_00212540* o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                if (o) {
                    int idx = r->idx;
                    if (idx >= 0 && idx <= o->count - 1 && o->lift->cur != idx) {
                        o->fE0 = 0;
                        if (o->lift->cur < idx) {
                            o->lift->dir = 1;
                        } else {
                            o->lift->dir = -1;
                        }
                        o->lift->target = idx;
                        o->fCC = idx;
                        { o->bDC = 0;
                            cMessage_ctor_cMessageNameR(&m, D_004F5450); m.vtable = D_004DAE90; m.kind = 1; m.arg = idx;
                            QueueMessage_cMessageR_cSystemP_int(&m, o, 0); m.vtable = D_004DAE90; cMessage_dtor(&m, 0); }
                    }
                    { o->bDC = 0;
                        cMessage_ctor_cMessageNameR(&n, D_004F5450);
                        n.vtable = D_004DAE90;
                        n.kind = 1;
                        n.arg = 0;
                        QueueMessage_cMessageR_cSystemP_int(&n, o, 0);
                        n.vtable = D_004DAE90;
                        cMessage_dtor(&n, 0);
                    }
                }
            }
        }
    }
}
static inline void merge_flush_func_00212540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00212540 */
