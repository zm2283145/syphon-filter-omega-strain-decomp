#include "types.h"
typedef struct { char pad[0x2C]; int count; char pad2[8]; int sel; int mode; } Menu27AA;
extern unsigned char D_00504040;
extern void func_0027B4E0(Menu27AA* s);
void func_0027AAA0(Menu27AA* s, int dir) {
    int n = 0;
    if (s->mode == 0) {
        if (D_00504040 || !s->count) return;
        n = 2;
    } else if (s->mode == 1) {
        n = s->count;
    }
    if (n) {
        if (dir) {
            s->sel++;
            if (s->sel >= n) s->sel = 0;
        } else {
            s->sel--;
            if (s->sel < 0) s->sel = n - 1;
        }
    }
    func_0027B4E0(s);
}
