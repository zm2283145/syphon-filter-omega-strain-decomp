#include "types.h"
typedef struct { char p0[0xE8]; int fE8; char pEC[0xF4 - 0xEC]; int fF4; char pF8[0x100 - 0xF8]; } R451B30;
typedef struct {
    char p0[0xAA4]; char fAA4[0x2C]; R451B30 room;
    char pBD0[0x2480 - 0xBD0]; int f2480; int f2484;
    char p2488[0x2590 - 0x2488]; int f2590;
} S451B30;
extern int D_00497830;
extern R451B30 D_00585E90;
extern int func_00443E70(void);
extern unsigned char func_00451200(S451B30*, int);
extern void func_004499A0(S451B30*);
extern void func_004505E0(S451B30*, R451B30*);
extern void func_00450880(S451B30*, int, char*, int, R451B30*);

void func_00451B30(S451B30* s)
{
    int dt;
    unsigned char ok;
    R451B30* room;

    dt = func_00443E70() - s->f2590;
    if (D_00497830 < dt) {
        ok = func_00451200(s, s->f2480);
        func_004499A0(s);
        room = ok ? &s->room : &D_00585E90;
        room->fE8 = s->f2484;
        func_004505E0(s, room);
        func_00450880(s, s->f2480, s->fAA4, room->fF4, room);
    }
}
