#include "SFOLobby.h"
typedef struct { char c[21]; } S21;
typedef struct { char c[256]; } S256;
typedef struct { char c[64]; } S64;
int func_0044EDC0();
int SFOLobby_NoInstance();
extern SFOLobby *D_00585E60;
typedef struct { S21 name; int a18, a1C, a20, a24, a28, a2C, a30; S256 s; S64 t; int b174, b178, b17C, b180, b184, b188; } R46B;
/* Reply callback: flags gotReply20C, forwards a successful record to func_0044EDC0
 * and keeps a copy in reply1D08. */
void func_00446B40(int d0, int d1, int d2, R46B *src) {
    if (SFOLobby_NoInstance() == 0) {
        R46B *d;
        D_00585E60->gotReply20C = 1;
        if (src->a18 == 0) {
            func_0044EDC0(D_00585E60, *(int *)((char *)src + 0x3C), src->a30, src->a24, src->b184, &src->s);
        }
        d = (R46B *)D_00585E60->reply1D08;
        d->name = src->name;
        d->a18 = src->a18;
        d->a1C = src->a1C;
        d->a20 = src->a20;
        d->a24 = src->a24;
        d->a28 = src->a28;
        d->a2C = src->a2C;
        d->a30 = src->a30;
        d->s = src->s;
        d->t = src->t;
        d->b174 = src->b174;
        d->b178 = src->b178;
        d->b17C = src->b17C;
        d->b180 = src->b180;
        d->b184 = src->b184;
        d->b188 = src->b188;
    }
}
