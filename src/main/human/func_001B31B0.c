#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct { char d[0x9C]; } Str;
struct Snd {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str s78;
    Str s114;
    char pad1B0[0x10];
} __attribute__((aligned(16)));
struct Snd2 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str s78;
    Str s114;
    char pad1B0[0x20];
} __attribute__((aligned(16)));
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Act {
    char pad0[0x14];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Vis* p58;
    char pad5C[0x33B9 - 0x5C];
    unsigned char b33B9;
    char pad33BA[0x346E - 0x33BA];
    unsigned char b346E;
    unsigned char b346F;
    signed char b3470;
};
extern "C" {
extern char D_004F1FD0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern void* D_004FFC30;
extern void* D_004FFC2C;
extern unsigned char D_0053B540;
void SoundEvent_CtorFromPreset(Snd* e, void* r, void* owner);
void func_0020EBA0(Snd2* e, void* r, void* owner);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void func_0036E220(Str* s, int flag);
void func_002609E0(void*, int, int);
void func_00241E30(void*, int);
}
extern "C" void Actor_UpdateNightVisionBlind(Act* a)
{
    signed char v = 0;
    unsigned char s;
    if (a->b346F) v = *(signed char*)&a->b346F;
    else if (a->b346E) v = *(signed char*)&a->b346E;
    s = v;
    if (s != (unsigned char)a->b3470) {
        a->b3470 = v;
        if (a->b14) {
            bool ok = 0;
            if (a->p58 && a->p58->IsOn()) ok = 1;
            if (ok) {
                int m = 0;
                switch (s) {
                case 1: m = 1; break;
                case 2: m = 2; break;
                case 3: m = 3; break;
                }
                func_002609E0(D_004FFC30, m, 0);
                func_00241E30(D_004FFC2C, s == 1);
                D_0053B540 = s == 1;
            }
        }
    }
    if (s == 2) {
        if (!a->b33B9) {
            Snd ev;
            SoundEvent_CtorFromPreset(&ev, D_004F1FD0, a);
            ev.flag = 1;
            Event_Send(&ev, D_004FFB50, 0);
            a->b33B9 = 1;
            ev.vt = D_004DAE30;
            func_0036E220(&ev.s114, -1);
            func_0036E220(&ev.s78, -1);
            cMessage_dtor(&ev, 0);
        }
    } else if (a->b33B9) {
        Snd2 ev;
        func_0020EBA0(&ev, D_004F1FD0, a);
        ev.flag = 1;
        Event_Send(&ev, D_004FFB50, 0);
        a->b33B9 = 0;
        ev.vt = D_004DADF0;
        func_0036E220(&ev.s114, -1);
        func_0036E220(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
}





