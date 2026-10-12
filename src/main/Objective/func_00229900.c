#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
struct Obj_229900 {
    void* vtable;
    char pad4[8];
    int id;               /* 0x0C */
    int netid;            /* 0x10 */
    unsigned char active; /* 0x14 */
    char pad15[0xF];
    unsigned char b24;
    char b25;
    unsigned char b26, b27, b28, b29;
    char pad2a[2];
    int arg;              /* 0x2C */
    int x30;
    int x34;
    int x38;
    unsigned char b3C;
    char pad3d[3];
    int x40, x44, x48, x4C, x50;
    unsigned char b54;
    char pad55[3];
    int x58;
    unsigned char b5C;
    char pad5d[3];
    int x60, x64, x68, x6C, x70, x74, x78, x7C, x80, x84, x88;
};
extern "C" {
extern char D_004F7570[];
extern char D_004DB7D0[];
void Receiver_Construct(Obj_229900* o, void* t);
void Objective_Activate(Obj_229900* o);
void IdMgr_Allocate(int* id, int n);
void NetMap_BindReceiver(int a, int b, void* c);
}
static inline int ObjId_229900(int& tmp)
{
    int id;
    int ok = D_005721C8 ? D_005721C0 : 1;
    if (ok) {
        id = NetLocalId();
    } else {
        func_002EBBA0(D_005721A8, &tmp);
        id = tmp;
    }
    return id;
}
struct IdObj { char pad[0xC]; int id; };
static inline int GetId_229900(IdObj* o, int& t)
{
    int* p;
    if (o) {
        p = &o->id;
    } else {
        t = -1;
        p = &t;
    }
    return *p;
}

extern "C" Obj_229900* Objective_Ctor(Obj_229900* self, int arg)
{
    int id;
    int tmp;
    int t;
    Receiver_Construct(self, D_004F7570);
    self->vtable = D_004DB7D0;
    self->x38 = -2;
    self->x34 = 0;
    self->arg = arg;
    self->b24 = 0;
    Objective_Activate(self);
    self->b26 = 0;
    self->b27 = 3;
    self->b28 = 1;
    self->b29 = 0;
    self->x30 = 0;
    self->x34 = 0;
    self->x38 = GetId_229900(0, t);
    self->b3C = 0;
    self->x40 = 0;
    self->x44 = 0;
    self->x48 = 0;
    self->x4C = 0;
    self->x50 = 0;
    self->b54 = 0;
    self->x58 = 0;
    self->b5C = 0;
    self->x60 = 0;
    self->x64 = 0;
    self->x68 = 0;
    self->x6C = 0;
    self->x70 = 0;
    self->x74 = 0;
    self->x78 = 0;
    self->x7C = 0;
    self->x80 = 0;
    self->x84 = 0;
    self->x88 = 0;
    if (D_005721C8) {
        IdMgr_Allocate(&id, 0xF6);
        self->id = id;
        self->netid = self->id;
        int nid = self->netid;
        NetMap_BindReceiver(nid, ObjId_229900(tmp), self);
        if (!(D_005721C8 ? D_005721C0 : 1))
            self->active = 0;
    }
    return self;
}




