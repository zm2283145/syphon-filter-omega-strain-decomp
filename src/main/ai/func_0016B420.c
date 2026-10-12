#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
typedef struct { __int128 q; } V_B420;
typedef struct {
    void* vt;
    char pad[0x20];
    unsigned char on;
    signed char kind;
    char pad26[2];
    float a;
    float b;
    int id;
    int target;
    char pad38[8];
    V_B420 pos;
} M_B420;
extern char D_004EE5C8[];
extern char D_004D92A0[];
extern char D_004D92C0[];
extern void Event_PackHeader();
extern void Message_GetScriptTypeKey();
extern void func_0016F690();
extern void func_0016F710();
void * const D_004D9850[8] = { (void*)0x0, (void*)0x0, (void*)func_0016F690, (void*)func_0016F710, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
void Event_Construct(M_B420* m, void* type);
static inline void C1_B420(M_B420* m, float a, float b, signed char k)
{
    Event_Construct(m, D_004EE5C8);
    m->vt = D_004D92A0;
    m->on = 0;
    m->kind = k;
    m->a = a;
    m->b = b;
}
static inline void C2_B420(M_B420* m, float a, float b, int* id, signed char k)
{
    C1_B420(m, a, b, k);
    m->vt = D_004D92C0;
    m->id = *id;
}
M_B420* func_0016B420(M_B420* self, float a, float b, int* id, V_B420* pos, signed char kind)
{
    C2_B420(self, a, b, id, kind);
    self->vt = ((char*)D_004D9850);
    self->target = -1;
    VCopyF(&self->pos, pos);
    self->on = 1;
    return self;
}
#pragma peephole reset
