/*
 * Libs/SFOLib/Source/guiCanvas: 6 files, 00414F00-00415160
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiCanvas_414F00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct C_414F00 {
    VPAD4(p) VPAD1(q)
    virtual void Show();
    virtual void s6();
    virtual void Focus();
    virtual void Unfocus();
};
struct W_414F00;
struct LNode_414F00 { LNode_414F00* prev; LNode_414F00* next; W_414F00* value; };
union LIt_414F00 {
    LNode_414F00* node;
    W_414F00* Get() const { return node->value; }
    void Next() { node = node->next; }
    bool operator!=(const LIt_414F00& o) const { return node != o.node; }
};
struct List_414F00 { int size; LNode_414F00* first; LNode_414F00* head; };
struct W_414F00 {
    VPAD8(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual W_414F00* DefaultFocus();
    char pad4[0x10];
    unsigned short flags;
    short pri;
    char pad18[4];
    W_414F00* parent;
    W_414F00* focus;
    char pad24[4];
    List_414F00 children;
    char pad34[0x10];
    C_414F00* comp;
};
extern "C" {
void std_list_GuiWidgetPtr_begin(LIt_414F00* out, List_414F00* list);
void std_list_GuiWidgetPtr_end(LIt_414F00* out, List_414F00* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(LIt_414F00* out, LIt_414F00* in);
#if 0 /* merge_units */
void std_list_GuiWidgetPtr_generic_iterator_opCast(LIt_414F00* out, LIt_414F00* in);
#endif /* merge_units */
void std_list_GuiWidgetPtr_generic_iterator_opCast(Word* dst, Word* src); /* merge_units */
#define std_list_GuiWidgetPtr_generic_iterator_opCast(a0, a1) (std_list_GuiWidgetPtr_generic_iterator_opCast((Word *)(a0), (Word *)(a1))) /* merge_units */

LIt_414F00* std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(LIt_414F00* out, LIt_414F00* in);
void std_list_deleter_voidPtr_insert(LIt_414F00* out, List_414F00* list, LIt_414F00* pos, W_414F00** v);
int GuiWidget_SendMessage(W_414F00* a, W_414F00* b, int msg, int c, int d);
void GuiWidget_ClearSleepStatus(W_414F00* w);
void cJoystick_Debounce(void* p);
extern char D_0055A300[];
}

extern "C" void GuiCanvas_PushGui(W_414F00* o, W_414F00* w, int pri)
{
    LIt_414F00 it;
    LIt_414F00 first;
    LIt_414F00 last;
    LIt_414F00 pos;
    LIt_414F00 res;
    LIt_414F00 pos2;
    LIt_414F00 beginTmp;
    LIt_414F00 endTmp;
    LIt_414F00 pos3;

    if (w == 0 || (w->flags & 8)) return;
    std_list_GuiWidgetPtr_begin(&beginTmp, &o->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&first, &beginTmp);
    it = first;
    std_list_GuiWidgetPtr_end(&endTmp, &o->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endTmp);
    while (it.node != last.node) {
        if (pri < it.Get()->pri) break;
        it.Next();
        std_list_GuiWidgetPtr_end(&endTmp, &o->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endTmp);
    }
    if ((w->flags & 2) && GuiWidget_SendMessage(o, w, 0x10, 2, 0) == 0)
        GuiWidget_SendMessage(w, o, 0x10, 2, 0);
    w->parent = o;
    w->pri = pri;
    pos.node = it.node;
    std_list_GuiWidgetPtr_generic_iterator_opCast(&pos2, &pos);
    std_list_deleter_voidPtr_insert(&res, &o->children, std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos3, &pos2), &w);
    GuiWidget_ClearSleepStatus(w);
    w->comp->Show();
    GuiWidget_SendMessage(o, w, 0x18, 0, 0);
    if (o->children.size > 0 && o->children.first->value == w) {
        cJoystick_Debounce(D_0055A300);
        if (o->focus) o->focus->comp->Unfocus();
        o->focus = w->focus;
        if (o->focus == 0) o->focus = w->DefaultFocus();
        if (o->focus) o->focus->comp->Focus();
    }
}
#undef std_list_GuiWidgetPtr_generic_iterator_opCast /* merge_units */
static inline void merge_flush_GuiCanvas_414F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiCanvas_414F00 */

/* merge_units: begin func_00415160 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

void std_list_GuiWidgetPtr_generic_iterator_opCast(Word* dst, Word* src) {
    dst->value = src->value;
}
static inline void merge_flush_func_00415160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415160 */

/* merge_units: begin func_00415170 */
#pragma push /* merge_units */
#pragma cplusplus on

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
extern "C" void GuiWidget_SendParentsMessage(W_415170* w, int msg, int a, int b);

static inline bool IsPress_415170(Ev_415170* e) { return e->type == 1 && e->dev == 0 && e->action == 0; }

extern "C" int GuiCanvas_onInput(W_415170* o, Ev_415170* ev)
{
    if (IsPress_415170(ev)) {
        unsigned short k = ev->key;
        if (k == 0x1000 || k == 0x4000) {
            W_415170* n;
            if (o->on == 0 || o->focus == 0) return 0;
            if (k == 0x1000) n = o->h->root->Next(o->focus, 1);
            else n = o->h->root->Prev(o->focus, 1);
            if (n && n != o->focus) GuiWidget_SendParentsMessage(n, 0x10, 0, 0);
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
static inline void merge_flush_func_00415170(void) {} /* merge_units */
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
extern "C" void GuiCanvas_ProcessInputEvent(O_415310* o, void* arg)
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
static inline void merge_flush_func_00415310(void) {} /* merge_units */
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
extern "C" unsigned char cUSBKeybd_KeyToAscii(int c, int flags);
extern "C" unsigned char cUSBKeybd_GetAsciiKey(Kb_4153F0* k);
extern "C" int cUSBKeybd_Read(Kb_4153F0* k, int n);

extern "C" void GuiCanvas_ProcessInput_cUSBKeybdR(W_4153F0* w, Kb_4153F0* kb)
{
    while (cUSBKeybd_Read(kb, 1)) {
        int c = cUSBKeybd_GetAsciiKey(kb);
        if (c) {
            int f = kb->flags;
            KeyEv_4153F0 ev;
            ev.type = 2;
            ev.a = 0;
            ev.b = 1;
            ev.c = 0;
            ev.key = c;
            ev.flags = f;
            if (w->b52) ev.ch = cUSBKeybd_KeyToAscii(c, f);
            else ev.ch = c;
            w->Event(&ev);
        }
    }
}
static inline void merge_flush_func_004153F0(void) {} /* merge_units */
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
extern int g_TimerAccum;
extern long g_TickCounter64;
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

extern "C" void GuiCanvas_ProcessInput_cJoystickR(W_415510* w, Pad_415510* pads)
{
    int now;
    int p;
    now = DivTime(g_TickCounter64 + (int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f));
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
static inline void merge_flush_func_00415510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00415510 */
