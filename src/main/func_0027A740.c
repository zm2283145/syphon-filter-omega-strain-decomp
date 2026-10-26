#include "types.h"
typedef struct { char pad[0x3C]; int mode; char pad2[0x16]; unsigned char busy; } Menu27A7;
typedef struct { char pad[0x14C]; unsigned int pressed; char pad2[8]; unsigned int held; } Pad27A7;
extern void cHudNetLobby_NextButton(Menu27A7* s, int dir);
extern void cHudNetLobby_ButtonPressed(Menu27A7* s);
extern void cHudNetLobby_InitCurrentScreen(Menu27A7* s);
void cHudNetLobby_HandleInput(Menu27A7* s, Pad27A7* p) {
    unsigned int bits;
    if (s->busy) return;
    bits = p->pressed & ~p->held;
    if (bits & 0x1000) cHudNetLobby_NextButton(s, 0);
    if (bits & 0x4000) cHudNetLobby_NextButton(s, 1);
    if (bits & 0x40) cHudNetLobby_ButtonPressed(s);
    if (s->mode == 1 && (bits & 0x10)) {
        s->mode = 0;
        cHudNetLobby_InitCurrentScreen(s);
    }
}