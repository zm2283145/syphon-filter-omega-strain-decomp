#pragma cplusplus on
#include "types.h"
typedef struct { char d[0x9C]; } Str_00186360;
struct Req_00186360 { char pad0[0x48]; Str_00186360 s48; Str_00186360 sE4; char pad180[0x10]; };
struct Snd_00186360 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00186360 s78;
    Str_00186360 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16)));
struct Snd2_00186360 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00186360 s78;
    Str_00186360 s114;
    char pad1B0[0x20];
} __attribute__((aligned(16)));
struct Msg_00186360 { void* vt; char pad4[0x18]; int f1C; unsigned char b20; char pad21[3]; int kind; unsigned char b28; char pad29[3]; int id; int on; };
struct Obj_00186360 { char pad[0xC]; int id; };
struct Npc_00186360 {
    char pad0[0x31F4]; float f31F4; char pad31F8[0x326A - 0x31F8]; unsigned char b326A;
    char pad326B[0x33A4 - 0x326B]; unsigned char b33A4; char pad33A5[0x33B8 - 0x33A5]; unsigned char b33B8;
    char pad33B9[0x3480 - 0x33B9]; Obj_00186360* p3480; int id3484; unsigned char b3488;
};
extern "C" {
extern char D_0049D8E0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern char D_0055D480[];
extern char D_004E0180[];
extern char D_004E0840[];
extern unsigned char D_005721C8;
void func_00185D40(Npc_00186360* self, int a, int b, float f);
void SoundRequest_Ctor(Req_00186360* r, int a, char* name, int b, int c);
void SoundEvent_CtorFromPreset(Snd_00186360* e, Req_00186360* r, void* owner);
void func_0020EBA0(Snd2_00186360* e, Req_00186360* r, void* owner);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void func_0036E220(Str_00186360* s, int flag);
}
static inline int GetId_00186360(Obj_00186360* o, int& t)
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
extern "C" void func_00186360(Npc_00186360* self, unsigned char on, Obj_00186360* obj, unsigned char a3, int quiet, float f)
{
    int t2;
    int t1;
    unsigned char old = self->b326A;
    if (self->b33B8 || self->b33A4)
        self->b326A = 0;
    else
        self->b326A = on;
    if (!old && self->b326A) {
        func_00185D40(self, 0, 1, 0.4f);
        func_00185D40(self, 1, 1, 0.4f);
        self->f31F4 = f;
        self->p3480 = obj;
        self->id3484 = GetId_00186360(obj, t1);
        self->b3488 = a3;
        {
            Req_00186360 req;
            Snd_00186360 ev;
            SoundRequest_Ctor(&req, 1, D_0049D8E0, 0, 0);
            SoundEvent_CtorFromPreset(&ev, &req, self);
            ev.flag = 1;
            Event_Send(&ev, D_004FFB50, 0);
            ev.vt = D_004DAE30;
            func_0036E220(&ev.s114, -1);
            func_0036E220(&ev.s78, -1);
            cMessage_dtor(&ev, 0);
            func_0036E220(&req.sE4, -1);
            func_0036E220(&req.s48, -1);
        }
    } else if (!self->b326A) {
        func_00185D40(self, 0, 0, 1.0f);
        func_00185D40(self, 1, 0, 1.0f);
        {
            Req_00186360 req;
            Snd2_00186360 ev;
            SoundRequest_Ctor(&req, 1, D_0049D8E0, 0, 0);
            func_0020EBA0(&ev, &req, self);
            ev.flag = 1;
            Event_Send(&ev, D_004FFB50, 0);
            ev.vt = D_004DADF0;
            func_0036E220(&ev.s114, -1);
            func_0036E220(&ev.s78, -1);
            cMessage_dtor(&ev, 0);
            func_0036E220(&req.sE4, -1);
            func_0036E220(&req.s48, -1);
        }
    }
    if (D_005721C8 && !quiet) {
        int id = GetId_00186360(obj, t2);
        int st = self->b326A;
        Msg_00186360 m;
        Event_Construct(&m, D_0055D480);
        m.kind = 0x44;
        m.b28 = 6;
        m.id = id;
        m.on = st;
        m.vt = D_004E0180;
        m.b20 = 4;
        m.f1C = 0x40;
        Event_Send(&m, self, 0);
        m.vt = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}