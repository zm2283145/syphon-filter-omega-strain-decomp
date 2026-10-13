#pragma cplusplus on
#include "types.h"
struct Ev_00299B90 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct W_00299B90 { char pad0[0x10]; int f10; unsigned short flags; char pad16[0x4E]; int x64; };
struct Ui_00299B90 { char pad[0x20]; W_00299B90* f20; };
struct S_00299B90 {
    char pad0[0x1C]; Ui_00299B90* x1C; char pad20[0x84 - 0x20]; W_00299B90* p84;
    char pad88[0xB8 - 0x88]; char xB8[0xC]; float fC4; char padC8[0x270 - 0xC8];
    char action[0x400 - 0x270]; unsigned char b400; char pad401[0x41C - 0x401]; W_00299B90* p41C;
};
extern "C" {
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
} SoundMsg;
typedef struct SoundEventMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
    char pad1C0[0x10];
} SoundEventMsg;
extern char* D_0048B908;
extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
Ui_00299B90* Gui_GetScreenStack(void);
void func_00299800(S_00299B90* self);
void func_00299780(S_00299B90* self);
void func_002998B0(S_00299B90* self);
void func_0029AD10(S_00299B90* self, int a);
void func_00456100(S_00299B90* self);
void func_0045A3A0(void* p, int n);
void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
void SoundEvent_Ctor(SoundEventMsg* msg, void* action, int flags);
void Event_Send(void* msg, void* target, int flags);
void func_0036E220(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
void SoundMsg_WrapAction(SoundMsg* msg, void* action);
}
static inline unsigned char Down_00299B90(Ev_00299B90* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_00299B90(Ev_00299B90* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_00299B90(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_00299B90(Ev_00299B90* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_00299B90(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
static inline bool Held_00299B90(Ev_00299B90* e, unsigned int b)
{
    return e->type == 1 && e->f2 == 0 && e->btn == b && e->f6 == 1;
}
/* Options page input handler: back/confirm/select buttons, gamma slider sound preview, default fallback. */
extern "C" int func_00299B90(S_00299B90* self, Ev_00299B90* ev)
{
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x10 && ev->f6 == 0;
        if (b) {
            if (!Gui_GetScreenStack()->f20 || Gui_GetScreenStack()->f20->f10 != -1) {
                func_0029AD10(self, 0);
                if (self->x1C == Gui_GetScreenStack()) {
                    func_00299780(self);
                    return 1;
                }
            } else {
                func_00299800(self);
                return 1;
            }
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
        if (b && Gui_GetScreenStack()->f20->f10 != -1) {
            func_002998B0(self);
            return 1;
        }
    }
    if (Press_00299B90(ev, 0x80)) {
        if (self->b400 && self->p84 && (self->p84->flags & 2))
            return 1;
        func_0029AD10(self, 1);
        return 1;
    }
    {
        if (Held_00299B90(ev, 0x8000) || Held_00299B90(ev, 0x2000)) {
            W_00299B90* w;
            if (Gui_GetScreenStack()->f20 == (w = self->p41C)) {
                SoundEventMsg evm;
                SoundMsg play;
                SoundRequest req;
                self->fC4 = w->x64 / 100.0f;
                func_0045A3A0(self->xB8, 0x20);
                SoundRequest_Ctor(&req, 4, D_0048B908, 0, 0);
                SoundEvent_Ctor(&evm, &req, 0);
                func_0036E220(req.partB, -1);
                func_0036E220(req.partA, -1);
                evm.flag = 1;
                Event_Send(&evm, D_004FFB50, 1);
                SoundAction_CtorVoice(self->action, 4, D_0048B908, 0, 0);
                SoundMsg_WrapAction(&play, self->action);
                play.flag = 1;
                Event_Send(&play, D_004FFB50, 1);
                play.vtbl = D_004DAE10;
                func_0036E220(play.partB, -1);
                func_0036E220(play.partA, -1);
                cMessage_dtor(&play, 0);
                evm.vtbl = D_004DADF0;
                func_0036E220(evm.partB, -1);
                func_0036E220(evm.partA, -1);
                cMessage_dtor(&evm, 0);
                return 1;
            }
        }
    }
    if (Press_00299B90(ev, 0x8000))
        return 1;
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x800 && ev->f6 == 0;
        if (b && self->b400) {
            func_00456100(self);
            return 1;
        }
    }
    return 0;
}
