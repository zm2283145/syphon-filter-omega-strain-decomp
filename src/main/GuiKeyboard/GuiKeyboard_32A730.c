/*
 * main/GuiKeyboard: 2 files, 0032A730-0032A870
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032A730 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "short_string_replace.h"
extern "C" void String_Reserve(ShortStr* self, unsigned int n);
struct E_32A730 { ShortStr name; int val; ShortStr desc; unsigned char flag; int a, b, c; };
static inline void StrCopy_32A730(ShortStr* self, const ShortStr* src)
{
    if (!ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        self->u.l.word = 0;
        self->u.l.length = 0;
        self->u.l.data = 0;
        String_Reserve(self, src->u.l.length);
        ShortStrIterTag tag;
        String_Replace(self, 0, 0, src->u.l.data, src->u.l.data + src->u.l.length, tag);
    }
}
static inline void StrCopy2_32A730(ShortStr* self, const ShortStr* src)
{
    if (!ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        self->u.l.word = 0;
        self->u.l.length = 0;
        self->u.l.data = 0;
        const unsigned int& len = src->u.l.length;
        String_Reserve(self, len);
        ShortStrIterTag tag;
        String_Replace(self, 0, 0, src->u.l.data, src->u.l.data + len, tag);
    }
}
extern "C" E_32A730* func_0032A730(E_32A730* self, const E_32A730* src)
{
    StrCopy_32A730(&self->name, &src->name);
    self->val = src->val;
    { ShortStr* d = &self->desc; StrCopy2_32A730(d, &src->desc); }
    self->flag = src->flag;
    self->a = src->a;
    self->b = src->b;
    self->c = src->c;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032A730 */

/* merge_units: begin func_0032A870 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct E2A870 { TStr a; int b; TStr c; unsigned char d; int e; int f; int g; };
struct V2A870 { unsigned int cap; unsigned int count; E2A870* data; };
extern "C" {
extern char D_004B88A0[];
extern char D_004B88C0[];
char D_004B8850[] = "vector::assign length error\n";
void func_00329930(TStr* d, const TStr* s);
void func_003282A0(E2A870* p, int f);
void* Mem_PlacementNew(unsigned int size, void* p);
#if 0 /* merge_units */
void func_0032A730(void* d, const E2A870* s);
#endif /* merge_units */
#define func_0032A730(a0, a1) ((void)func_0032A730((E_32A730 *)(a0), (const E_32A730 *)(a1))) /* merge_units */

void func_0032AB90(V2A870* v);
void func_0032A190(void* allocation, int pool, int destroy, char* file, int line);
}
static inline const unsigned int& Min2A870(const unsigned int& a, const unsigned int& b) { return b < a ? b : a; }
static inline E2A870* Alloc2A870(unsigned int n) { AllocGuard g; return (E2A870*)Mem_Alloc(0, n * sizeof(E2A870), D_004B88C0, 0x5C); }

extern "C" void func_0032A870(V2A870* v, const E2A870* first, const E2A870* last)
{
    unsigned int n = last - first;
    if (n <= v->cap) {
        const unsigned int& m = Min2A870(n, v->count);
        E2A870* p = v->data;
        E2A870* e = p + m;
        for (; p < e; p++, first++) {
            func_00329930(&p->a, &first->a);
            p->b = first->b;
            func_00329930(&p->c, &first->c);
            p->d = first->d;
            p->e = first->e;
            p->f = first->f;
            p->g = first->g;
        }
        if (n < v->count) {
            E2A870* e2 = v->data + v->count;
            for (; p < e2; p++)
                func_003282A0(p, -1);
            v->count = n;
        } else if (v->count < n) {
            for (; first != last; first++, p++) {
                void* m = Mem_PlacementNew(sizeof(E2A870), p);
                if (m)
                    func_0032A730(m, first);
                v->count++;
            }
        }
    } else {
        if (n > 0x22E8BA) {
            Libc_Fprintf(D_00489738->stream, D_004B8850);
            Libc_Abort();
        }
        func_0032AB90(v);
        if (v->data) {
            if (v->data)
                func_0032A190(v->data, 0, 0, D_004B88A0, 100);
            v->data = 0;
            v->cap = 0;
        }
        {
            E2A870** pd = &v->data;
            *pd = Alloc2A870(n);
        }
        v->cap = n;
        {
            E2A870* p = v->data;
            for (; first != last; first++, p++) {
                void* m = Mem_PlacementNew(sizeof(E2A870), p);
                if (m)
                    func_0032A730(m, first);
                v->count++;
            }
        }
    }
}
#undef func_0032A730 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032A870 */
