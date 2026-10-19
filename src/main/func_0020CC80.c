#include "types.h"

typedef struct E { int w[9]; } E;
typedef struct V { E* data; unsigned int count; unsigned int cap; } V;
extern char D_004A3E90[];
extern unsigned int func_0020CC20(E* first, E* last);
extern unsigned int func_0020B320(V* v);
extern unsigned int* func_00209EE0(unsigned int* a, unsigned int* b);
extern E* func_0020AEE0(V* v);
extern void func_0020B0F0(E* d, E* s);
extern E* func_001F34D0(V* v);
extern void* func_0020B2F0(V* v);
extern void func_0020C640(void* alloc, E* p);
extern void func_0020B220(void* alloc, E* p, E* s);
extern unsigned int func_0020B380(V* v);
extern void func_00209950(const char* msg);
extern void func_001F36F0(V* v);
extern E** func_001F3510(V* v);
extern unsigned int* func_0020AF50(V* v);
extern void func_0020C750(void* alloc, E* p, unsigned int n);
extern E* func_0020AF10(void* alloc, unsigned int n, int hint);

#pragma push
#pragma optimization_level 1
void Vector_Assign_20CC80(V* v, E* first, E* last)
{
    unsigned int n;
    E* p;
    E* end;
    n = func_0020CC20(first, last);
    if (n <= func_0020B320(v)) {
        unsigned int k = *func_00209EE0(&n, &v->count);
        p = func_0020AEE0(v);
        end = p + k;
        while (p < end) {
            func_0020B0F0(p, first);
            p++;
            first++;
        }
        if (n < v->count) {
            end = func_001F34D0(v);
            while (p < end) {
                func_0020C640(func_0020B2F0(v), p);
                p++;
            }
            v->count = n;
        } else if (v->count < n) {
            while (first != last) {
                func_0020B220(func_0020B2F0(v), p, first);
                first++;
                p++;
                v->count++;
            }
        }
    } else {
        if (n > func_0020B380(v))
            func_00209950(D_004A3E90);
        func_001F36F0(v);
        if (*func_001F3510(v) != 0) {
            func_0020C750(func_0020B2F0(v), *func_001F3510(v), *func_0020AF50(v));
            *func_001F3510(v) = 0;
            *func_0020AF50(v) = 0;
        }
        *func_001F3510(v) = func_0020AF10(func_0020B2F0(v), n, 0);
        *func_0020AF50(v) = n;
        p = func_0020AEE0(v);
        while (first != last) {
            func_0020B220(func_0020B2F0(v), p, first);
            first++;
            p++;
            v->count++;
        }
    }
}
#pragma pop

