/*
 * main/gobj: 2 files, 003D0B90-003D0C10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D0B90 */
#pragma push /* merge_units */
#include "types.h"
extern void ReceiverList_Dtor_3D0A90(void* self, short del);
extern void func_003D0B10(void* self, short del);
extern void operator_delete(void* p);
void* TextManager_Destroy(void* self, short del)
{
    if (self) {
        void* a = (char*)self + 0x10;
        void* b;
        if (a)
            ReceiverList_Dtor_3D0A90(a, 0);
        b = (char*)self + 4;
        if (b)
            func_003D0B10(b, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D0B90 */

/* merge_units: begin func_003D0C10 */
#pragma push /* merge_units */
typedef struct { int value; } Word_003D0C10;
typedef struct Node3D { struct Node3D* prev; struct Node3D* next; int f8; int fC; int f10[3]; int f1C; char pad20[0x10]; float f30; float f34; } Node3D;
typedef struct { int size; Node3D hdr; } List3D;
typedef struct { int pad; Node3D* nodes_unused; Node3D* data; } Vec3D;
typedef struct {
    int f0;
    List3D list;
    char padx[0x10 - 4 - sizeof(List3D) > 0 ? 0x10 - 4 - sizeof(List3D) : 1];
} Dummy;
typedef struct {
    int f0;
    int size;
    Node3D* prev;
    Node3D* next;
    char vec[0xC];
    unsigned char b1C;
} Obj3D;
extern Node3D* func_003D0DC0(void* l);
extern Word_003D0C10* func_003D0DB0(Word_003D0C10* w, void* v);
extern Word_003D0C10* func_003D0DA0(Word_003D0C10* w, void* v);
extern void func_003D0D90(Word_003D0C10* w, void* v);
extern Word_003D0C10* func_003D0D80(Word_003D0C10* d, Word_003D0C10* s);
extern void func_003D0D70(Word_003D0C10* w, void* v);
extern int String_CStr_189540(void* p);
extern void Font_DrawString(int a0, int a1, void* a2, float x, float y, float z, float p, float q, float r);
extern void TextObj_Draw(int c);
extern void func_003D10B0(Word_003D0C10* out, int* size, Word_003D0C10* first, Word_003D0C10* last);
static inline int ne3D(Node3D* n, Word_003D0C10* w) { return n != (Node3D*)w->value; }
void TextManager_DrawImmediate(Obj3D* o)
{
    Word_003D0C10 end, end2, b, d, it, e, out, first, last, a, c;
    Word_003D0C10* pe;
    Node3D* n;
    Word_003D0C10* pf;
    Node3D* m;
    if (o->b1C) {
        func_003D0DB0(&it, func_003D0DC0(&o->size)->next);
        n = (Node3D*)it.value;
        func_003D0DA0(&e, func_003D0DC0(&o->size));
        end.value = e.value;
        pe = &end;
        for (; ne3D(n, pe); n = n->next) {
            int* s = (int*)((char*)n + 0x10);
            Font_DrawString(s[3], String_CStr_189540(s), s + 4, *(float*)(s + 8), *(float*)(s + 9), 0.001f, 0.0f, 0.0f, 0.0f);
        }
        func_003D0D90(&a, o->vec);
        func_003D0D80(&b, &a);
        m = (Node3D*)b.value;
        func_003D0D70(&c, o->vec);
        func_003D0D80(&d, &c);
        end2.value = d.value;
        pf = &end2;
        for (; ne3D(m, pf); m = m->next)
            TextObj_Draw(m->f8);
    }
    last.value = (int)&o->prev;
    first.value = (int)o->next;
    func_003D10B0(&out, &o->size, &first, &last);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D0C10 */
