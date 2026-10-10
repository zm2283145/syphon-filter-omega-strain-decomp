#include "types.h"
typedef struct { char d[0x9C]; } E4Str;
typedef struct {
    char pad0[0x48];
    E4Str s48;
    E4Str sE4;
    char pad180[0x10];
} __attribute__((aligned(16))) E4Req;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    E4Str s78;
    E4Str s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) E4Ev;
extern char D_0049D900[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern void SoundRequest_Ctor(E4Req* r, int a, char* b, int c, int d);
extern void SoundEvent_CtorFromPreset(E4Ev* e, E4Req* r, int preset);
extern void Event_Send(E4Ev* e, char* tgt, int n);
extern void func_0036E220(E4Str* s, int flag);
extern void cMessage_dtor(E4Ev* e, int flag);
void func_00188F00(int preset)
{
    E4Req req;
    E4Ev ev;
    SoundRequest_Ctor(&req, 0, D_0049D900, 0, 0);
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