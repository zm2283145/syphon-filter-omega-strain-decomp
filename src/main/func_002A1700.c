#include "types.h"
typedef struct { char pad[0x1C]; } M2A1700;
typedef struct {
    char pad0[0x80];
    unsigned char active;
    char pad81[7];
    M2A1700 m88;
    M2A1700 mA4;
    M2A1700 mC0;
    char padDC[0xF8 - 0xDC];
    unsigned char hasFx;
} S2A1700;
extern void* func_004294C0(void);
extern void func_00451610(void* p);
extern void LobbyArray_Free(M2A1700* m);
void func_002A1700(S2A1700* s)
{
    if (s->active) {
        if (s->hasFx) {
            void* p = func_004294C0();
            if (p)
                func_00451610(p);
            s->hasFx = 0;
        }
        LobbyArray_Free(&s->m88);
        LobbyArray_Free(&s->mA4);
        LobbyArray_Free(&s->mC0);
        s->active = 0;
    }
}