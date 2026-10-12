#include "types.h"
typedef struct { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[0xB]; unsigned char b2C; char p2D[3]; int f30; char p34[0x1C]; } Msg225F00;
extern unsigned char D_005721C8;
extern char D_0051F0B0[];
extern char D_004DE4F0[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void Objective_FormatStatusText(void* o);
static inline void SetF225F00(int* p, int v) { *p = v; }
#pragma push
#pragma opt_propagation off
#pragma opt_dead_assignments off
void cObjectiveMan_SucceedPart(void* self, void* obj)
{
    if (D_005721C8) {
        Msg225F00 m;
        Event_Construct(&m, D_0051F0B0);
        m.vtable = D_004DE4F0;
m.f30 = -1;
m.b2C = 2;
SetF225F00(&m.f1C, 0x40);
m.b20 = 4;
        SetF225F00(&m.f1C, 0x40);
        Event_Send(&m, obj, 0);
        m.vtable = D_004DE4F0;
        cMessage_dtor(&m, 0);
    }
    Objective_FormatStatusText(obj);
}
#pragma pop
