/*
 * main/GameGOBJ: range (2 files, 002111E0-00211220)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002111E0 */
#pragma push /* merge_units */
typedef struct { int start; int len; int cur; } SmSeg;
typedef struct { char pad0[0xCC]; int target; SmSeg* seg; char pad1[8]; unsigned char stopped; } SmMover;
int Script_Mover_Stop(SmMover** args)
{
    SmMover* m = *args;
    if (!m->stopped) {
        m->seg->cur = m->seg->start + m->seg->len;
        m->target = m->seg->start + m->seg->len;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002111E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002111E0 */

/* merge_units: begin func_00211220 */
#pragma push /* merge_units */
#define STACK_COPY(arr) (*(int*)(arr))
typedef struct { void* vtable; char base[0x20]; int kind; int index; } PathMsg_f3;
typedef struct { int cur; int dir; int target; } PathState_f3;
typedef struct {
    char pad0[0x98]; int count;
    char pad9C[0xCC - 0x9C]; int posCC; PathState_f3* path;
    char padD4[0xDC - 0xD4]; unsigned char bDC; char padDD[3]; int fE0;
} PathObj_f3;
typedef struct { PathObj_f3* obj; int target; } PathArgs_f3;
extern char D_004F5450[];
extern char D_004DAE90[];
extern void cMessage_ctor_cMessageNameR(PathMsg_f3* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(PathMsg_f3* m, void* target, int immediate);
extern void cMessage_dtor(PathMsg_f3* m, int flags);
static inline void PathObj_SetPos_f3(int idx, PathObj_f3* o)
{
    PathMsg_f3 msg;
    if (idx >= 0 && idx <= o->count - 1 && o->path->cur != idx) {
        o->fE0 = 0;
        if (o->path->cur < idx) {
            o->path->dir = 1;
        } else {
            o->path->dir = -1;
        }
        o->path->target = idx;
        o->posCC = idx;
        o->bDC = 0;
        cMessage_ctor_cMessageNameR(&msg, D_004F5450);
        msg.vtable = D_004DAE90;
        msg.kind = 1;
        msg.index = idx;
        QueueMessage_cMessageR_cSystemP_int(&msg, o, 0);
        msg.vtable = D_004DAE90;
        cMessage_dtor(&msg, 0);
    }
}
int PathObj_ScriptSetPos(PathArgs_f3* a)
{
    int idx[1];
    idx[0] = a->target;
    PathObj_SetPos_f3(STACK_COPY(idx), a->obj);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00211220(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00211220 */
