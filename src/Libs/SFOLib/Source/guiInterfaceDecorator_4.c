/*
 * Libs/SFOLib/Source/guiInterfaceDecorator: 4 files, 00417AE0-00417C40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00417AE0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int String_Dtor();                         
int cInterfaceManager_RemoveInterface();                          
int GuiDecorator_dtor();                         
int std_vector_deleter_GuiAnimationTrack_dtor();                         
int operator_delete();                          
extern void GuiInterfaceDecorator_onActivate();
extern void GuiInterfaceDecorator_onDeactivate();
extern void GuiInterfaceDecorator_onGainFocus();
extern void GuiInterfaceDecorator_onLoseFocus();
extern void GuiInterfaceDecorator_onSleep();
extern void GuiInterfaceDecorator_onWake();
extern void GuiInterfaceDecorator_Load();
extern void GuiInterfaceDecorator_onRender();
extern void GuiInterfaceDecorator_onMessage();
extern void GuiInterfaceDecorator_onAdvanceTime();
extern void GuiInterfaceDecorator_onRemove();
extern void GuiInterfaceDecorator_onAdd();
extern void GuiDecorator_onInput();
extern void GuiDecorator_onAction();
extern void * const D_004E09F0[];
extern char D_00571DC0;

char * GuiInterfaceDecorator_dtor(char * arg0, long long arg1) {
    int temp_a1;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E09F0));
        temp_a1 = F_(arg0, 0x20, int);
        if (temp_a1 != -1) {
            cInterfaceManager_RemoveInterface(&D_00571DC0, temp_a1);
        }
        temp_a0 = arg0 + 0x70;
        if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
            std_vector_deleter_GuiAnimationTrack_dtor(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x14;
        if (temp_a0_2 != NULL) {
            String_Dtor(temp_a0_2, 0);
        }
        temp_a0_3 = arg0 + 8;
        if (temp_a0_3 != NULL) {
            String_Dtor(temp_a0_3, 0);
        }
        GuiDecorator_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E09F0[20] = { (void*)0x0, (void*)0x0, (void*)GuiInterfaceDecorator_dtor, (void*)GuiInterfaceDecorator_onAdd, (void*)GuiInterfaceDecorator_onRemove, (void*)GuiInterfaceDecorator_onActivate, (void*)GuiInterfaceDecorator_onDeactivate, (void*)GuiInterfaceDecorator_onWake, (void*)GuiInterfaceDecorator_onSleep, (void*)GuiInterfaceDecorator_onGainFocus, (void*)GuiInterfaceDecorator_onLoseFocus, (void*)GuiDecorator_onInput, (void*)GuiInterfaceDecorator_onRender, (void*)GuiDecorator_onAction, (void*)GuiInterfaceDecorator_onAdvanceTime, (void*)GuiInterfaceDecorator_onMessage, (void*)GuiInterfaceDecorator_Load, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_00417AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00417AE0 */

/* merge_units: begin func_00417BC0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char enabled; char pad2[3]; } SubState;
typedef struct {
    void* vtable;
    int unk4;
    int a, b, c, d, e, f;   /* 0x08..0x1C */
    int index;              /* 0x20 */
    int count;              /* 0x24 */
    unsigned char busy;     /* 0x28 */
    char pad29[0x47];
    SubState sub;           /* 0x70 */
    int last;               /* 0x80 */
} Widget;
#if 0 /* merge_units */
extern char D_004E09F0[];
#endif /* merge_units */
#define D_004E09F0 ((char*)&D_004E09F0) /* merge_units */


extern void GuiDecorator_ctor(Widget* w);
#if 0 /* merge_units */
extern void std_vector_GuiAnimationTrack_ctor(SubState* s);
#endif /* merge_units */
Rel * std_vector_GuiAnimationTrack_ctor(); /* merge_units */

/* Constructor. */
Widget* GuiInterfaceDecorator_ctor(Widget* w)
{
    SubState* sub;
    GuiDecorator_ctor(w);
    sub = &w->sub;
    w->vtable = D_004E09F0;
    w->a = 0;
    w->b = 0;
    w->c = 0;
    w->d = 0;
    w->e = 0;
    w->f = 0;
    std_vector_GuiAnimationTrack_ctor(sub);
    sub->enabled = 1;
    w->count = 0;
    w->index = -1;
    w->busy = 0;
    w->last = 0;
    return w;
}
#undef D_004E09F0 /* merge_units */
static inline void merge_flush_func_00417BC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00417BC0 */

/* merge_units: begin func_00417C40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* std_vector_GuiAnimationTrack_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00417C40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00417C40 */

/* merge_units: begin func_00417C60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct E7C60 { char s[0xC]; signed char c; int a; int b; };
struct V7C60 { unsigned int cap; unsigned int count; E7C60* data; };
extern "C" {
extern char D_004BF080[];
extern char D_004BF0B0[];
void std_basic_string_char_char_traits_char_ctor_basicstringR(void* d, const void* s);
E7C60* std_copy_backward_GuiAnimationTrack_copy_backward(E7C60* first, E7C60* last, E7C60* result);
void std_fill_n_GuiAnimationTrack_int_fill_n(E7C60* p, unsigned int n, const E7C60* v);
void std_swap_vectordeleterR_vectordeleterR_49(V7C60* a, V7C60* b);
#if 0 /* merge_units */
void std_vector_deleter_GuiAnimationTrack_dtor(V7C60* v, int f);
#endif /* merge_units */

}

static inline void construct(E7C60* p, const E7C60* s)
{
    if (p) {
        std_basic_string_char_char_traits_char_ctor_basicstringR(p, s);
        p->c = s->c;
        p->a = s->a;
        p->b = s->b;
    }
}

#define T E7C60
extern "C" void std_vector_imp_GuiAnimationTrack_insert(V7C60* v, T* pos, unsigned int n, const T* value)
{
    if (n == 0)
        return;
    if (n > 0x400000 || v->count > 0x400000 - n) {
        Libc_Fprintf(D_00489738->stream, D_004BF080);
        Libc_Abort();
    }
    if (v->count + n <= v->cap) {
        T* p; T* q; T* src; T* dst; T* end;
        end = v->data + v->count;
        unsigned int after = end - pos;
        if (after < n) {
            p = end;
            for (; after < n; n--) {
                construct(p, value);
                p++;
                v->count++;
            }
            for (q = pos; q < end; q++, p++) {
                construct(p, q);
                v->count++;
            }
        } else {
            src = end - n;
            dst = end;
            for (; src < end; src++, dst++) {
                construct(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            std_copy_backward_GuiAnimationTrack_copy_backward(pos, pos + (after - n), end);
        }
        std_fill_n_GuiAnimationTrack_int_fill_n(pos, n, value);
    } else {
        V7C60 tmp;
        T* dst;
        unsigned int newCap;
        T** tdata;
        T* src;
        unsigned int* tcount;
        T* srcEnd;
        unsigned int need;
        tcount = &tmp.count;
        tdata = &tmp.data;
        tmp.cap = 0;
        *tcount = 0;
        *tdata = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < 0x200000)
                newCap *= 2;
            else
                newCap = 0x400000;
        }
        *tdata = (T*)TStr_Alloc(newCap * sizeof(T), D_004BF0B0, 0x5C);
        tmp.cap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = *tdata;
        for (; src < pos; src++, dst++) {
            construct(dst, src);
            (*tcount)++;
        }
        for (; n; n--, dst++) {
            construct(dst, value);
            (*tcount)++;
        }
        for (; src < srcEnd; src++, dst++) {
            construct(dst, src);
            (*tcount)++;
        }
        std_swap_vectordeleterR_vectordeleterR_49(&tmp, v);
        std_vector_deleter_GuiAnimationTrack_dtor(&tmp, -1);
    }
}
static inline void merge_flush_func_00417C60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00417C60 */
