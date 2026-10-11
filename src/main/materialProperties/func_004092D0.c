#include "types.h"
typedef struct { int a; int b; int c; } S92Str;
typedef struct { S92Str key; unsigned char val; } S92Pair;
typedef struct { void* it; unsigned char ok; } S92Res;
extern void func_0013BCB0(S92Str* dst, const S92Str* src);
extern void func_00138B70(S92Str* s, int del);
extern void func_004089B0(S92Pair* out, S92Str* key, unsigned char val);
extern void func_0040A880(S92Res* out, void* map, S92Pair* p);
/* Inserts (name, value) into the map; returns whether it was inserted. */
unsigned char func_004092D0(void* map, const S92Str* name, unsigned char* val) {
    S92Res r;
    S92Str k;
    S92Pair p1;
    S92Pair p2;
    unsigned char ok;
    func_0013BCB0(&k, name);
    func_004089B0(&p1, &k, *val);
    func_0013BCB0(&p2.key, &p1.key);
    p2.val = p1.val;
    func_0040A880(&r, map, &p2);
    ok = r.ok;
    func_00138B70(&p2.key, 0);
    func_00138B70(&p1.key, 0);
    func_00138B70(&k, 0);
    return ok;
}