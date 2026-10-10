#pragma opt_common_subs off
#include "types.h"
typedef struct { char pad[8]; int* key; } Svc_c7;
typedef struct SvcNode_c7 { struct SvcNode_c7* prev; struct SvcNode_c7* next; Svc_c7* svc; } SvcNode_c7;
typedef struct { SvcNode_c7* p; } SvcIt_c7;
typedef struct { char pad[0x20]; int list; } SvcMgr_c7;
extern void func_0013B160(SvcIt_c7* out, void* list);
extern SvcIt_c7* func_003CAB40(SvcIt_c7* dst, SvcIt_c7* src);
extern void func_003CAB30(SvcIt_c7* out, void* list);
extern SvcIt_c7* func_003CAB20(SvcIt_c7* dst, SvcIt_c7* src);
Svc_c7* Service_Lookup(SvcMgr_c7* self, int* id) {
    SvcIt_c7 it;
    SvcIt_c7 beg;
    SvcIt_c7 end;
    SvcIt_c7 e0;
    SvcIt_c7 b0;
    SvcNode_c7* last;
    func_0013B160(&e0, &self->list);
    func_003CAB40(&end, &e0);
    last = end.p;
    func_003CAB30(&b0, &self->list);
    func_003CAB20(&beg, &b0);
    for (it = beg; it.p != last; it.p = it.p->next) {
        Svc_c7* s = it.p->svc; if (*s->key == *id) return s;
    }
    return 0;
}