/*
 * SFOGame/Source/hud: 7 files, 00242180-002426A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00242180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_cInterfaceElementPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_00242180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00242180 */

/* merge_units: begin func_00242190 */
#pragma push /* merge_units */
typedef struct { int a, b, id, c; } S242;
typedef struct { S242 s[8]; char pad[4]; unsigned char b84; } I242;
typedef struct { char pad[0x3524]; I242* f3524; } P242;
typedef struct { char pad[0xD4]; int fd4; int fd8; } T242;
typedef struct { char pad[0x694]; int f694; unsigned char b698; char p699[3]; void* f69c; char pad2[4]; T242* f6a4; unsigned char b6a8; } H242;
typedef struct { char pad[0xF0]; unsigned char bf0; char pad2[0x2B]; int f11c; char pad3[0x1C]; int f13c; } W242;
extern void cInterfaceElement_SetText(void*, char*);
extern char D_004A7218[];
extern int cWeapon_GetEquipmentType(I242*);
extern int cWeapon_GetAmmo(I242*, int);
extern int cWeapon_HasAmmoCount(I242*, int);
extern int cWeapon_GetClipAmmo(I242*, int);
extern int sprintf(char*, const char*, ...);
extern int g_WeaponDatabase;
extern W242* cWeaponDB_GetEntry(int, int);
void cHud_UpdateWeapon(H242* h, P242* p) {
    char buf[0x20];
    I242* inv = p->f3524;
    int id;
    W242* w;
    if (inv->b84 != 6) id = inv->s[inv->b84].id;
    else id = -1;
    if (id == -1) {
        cInterfaceElement_SetText(h->f69c, D_004A7218);
        h->f694 = h->f6a4->fd8;
        h->b698 = 7;
        return;
    }
    buf[0] = 0;
    if (!h->b6a8 && h->f6a4->fd4 != 1) {
        if ((unsigned char)cWeapon_GetEquipmentType(inv) == 1 || (unsigned char)cWeapon_GetEquipmentType(inv) == 7) {
            sprintf(buf, "%d", cWeapon_GetAmmo(inv, 6));
        } else if (cWeapon_HasAmmoCount(inv, -1)) {
            int a = cWeapon_GetClipAmmo(inv, 6);
            sprintf(buf, "%d/%d", a, cWeapon_GetAmmo(inv, 6));
        }
    }
    cInterfaceElement_SetText(h->f69c, buf);
    w = cWeaponDB_GetEntry(g_WeaponDatabase, id);
    if (w->bf0 == 7) {
        h->f694 = w->f11c;
        h->b698 = 7;
    } else {
        h->f694 = w->f13c;
        h->b698 = 7;
    }
}
static inline void merge_flush_func_00242190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00242190 */

/* merge_units: begin func_00242330 */
#pragma push /* merge_units */
#pragma optimization_level 0
#pragma schedule on
#pragma peephole on
#pragma inline_depth(8)
#pragma cplusplus on
#include "vslot_pad.h"

struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    V operator-(const V& o) const { V r; SubV(&r, this, &o); return r; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float LenSq(const V* a) { int t; float r = 0.0f; __asm__("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline float LenSqV(V v) { return LenSq(&v); }

class Obj_2423 {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    VPAD8(f)
    virtual unsigned char GetKind();
    char pad4[0x28];
    unsigned char b2C, b2D, b2E;
    bool Shown() { return !b2E; }
};
struct Player_2423 { char pad0[0x30]; Obj_2423* obj; };
struct Elem_2423 { char pad0[0x70]; int x70; };
struct Ent_2423 { int key; float timer; int id; Elem_2423* elem; char pad10[4]; float distSq; unsigned char b18; };
struct Node_2423 { Node_2423* prev; Node_2423* next; Ent_2423* ent; };
struct It_2423 { Node_2423* n; };
struct Sub_2423 { char pad0[0xD4]; int xD4; };
struct Hud_2423 { char pad0[0x6A0]; int x6A0; Sub_2423* x6A4; unsigned char b6A8; unsigned char b6A9; char pad6AA[0x6E8 - 0x6AA]; char list[4]; };

extern "C" {
extern unsigned char D_004FFBB7;
extern int D_004F7D90;
extern Player_2423* g_LocalPlayer;
void std_list_deleter_voidPtr_begin_void(It_2423* out, char* l);
#if 0 /* merge_units */
void std_list_tCalloutPtr_end_void(It_2423* out, char* l);
#endif /* merge_units */
void std_list_tCalloutPtr_end_void(Iter* out, Tree* t); /* merge_units */
#define std_list_tCalloutPtr_end_void(a0, a1) (std_list_tCalloutPtr_end_void((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cLListIterator_tCalloutPtr_ctor(It_2423* out, It_2423* in);
#endif /* merge_units */
Word* cLListIterator_tCalloutPtr_ctor(Word* dst, Word* src); /* merge_units */
#define cLListIterator_tCalloutPtr_ctor(a0, a1) ((void)cLListIterator_tCalloutPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_tCalloutPtr_generic_iterator_ctor(It_2423* out, It_2423* in);
#endif /* merge_units */
Word* std_list_tCalloutPtr_generic_iterator_ctor(Word* dst, Word* src); /* merge_units */
#define std_list_tCalloutPtr_generic_iterator_ctor(a0, a1) ((void)std_list_tCalloutPtr_generic_iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

int Hud_IsGuiFocused(Hud_2423* s);
void cInterfaceElement_Activate(Elem_2423* e, int v);
Obj_2423* nGobjManager_LookupGOBJ_cObjectIdR(Ent_2423* e);
int cHud_ClearCallout(Hud_2423* o, Ent_2423* key, int id, signed char flag, int send);
}

static inline bool Visible(Obj_2423* o)
{
    bool ok = 0;
    bool vis = 0;
    if (o->b2D) { if (o->b2C) vis = 1; }
    if (vis) { if (o->Shown()) ok = 1; }
    return ok;
}
static inline void Begin_(It_2423* out, char* l) { It_2423 t; std_list_deleter_voidPtr_begin_void(&t, l); std_list_tCalloutPtr_generic_iterator_ctor(out, &t); }
static inline void End_(It_2423* out, char* l) { It_2423 t; std_list_tCalloutPtr_end_void(&t, l); cLListIterator_tCalloutPtr_ctor(out, &t); }

extern "C" void cHud_UpdateCallouts(Hud_2423* self, float dt)
{
    It_2423 it;
    It_2423 e;
    It_2423 b;
    Begin_(&b, self->list);
    for (it = b; End_(&e, self->list), it.n != e.n; ) {
        Ent_2423* ent = it.n->ent;
        if (ent->elem) {
            if (D_004FFBB7 || (Hud_IsGuiFocused(self) && self->x6A4->xD4 != 1)) {
                cInterfaceElement_Activate(ent->elem, 0);
                it.n = it.n->next;
                continue;
            }
            if (self->b6A9) {
                Elem_2423* el = ent->elem;
                if (el->x70 == D_004F7D90) {
                    cInterfaceElement_Activate(el, 0);
                    it.n = it.n->next;
                    continue;
                }
            }
            cInterfaceElement_Activate(ent->elem, 1);
            {
                Obj_2423* o = nGobjManager_LookupGOBJ_cObjectIdR(ent);
                if (!o || !Visible(o)) {
                    cInterfaceElement_Activate(ent->elem, 0);
                } else if (ent->b18 && o->GetKind() == 3) {
                    it.n = it.n->next;
                    cHud_ClearCallout(self, ent, ent->id, 0, 0);
                    continue;
                } else if (!self->x6A0 || !self->b6A9) {
                    Player_2423* p = g_LocalPlayer;
                    if (p && p->obj) {
                        V d = p->obj->GetPos() - o->GetPos();
                        ent->distSq = LenSq(&d);
                        if (!(ent->distSq <= 8100.0f))
                            cInterfaceElement_Activate(ent->elem, 0);
                    }
                }
            }
        }
        float z = 0.0f;
        float t = ent->timer;
        if (t > z) {
            t -= dt;
            ent->timer = t;
            if (t <= z) {
                it.n = it.n->next;
                cHud_ClearCallout(self, ent, ent->id, 0, 0);
            } else {
                it.n = it.n->next;
            }
        } else {
            it.n = it.n->next;
        }

    }
}
#undef std_list_tCalloutPtr_end_void /* merge_units */
#undef cLListIterator_tCalloutPtr_ctor /* merge_units */
#undef std_list_tCalloutPtr_generic_iterator_ctor /* merge_units */
static inline void merge_flush_func_00242330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00242330 */

/* merge_units: begin func_002426A0 */
#pragma push /* merge_units */
#include "hud_types.h"

extern int D_004F7DB8;
extern void cRADAR_GOBJ_SetRelative(int* p);

Word* cLListIterator_tCalloutPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_tCalloutPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_tCalloutPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Stores *p into the global at 0x004F7DB8, then forwards p. */
void cHud_SetOwner(int* p) {
    D_004F7DB8 = *p;
    cRADAR_GOBJ_SetRelative(p);
}
static inline void merge_flush_func_002426A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002426A0 */

/* merge_units: begin func_002426E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } Obj2426;
extern void GuiGameScreen_ActivateQuickChat(void* p, int on);
extern void cJoystick_Debounce(void* p);
extern char D_0055A300[];void cHud_DeactivateQuickChat(Obj2426* s) {
    if (!s->b6AA || !s->snd) return;
    GuiGameScreen_ActivateQuickChat(s->snd, 0);
    cJoystick_Debounce(D_0055A300);
    s->b6AA = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002426E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002426E0 */

/* merge_units: begin func_00242740 */
#pragma push /* merge_units */
void cHud_ActivateQuickChat(Obj2426* s) {
    if (s->b6AA || !s->snd) return;
    cJoystick_Debounce(D_0055A300);
    GuiGameScreen_ActivateQuickChat(s->snd, 1);
    s->b6AA = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00242740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00242740 */

/* merge_units: begin func_002427A0 */
#pragma push /* merge_units */
extern int D_0055A6C0;
extern void cHud_DeactivateMap(Obj2426* s);
extern void cHud_ActivateMap(Obj2426* s);
void cHud_ToggleMap(Obj2426* s) {
    D_0055A6C0 = -0x41;
    if (s->b6A9) cHud_DeactivateMap(s);
    else cHud_ActivateMap(s);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002427A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002427A0 */
