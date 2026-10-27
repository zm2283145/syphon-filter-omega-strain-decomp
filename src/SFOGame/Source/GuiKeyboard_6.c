/*
 * SFOGame/Source/GuiKeyboard: 4 files, 0032D040-0032D2A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032D040 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer-vector helpers (iterator copy, end(), push_back).
 */

#include "loose03_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int count, int* value);

Word* func_0032D040(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end() */
void func_0032D050(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

/* push_back */
int std_vector_GuiWidgetPtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

void func_0032D090(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
int* func_0032D0A0(PtrVec* v) {
    return v->data;
}

/* push_back */
int func_0032D0B0(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_0032D040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032D040 */

/* merge_units: begin func_0032D0D0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct {
    unsigned char key;
    char p1[5];
    unsigned short a;
    unsigned short b;
    char pA[2];
} KbEntry;

typedef struct {
    KbEntry *items;
    int count;
    int p8;
    int pC;
} KbTable;

typedef struct {
    char p0[0x64];
    int count;
    void **widgets;
    char p6C[0x8];
    int count74;
    int *types;
    char p7C[0x4];
    char vec80[0x8];
    int *index;
    char p8C[0x4];
    KbTable *tab;
    int mode;
    int f98;
    unsigned char b9C;
} KbSelf;

extern KbTable D_0052AF60[];
extern int D_004926C0;
extern char D_004B8CF0[];
extern void std_vector_pod_int_resize(void *v, int n, int *fill);
extern void GuiTextWidget_SetText(void *w, char *s, int a, int b);
extern void GuiKeyboard_Relabel(KbSelf *self, unsigned int flags);

void GuiKeyboard_ApplyLayout(KbSelf *self, unsigned char mode)
{
    int i;
    int j;
    int off;
    self->f98 = 0;
    self->mode = mode;
    self->tab = &D_0052AF60[mode];
    std_vector_pod_int_resize(self->vec80, *(volatile int *)&self->count, &D_004926C0);
    for (i = 0; i < *(volatile int *)&self->count; i++)
        self->index[i] = -1;
    if (self->count == self->count74) {
        if (self->tab) {
            self->b9C = 0;
            for (i = 0; i < self->count; i++) {
                KbTable *t;
                KbEntry *e;
                int key;
                int n;
                t = self->tab;
                n = t->count;
                j = 0;
                if (j < n) {
                    e = t->items;
                    key = self->types[i];
                    do {
                        if (e->key == key) {
                            self->index[i] = j;
                            GuiTextWidget_SetText(self->widgets[i], D_004B8CF0, 0, j);
                            break;
                        }
                        j++;
                        e++;
                    } while (j < n);
                }
            }
            {
                int k;
                int off;
                k = 0;
                if (k < self->tab->count) {
                    off = 0;
                    do {
                        KbEntry *e = (KbEntry *)((char *)self->tab->items + off);
                        if (e->a != 0xFFFF || e->b != 0xFFFF)
                            self->b9C = 1;
                        k++;
                        off += sizeof(KbEntry);
                    } while (k < self->tab->count);
                }
            }
        }
        GuiKeyboard_Relabel(self, 0);
    }
}
static inline void merge_flush_func_0032D0D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032D0D0 */

/* merge_units: begin func_0032D2A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; char padD[3]; } List0032D2A0;
typedef struct {
    void* vtable;
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x32];
    int unk48, unk4C, unk50, unk54, unk58, unk5C;
    List0032D2A0 list60;
    List0032D2A0 list70;
    List0032D2A0 list80;
    void* unk90;
    int unk94;
    int unk98;
    unsigned char unk9C;
    char pad9D[3];
    List0032D2A0 listA0;
    List0032D2A0 listB0;
    List0032D2A0 listC0;
    List0032D2A0 listD0;
    char padE0;
    unsigned char unkE1;
    char padE2[2];
    int unkE4;
} Widget0032D2A0;
extern char D_004DE790[];
extern void GuiWidget_ctor(Widget0032D2A0* w);
extern void std_vector_GuiWidgetPtr_ctor(List0032D2A0* list);
extern void std_vector_int_ctor_void(List0032D2A0* list);
extern unsigned char D_004926B8;
extern char D_00491580[], D_004917D0[], D_00491A20[], D_004925A0[], D_00491C70[], D_00491C90[];
extern char D_00491CC0[], D_00491CF0[], D_00491D20[], D_004925D0[], D_00491F70[], D_00491FB0[];
extern char D_00491FE0[], D_00492010[], D_00492260[], D_00492600[], D_004924B0[], D_004924D0[];
extern char D_00492500[], D_00492530[], D_00492570[];
#if 0 /* merge_units */
extern void* D_0052AF60;
#endif /* merge_units */
#define D_0052AF60 (*(void **)&D_0052AF60) /* merge_units */
extern int D_0052AF64;
extern void* D_0052AF70; extern int D_0052AF74;
extern void* D_0052AF80; extern int D_0052AF84; extern void* D_0052AF88; extern int D_0052AF8C;
extern void* D_0052AF90; extern int D_0052AF94;
extern void* D_0052AFA0; extern int D_0052AFA4; extern void* D_0052AFA8; extern int D_0052AFAC;
extern void* D_0052AFB0; extern int D_0052AFB4; extern void* D_0052AFB8; extern int D_0052AFBC;
extern void* D_004925A4; extern int D_004925A8;
extern void* D_004925B0; extern int D_004925B4;
extern void* D_004925BC; extern int D_004925C0;
extern void* D_004925C8; extern int D_004925CC;
extern void* D_004925D4; extern int D_004925D8;
extern void* D_004925E0; extern int D_004925E4;
extern void* D_004925EC; extern int D_004925F0;
extern void* D_00492604; extern int D_00492608;
extern void* D_00492610; extern int D_00492614;
extern void* D_0049261C; extern int D_00492620;
extern void* D_00492628; extern int D_0049262C;
extern void* D_00492634; extern int D_00492638;

Widget0032D2A0* GuiKeyboard_ctor(Widget0032D2A0* w)
{
    List0032D2A0 *l, *l2, *l3, *l4, *l5, *l6, *l7;
    GuiWidget_ctor(w);
    w->vtable = D_004DE790;
    l = &w->list60; std_vector_GuiWidgetPtr_ctor(l); l->flag = 1;
    l2 = &w->list70; std_vector_int_ctor_void(l2); l2->flag = 1;
    l3 = &w->list80; std_vector_int_ctor_void(l3); l3->flag = 1;
    l4 = &w->listA0; std_vector_int_ctor_void(l4); l4->flag = 1;
    l5 = &w->listB0; std_vector_int_ctor_void(l5); l5->flag = 1;
    l6 = &w->listC0; std_vector_int_ctor_void(l6); l6->flag = 1;
    l7 = &w->listD0; std_vector_int_ctor_void(l7); l7->flag = 1;
    w->unk5C = 0;
    w->unkE4 = 0;
    w->unkE1 = 0;
    w->unk98 = 0;
    w->unk9C = 0;
    w->flags &= ~0x20;
    w->unk48 = 0;
    w->unk4C = 0;
    w->unk54 = 0;
    w->unk58 = 0;
    w->unk50 = 0;
    if (D_004926B8) {
        D_004926B8 = 0;
        D_0052AF60 = D_00491580; D_0052AF64 = 0x31;
        D_0052AF70 = D_004917D0; D_0052AF74 = 0x31;
        D_0052AF80 = D_00491A20; D_0052AF84 = 0x31;
        D_0052AF88 = D_004925A0; D_0052AF8C = 4;
        D_004925A4 = D_00491C70; D_004925A8 = 7;
        D_004925B0 = D_00491C90; D_004925B4 = 0xB;
        D_004925BC = D_00491CC0; D_004925C0 = 0xB;
        D_004925C8 = D_00491CF0; D_004925CC = 0xC;
        D_0052AFA0 = D_00491D20; D_0052AFA4 = 0x31;
        D_0052AFA8 = D_004925D0; D_0052AFAC = 3;
        D_004925D4 = D_00491F70; D_004925D8 = 0xD;
        D_004925E0 = D_00491FB0; D_004925E4 = 0xB;
        D_004925EC = D_00491FE0; D_004925F0 = 0xB;
        D_0052AF90 = D_00492010; D_0052AF94 = 0x31;
        D_0052AFB0 = D_00492260; D_0052AFB4 = 0x31;
        D_0052AFB8 = D_00492600; D_0052AFBC = 5;
        D_00492604 = D_004924B0; D_00492608 = 7;
        D_00492610 = D_004924D0; D_00492614 = 0xB;
        D_0049261C = D_00492500; D_00492620 = 0xB;
        D_00492628 = D_00492530; D_0049262C = 0xD;
        D_00492634 = D_00492570; D_00492638 = 0xC;
    }
    w->unk90 = 0;
    return w;
}
#undef D_0052AF60 /* merge_units */
static inline void merge_flush_func_0032D2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032D2A0 */

/* merge_units: begin func_0032D5E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nested_null_dtor.h"

DEFINE_NESTED_NULL_DTOR2(cArray_GuiWidgetPtr_dtor, std_vector_imp_GuiWidgetPtr_1_dtor)
static inline void merge_flush_func_0032D5E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032D5E0 */
