/*
 * SFOGame/Source/GuiNetMessages: 8 files, 00348500-003488E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00348500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiNetMessages.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

Quad* func_00348500(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}
static inline void merge_flush_func_00348500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00348500 */

/* merge_units: begin func_00348530 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
/* GuiNetMessageArray_onElementRender: GuiNetMessages list cell draw: column 0 places the type
 * icon widget, columns 1/3 draw the message text / localised type name in
 * the type colour. The helpers are the inlined GuiNetMessageArray_GetMessageDescription (type name),
 * GuiNetMessageArray_GetMessageIcon (icon widget) and GuiNetMessageArray_GetMessageColor (colour) of
 * GuiNetMessages_3488E0.c. */
#pragma opt_rebuildconditionals off

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
struct Icon { VPAD8(a) VPAD2(b) virtual void Show(); };
struct IconW { char pad0[0x3C]; float w; float h; Icon* icon; };
struct Text { int x, y, w, h; unsigned char f10; char pad11[0x58 - 0x11]; unsigned char f58; char pad59[2]; unsigned char f5B; };
struct Msg { int type; char pad4[8]; char text[1]; };
struct Arr { int pad0; unsigned int count; };
struct Self { char pad0[0x94]; IconW* iconDef; IconW* iconSys; IconW* iconChat; Text* text; Arr* msgs; char name[0xC]; };

extern "C" {
extern char g_Video[];
extern int D_00538C64;
extern char D_00538C68;
extern char D_004BA3B8[];
extern char D_004BA338[];
extern char D_00587BF0[];
extern char D_00587C00[];
extern char D_00587C10[];
int sprintf(void*, const void*, ...);
char* nGlobalization_GetString_charP(char* key);
void GuiArrayWidget_onElementRender(Self* self, int col, unsigned int row, float* r);
Msg* SFOLobbyList_GetSlot(Arr* a, unsigned int i);
void GuiWidget_SetPosition(IconW* w, float x, float y);
void cTextArea_SetColor(Text* c, void* p);
char* std_basic_string_char_char_traits_char_c_str(void* s);
void cTextArea_SetText(Text* c, char* text);
void TextObj_Draw(Text* c);
void GuiNetMessageArray_onElementRender(Self* self, int col, unsigned int row, float* r);
}

static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

static inline void SetPos(Text* c, int x, int y) { c->x = x; c->y = y; }
static inline void SetSize(Text* c, int w, int h) { c->w = w; c->h = h; }
static inline void SetF58(Text* c, unsigned char v) { c->f58 = v; }
static inline void SetF10(Text* c, unsigned char v) { c->f10 = v; }
static inline void SetF5B(Text* c, unsigned char v) { c->f5B = v; }
static inline char* TypeName(Self* self, int n)
{
    char buf[16];
    char* t;
    if (n < 0 || (unsigned int)n >= 12) return 0;
    sprintf(buf, D_004BA3B8, n);
    t = nGlobalization_GetString_charP(buf);
    if (!t) return D_004BA338;
    return t;
}
static inline IconW* TypeIcon(Self* o, int k)
{
    switch (k) {
    case 9:
        return o->iconSys;
    case 0:
    case 1:
        return o->iconChat;
    default:
        return o->iconDef;
    }
}
static inline char* TypeColour(Self* self, int k)
{
    switch (k) {
    case 9:
        return D_00587BF0;
    case 0:
    case 1:
        return D_00587C10;
    default:
        return D_00587C00;
    }
}

extern "C" void GuiNetMessageArray_onElementRender(Self* self, int col, unsigned int row, float* r)
{
    Msg* m;
    GuiArrayWidget_onElementRender(self, col, row, r);
    if (!self->text || !self->msgs || row >= self->msgs->count || col == 2)
        return;
    m = SFOLobbyList_GetSlot(self->msgs, row);
    if (!m)
        return;
    if (col == 0) {
        IconW* w = TypeIcon(self, m->type);
        if (w) {
            GuiWidget_SetPosition(w, r[0] + (r[2] / 2.0f - w->w / 2.0f), r[1] - (r[3] / 2.0f - w->h / 2.0f));
            w->icon->Show();
        }
        return;
    }
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    SetPos(self->text, (int)r[0], (int)r[1]);
    SetSize(self->text, (int)r[2], (int)r[3]);
    SetF58(self->text, 1);
    if (col == 1) {
        if (m->type == 10)
            cTextArea_SetText(self->text, std_basic_string_char_char_traits_char_c_str(self->name));
        else
            cTextArea_SetText(self->text, m->text);
        SetF10(self->text, 2);
        SetF5B(self->text, 1);
    } else if (col == 3) {
        cTextArea_SetText(self->text, TypeName(self, m->type));
        SetF10(self->text, 0);
        SetF5B(self->text, 0);
    }
    cTextArea_SetColor(self->text, TypeColour(self, m->type));
    TextObj_Draw(self->text);
    D_00538C64--;
    D_00538C68 = 1;
}
static inline void merge_flush_func_00348530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00348530 */

/* merge_units: begin func_003488E0 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
extern char* nGlobalization_GetString_charP(char* key);
char* GuiNetMessageArray_GetMessageDescription(void* self, int n)
{
    char buf[16];
    char* t;
    if (n < 0 || (unsigned int)n >= 12) return 0;
    sprintf(buf, D_004BA3B8, n);
    t = nGlobalization_GetString_charP(buf);
    if (t) return t;
    return D_004BA338;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003488E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003488E0 */

/* merge_units: begin func_00348950 */
#pragma push /* merge_units */
typedef struct { char pad[0x94]; int a94; int a98; int a9C; } S348950;
int GuiNetMessageArray_GetMessageIcon(S348950* o, int k)
{
    switch (k) {
    case 9:
        return o->a98;
    case 0:
    case 1:
        return o->a9C;
    default:
        return o->a94;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348950(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00348950 */

/* merge_units: begin func_003489A0 */
#pragma push /* merge_units */
char* GuiNetMessageArray_GetMessageColor(void* self, int k)
{
    switch (k) {
    case 9:
        return D_00587BF0;
    case 0:
    case 1:
        return D_00587C10;
    default:
        return D_00587C00;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003489A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003489A0 */

/* merge_units: begin func_00348A00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C348A00 { int pad0; int a4; char pad8[0x10]; unsigned char a18; };
class S348A00 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void f5C(int, int);
    char pad[0x48]; unsigned int a4C; int pad50; int a54; char pad2[0x4C]; C348A00* aA4;
};
extern "C" {
extern void GuiWidget_onAdvanceTime(S348A00*);
extern void GuiArrayWidget_GetSelected(S348A00*, int*, unsigned int*);
extern void GuiArrayWidget_SetSelected(S348A00*, int, unsigned int);
extern void SFOLobbyList_SetUpdateFlag(C348A00*, int);
void GuiNetMessageArray_onAdvanceTime(S348A00* o);
}
static inline void inl_348A00(S348A00* o)
{
    int a;
    unsigned int b;
    if (o->aA4) o->f5C(4, o->aA4->a4);
    GuiArrayWidget_GetSelected(o, &a, &b);
    if (b >= o->a4C && o->a4C != 0) b = o->a4C - 1;
    else if (b >= o->a4C) b = 0;
    o->a54 = 100000;
    GuiArrayWidget_SetSelected(o, a, b);
}
void GuiNetMessageArray_onAdvanceTime(S348A00* o)
{
    GuiWidget_onAdvanceTime(o);
    if (o->aA4 && o->aA4->a18) {
        inl_348A00(o);
        SFOLobbyList_SetUpdateFlag(o->aA4, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348A00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00348A00 */

/* merge_units: begin func_00348AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Release the owned record at +0xA0 (string member at +0x14) under the allocator guard, clear +0xA0/+0xA4. */
extern "C" {
void* String_Dtor(void* self, short flags);
void GuiArrayWidget_onSleep(void* self);
}
struct O348AD0 { char pad[0xA0]; char* aA0; int aA4; };
extern "C" void GuiNetMessageArray_onSleep(O348AD0* o)
{
    char* p;
    GuiArrayWidget_onSleep(o);
    p = o->aA0;
    {
        AllocGuard guard;
        if (p) {
            char* s = p + 0x14;
            if (s)
                String_Dtor(s, 0);
        }
        cMemMan_Deallocate(0, p, "GuiNetMessages.cc", 0xC1);
    }
    o->aA0 = 0;
    o->aA4 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00348AD0 */

/* merge_units: begin func_00348B90 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; unsigned char b10; unsigned char b11; unsigned char b12; char pad2[0x45]; unsigned char b58; } C48B90;
typedef struct { char pad[0x90]; C48B90* f90; } B48B90;
typedef struct { int f0; int f4; } L48B90;
class W48B90 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void SetCount(int kind, int n); /* +0x5C */
    char pad4[0x38]; float f3c; float f40; char p44[8]; unsigned int f4C; char p50[4]; int f54; char p58[0x38];
    B48B90* f90; char p94[0xC]; C48B90* fa0; L48B90* fa4;
};
extern "C" {
extern void GuiArrayWidget_onWake(W48B90*);
extern void* cMemMan_Allocate(int, int, char*, int);
extern char D_004BA3D0[];
extern char D_00587C20[];
extern int Gui_Manager(void);
extern int GuiManager_GetFont(int, char*);
extern C48B90* cTextArea_ctor(void*, int, int, int, int, int, char*);
extern char* cDME_GetLobby(void);
#if 0 /* merge_units */
extern void GuiArrayWidget_GetSelected(W48B90*, int*, unsigned int*);
#endif /* merge_units */
#define GuiArrayWidget_GetSelected(a0, a1, a2) (GuiArrayWidget_GetSelected((S348A00 *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void GuiArrayWidget_SetSelected(W48B90*, int, unsigned int);
#endif /* merge_units */
#define GuiArrayWidget_SetSelected(a0, a1, a2) (GuiArrayWidget_SetSelected((S348A00 *)(a0), (a1), (a2))) /* merge_units */


}
/* List screen init: creates the callout, binds the lobby list and clamps the restored selection. */
extern "C" void GuiNetMessageArray_onWake(W48B90* w) {
    C48B90* c;
    GuiArrayWidget_onWake(w);
    {
        AllocGuard g;
        c = (C48B90*)cMemMan_Allocate(0, 0x60, D_004BA3D0, 0x89);
    }
    if (c) {
        int x = (int)w->f3c;
        int y = (int)w->f40;
        c = cTextArea_ctor(c, 0, 0, x, y, GuiManager_GetFont(Gui_Manager(), "callout"), D_00587C20);
    }
    w->fa0 = c;
    w->fa0->b12 = 1;
    w->fa0->b10 = 2;
    if (cDME_GetLobby()) w->fa4 = (L48B90*)(cDME_GetLobby() + 0x1C);
    w->f54 = 0;
    if (w->fa4) w->SetCount(4, w->fa4->f4);
    {
        int top[1];
unsigned int sel[1];
        GuiArrayWidget_GetSelected(w, top, sel);
        if (sel[0] >= w->f4C && w->f4C != 0) sel[0] = w->f4C - 1;
        else if (sel[0] >= w->f4C) sel[0] = 0;
        w->f54 = 100000;
        GuiArrayWidget_SetSelected(w, top[0], sel[0]);
    }
    if (w->f90 && w->f90->f90) {
        C48B90* x = w->f90->f90;
        x->b11 = 1;
        x->b58 = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00348B90(void) {}
#undef GuiArrayWidget_GetSelected /* merge_units */
#undef GuiArrayWidget_SetSelected /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00348B90 */
