#include "types.h"

typedef struct Msg2530 {
    void* vtable;
    int a, b, c, d, e, f, g;
    char h;
    char p1[3];
    int i0;
    int i1;
    float x, y, z;
    int i2;
    int i3;
} Msg2530;

typedef struct Pkt {
    char pad[8];
    int i0;
    int i1;
    float x, y, z;
    int i2;
    int i3;
} Pkt;

extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern char D_0051EE68[];
extern char D_004DE130[];
extern void Event_Construct(Msg2530* m, void* type);
extern int Object_LookupById(int* id);
extern void Blast_Prepare(int obj, int a, float x, float y, float z, int b, int c, int d, int e);
extern void cMessage_dtor(Msg2530* m, int flags);

#pragma opt_propagation off
int func_002C6370(int a0, int a1, int a2, Pkt* pkt) {
    if (!D_005723C8) {
        D_005723C8 = 1;
    }
    if (D_005721D0) {
        Msg2530 m;
        int id[2];
        int obj;
        Pkt* p = pkt;
        Event_Construct(&m, D_0051EE68);
        m.vtable = D_004DE130;
        m.i0 = p->i0;
        m.i1 = p->i1;
        m.x = p->x;
        m.y = p->y;
        m.z = p->z;
        m.i3 = p->i3;
        m.i2 = p->i2;
        id[0] = m.i0;
        obj = Object_LookupById(id);
        if (obj) {
            Blast_Prepare(obj, m.i1, m.x, m.y, m.z, m.i3 != 0, 0, m.i2 != 0, 1);
        }
        m.vtable = D_004DE130;
        cMessage_dtor(&m, 0);
    }
    D_005723C8 = 0;
    return 0x24;
}