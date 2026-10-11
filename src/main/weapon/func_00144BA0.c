#include "types.h"
typedef struct { void* vt; char pad[0x1C]; unsigned char flag; char pad21[0x57]; char m78[0x9C]; char m114[0xBC]; } Msg_4BA0;
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[0xAC]; } Req_4BA0;
typedef struct { char pad[0x88]; int src; char pad8C[0x38]; int snd[6]; } S_4BA0;
extern char D_004DADF0[];
extern char D_004FFB50[];
void SoundRequest_Ctor(Req_4BA0* r, int a, int id, int b, int c);
void func_0020EBA0(Msg_4BA0* m, Req_4BA0* r, int src);
void Event_Send(Msg_4BA0* m, void* target, int a);
void func_0036E220(void* p, int f);
void cMessage_dtor(Msg_4BA0* m, int f);
void func_00144BA0(S_4BA0* self, unsigned char slot)
{
    int* p = (int*)((char*)self->snd + (slot << 2));
    if (*p) {
        Req_4BA0 req;
        Msg_4BA0 msg;
        SoundRequest_Ctor(&req, 1, *p, 0, 0);
        func_0020EBA0(&msg, &req, self->src);
        msg.flag = 1;
        Event_Send(&msg, D_004FFB50, 0);
        *p = 0;
        msg.vt = D_004DADF0;
        func_0036E220(msg.m114, -1);
        func_0036E220(msg.m78, -1);
        cMessage_dtor(&msg, 0);
        func_0036E220(req.mE4, -1);
        func_0036E220(req.m48, -1);
    }
}