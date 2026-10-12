#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct { void* vt; char pad04[0x2C]; } Msg1_7510;
typedef struct { void* vt; char pad04[0x20]; int f24; signed char b28; char pad29[7]; } Msg2_7510;
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_0055C780[];
extern char D_00572198[];
extern char D_00582760[];
extern char D_004E0E80[];
extern char D_004E0F00[];
void NpcAi_GetPlayerRecord(void* self, int a, int b);
void func_002EBAF8(int* p, int v);
void func_0042D910(void* o);
void func_00429200(void* m, int a, int b);
void Event_Construct(void* m, void* type);
void Transport_Send(int a, void* m, int b, int c);
void cMessage_dtor(void* m, int f);
}
class Body_7510 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void SetActive(int on);
    VPAD4(d) VPAD2(e)
    virtual int IsLocal();
    char pad[0x8];
    int cC;
    char pad10[0x1C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
};
typedef struct { char pad[0x30]; Body_7510* body; } Npc_7510;
static inline int LocalId_7510(void)
{
    int a = D_005721A8;
    if (D_005721C8) {
        if (D_00494178 == -1)
            func_002EBAF8(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}
static inline bool CanActivate_7510(Body_7510* b) { return b->b2D && b->b2C && !b->b2E; }
extern "C" void NpcAi_DeactivateAnon(Npc_7510* self)
{
    Body_7510* b;
    int i;
    unsigned char* p;
    NpcAi_GetPlayerRecord(self, -1, 0);
    b = self->body;
    if (CanActivate_7510(b))
        b->SetActive(1);
    func_0042D910(self->body);
    if (!self->body->IsLocal()) {
        for (i = 0, p = D_0055C780; i < 4; i++, p++) {
            if (*p == 2) {
                if (i != LocalId_7510()) {
                    Msg1_7510 m1;
                    Msg2_7510 m2;
                    Event_Construct(&m1, D_00572198);
                    m1.vt = D_004E0E80;
                    func_00429200(&m1, self->body->cC, i);
                    m1.vt = D_004E0E80;
                    cMessage_dtor(&m1, 0);
                    Event_Construct(&m2, D_00582760);
                    m2.vt = D_004E0F00;
                    m2.f24 = -1;
                    m2.b28 = 1;
                    Transport_Send(self->body->cC, &m2, -1, i);
                    m2.vt = D_004E0F00;
                    cMessage_dtor(&m2, 0);
                }
            }
        }
    }
}
