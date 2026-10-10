#include "types.h"
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
extern void Event_Construct(PathMsg_f3* m, void* type);
extern void Event_Send(PathMsg_f3* m, void* target, int immediate);
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
        Event_Construct(&msg, D_004F5450);
        msg.vtable = D_004DAE90;
        msg.kind = 1;
        msg.index = idx;
        Event_Send(&msg, o, 0);
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