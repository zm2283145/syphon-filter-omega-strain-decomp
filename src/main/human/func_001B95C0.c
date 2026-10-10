#include "types.h"
typedef struct { char d[0x9C]; } F2Str;
typedef struct {
    char pad0[0x48];
    F2Str s48;
    F2Str sE4;
    char pad180[0x10];
} __attribute__((aligned(16))) F2Req;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    F2Str s78;
    F2Str s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) F2Ev;
typedef struct { char pad[0xC]; int preset; unsigned char kind; } F2Arg;
extern char D_0049D910[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern void SoundRequest_Ctor(F2Req* r, int a, char* b, int c, int d);
extern void SoundEvent_CtorFromPreset(F2Ev* e, F2Req* r, int preset);
extern void Event_Send(F2Ev* e, char* tgt, int n);
extern void func_0036E220(F2Str* s, int flag);
extern void cMessage_dtor(F2Ev* e, int flag);
extern void func_00188FB0(int preset, int a, int b);
static inline void Play_F2(int preset)
{
    F2Req req;
    F2Ev ev;
    SoundRequest_Ctor(&req, 1, D_0049D910, 0, 0);
    SoundEvent_CtorFromPreset(&ev, &req, preset);
    ev.flag = 1;
    Event_Send(&ev, D_004FFB50, 1);
    ev.vt = D_004DAE30;
    func_0036E220(&ev.s114, -1);
    func_0036E220(&ev.s78, -1);
    cMessage_dtor(&ev, 0);
    func_0036E220(&req.sE4, -1);
    func_0036E220(&req.s48, -1);
}
void func_001B95C0(F2Arg* a)
{
    switch (a->kind) {
    case 0:
        func_00188FB0(a->preset, 1, 1);
        break;
    case 1:
        Play_F2(a->preset);
        break;
    }
}