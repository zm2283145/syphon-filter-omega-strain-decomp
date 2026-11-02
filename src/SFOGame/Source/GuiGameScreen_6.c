/*
 * SFOGame/Source/GuiGameScreen: 11 files, 0045C960-0045CF80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045C960 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_int_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_0045C980(Iter* it) {
    it->p++;
    return it;
}

Word* func_0045C9A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_0045C9B0(char* self) {
    return *(int*)(self + 0);
}

void cArray_int_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_0045C9E0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_0045C9F0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_int_end_void_2(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
static inline void merge_flush_func_0045C960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045C960 */

/* merge_units: begin func_0045CA20 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

typedef struct { char pad[0x14]; unsigned short flags; } W_45CA20;
typedef struct {
    char pad[0x6C]; W_45CA20* w; char pad70[0x20]; int f90; int f94; int f98; unsigned char f9C;
    char pad9D[3]; void* fA0; void* fA4; char padA8[0x28]; int fD0; int fD4; char padD8[4]; int fDC;
} S_45CA20;
typedef struct { char pad[0x6A8]; unsigned char busy; } G_45CA20;
extern G_45CA20* g_Hud;
extern int D_00497ACC[];
extern int D_00497AEC[];
void GuiGameScreen_BuildWeaponSelectList(S_45CA20* o);
long long cTimer_GetMillisecondTime(void);
void GuiGameScreen_UpdateWeaponPanels(S_45CA20* o);
#if 0 /* merge_units */
void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
#endif /* merge_units */
int GuiWidget_SendMessage(void* w, void* src, int kind, int a, int b); /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) ((void)GuiWidget_SendMessage((a0), (a1), (a2), (a3), (a4))) /* merge_units */

void* Gui_Canvas(void);
void GuiCanvas_SetFocus(void* mgr, void* w);
static inline float fmin_45CA20(float a, float b) { float r; asm { min.s r, a, b } return r; }

static inline unsigned char Has_45CA20(unsigned short* p, int m) { return (*p & m) != 0; }
static inline void Set_45CA20(unsigned short* p, int m) { *p |= m; }
void GuiGameScreen_ActivateWeaponSelect(S_45CA20* o, int on)
{
    W_45CA20* w = o->w;
    unsigned short* pf;
    if (w == 0) return;
    pf = &w->flags;
    if ((unsigned char)on == Has_45CA20(pf, 4)) return;
    if (on) {
        if (g_Hud->busy) return;
        Set_45CA20(pf, 2);
        o->w->flags |= 4;
        GuiGameScreen_BuildWeaponSelectList(o);
        o->f94 = o->f90;
        o->f98 = cTimer_GetMillisecondTime();
        o->f9C = 0;
        GuiGameScreen_UpdateWeaponPanels(o);
        if (o->fD4 == 0 && o->fD0 == 0) GuiWidget_SendMessage(o, o->fA4, 0xA, D_00497ACC[o->fDC], 0);
        o->fD4 = 1;
        o->fD0 = 2;
        GuiWidget_SendMessage(o, o->fA4, 0xB, D_00497AEC[o->fDC], 0);
        GuiWidget_SendMessage(o, o->fA0, 6, (int)"onWake", 0);
        o->w->flags |= 0x80;
        GuiCanvas_SetFocus(Gui_Canvas(), o->w);
        GuiWidget_SendMessage(o->w, Gui_Canvas(), 0x10, 2, 0);
    } else {
        float v;
        o->fD4 = 0;
        o->fD0 = 2;
        v = 0;
        GuiWidget_SendMessage(o, o->fA4, 9, (int)&v, 0);
        v = fmin_45CA20((float)D_00497AEC[o->fDC], v);
        GuiWidget_SendMessage(o, o->fA4, 0xC, (int)v, D_00497ACC[o->fDC]);
        o->w->flags &= ~4;
        GuiWidget_SendMessage(o, o->fA0, 6, (int)"onSleep", 0);
        o->w->flags &= ~0x80;
        GuiCanvas_SetFocus(Gui_Canvas(), o);
        GuiWidget_SendMessage(o->w, Gui_Canvas(), 0x10, 3, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045CA20(void) {}
#undef GuiWidget_SendMessage /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045CA20 */

/* merge_units: begin func_0045CC90 */
#pragma push /* merge_units */
typedef struct { float x, y; } Vec2_45CC90;
typedef struct {
    char pad0[0x14];
    unsigned short flags;
    char pad16[0x34 - 0x16];
    Vec2_45CC90 pos;
    Vec2_45CC90 size;
    char pad44[0xA4 - 0x44];
    unsigned char fA4;
} W_45CC90;
typedef struct {
    char pad0[0x6C];
    W_45CC90* root;
    char pad70[0x90 - 0x70];
    int f90;
    int f94;
    int f98;
    unsigned char f9C;
    char pad9D[0xA8 - 0x9D];
    W_45CC90* items[5];
    char padBC[0xD0 - 0xBC];
    int fD0;
    int fD4;
    char fD8[4];
    int fDC;
} S_45CC90;
extern char D_004C2210[];
extern char D_004C2228[];
extern void* g_WeaponDatabase;
extern void* D_00497AC0;
extern W_45CC90* AbstractWidgetClassRep_Create(char*);
#if 0 /* merge_units */
extern W_45CC90* GuiWidget_FindChild_charP(W_45CC90*, char*);
#endif /* merge_units */
void* GuiWidget_FindChild_charP(void* w, void* id); /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((W_45CC90 *)GuiWidget_FindChild_charP((void *)(a0), (void *)(a1))) /* merge_units */

extern void GuiWidget_SetPosition(W_45CC90*, float, float);
extern void GuiWidget_AddChild(W_45CC90*, W_45CC90*);
extern void cWeaponDB_LoadGun(void* m, void* a, void* b, int c, int d, int e, int f);

static inline void SetSize(W_45CC90* w, float x, float y)
{
    w->size.x = x;
    w->size.y = y;
}

void GuiGameScreen_InitWeaponSelect(S_45CC90* self)
{
    int i;
    char buf[16];
    if (self->root == 0) {
        return;
    }
    self->f90 = -1;
    self->fDC = 0;
    self->f94 = -1;
    self->f9C = 0;
    self->f98 = 0;
    self->fD0 = 0;
    self->fD4 = 0;
    self->root->flags &= ~2;
    self->root->flags &= ~4;
    for (i = 0; i < 5; i++) {
        W_45CC90* ref;
        Vec2_45CC90 p;
        Vec2_45CC90 s;
        self->items[i] = AbstractWidgetClassRep_Create(D_004C2210);
        sprintf(buf, D_004C2228, i + 1);
        ref = GuiWidget_FindChild_charP(self->root, buf);
        p = ref->pos;
        GuiWidget_SetPosition(self->items[i], p.x, p.y);
        s = ref->size;
        SetSize(self->items[i], s.x, s.y);
        GuiWidget_AddChild(self->root, self->items[i]);
        self->items[i]->fA4 = 0;
    }
    cWeaponDB_LoadGun(g_WeaponDatabase, D_00497AC0, self->fD8, -1, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045CC90(void) {}
#undef GuiWidget_FindChild_charP /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045CC90 */

/* merge_units: begin func_0045CE10 */
#pragma push /* merge_units */
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];   /* 0x048 */
    char partB[0xAC];   /* 0x0E4 */
} SoundRequest; /* size 0x190 */
typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag; /* 0x20 */
    char pad021[0x57];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} SoundMsg; /* size 0x1C0 */
typedef struct { char pad[0x14]; unsigned short flags; char pad16[0x78 - 0x16]; int x78; } Sub_5CE10;
typedef struct { char pad[0x68]; Sub_5CE10* sub; } Scr_5CE10;
extern char g_Game[];
extern char D_004DAE10[];
extern char D_004C21F8[];
extern char* nGlobalization_GetString_charP(char* key);
extern int GuiSubTitleDisplay_AddMessage(Sub_5CE10* d, char* text);
#if 0 /* merge_units */
extern void GuiWidget_SendMessage(Scr_5CE10* w, Sub_5CE10* to, int ev, int name, int x);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) ((void)GuiWidget_SendMessage((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */


extern void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, char* name, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg* msg, SoundRequest* req);
extern void QueueMessage_cMessageR_cSystemP_int(SoundMsg* msg, void* target, int flags);
extern void cFileMan_dtor(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);
void GuiGameScreen_AddXAAudio(Scr_5CE10* self, char* name, int unused, int sound)
{
    char* text;
    if (!name || !*name || !self->sub) {
        self->sub->flags &= ~2;
        return;
    }
    text = nGlobalization_GetString_charP(name);
    if (text && GuiSubTitleDisplay_AddMessage(self->sub, text)) {
        if (!(self->sub->flags & 2)) GuiWidget_SendMessage(self, self->sub, 6, (int)D_004C21F8, 0);
        self->sub->x78 = 4;
        self->sub->flags |= 2;
    }
    if (sound) {
        SoundMsg msg;
        SoundRequest req;
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 4, name, 0, 100);
        SoundMsg_WrapAction(&msg, &req);
        cFileMan_dtor(req.partB, -1);
        cFileMan_dtor(req.partA, -1);
        msg.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
        msg.vtbl = D_004DAE10;
        cFileMan_dtor(msg.partB, -1);
        cFileMan_dtor(msg.partA, -1);
        cMessage_dtor(&msg, 0);
    }
}
#undef GuiWidget_SendMessage /* merge_units */
static inline void merge_flush_func_0045CE10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045CE10 */

/* merge_units: begin func_0045CF80 */
#pragma push /* merge_units */
typedef struct { char pad0[0x50]; unsigned char* p; } O_45CF80;
unsigned char GuiGameScreen_InteractActive(O_45CF80* o)
{
    unsigned char r = 0;
    if (o->p != 0 && (*(unsigned short*)(o->p + 0x14) & 2) != 0) r = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045CF80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045CF80 */

/* merge_units: begin func_0045CFB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct L45CFB0 { char p[0x14]; unsigned short flags; };
struct W45CFB0 { char p[0x50]; L45CFB0* label; unsigned char b54, b55; char p56[2]; char m58[0xC]; unsigned char b64; };
extern "C" {
void* std_basic_string_char_char_traits_char_c_str(void* s);
#if 0 /* merge_units */
void GuiTextWidget_SetText(L45CFB0* l, void* s, int z);
#endif /* merge_units */
void GuiTextWidget_SetText(void*, void*, int); /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (a1), (a2))) /* merge_units */

int GuiWidget_SendMessage(void* w, void* src, int kind, int a, int b);
}
#pragma push
extern "C" void GuiGameScreen_ClearInteract(W45CFB0* w, int a)
{
    if (w->label) {
        if (a) w->b55 = 0;
        else {
            w->b54 = 0;
            if (w->b55) {
                GuiTextWidget_SetText(w->label, std_basic_string_char_char_traits_char_c_str(w->m58), 0);
                GuiWidget_SendMessage(w->label, w->label, 10, w->b64, 0);
            }
        }
        bool on = w->b55 || w->b54; L45CFB0* l = w->label; if ((unsigned char)on) l->flags |= 2; else l->flags &= ~2;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045CFB0(void) {}
#undef GuiTextWidget_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045CFB0 */

/* merge_units: begin func_0045D070 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct M4 { V4 r[4]; };
struct L45D070 { char p[0x14]; unsigned short flags; char p16[0x3E]; int font; };
struct O45D070 { char p[0x30]; M4 mtx; int unk70; };
struct W45D070 { char p[0x50]; L45D070* label; unsigned char b54, b55; char p56[2]; char m58[0xC]; unsigned char b64; };
extern "C" {
void std_basic_string_char_char_traits_char_ctor_charP(void* s);
void String_Dtor(void* s, int z);
void std_basic_string_char_char_traits_char_assign_basicstringR(void* d, void* s);
int cFont_GetStringWidth(int font, const char* s, int n);
void cInterfaceElement_SetView(O45D070* o, M4* m);
void cInterfaceModel_GetBounds(V4* out, float f, int x);
int cInterfaceModel_FindChild(int a, void* b);
#if 0 /* merge_units */
void GuiTextWidget_SetText(L45D070* l, const char* s, int z);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (void *)(a1), (a2))) /* merge_units */



void* GuiWidget_FindChild_charP(void* w, void* id);
#if 0 /* merge_units */
void GuiGameScreen_ClearInteract(W45D070* w, int a);
#endif /* merge_units */
#define GuiGameScreen_ClearInteract(a0, a1) (GuiGameScreen_ClearInteract((W45CFB0 *)(a0), (a1))) /* merge_units */



extern char D_004C2238[];
extern char D_004C2250[];
extern char D_005861C8;
extern M4 D_005861D0;
extern char D_00586210;
extern unsigned char D_00497B10;
extern float D_00586220;
extern float D_00586224;
extern float D_00586228;
extern float D_0058622C;
}
inline void M4Copy(M4* d, M4* s) { M4* dd = d; M4* ss = s; __int128 a, b; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(dd), "r"(ss) : "memory"); }
inline void M4CopyB(M4* d, M4* s) { __int128* dd = (__int128*)d; __int128 a, b; __int128* ss = (__int128*)s; a = ss[0]; b = ss[1]; dd[0] = a; a = ss[2]; dd[1] = b; b = ss[3]; dd[2] = a; dd[3] = b; }
inline void V4Copy(V4* d, V4* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
inline void V4Scale(V4* o, V4* i, float f) { V4* oo = o; V4* ii = i; int tt; asm { .set noreorder; lqc2 vf1, 0x0(ii); mfc1 tt, f; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(oo); .set reorder } }
#pragma push
#pragma opt_propagation off
extern "C" void GuiGameScreen_ShowInteract(W45D070* w, const char* text, unsigned char color, int a)
{
    O45D070* obj;
    float width;
    M4 m;
    V4 s;
    V4 t;
    V4 v;
    if (w->label) {
        if (text == 0 || *text == 0) {
            GuiGameScreen_ClearInteract(w, a);
            return;
        }
        if (a) {
            char str[0xC];
            w->b55 = 1;
            std_basic_string_char_char_traits_char_ctor_charP(str);
            std_basic_string_char_char_traits_char_assign_basicstringR(w->m58, str);
            String_Dtor(str, 0);
            w->b64 = color;
        } else {
            w->b54 = 1;
        }
        w->label->flags |= 2;
        GuiTextWidget_SetText(w->label, text, 0);
        { L45D070* l = w->label; GuiWidget_SendMessage(l, l, 10, color, 0); }
        { void* id = GuiWidget_FindChild_charP(w, D_004C2238); obj = 0;
        if (!GuiWidget_SendMessage(w, id, 5, (int)&obj, 0)) return; }
        if (!obj) return;
        if (!D_005861C8) {
            M4Copy(&D_005861D0, &obj->mtx);
            D_005861C8 = 1;
        }
        if (!D_00586210) D_00586210 = 1;
        if (D_00497B10) {
            int h = cInterfaceModel_FindChild(obj->unk70, D_004C2250);
            if (h) {
                cInterfaceModel_GetBounds(&v, 0.0f, h);
                D_00586220 = v.x;
                D_00586224 = v.y;
                D_00586228 = v.z;
                D_0058622C = v.w;
                D_00586228 -= 70.0f;
            }
            D_00497B10 = 0;
        }
        { int font = w->label->font; if (font) width = cFont_GetStringWidth(font, text, 0x200);
        else width = 0.0f; }
        if (width > D_00586228 && D_00586228 > 0.0f) {
            M4CopyB(&m, &D_005861D0);
            V4Copy(&s, &m.r[0]);
            __int128 tt = 0;
            V4Scale(&s, &s, width / D_00586228);
            { float x, y, z, ww; ww = s.w; z = s.z; y = s.y; x = s.x; m.r[0].w = ww; m.r[0].z = z; m.r[0].y = y; m.r[0].x = x; }
            { V4* sp3 = &m.r[3]; V4* tp = &t; V4Copy(tp, sp3); }
            { float hw = (width - D_00586228); t.x += hw / 2.0f; }
            V4Copy(&m.r[3], &t);
            cInterfaceElement_SetView(obj, &m);
        } else {
            cInterfaceElement_SetView(obj, &D_005861D0);
        }
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045D070(void) {}
#undef GuiTextWidget_SetText /* merge_units */
#undef GuiGameScreen_ClearInteract /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045D070 */

/* merge_units: begin func_0045D3D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiGameScreen_types.h"

extern int GuiWidget_onMessage(GuiGameScreen* self, void* sender, int msg);
extern int GuiGameScreen_AcceptChooseMenu(GuiGameScreen* self);

/* Message handler: message 19 from the choice list is handled here,
 * everything else goes to the base widget handler. */
int GuiGameScreen_onMessage(GuiGameScreen* self, void* sender, int msg) {
    if ((msg & 0xFFFF) == 19 && sender == self->choices) {
        GuiGameScreen_AcceptChooseMenu(self);
        return 1;
    }
    return GuiWidget_onMessage(self, sender, msg);
}
static inline void merge_flush_func_0045D3D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045D3D0 */

/* merge_units: begin func_0045D420 */
#pragma push /* merge_units */
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_45D420;
typedef struct { char pad[0x90]; int f90; int f94; int f98; unsigned char b9C; char pad9D[0xD4 - 0x9D]; int fD4; } O_45D420;
int GuiGameScreen_IsChooseMenuActive(O_45D420* o);
void GuiGameScreen_CloseChooseMenu(O_45D420* o);
#if 0 /* merge_units */
unsigned long long cTimer_GetMillisecondTime(void);
#endif /* merge_units */
#define cTimer_GetMillisecondTime() ((unsigned long long)cTimer_GetMillisecondTime()) /* merge_units */

void GuiGameScreen_CycleWeaponSelect(O_45D420* o, int v);
void GuiGameScreen_SelectCurrentWeapon(O_45D420* o);
#if 0 /* merge_units */
void GuiGameScreen_ActivateWeaponSelect(O_45D420* o, int on);
#endif /* merge_units */
#define GuiGameScreen_ActivateWeaponSelect(a0, a1) (GuiGameScreen_ActivateWeaponSelect((S_45CA20 *)(a0), (a1))) /* merge_units */

static inline unsigned char Down_45D420(Ev_45D420* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_45D420(Ev_45D420* e, int b) { unsigned char r = 0; if (Down_45D420(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Shift_45D420(Ev_45D420* e, int b) { unsigned char r = 0; if (Btn_45D420(e, b) && e->b6 == 1) r = 1; return r; }
static inline int Down2_45D420(Ev_45D420* e) { return e->type == 1 && e->b2 == 0; }
static inline int Btn2_45D420(Ev_45D420* e, int b) { return Down2_45D420(e) && e->btn == b; }
static inline int Plain2_45D420(Ev_45D420* e, int b) { return Btn2_45D420(e, b) && e->b6 == 0; }

int GuiGameScreen_onInput(O_45D420* o, Ev_45D420* ev)
{
    if (Plain2_45D420(ev, 0x10) && GuiGameScreen_IsChooseMenuActive(o)) {
        GuiGameScreen_CloseChooseMenu(o);
        return 1;
    }
    if (o->fD4 == 1) {
    if (Shift_45D420(ev, 0x100)) {
        if (!o->b9C && o->f94 == o->f90 && cTimer_GetMillisecondTime() - o->f98 < 100) GuiGameScreen_CycleWeaponSelect(o, 1);
        GuiGameScreen_SelectCurrentWeapon(o);
        GuiGameScreen_ActivateWeaponSelect(o, 0);
        return 1;
    }
    if (Plain2_45D420(ev, 8) || Plain2_45D420(ev, 2)) {
        GuiGameScreen_CycleWeaponSelect(o, 0);
        return 1;
    }
    if (Plain2_45D420(ev, 4) || Plain2_45D420(ev, 1)) {
        GuiGameScreen_CycleWeaponSelect(o, 1);
        return 1;
    }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045D420(void) {}
#undef cTimer_GetMillisecondTime /* merge_units */
#undef GuiGameScreen_ActivateWeaponSelect /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045D420 */

/* merge_units: begin func_0045D710 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { char pad[0x416]; signed char v; } T_45D710;
typedef struct {
    char pad0[0xF0];
    unsigned char type;
    char padF1[0x11C - 0xF1];
    T_45D710* alt;
    char pad120[0x13C - 0x120];
    T_45D710* main;
} W_45D710;
typedef struct {
    char pad0[0x74];
    int n;
    int* ids;
    char pad7C[0x88 - 0x7C];
    int* vals;
    char pad8C[0xD8 - 0x8C];
    T_45D710* def;
} O_45D710;
W_45D710* cWeaponDB_GetEntry(void* db, int id);

static inline T_45D710* W_Get(W_45D710* w)
{
    if (w->type == 7 && w->alt != 0) return w->alt;
    return w->main;
}

void GuiGameScreen_WeaponRestoreTransparency(O_45D710* o)
{
    int i;
    for (i = 0; i < o->n; i++) {
        if (o->ids[i] == -2) {
            o->def->v = -1;
        } else {
            W_45D710* w = cWeaponDB_GetEntry(g_WeaponDatabase, o->ids[i]);
            if (w) {
                T_45D710* t = W_Get(w);
                if (t) t->v = o->vals[i];
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045D710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045D710 */

/* merge_units: begin func_0045D7F0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct {
    char pad0[0x74];
    int n;
    int* ids;
    char pad7C[0x80 - 0x7C];
    char vec80[8];
    int* vals;
    char pad8C[0xD8 - 0x8C];
    T_45D710* def;
} O_45D710_0045D7F0;
extern int D_00497B08;
void std_vector_pod_int_resize(void* v, unsigned int n, int* fill);

void GuiGameScreen_WeaponSaveTransparency(O_45D710_0045D7F0* o)
{
    int i;
    std_vector_pod_int_resize(o->vec80, o->n, &D_00497B08);
    for (i = 0; i < o->n; i++) {
        if (o->ids[i] != -2) {
            W_45D710* w = cWeaponDB_GetEntry(g_WeaponDatabase, o->ids[i]);
            if (w) {
                T_45D710* t = W_Get(w);
                if (t) o->vals[i] = t->v;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045D7F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045D7F0 */
