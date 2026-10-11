#include "types.h"
typedef struct { char d[0x38]; } E124;
typedef struct { char base[0xC]; E124 e[5]; } T124;
extern void func_00329930(T124* d, const T124* s);
extern void func_00409EC0(E124* d, const E124* s);
static inline void t124_assign(T124* d, const T124* s) {
    E124* a;
    const E124* b;
    func_00329930(d, s);
    a = d->e;
    b = s->e;
    do {
        func_00409EC0(a, b);
        a++;
        b++;
    } while (a != d->e + 5);
}/* Fills n records with a copy of v. */
void func_00409E30(T124* d, unsigned int n, const T124* v) {
    for (; n != 0; n--, d++)
        t124_assign(d, v);
}