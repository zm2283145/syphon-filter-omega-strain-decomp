/*
 * SFOGame/Source/GuiSubTitleDisplay: 8 files, 004587D0-00458A10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004587D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cLList_TextAtomPtr_1_dtor)
static inline void merge_flush_func_004587D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004587D0 */

/* merge_units: begin func_004588C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* func_004588C0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* std_vector_cLList_TextAtomPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_004588C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004588C0 */

/* merge_units: begin func_00458900 */
#pragma push /* merge_units */
extern int *std_list_deleter_TextAtom_generic_iterator_ctor(int *self, int value);
extern int std_list_deleter_TextAtom_tail(char *self);
extern char *details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_12(char *self);
#if 0 /* merge_units */
extern void std_vector_float_push_back(void *v, float *value);
#endif /* merge_units */
int std_vector_float_push_back(); /* merge_units */


static inline char *At(char *self, int i) { return (*(char ***)(self + 0x60))[i]; }
#pragma opt_strength_reduction off
void GuiSubTitleDisplay_CalcLineTimes(char *self)
{
    float sum;
    int end;
    int i;
    char *list;
    char *n;

    *(int *)(self + 0x6C) = 0;
    sum = 0.0f;
    for (i = 0; i < *(int *)(self + 0x5C); i++) {
        list = At(self, i);
        for (n = *(char **)(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_12(list + 4) + 4); std_list_deleter_TextAtom_generic_iterator_ctor(&end, std_list_deleter_TextAtom_tail(list)), n != (char *)end; n = *(char **)(n + 4)) {
            sum += *(float *)(n + 0x10);
            sum += *(int *)(n + 0x3C) / 20.0f;
        }
        std_vector_float_push_back(self + 0x68, &sum);
    }
}
#pragma opt_strength_reduction reset
static inline void merge_flush_func_00458900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00458900 */

/* merge_units: begin func_00458A10 */
#pragma push /* merge_units */
extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int std_vector_float_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00458A10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00458A10 */

/* merge_units: begin func_00458A30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct SubVal {
    float a;
    float b __attribute__((aligned(16)));
    float c;
    float d;
    float e;
    int f;
    int g;
    int h;
    int i;
};

struct SubNode;
struct SubList {
    int count;
    SubNode *first;
    SubNode *last;
};

struct SubDisp {
    char pad0[0x3C];
    float maxWidth;
    char pad40[0x4C - 0x40];
    int font;
    char *text;
    char pad54[0x58 - 0x54];
    int lines[2];
};

extern "C" {
void *cMemMan_Allocate(int, unsigned int, char *, int);
#if 0 /* merge_units */
void cMemMan_Deallocate(int, void *, char *, int);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (a2), (a3))) /* merge_units */

int Libc_Sscanf(char *, char *, ...);
void cTimerDisable_ctor(int *);
void cTimerDisable_dtor(int *, int);
int cFont_GetCharH(int);
int cFont_GetStringWidth(int, char *, int);
#if 0 /* merge_units */
void GuiSubTitleDisplay_CalcLineTimes(SubDisp *);
#endif /* merge_units */
#define GuiSubTitleDisplay_CalcLineTimes(a0) (GuiSubTitleDisplay_CalcLineTimes((char *)(a0))) /* merge_units */

void cLList_TextAtom_dtor(SubList *, int);
int std_vector_cLList_TextAtomPtr_push_back(int *, SubList **);
void GuiSubTitleDisplay_DestroyTextLines(SubDisp *);
int std_list_deleter_TextAtom_insert(SubNode **, SubList *, SubNode **, SubVal *);
SubList *std_list_deleter_TextAtom_ctor(SubList *);
extern char D_004C1EB0[];
extern char D_004C1ED0[];
extern char D_004C1ED8[];
extern float D_00587D70;
extern float D_00587D74;
extern float D_00587D78;
extern float D_00587D7C;
int GuiSubTitleDisplay_Atomize(SubDisp *self);
}

static inline void Push(SubList *l, SubVal *v)
{
    SubNode *res;
    SubNode *pos = (SubNode *)&l->first;
    std_list_deleter_TextAtom_insert(&res, l, &pos, v);
}

static inline void FreeList(SubList *l)
{
    int guard;
    cTimerDisable_ctor(&guard);
    cLList_TextAtom_dtor(l, -1);
    cMemMan_Deallocate(0, l, D_004C1EB0, 0x124);
    cTimerDisable_dtor(&guard, -1);
}

int GuiSubTitleDisplay_Atomize(SubDisp *self)
{
    SubList *list;
    float pf;
    int r;
    int g;
    int b;
    float nf;
    char *p;
    int width;
    SubVal val;
    char buf[0x20];
    int maxw;

    GuiSubTitleDisplay_DestroyTextLines(self);
    p = self->text;
    if (p == 0)
        return 0;
    maxw = (int)self->maxWidth;
    val.a = 0;
    val.b = 1.0f;
    val.c = 1.0f;
    val.d = 1.0f;
    val.e = 1.0f;
    val.f = 0;
    val.g = 0;
    val.h = 0;
    val.i = 0;
    width = 0;
    {
        SubList *nl;
        {
            AllocGuard guard;
            nl = (SubList *)cMemMan_Allocate(0, 0xC, D_004C1EB0, 0x67);
        }
        if (nl)
            std_list_deleter_TextAtom_ctor(nl);
        list = nl;
    }
    for (;;) {
        signed char c = *p;
        if (!c)
            break;
        if (c == '<' && p[1] != '<') {
            signed char t;
            char *d;
            p++;
            if (!*p)
                return 0;
            t = *p;
            p++;
            if (!*p || (*p != '>' && *p != ':'))
                return 0;
            d = buf;
            if (*p != '>')
                p++;
            while (*p != '>') {
                if (*p == 0)
                    return 0;
                *d++ = *p++;
            }
            *d = 0;
            p++;
            switch (t) {
            case 'p':
                if (Libc_Sscanf(buf, D_004C1ED0, &pf) != 1)
                    return 0;
                if (val.i != 0) {
                    Push(list, &val);
                    width += cFont_GetStringWidth(self->font, self->text + val.h, val.i);
                    val.f = width;
                    val.i = 0;
                }
                val.h = p - self->text;
                val.a = pf;
                break;
            case 'c': {
                float cr;
                float cg;
                float cb;
                float ca;
                if (Libc_Sscanf(buf, D_004C1ED8, &r, &g, &b) == 3) {
                    cr = r / 255.0f;
                    cg = g / 255.0f;
                    cb = b / 255.0f;
                    ca = 1.0f;
                } else {
                    cr = D_00587D70;
                    cg = D_00587D74;
                    cb = D_00587D78;
                    ca = D_00587D7C;
                }
                if (val.i != 0) {
                    Push(list, &val);
                    width += cFont_GetStringWidth(self->font, self->text + val.h, val.i);
                    val.f = width;
                    val.i = 0;
                    val.a = 0;
                }
                val.h = p - self->text;
                val.b = cr;
                val.c = cg;
                val.d = cb;
                val.e = ca;
                break;
            }
            case 'n':
                nf = 0;
                Libc_Sscanf(buf, D_004C1ED0, &nf);
                Push(list, &val);
                std_vector_cLList_TextAtomPtr_push_back(self->lines, &list);
                {
                    SubList *nl;
                    {
                        AllocGuard guard;
                        nl = (SubList *)cMemMan_Allocate(0, 0xC, D_004C1EB0, 0xD9);
                    }
                    if (nl)
                        std_list_deleter_TextAtom_ctor(nl);
                    list = nl;
                }
                val.f = 0;
                width = 0;
                val.g += cFont_GetCharH(self->font);
                val.a = nf;
                val.h = p - self->text;
                val.i = 0;
                break;
            }
        } else {
            char *s;
            val.i++;
            s = self->text + val.h;
            if (maxw < width + cFont_GetStringWidth(self->font, s, val.i)) {
                int len = val.i;
                int k;
                bool found = false;
                for (k = len - 1; k >= 0; k--) {
                    if (s[k] == ' ') {
                        val.i = k;
                        Push(list, &val);
                        val.h += k + 1;
                        val.i = len - k - 1;
                        if (val.i < 0)
                            val.i = 0;
                        val.a = 0;
                        found = true;
                        break;
                    }
                }
                if (found == false)
                    Push(list, &val);
                std_vector_cLList_TextAtomPtr_push_back(self->lines, &list);
                {
                    SubList *nl;
                    {
                        AllocGuard guard;
                        nl = (SubList *)cMemMan_Allocate(0, 0xC, D_004C1EB0, 0x111);
                    }
                    if (nl)
                        std_list_deleter_TextAtom_ctor(nl);
                    list = nl;
                }
                val.f = 0;
                width = 0;
                val.g += cFont_GetCharH(self->font);
                val.a = 0;
            }
            p++;
        }
    }
    if (val.i != 0 || val.a != 0.0f)
        Push(list, &val);
    if (list->count != 0) {
        std_vector_cLList_TextAtomPtr_push_back(self->lines, &list);
    } else {
        FreeList(list);
    }
    GuiSubTitleDisplay_CalcLineTimes(self);
    return 1;
}
#undef cMemMan_Deallocate /* merge_units */
#undef GuiSubTitleDisplay_CalcLineTimes /* merge_units */
static inline void merge_flush_func_00458A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00458A30 */

/* merge_units: begin func_004591B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#define std_list_deleter_voidPtr_erase_listdeleter_listdeleter std_list_deleter_TextAtom_erase
#include "obj_list_dtor.h"

DEFINE_OBJ_LIST_DTOR(std_list_TextAtom_dtor)
static inline void merge_flush_func_004591B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004591B0 */

/* merge_units: begin func_00459230 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor_mid.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_MID(std_list_imp_TextAtom_dtor)
static inline void merge_flush_func_00459230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00459230 */

/* merge_units: begin func_004592B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor_shallow.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_SHALLOW(std_list_deleter_TextAtom_dtor)
static inline void merge_flush_func_004592B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004592B0 */
