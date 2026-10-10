#include "types.h"
typedef struct {
    void* vtbl;
    char pad04[0x18];
    int size;
    unsigned char len;
    char pad21[0xB];
    unsigned char type;
    char pad2D[3];
    int id;
    char pad34[0x1C];
} C1Msg_2273;
typedef struct {
    char p0[0xA4];
    int cur;
    char pA8[0xB0 - 0xA8];
    void* lists[32][32];
    void* extra[32];
    int counts[32];
} C1Man_2273;
extern unsigned char D_005721C8;
extern char D_0051F0B0[];
extern char D_004DE4F0[];
extern void Event_Construct(C1Msg_2273* m, void* type);
extern void Event_Send(C1Msg_2273* m, void* target, int flags);
extern void cMessage_dtor(C1Msg_2273* m, int flags);
extern void Objective_Deactivate(void* o);
void ObjMan_StartStage(C1Man_2273* m, int stage, int quiet)
{
    int i;
    if (D_005721C8 && !quiet) {
        C1Msg_2273 msg;
        Event_Construct(&msg, D_0051F0B0);
        msg.vtbl = D_004DE4F0;
        msg.id = -1;
        msg.type = 4;
        msg.size = 0x40;
        msg.len = 4;
        Event_Send(&msg, m, 0);
        msg.vtbl = D_004DE4F0;
        cMessage_dtor(&msg, 0);
    }
    if (stage != m->cur) {
        for (i = 0; i < m->counts[m->cur]; i++)
            Objective_Deactivate(m->lists[m->cur][i]);
        m->cur = stage;
    }
}