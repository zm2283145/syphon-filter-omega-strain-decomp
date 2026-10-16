#pragma cplusplus on
#include "types.h"
struct Kb_165540 { char pad[0x98]; int active; unsigned short code; };
struct Tog_165540 { char a; unsigned char on; };
struct Obj_165540 { char pad[0x2C]; Tog_165540 tog; };
extern "C" {
int UsbKbd_Poll(Kb_165540* k, int n);
int UsbKbd_GetCode(Kb_165540* k);
void func_003E7CF0(Tog_165540* t);
void func_003E7CD0(Tog_165540* t);
extern Kb_165540 D_0055A700;
extern signed char D_004FFBA0;
extern signed char D_004FFBA1;
}
static inline bool IsKey(Kb_165540* k, unsigned char c) { return k->active ? (unsigned char)UsbKbd_GetCode(k) == c : false; }
static inline bool IsCode(Kb_165540* k, int c) { return k->active ? k->code == c : false; }
extern "C" void func_00165540(Obj_165540* o) {
    Kb_165540* k = &D_0055A700;
    if (UsbKbd_Poll(k, 1)) {
        if (IsKey(k, 0x60)) {
            if (!o->tog.on) func_003E7CF0(&o->tog); else func_003E7CD0(&o->tog);
        }
        if (IsCode(k, 0x402D)) {
            D_004FFBA1 = D_004FFBA0;
            D_004FFBA0 = 0x10;
        }
    }
}