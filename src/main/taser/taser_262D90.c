#include "types.h"
typedef struct { char pad[8]; unsigned char state; } Obj262D;
extern void cAirTaser_UpdateShot(Obj262D* s);
extern void cAirTaser_UpdateShock(Obj262D* s);
extern void cAirTaser_UpdateRetract(Obj262D* s);
void cAirTaser_NextFrame(Obj262D* s) {
    switch (s->state) {
    case 1: cAirTaser_UpdateShot(s); break;
    case 2: cAirTaser_UpdateShock(s); break;
    case 3: cAirTaser_UpdateRetract(s); break;
    }
}