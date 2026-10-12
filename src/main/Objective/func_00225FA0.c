#include "types.h"
typedef struct { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[0xB]; unsigned char b2C; char p2D[3]; int f30; char p34[0x1C]; } Msg225FA0;
extern unsigned char D_005721C8;
extern char D_0051F0B0[];
extern char D_004DE4F0[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void Objective_SetCompleted(void* o);
void* ObjMan_GetService(void);
int ObjMan_GetTotalCount(void* s);
int func_002270C0(void* s, int* buf, int n, int f);
void Objective_QueueThresholdVoice(int id, int f);
void Actor_BuildVoiceKey(void* a, int v);
extern int D_0049D010;
typedef struct { char p[0x4C]; int kind; } Act225FA0;
static inline void SetF225FA0(int* p, int v) { *p = v; }
#pragma push
#pragma opt_propagation off
#pragma opt_dead_assignments off
void Objective_Succeed(void* self, void* obj, Act225FA0* actor)
{
    int total;
    int half;
    int n;
    Msg225FA0 m;
    int buf[20];
    if (D_005721C8) {
        Event_Construct(&m, D_0051F0B0);
        m.vtable = D_004DE4F0;
        m.f30 = -1;
        m.b2C = 1;
        SetF225FA0(&m.f1C, 0x40);
        m.b20 = 4;
        SetF225FA0(&m.f1C, 0x40);
        Event_Send(&m, obj, 0);
        m.vtable = D_004DE4F0;
        cMessage_dtor(&m, 0);
    }
    Objective_SetCompleted(obj);
    total = ObjMan_GetTotalCount(ObjMan_GetService());
    half = total / 2;
    n = func_002270C0(ObjMan_GetService(), buf, 0x14, 1);
    if (n == total) Objective_QueueThresholdVoice(0x17, 1);
    else if (n >= half && n - 1 < half) Objective_QueueThresholdVoice(0x16, 1);
    if (actor && actor->kind == D_0049D010) Actor_BuildVoiceKey(actor, 0xD);
}
#pragma pop
