#include "types.h"

typedef struct E { int w[3]; } E;
typedef struct V { E* data; unsigned int count; unsigned int cap; } V;
extern char D_004A3E90[];
extern unsigned int func_002099C0(E* first, E* last);
extern unsigned int func_00209F00(V* v);
extern unsigned int* func_00209EE0(unsigned int* a, unsigned int* b);
extern E* func_00209880(V* v);
extern void func_00209E50(E* d, E* s);
extern E* func_001F4110(V* v);
extern void* func_00209920(V* v);
extern void func_00209E20(void* alloc, E* p);
extern void func_002097C0(void* alloc, E* p, E* s);
extern unsigned int func_00209980(V* v);
extern void func_00209950(const char* msg);
extern void func_001F4330(V* v);
extern E** func_001F4150(V* v);
extern unsigned int* func_002098B0(V* v);
extern void func_00209D30(void* alloc, E* p, unsigned int n);
extern E* func_002098E0(void* alloc, unsigned int n, int hint);

#pragma push
#pragma optimization_level 1
void func_00209A20(V* v, E* first, E* last)
{
    unsigned int n;
    E* p;
    E* end;
    n = func_002099C0(first, last);
    if (n <= func_00209F00(v)) {
        unsigned int k = *func_00209EE0(&n, &v->count);
        p = func_00209880(v);
        end = p + k;
        while (p < end) {
            func_00209E50(p, first);
            p++;
            first++;
        }
        if (n < v->count) {
            end = func_001F4110(v);
            while (p < end) {
                func_00209E20(func_00209920(v), p);
                p++;
            }
            v->count = n;
        } else if (v->count < n) {
            while (first != last) {
                func_002097C0(func_00209920(v), p, first);
                first++;
                p++;
                v->count++;
            }
        }
    } else {
        if (n > func_00209980(v))
            func_00209950(D_004A3E90);
        func_001F4330(v);
        if (*func_001F4150(v) != 0) {
            func_00209D30(func_00209920(v), *func_001F4150(v), *func_002098B0(v));
            *func_001F4150(v) = 0;
            *func_002098B0(v) = 0;
        }
        *func_001F4150(v) = func_002098E0(func_00209920(v), n, 0);
        *func_002098B0(v) = n;
        p = func_00209880(v);
        while (first != last) {
            func_002097C0(func_00209920(v), p, first);
            first++;
            p++;
            v->count++;
        }
    }
}
#pragma pop
