/*
 * main/guiWidget: 8 files, 0041E560-0041F090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041E560 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& s) { __int128* pd = (__int128*)this; const __int128* ps = (const __int128*)&s; *pd = *ps; }
    V4& operator=(const V4& s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&s) : "memory"); void* xx = this; /* dead on purpose: retail keeps this addiu */ return *this; }
} __attribute__((aligned(16)));
typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Slot { V4 color; char pad10[0x105 - 0x10]; char b105; char b106; char pad107[0x110 - 0x107]; } Slot;
typedef struct Ent { char pad[0x28]; char* pos; char* c2C; char* c30; char* c34; } Ent;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
typedef struct Widget { char pad[0x34]; float x, y, w, h; } Widget;

extern "C" {
extern char D_005381F0[];
extern long long D_005381F8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern float D_00539170[4];
extern int D_00539210;
extern int D_00539224;
extern int D_00539228;
extern int D_00539238;
extern int D_0053923C;
extern int D_005392D0;
void func_0025CD10(char* r);
void func_0025CA40(char* r);
void Vec4_Copy(void* d, V4* s);
int* GuiBatch_AddVertexColor(void* out, V4* in);
void func_003701B0(char* r);
}

#define SlotAt(i) ((Slot*)(D_005381F0 + 0x1F0 + (i) * 0x110))
#define EntAt(i) ((Ent*)(D_005381F0 + 0xFB0 + (i) * 0x38))
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

static inline V4 Pt(float x, float y) { return V4(x, y, 1.0f, 0.0f); }

static inline void Vertex(V4* p, V4* c) {
    Ent* e;
    func_0025CA40(D_005381F0);
    e = EntAt(D_00539210);
    Vec4_Copy(e->pos + (D_00539224 - 1) * 16, p);
    GuiBatch_AddVertexColor(e->c30 + (D_00539224 - 1) * 16, c);
    D_005381F8 = 0x200000000LL;
}

extern "C" void GuiWidget_DrawFocusHighlight(Widget* self, V4* colorp)
{
    V4 color = *colorp;
    int save = D_005392D0;
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_005392D0 = 0;
    V4 p[4];
    {
        int i;
        Slot* s;
        float* v;
        v = D_00539170;
        i = D_00538C60;
        D_00538C68 = 1;
        s = SlotAt(i);
        s->color.x = v[0];
        s->color.y = v[1];
        s->color.z = v[2];
        s->color.w = v[3];
        s->b105 = 1;
        s->b106 = 1;
    }
    {
        p[0] = Pt(self->x, self->y);
        p[1] = Pt(self->x + self->w, self->y);
        p[2] = Pt(self->x + self->w, self->y - self->h);
        p[3] = Pt(self->x, self->y - self->h);
        { unsigned char t; if (D_005392D0 & 1) t = 3; else t = 2; D_00539238 = t; }
        { int m; if (D_005392D0 & 1) m = 0x41; else m = 0x62; D_0053923C = m; }
        D_00539228 = 0;
        {
            int m = D_0053923C;
            Ent* e;
            D_0053923C = m & ~1;
            e = EntAt(D_00539210);
            e->pos += D_00539224 * 16;
            e->c2C += D_00539224 * 16;
            e->c30 += D_00539224 * 16;
            e->c34 += D_00539224 * 16;
            func_0025CD10(D_005381F0);
            D_00539224 = 0;
        }
        Vertex(&p[0], &color);
        Vertex(&p[1], &color);
        Vertex(&p[2], &color);
        Vertex(&p[3], &color);
        Vertex(&p[0], &color);
        func_003701B0(D_005381F0);
    }
    D_005392D0 = save;
    D_00538C68 = 1;
    D_00538C64--;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041E560 */

/* merge_units: begin func_0041EB70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Quad* func_0041EB70(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041EB70 */

/* merge_units: begin func_0041EBA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct W41EBA0;
struct H41EBA0 { VPAD8(a) VPAD4(b) VPAD1(c) virtual void OnEvent(W41EBA0* w, int kind, int x, int y); };
struct W41EBA0 { char pad[0x34]; float x; float y; char p3C[8]; H41EBA0* handler; };
extern "C" void GuiWidget_SetPos(W41EBA0* w, float x, float y)
{
    w->x = x;
    w->y = y;
    if (w) w->handler->OnEvent(w, 0x12, (int)x, (int)y);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041EBA0 */

/* merge_units: begin func_0041EBF0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void List_Begin(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
void GuiWidget_CheckSleep(TraversalWidget* self);
}

static inline unsigned char notify(TraversalWidget* receiver, TraversalWidget* sender,
                                  int message)
{
    if (receiver)
        return receiver->handler->on_message(sender, message, 0, 0);
    return 0;
}

/* Propagate the requested state to children, then check for completion. */
extern "C" void GuiWidget_BaseSleep(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (self->flags & 8) {
        self->flags |= 0x10;
        int requested = (notify(self, self, 15) != 0) ^ 1;
        if (requested)
            self->flags |= 8;
        else
            self->flags &= ~8;
        List_Begin(&rawBegin, &self->children);
        func_0028C0B0(&begin, &rawBegin);
        ChildNode* node = begin.node;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
        while (node != end.node) {
            node->widget->handler->propagate_state();
            node = node->next;
            func_0028C0A0(&rawEnd, &self->children);
            func_0028C090(&end, &rawEnd);
        }
        GuiWidget_CheckSleep(self);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0041EBF0 */

/* merge_units: begin func_0041ED20 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_lifetimes off
#pragma opt_propagation off

extern "C" {
}

/* Once every child accepts the completion message, clear pending and notify the parent. */
extern "C" void GuiWidget_CheckSleep(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if ((self->flags & 0x10) && !(self->flags & 8)) {
        List_Begin(&rawBegin, &self->children);
        func_0028C0B0(&begin, &rawBegin);
        ChildNode* node = begin.node;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
        ChildNode* e = end.node;
        if (node != e) do {
            if (!notify(node->widget, self, 15)) return;
            node = node->next;
            func_0028C0A0(&rawEnd, &self->children);
            func_0028C090(&end, &rawEnd);
            e = end.node;
        } while (node != e);
        self->flags &= ~0x10;
        notify(self->parent, self, 3);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0041ED20 */

/* merge_units: begin func_0041EE50 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void* Gui_GetScreenList(void);
void GuiManager_ReleaseRoot(void* manager, TraversalWidget* widget);
}

/* Clear pending and requested state throughout the live child hierarchy. */
extern "C" void GuiWidget_ClearAwake(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    self->flags &= ~0x10;
    self->flags &= ~8;
    List_Begin(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        GuiWidget_ClearAwake(node->widget);
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
}

/* Handle state completion and flagged removal requests; reject other messages. */
extern "C" int GuiWidget_OnEvent(TraversalWidget* self, TraversalWidget* sender, int message)
{
    switch ((unsigned short)message) {
    case 15:
        self->flags &= ~8;
        return 1;
    case 25:
        if (self->flags & 0x20) {
            GuiManager_ReleaseRoot(Gui_GetScreenList(), self);
            return 1;
        }
        break;
    }
    return 0;
}

/* Request state on every child only when the parent was not already requested. */
extern "C" void GuiWidget_BaseWake(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (!(self->flags & 8)) {
        self->flags |= 8;
        List_Begin(&rawBegin, &self->children);
        func_0028C0B0(&begin, &rawBegin);
        ChildNode* node = begin.node;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
        while (node != end.node) {
            node->widget->handler->request_state();
            node = node->next;
            func_0028C0A0(&rawEnd, &self->children);
            func_0028C090(&end, &rawEnd);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0041EE50 */

/* merge_units: begin func_0041F070 */
#pragma push /* merge_units */
#include "loose04_types.h"

/* Clears GuiWidget flag bit 2. */
void GuiWidget_ClearFlag4(GuiWidget* self) {
    unsigned int flags;

    flags = self->flags; /* zero-extended load keeps the match */
    self->flags = flags & 65531;
}

/* Sets GuiWidget flag bit 2. */
void GuiWidget_SetFlag4(GuiWidget* self) {
    unsigned int flags;

    flags = self->flags;
    self->flags = flags | 4;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041F070 */

/* merge_units: begin func_0041F090 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
}

/* Clear the registration flag and notify every child in live list order. */
extern "C" void GuiWidget_Deinit(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    self->flags &= ~1;
    List_Begin(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        node->widget->handler->on_unregistered();
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0041F090 */
