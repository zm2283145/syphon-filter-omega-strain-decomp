#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_26C8D0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct Hum_26C8D0 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_26C8D0* ctl; };
struct G_26C8D0 { char pad[0x60]; unsigned char b60; };
struct S_26C8D0 { int f0; int f4; G_26C8D0** f8; };
struct M_26C8D0 { int id; char pad[0xC]; int f10; };
struct Buf_26C8D0 { char b0; char text[0x8F]; };
extern "C" {
extern unsigned char D_005721C8;
extern int D_004FFC2C;
Hum_26C8D0* Object_LookupById(M_26C8D0* id);
int func_00272AC0(int a);
void func_00272AD0(int a, M_26C8D0* m);
void func_0026C570(S_26C8D0* s);
void func_002C9170(Buf_26C8D0* b, int key, int c);
void func_00242FA0(int a, M_26C8D0* m, char* text, int n, int b, int c, float f0, float f1);
void func_0026C8D0(S_26C8D0* s, M_26C8D0* m);
}
static inline unsigned char IsPlayer_26C8D0(Hum_26C8D0* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_26C8D0(Hum_26C8D0* h) { int id; if (D_005721C8) { if (IsPlayer_26C8D0(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }

void func_0026C8D0(S_26C8D0* s, M_26C8D0* m)
{
    bool b = m->f10 == 1 || m->f10 == 2;
    if (b) {
        if (!func_00272AC0(s->f0)) {
            func_00272AD0(s->f0, m);
            func_0026C570(s);
        }
    } else if (m->f10 == 0 && (*s->f8)->b60) {
        Hum_26C8D0* h = Object_LookupById(m);
        if (h && IsPlayer_26C8D0(h)) {
            int id = LocalId_26C8D0(h);
            if (id >= 0 && id < 4) {
                Buf_26C8D0 buf;
                buf.b0 = 0;
                func_002C9170(&buf, id, 1);
                func_00242FA0(D_004FFC2C, m, buf.text, 4, 1, 0, -1.0f, -1.0f);
            }
        }
    }
}