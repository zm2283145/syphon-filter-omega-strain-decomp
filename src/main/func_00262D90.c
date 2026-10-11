#include "types.h"
typedef struct { char pad[8]; unsigned char state; } Obj262D;
extern void func_00264E10(Obj262D* s);
extern void func_00263890(Obj262D* s);
extern void func_00262E00(Obj262D* s);
void func_00262D90(Obj262D* s) {
    switch (s->state) {
    case 1: func_00264E10(s); break;
    case 2: func_00263890(s); break;
    case 3: func_00262E00(s); break;
    }
}