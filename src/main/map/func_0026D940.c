#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_26D940 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct M_26D940 { int id; };
struct Hum_26D940 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_26D940* ctl; };
struct Node_26D940 { int f0; Node_26D940* next; M_26D940* id; };
struct Holder_26D940 { char pad[0x30]; Hum_26D940* x30; };
struct Self_26D940 { int* x0; };
struct Buf_26D940 { char b0; char text[0x8F]; };
extern "C" {
extern unsigned char D_005721C8;
extern int D_004FFC2C;
extern Holder_26D940* D_004FFC0C;
Hum_26D940* Object_LookupById(M_26D940* id);
void func_0016E880(int* out, int* list);
void func_0026C390(Node_26D940** out, int b);
void func_0026C320(int* out, int* list);
void func_0026C350(Node_26D940** out, int* e);
void func_002C9170(Buf_26D940* b, int key, int c);
void func_00242FA0(int a, M_26D940* m, char* text, int n, int b, int c, float f0, float f1);
void func_0026D940(Self_26D940* self);
}
static inline unsigned char IsPlayer_26D940(Hum_26D940* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_26D940(Hum_26D940* h) { int id; if (D_005721C8) { if (IsPlayer_26D940(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
static inline Node_26D940* Begin_26D940(int* list) { Node_26D940* n; int b; func_0016E880(&b, list); func_0026C390(&n, b); return n; }
static inline void End_26D940(Node_26D940** out, int* list) { int e; func_0026C320(&e, list); func_0026C350(out, &e); }

void func_0026D940(Self_26D940* self)
{
    int* list = self->x0 + 3;
    Hum_26D940* h;
    Node_26D940* end;
    for (Node_26D940* it = Begin_26D940(list); End_26D940(&end, list), it != end; it = it->next) {
        h = Object_LookupById(it->id);
        if (h && IsPlayer_26D940(h)) {
            int id = LocalId_26D940(h);
            if (id >= 0 && id < 4) {
                Buf_26D940 buf;
                buf.b0 = 0;
                func_002C9170(&buf, id, 1);
                func_00242FA0(D_004FFC2C, it->id, buf.text, 4, 1, 0, -1.0f, -1.0f);
            }
        }
    }
    Holder_26D940* hd = D_004FFC0C;
    if (hd) {
        h = hd->x30;
        if (h) {
            int id = LocalId_26D940(h);
            if (id >= 0 && id < 4) {
                Buf_26D940 buf;
                buf.b0 = 0;
                func_002C9170(&buf, id, 1);
                func_00242FA0(D_004FFC2C, (M_26D940*)&hd->x30->flags, buf.text, 4, 1, 0, -1.0f, -1.0f);
            }
        }
    }
}
