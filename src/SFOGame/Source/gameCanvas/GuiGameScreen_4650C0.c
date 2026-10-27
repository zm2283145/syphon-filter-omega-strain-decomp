#pragma cplusplus on
#include "types.h"
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; char padA[8]; unsigned short f12; } Ev_4650C0;
typedef struct { char pad[0x6C]; unsigned char b6C; } O_4650C0;
extern "C" {
unsigned char func_004651F0(O_4650C0* o);
void func_00465A40(O_4650C0* o, Ev_4650C0* e);
void GuiGameCanvas_DispatchInput(O_4650C0* o, Ev_4650C0* e);
}
static inline unsigned char Down_4650C0(Ev_4650C0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_4650C0(Ev_4650C0* e, int b) { unsigned char r = 0; if (Down_4650C0(e) && e->btn == b) r = 1; return r; }
static inline bool Down2_4650C0(Ev_4650C0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Plain2_4650C0(Ev_4650C0* e) { return Down2_4650C0(e) && e->b6 == 0; }
static inline bool Btn2_4650C0(Ev_4650C0* e, int b) { return Down2_4650C0(e) && e->btn == b; }

extern "C" void GuiGameCanvas_DispatchInput(O_4650C0* o, Ev_4650C0* e)
{
    if (!Btn_4650C0(e, 0x200)) {
        if (Btn2_4650C0(e, 0x1000) && func_004651F0(o) && e->f12 == 0) {
            if (Plain2_4650C0(e)) o->b6C = 1;
            else o->b6C = 0;
        }
    }
    func_00465A40(o, e);
}

