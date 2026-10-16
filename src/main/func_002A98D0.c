#pragma cplusplus on
#include "types.h"
struct Ev_002A98D0 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct S_002A98D0 { char pad0[0x98]; int f98; int f9C; };
extern "C" {
void func_002A96A0(S_002A98D0* self, int a);
void func_002A9A20(S_002A98D0* self);
int GuiScreen_HandleInput(S_002A98D0* self, Ev_002A98D0* ev);
}
static inline unsigned char Down_002A98D0(Ev_002A98D0* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_002A98D0(Ev_002A98D0* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_002A98D0(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_002A98D0(Ev_002A98D0* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_002A98D0(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int func_002A98D0(S_002A98D0* self, Ev_002A98D0* ev)
{
    if (Press_002A98D0(ev, 0x10)) {
        if (self->f98 == -1 && self->f9C != -1)
            func_002A9A20(self);
        else
            func_002A96A0(self, 1);
        return 1;
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x80 && ev->f6 == 0;
        if (b) {
            if (self->f9C == -1 || self->f9C == self->f98)
                func_002A96A0(self, 1);
            else
                func_002A9A20(self);
            return 1;
        }
    }
    return GuiScreen_HandleInput(self, ev);
}
