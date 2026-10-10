#include "types.h"
typedef struct G1Ev G1Ev;
typedef struct {
    char pad[0x50]; char state; char prevState; char pad2[0xE8 - 0x52]; void* anim;
    char pad3[0x1C4 - 0xEC]; unsigned char f1C4; unsigned char f1C5; unsigned char f1C6;
} G1Ob;
extern int* Event_GetType(G1Ev*);
extern int func_003CACA0(G1Ob*, G1Ev*);
extern int World_UpdateFrame(G1Ob*);
extern void func_0012EEE0(G1Ob*, int, int);
extern void func_0025E6E0(void*, int, float);
extern int D_005436B0;
extern int D_004F5398;
extern unsigned char D_005721C8;
int func_00136A90(G1Ob* o, G1Ev* e)
{
    int t;
    int handled = (unsigned char)func_003CACA0(o, e);
    t = *Event_GetType(e);
    if (t == D_005436B0) {
        return World_UpdateFrame(o) != 0 || handled != 0;
    }
    t = *Event_GetType(e);
    if (t == D_004F5398) {
        if ((unsigned char)o->state != 0x13 && (unsigned char)o->state != 0x14) {
            if (D_005721C8) func_0012EEE0(o, 0, 1);
            if (o->f1C4 && o->f1C5 && o->f1C6) {
                o->prevState = o->state;
                o->state = 0x14;
            } else {
                o->prevState = o->state;
                o->state = 0x13;
                func_0025E6E0(o->anim, 2, 1.0f);
            }
            return 1;
        }
    }
    return handled;
}