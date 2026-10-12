#include "types.h"
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_45D420;
typedef struct { char pad[0x90]; int f90; int f94; int f98; unsigned char b9C; char pad9D[0xD4 - 0x9D]; int fD4; } O_45D420;
int func_0045BD00(O_45D420* o);
void func_0045BF80(O_45D420* o);
unsigned long long func_003698B0(void);
void func_0045C540(O_45D420* o, int v);
void func_0045C480(O_45D420* o);
void func_0045CA20(O_45D420* o, int on);
static inline unsigned char Down_45D420(Ev_45D420* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_45D420(Ev_45D420* e, int b) { unsigned char r = 0; if (Down_45D420(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Shift_45D420(Ev_45D420* e, int b) { unsigned char r = 0; if (Btn_45D420(e, b) && e->b6 == 1) r = 1; return r; }
static inline int Down2_45D420(Ev_45D420* e) { return e->type == 1 && e->b2 == 0; }
static inline int Btn2_45D420(Ev_45D420* e, int b) { return Down2_45D420(e) && e->btn == b; }
static inline int Plain2_45D420(Ev_45D420* e, int b) { return Btn2_45D420(e, b) && e->b6 == 0; }

int func_0045D420(O_45D420* o, Ev_45D420* ev)
{
    if (Plain2_45D420(ev, 0x10) && func_0045BD00(o)) {
        func_0045BF80(o);
        return 1;
    }
    if (o->fD4 == 1) {
    if (Shift_45D420(ev, 0x100)) {
        if (!o->b9C && o->f94 == o->f90 && func_003698B0() - o->f98 < 100) func_0045C540(o, 1);
        func_0045C480(o);
        func_0045CA20(o, 0);
        return 1;
    }
    if (Plain2_45D420(ev, 8) || Plain2_45D420(ev, 2)) {
        func_0045C540(o, 0);
        return 1;
    }
    if (Plain2_45D420(ev, 4) || Plain2_45D420(ev, 1)) {
        func_0045C540(o, 1);
        return 1;
    }
    }
    return 0;
}