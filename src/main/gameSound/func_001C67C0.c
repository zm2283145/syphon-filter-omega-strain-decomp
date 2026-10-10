#include "types.h"
typedef struct { char pad[0x48]; char a[0x9C]; char b[0xA2]; unsigned char play; char pad2[9]; } E2SoundReq;
typedef struct { void* vtbl; char pad[0x74]; char a[0x9C]; char b[0xAC]; } E2SoundMsg;
extern void SoundRequest_Ctor(E2SoundReq*, int, char*, int, int);
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004FFB50[];
extern char D_004DAE10[];
extern void SoundMsg_WrapAction(E2SoundMsg*, E2SoundReq*);
extern void Event_Send(E2SoundMsg*, void*, int);
extern void func_0036E220(void*, int);
extern void cMessage_dtor(E2SoundMsg*, int);
void Voice_PlayQuip(char* name, int arg) {
    E2SoundReq req;
    E2SoundMsg msg;
    int ok;
    if (name == 0 || *name == 0) return;
    SoundRequest_Ctor(&req, 4, name, 0, arg);
    req.play = 1;
    ok = D_005721C8 ? D_005721C0 : 1;
    if (ok) {
        SoundMsg_WrapAction(&msg, &req);
        Event_Send(&msg, D_004FFB50, 0);
        msg.vtbl = D_004DAE10;
        func_0036E220(msg.b, -1);
        func_0036E220(msg.a, -1);
        cMessage_dtor(&msg, 0);
    }
    func_0036E220(req.b, -1);
    func_0036E220(req.a, -1);
}