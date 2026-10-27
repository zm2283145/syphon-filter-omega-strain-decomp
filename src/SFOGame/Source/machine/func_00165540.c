#pragma cplusplus on
#include "types.h"
struct Kb_165540 { char pad[0x98]; int active; unsigned short code; };
struct Tog_165540 { char a; unsigned char on; };
struct Obj_165540 { char pad[0x2C]; Tog_165540 tog; };
extern "C" {
int cUSBKeybd_Read(Kb_165540* k, int n);
int cUSBKeybd_GetAsciiKey(Kb_165540* k);
void cConsole_Activate(Tog_165540* t);
void cConsole_Deactivate(Tog_165540* t);
extern Kb_165540 D_0055A700;
extern signed char g_GameState;
extern signed char g_PrevGameState;
}
static inline bool IsKey(Kb_165540* k, unsigned char c) { return k->active ? (unsigned char)cUSBKeybd_GetAsciiKey(k) == c : false; }
static inline bool IsCode(Kb_165540* k, int c) { return k->active ? k->code == c : false; }
extern "C" void cMachine_KeyboardHandler(Obj_165540* o) {
    Kb_165540* k = &D_0055A700;
    if (cUSBKeybd_Read(k, 1)) {
        if (IsKey(k, 0x60)) {
            if (!o->tog.on) cConsole_Activate(&o->tog); else cConsole_Deactivate(&o->tog);
        }
        if (IsCode(k, 0x402D)) {
            g_PrevGameState = g_GameState;
            g_GameState = 0x10;
        }
    }
}