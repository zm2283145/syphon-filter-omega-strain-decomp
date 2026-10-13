#include "types.h"
typedef struct { char p0[0xE8]; int fE8; char pEC[0xF4 - 0xEC]; int fF4; char pF8[0x100 - 0xF8]; } R451B30;
typedef struct {
    char p0[0xAA4]; char fAA4[0x2C]; R451B30 room;
    char pBD0[0x2480 - 0xBD0]; int f2480; int f2484;
    char p2488[0x2590 - 0x2488]; int f2590;
} S451B30;
extern int D_00497830;
extern R451B30 D_00585E90;
extern int Lobby_GetTime(void);
extern unsigned char SFOLobby_RequestAccountInfo(S451B30*, int);
extern void func_004499A0(S451B30*);
extern void func_004505E0(S451B30*, R451B30*);
extern void SFOLobby_CacheAccount(S451B30*, int, char*, int, R451B30*);

void func_00451B30(S451B30* s)
{
    int dt;
    unsigned char ok;
    R451B30* room;

    dt = Lobby_GetTime() - s->f2590;
    if (D_00497830 < dt) {
        ok = SFOLobby_RequestAccountInfo(s, s->f2480);
        func_004499A0(s);
        room = ok ? &s->room : &D_00585E90;
        room->fE8 = s->f2484;
        func_004505E0(s, room);
        SFOLobby_CacheAccount(s, s->f2480, s->fAA4, room->fF4, room);
    }
}
