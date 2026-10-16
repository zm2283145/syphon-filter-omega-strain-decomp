/*
 * main/GuiCanvas: 5 files, 00415160-00415510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00415160 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

void func_00415160(Word* dst, Word* src) {
    dst->value = src->value;
}
#pragma pop /* merge_units */
/* merge_units: end func_00415160 */

/* merge_units: begin func_00415170 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

struct Ev_415170 { unsigned short type; unsigned short dev; unsigned short b; unsigned short action; unsigned short key; };
struct C_415170 {
    VPAD4(p) VPAD2(q) VPAD1(r)
    virtual void Focus();
    virtual void Unfocus();
};
struct W_415170;
struct R_415170 {
    VPAD16(p) VPAD1(q)
    virtual W_415170* Prev(W_415170* cur, int wrap);
    virtual W_415170* Next(W_415170* cur, int wrap);
};
struct H_415170 { char pad[8]; R_415170* root; };
struct W_415170 {
    void* vt;
    char pad[0x18];
    W_415170* parent;
    W_415170* focus;
    int f24;
    int on;
    H_415170* h;
    char pad30[0x14];
    C_415170* comp;
};
extern "C" void GuiWidget_SendEventUp(W_415170* w, int msg, int a, int b);

static inline bool IsPress_415170(Ev_415170* e) { return e->type == 1 && e->dev == 0 && e->action == 0; }

extern "C" int GuiCanvas_Navigate(W_415170* o, Ev_415170* ev)
{
    if (IsPress_415170(ev)) {
        unsigned short k = ev->key;
        if (k == 0x1000 || k == 0x4000) {
            W_415170* n;
            if (o->on == 0 || o->focus == 0) return 0;
            if (k == 0x1000) n = o->h->root->Next(o->focus, 1);
            else n = o->h->root->Prev(o->focus, 1);
            if (n && n != o->focus) GuiWidget_SendEventUp(n, 0x10, 0, 0);
            if (n != o->focus) {
                if (o->focus) o->focus->comp->Unfocus();
                o->focus = n;
                if (o->focus) {
                    o->focus->comp->Focus();
                    if (n == o->focus && n) {
                        do {
                            if (n == o) break;
                            n->focus = o->focus;
                            n = n->parent;
                        } while (n);
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00415170 */

/* merge_units: begin func_00415310 */
#pragma push /* merge_units */
#pragma cplusplus on
struct N_415310 {
    VPAD8(p) VPAD1(q)
    virtual unsigned char Handle(void* arg);
    char pad[0x18];
    N_415310* next;
    N_415310* child;
};
struct H_415310 { char pad[8]; N_415310* root; };
struct O_415310 {
    VPAD8(p) VPAD1(q)
    virtual unsigned char Handle(void* arg);
    char pad[0x24];
    int on;
    H_415310* h;
};
#pragma bool off
static inline int IsZero_415310(void* c) { return ((int)c != 0) ^ 1; }
#pragma opt_rotateloops off
extern "C" void GuiCanvas_DispatchInput(O_415310* o, void* arg)
{
    unsigned char r = 0;
    if (o->on) {
        N_415310* p = o->h->root;
        N_415310* n = p->child ? p->child : p;
        r = n->Handle(arg);
        if (!r) {
            for (n = n->next; !IsZero_415310(n) && !r; n = n->next)
                r = n->Handle(arg);
        }
    }
    if (!r) o->Handle(arg);
}
#pragma opt_rotateloops reset
#pragma bool reset
#pragma pop /* merge_units */
/* merge_units: end func_00415310 */

/* merge_units: begin func_004153F0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct KeyEv_4153F0 {
    short type;
    short a;
    short b;
    short c;
    short key;
    int flags;
    char ch;
};
struct Kb_4153F0 { char pad[0x94]; int flags; };
struct W_4153F0;
struct W_4153F0 {
    VPAD16(p) VPAD8(q) VPAD1(r)
    virtual void Event(KeyEv_4153F0* ev);
    char pad[0x4E];
    unsigned char b52;
};
extern "C" unsigned char UsbKbd_TranslateKey(int c, int flags);
extern "C" unsigned char UsbKbd_GetCode(Kb_4153F0* k);
extern "C" int UsbKbd_Poll(Kb_4153F0* k, int n);

extern "C" void GuiCanvas_KeyboardInput(W_4153F0* w, Kb_4153F0* kb)
{
    while (UsbKbd_Poll(kb, 1)) {
        int c = UsbKbd_GetCode(kb);
        if (c) {
            int f = kb->flags;
            KeyEv_4153F0 ev;
            ev.type = 2;
            ev.a = 0;
            ev.b = 1;
            ev.c = 0;
            ev.key = c;
            ev.flags = f;
            if (w->b52) ev.ch = UsbKbd_TranslateKey(c, f);
            else ev.ch = c;
            w->Event(&ev);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004153F0 */

/* merge_units: begin func_00415510 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Ev_415510 {
    short type;
    short pad;
    short a;
    short b;
    short button;
    short p0A;
    int p0C;
    short p10;
    short count;
};
struct Node_415510 { char pad[8]; int value; };
struct Pad_415510 { char pad[0x14C]; unsigned int cur; char pad150[8]; unsigned int prev; char pad15C[0x1C0 - 0x15C]; };
struct W_415510 {
    VPAD16(p) VPAD8(q) VPAD1(r)
    virtual void Event(Ev_415510* ev);
    char pad[0x24];
    int count;
    Node_415510* first;
    char pad30[0x38];
    unsigned int mask;
};
static unsigned int D_004940B0[16] = {
    0x1000, 0x4000, 0x8000, 0x2000, 0x10, 0x40, 0x80, 0x20,
    0x200, 0x400, 0x4, 0x1, 0x8, 0x2, 0x800, 0x100
};
extern int D_00533870;
extern long D_00533878;
extern int D_00571FD8;
extern int D_00571FE0[2][16];
extern int D_00572060[2][16];

static inline int DivTime(long n)
{
    int bit = 1 << 30;
    int q = 0;
    long d = 100;
    int i;
    d <<= 30;
    for (i = 0; i < 31; i++) {
        long r = n - d;
        if (r >= 0) {
            n = r;
            q += bit;
        }
        d >>= 1;
        bit >>= 1;
    }
    return q;
}

extern "C" void func_00415510(W_415510* w, Pad_415510* pads)
{
    int now;
    int p;
    now = DivTime(D_00533878 + (int)((float)(unsigned int)(*(volatile int*)0x10000800 + D_00533870) / 5.76f));
    for (p = 0; p < 2; p++) {
        int j;
        for (j = 0; j < 16; j++) {
            unsigned int m = D_004940B0[j];
            unsigned int cur = pads[p].cur;
            if ((m & cur) != (m & pads[p].prev)) {
                Ev_415510 ev;
                ev.type = 1;
                ev.pad = p;
                ev.a = 0;
                unsigned int bm = D_004940B0[j];
                bool rel = !(bm & cur);
                ev.b = rel;
                ev.button = D_004940B0[j];
                ev.count = 0;
                D_00571FD8 = w->count ? w->first->value : 0;
                D_00571FE0[p][j] = 0;
                D_00572060[p][j] = now;
                w->Event(&ev);
            } else if ((m & cur) && (w->mask & m) && w->count && D_00571FD8 == w->first->value) {
                int e = now - D_00572060[p][j] - 300;
                if (e >= 0) {
                    int c = D_00571FE0[p][j];
                    int n = c >= 4 ? (e - 600) / 75 + 5 : e / 150 + 1;
                    if (c < n) {
                        Ev_415510 ev;
                        ev.type = 1;
                        ev.pad = p;
                        ev.a = 0;
                        ev.b = 0;
                        ev.button = D_004940B0[j];
                        ev.count = D_00571FE0[p][j]++;
                        w->Event(&ev);
                    }
                }
            }
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00415510 */
