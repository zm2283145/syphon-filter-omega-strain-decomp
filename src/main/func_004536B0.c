#include "types.h"
typedef struct { char pad[0x255C]; int mode; } S4536B0;
extern unsigned char D_00585FB8;
extern int SFOLobby_Poll(S4536B0*, int, int, int);
extern void func_0044C420(S4536B0*);
extern void func_00442F30(S4536B0*);
extern void func_00445E60(S4536B0*);
extern void func_004516E0(S4536B0*);
extern void SFOLobby_UpdateContacts(S4536B0*);
extern void func_0044B180(S4536B0*);
extern void func_00442700(S4536B0*);
extern void func_0044E330(S4536B0*);
void func_004536B0(S4536B0* s) {
    if (D_00585FB8) return;
    D_00585FB8 = 1;
    if (s->mode != 0 && s->mode != 1) {
        if (!SFOLobby_Poll(s, 0, 0, 0)) {
            D_00585FB8 = 0;
            return;
        }
    }
    switch (s->mode) {
    case 1: func_0044C420(s); break;
    case 2: func_00442F30(s); break;
    case 3: func_00445E60(s); break;
    case 5: func_004516E0(s); break;
    case 6: SFOLobby_UpdateContacts(s); break;
    case 7: func_0044B180(s); break;
    case 4: func_00442700(s); break;
    case 10: func_0044E330(s); break;
    }
    D_00585FB8 = 0;
}