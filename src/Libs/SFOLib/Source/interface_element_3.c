/*
 * Libs/SFOLib/Source/interface_element: 4 files, 003E8E80-003E9390
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E8E80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int std_list_deleter_voidPtr_insert(int** out, StdList* list, int** pos, int value);
extern int cInterfaceModel_DestroyInstance(int owner, IfElement* elem);

/* list.push_back(value): insert before the sentinel. */
int cLList_cTextAreaPtr_PushBackActual(StdList* list, int value) {
    ListInsertArgs it;

    it.pos = &list->header;
    return std_list_deleter_voidPtr_insert(&it.result, list, &it.pos, value);
}

/* Forward the element to cInterfaceModel_DestroyInstance on its owner. */
int cInterfaceElement_Destroy(IfElement* elem) {
    return cInterfaceModel_DestroyInstance(elem->owner, elem);
}
static inline void merge_flush_func_003E8E80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8E80 */

/* merge_units: begin func_003E8EC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct Eq_8EC0 {};
struct Pred_8EC0 { Eq_8EC0 op; int* ref; Pred_8EC0(Eq_8EC0 o, int* r) : op(o), ref(r) {} };
struct Str_8EC0 { int a, b, c; };
struct Item_8EC0 { char pad[0x14]; Str_8EC0 str; };
extern "C" {
extern char D_004E0220[];
extern char D_004E0800[];
extern char D_004BDFB0[];
void std_list_imp_voidPtr_remove_if(void* list, Pred_8EC0 p);
char* GetTextSystem(void);
void String_Dtor(Str_8EC0*, int);
void cMemMan_Deallocate(int, void*, char*, int);
void operator_delete(void*);
}
static inline Pred_8EC0 MakePred_8EC0(int* p) { Eq_8EC0 c; return Pred_8EC0(c, p); }
struct O_8EC0 { void* vt; char pad[0x70]; Item_8EC0* id; };
extern "C" O_8EC0* cInterfaceElement_dtor(O_8EC0* self, short del)
{
    if (self) {
        self->vt = D_004E0220;
        if (self->id) {
            int id = (int)self->id;
            Eq_8EC0 e;
            char* x = GetTextSystem();
            std_list_imp_voidPtr_remove_if(x + 0x10, MakePred_8EC0(&id));
            {
                Item_8EC0* p = self->id;
                AllocGuard g;
                if (p) {
                    Str_8EC0* s = &p->str;
                    if (s) String_Dtor(s, 0);
                }
                cMemMan_Deallocate(0, p, D_004BDFB0, 0x41);
            }
        }
        if (self) self->vt = D_004E0800;
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003E8EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8EC0 */

/* merge_units: begin func_003E9000 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cInterfaceElement_ctor (interface_element.cc): base IfItem fields, then derived vtable,
 * identity matrix, optional text object from info->rD0, and RGBA bytes from info->colA0. */
struct V4_9000 { float x, y, z, w; V4_9000(const V4_9000& o) : x(o.x), y(o.y), z(o.z), w(o.w) {} };
struct C4_9000 { unsigned char r, g, b, a; C4_9000() {} C4_9000(V4_9000 v) : r(255.0f * v.x), g(255.0f * v.y), b(255.0f * v.z), a(255.0f * v.w) {} };
typedef struct { float f0, f4; char pad8[8]; float f10, f14; char pad18[4]; float f1C; } Rect_9000;
typedef struct { char pad[0xA0]; V4_9000 colA0; char padB0[0x20]; Rect_9000* rD0; } Info_9000;
typedef struct { char pad[0x20]; int font; } Text_9000;
typedef struct { __int128 q[4]; } M4_9000;
struct Ie_9000 {
    void* vt;
    float f4;
    float f8;
    float fC;
    int f10;
    unsigned char b14;
    char pad15[3];
    unsigned char b18;
    unsigned char b19;
    C4_9000 col;
    char pad1E[2];
    int f20;
    int f24;
    int f28;
    float f2C;
    M4_9000 m30;
    Info_9000* info;
    Text_9000* text;
    int f78;
};
extern "C" {
extern int g_InterfaceFont;
extern V4_9000 g_TextColourBlock;
void* cMemMan_Allocate(int pool, int size, char* file, int line);
Text_9000* cTextArea_ctor(Text_9000* s, int a, int b, int c, int d, int e, V4_9000* v);
#if 0 /* merge_units */
void cLList_cTextAreaPtr_PushBackActual(void* list, int* id);
#endif /* merge_units */
#define cLList_cTextAreaPtr_PushBackActual(a0, a1) ((void)cLList_cTextAreaPtr_PushBackActual((StdList *)(a0), (int)(a1))) /* merge_units */

}
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void* NewMem(unsigned int size) { AllocGuard g; return cMemMan_Allocate(0, size, D_004BDFB0, 0x31); }
static inline void AddText(Text_9000* t) { cLList_cTextAreaPtr_PushBackActual(GetTextSystem() + 0x10, (int*)&t); }
extern "C" Ie_9000* cInterfaceElement_ctor(Ie_9000* self, Info_9000* info)
{
    Rect_9000* r;
    self->vt = D_004E0800;
    self->f4 = 0.0f;
    self->f8 = -1.0f;
    self->fC = -1.0f;
    self->f10 = 0;
    self->b14 = 0;
    self->vt = D_004E0220;
    self->b18 = 1;
    self->b19 = 1;
    self->f20 = 0;
    self->f24 = 0;
    self->f28 = 0;
    self->f2C = 1.0f;
    UM(&self->m30);
    self->info = info;
    self->text = 0;
    self->f78 = 0;
    r = self->info->rD0;
    if (r) {
        float w, h;
        Text_9000* t;
        if (r->f1C > 0.0f) {
            w = r->f10 - r->f0;
            h = r->f4 - r->f14;
        } else {
            h = 1000.0f;
            w = h;
        }
        t = (Text_9000*)NewMem(0x60);
        if (t)
            t = cTextArea_ctor(t, (int)r->f0, (int)r->f4, (int)w, (int)h, 0, &g_TextColourBlock);
        self->text = t;
        { Text_9000* tt = self->text; tt->font = g_InterfaceFont; }
        AddText(self->text);
    }
    self->col = C4_9000(info->colA0);
    return self;
}
#undef cLList_cTextAreaPtr_PushBackActual /* merge_units */
static inline void merge_flush_func_003E9000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E9000 */

/* merge_units: begin func_003E9390 */
#pragma push /* merge_units */
typedef struct { void* vt; } T9390;
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

T9390* cAnimator_dtor(T9390* self, short del)
{
    if (self) {
        self->vt = D_004E0800;
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
static inline void merge_flush_func_003E9390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E9390 */
