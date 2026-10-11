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
extern void func_0044F6B0(M2A1700* m);
void func_002A1700(S2A1700* s)
{
    if (s->active) {
        if (s->hasFx) {
            void* p = func_004294C0();
            if (p)
                func_00451610(p);
            s->hasFx = 0;
        }
        func_0044F6B0(&s->m88);
        func_0044F6B0(&s->mA4);
        func_0044F6B0(&s->mC0);
        s->active = 0;
    }
}