#include "types.h"
typedef struct { char p[0xC]; int id; } Obj249580;
typedef struct { void* vtable; char base[0x1C]; unsigned char b20; char p21[3]; int f24; unsigned char b28; char p29[3]; int f2C; } Msg249580;
extern char D_0055D480[];
extern char D_004E01A0[];
extern char D_004E0840[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void func_00249580(void* self, Obj249580* o, void* target) {
    if (o) {
        Msg249580 m;
        int id = o->id;
        Event_Construct(&m, D_0055D480);
        m.f24 = 0x3E;
m.b28 = 5;
m.vtable = D_004E01A0;
m.b20 = 1;
m.f2C = id;
        Event_Send(&m, target, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    } else {
        Msg249580 m;
        Event_Construct(&m, D_0055D480);
        m.vtable = D_004E0840;
        m.f24 = 0x3F;
        m.b20 = 1;
        m.b28 = 0;
        Event_Send(&m, target, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
