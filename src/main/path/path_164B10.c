/*
 * main/path: range (4 files, 00164B10-00164CA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tstr_types.h"
#pragma pop
#include "vc_copy.h"

/* merge_units: begin func_00164B10 */
#pragma push /* merge_units */
typedef struct N164 { int pad; struct N164* next; struct N164* prev; float key; } N164;
typedef struct { int pad; N164* next; N164* prev; } H164;
typedef struct { int pad[2]; N164* first; int pad2; H164 sent; int count; } L164;
static inline int Less164(N164* a, N164* b) { return a->key <= b->key; }
void NpcNodeSearch_InsertSorted(L164* l, N164* item) {
    N164* n;
    N164* p;
    for (n = l->first; n != (N164*)&l->sent && !Less164(item, n); n = n->next) { }
    p = n->prev;
    item->next = n;
    item->prev = p;
    p->next = item;
    n->prev = item;
    l->count++;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00164B10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00164B10 */

/* merge_units: begin func_00164B70 */
#pragma push /* merge_units */
void NpcRoute_InsertSorted(L164* l, N164* item) {
    N164* n;
    N164* p;
    for (n = l->first; n != (N164*)&l->sent && !Less164(item, n); n = n->next) { }
    p = n->prev;
    item->next = n;
    item->prev = p;
    p->next = item;
    n->prev = item;
    l->count++;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00164B70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00164B70 */

/* merge_units: begin func_00164BD0 */
#pragma push /* merge_units */
#pragma opt_unroll_loops off
#pragma opt_dead_code off
#pragma cplusplus on
#pragma opt_rotateloops off
struct CxEraseItem {__int128 q[2];~CxEraseItem(){}};
struct CxEraseVec {int capacity,count;CxEraseItem*data;};
extern "C" CxEraseItem*func_00164BD0(CxEraseVec*self,CxEraseItem*first,CxEraseItem*last){
 if(first==last)return first;
 CxEraseItem*end=self->data+self->count;
 int count=((int)end-(int)last)/32;
 CxEraseItem*src;CxEraseItem*dst=first;
 if(count){for(src=last;src<end;++dst,++src)*dst=*src;}
 for(CxEraseItem*p=first+count;p<end;++p)p->~CxEraseItem();
 self->count-=((int)last-(int)first)/32;
 return first;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00164BD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00164BD0 */

/* merge_units: begin func_00164CA0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Q_00164CA0 { __int128 q; };
static inline void Q_00164CA0_Copy(Q_00164CA0* d, const Q_00164CA0* s)
{
    __int128 t;
    __asm__ volatile("lq %0, 0(%1)" : "=r"(t) : "r"(s));
    __asm__ volatile("sq %0, 0(%1)" : : "r"(t), "r"(d) : "memory");
}
struct E_00164CA0 { Q_00164CA0 a; Q_00164CA0 b; ~E_00164CA0() {} };
static inline void E_00164CA0_Assign(E_00164CA0* d, const E_00164CA0* s) { __int128 x = s->a.q; __int128 y = s->b.q; d->a.q = x; d->b.q = y; }
#define COPY(d, s) (VCopyF(&(d)->a, &(s)->a), VCopyF(&(d)->b, &(s)->b))
#define ASSIGN(d, s) E_00164CA0_Assign(d, s)
#define T E_00164CA0
struct V_00164CA0 { unsigned int cap; unsigned int count; T* data; };
static inline void Construct_00164CA0(T* p, const T* src) { if (p) COPY(p, src); }
static inline void ConstructV_00164CA0(T* p, const T* src, const Q_00164CA0* vb) { if (p) (VCopyF(&p->a, &src->a), VCopyF(&p->b, vb)); }
static inline void Fill_00164CA0(T* p, unsigned int k, const T* x) { for (; k; --k, ++p) ASSIGN(p, x); }
extern "C" {
extern char D_0049C1C0[];
extern char D_0049C210[];
extern char D_0049C240[];
void func_001651B0(V_00164CA0* a, V_00164CA0* b);
}
/* whole-function settings; left in effect because C++ code generation is deferred to end of file */
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_code off
#pragma opt_loop_invariants off
extern "C" void func_00164CA0(V_00164CA0* v, T* pos, unsigned int n, const T* value)
{
    /* declared before vb so pb colours above vb (retail a3/a2) */
    Q_00164CA0* pb; const Q_00164CA0* vb;
    if (n == 0)
        return;
    unsigned int max = 0x300000;
    if (n > max || v->count > max - n) {
        func_00123BE8(D_00489738->stream, D_0049C1C0);
        func_00121B60();
    }
    unsigned int cap = v->cap; unsigned int cnt = v->count;
    if (cnt + n <= cap) {
        T* end = v->data + cnt;
        unsigned int after = end - pos;
        if (after < n) {
            T* p = end; vb = &value->b;
            for (; n > after; n--) {
                if (p) { VCopyF(&p->a, &value->a); pb = &p->b; VCopyF(pb, vb); }
                p++;
                v->count++;
            }
            for (T* q = pos; q < end; q++, p++) {
                Construct_00164CA0(p, q);
                v->count++;
            }
        } else {
            T* src = end - n;
            T* dst = end;
            for (; src < end; src++, dst++) {
                Construct_00164CA0(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            T* last = pos + (after - n);
            T* d = end;
            while (last > pos) {
                --last;
                --d;
                ASSIGN(d, last);
            }
        }
        Fill_00164CA0(pos, n, value);
    } else {
        V_00164CA0 tmp;
        tmp.cap = 0; tmp.count = 0; tmp.data = 0;
        unsigned int need = v->count + n;
        /* empty then-arm (scheduling barrier) keeps retail's block layout */
        unsigned int newCap = v->cap; if (newCap != 0) asm { .set reorder } else newCap = 1;
        unsigned int half = max / 2;
        while (need > newCap) { if (newCap < half) newCap *= 2; else newCap = max; }
        T* buf = (T*)TStr_Alloc(newCap * sizeof(T), D_0049C210, 0x5C);
        { V_00164CA0* tp = &tmp; tmp.data = buf; tp->cap = newCap; }
        T* dst; T* src; T* srcEnd;
        src = v->data;
        srcEnd = src + v->count;
        dst = tmp.data;
        for (; src < pos; src++, dst++) {
            Construct_00164CA0(dst, src);
            tmp.count++;
        }
        vb = &value->b;
        for (; n; dst++, n--) {
            ConstructV_00164CA0(dst, value, vb);
            tmp.count++;
        }
        for (; src < srcEnd; src++, dst++) {
            Construct_00164CA0(dst, src);
            tmp.count++;
        }
        func_001651B0(&tmp, v);
        {
            T* b_ = tmp.data;
            T* e_ = b_ + tmp.count;
            while (b_ < e_) (--e_)->~T();
            T* fp_ = tmp.data;
            tmp.count = 0; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049C240, 0x64); }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00164CA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00164CA0 */
