#include "types.h"
typedef struct { int w[4]; } V4_1842;
typedef struct { V4_1842 v[4]; int f40[4]; unsigned char b50; unsigned char b51; unsigned char b52; char pad[13]; int f60[4]; } E_1842;
extern void Vec4_Copy(V4_1842* d, V4_1842* s);
extern void func_00139BB0(int* d, int* s);
extern void func_00139BA0(int* d, int* s);
static inline void Assign_1842(E_1842* d, E_1842* s)
{
    Vec4_Copy(&d->v[0], &s->v[0]);
    Vec4_Copy(&d->v[1], &s->v[1]);
    Vec4_Copy(&d->v[2], &s->v[2]);
    Vec4_Copy(&d->v[3], &s->v[3]);
    d->b50 = s->b50;
    func_00139BB0(d->f40, s->f40);
    func_00139BA0(d->f60, s->f60);
    d->b51 = s->b51;
    d->b52 = s->b52;
}E_1842* func_001842C0(E_1842* first, E_1842* last, E_1842* dest)
{
    while (first < last) {
        --last;
        --dest;
        Assign_1842(dest, last);
    }
    return dest;
}