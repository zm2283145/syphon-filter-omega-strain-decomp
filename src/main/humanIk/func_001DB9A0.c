#include "types.h"
typedef struct { int w[0x60 / 4]; } A_1DB9A0;
typedef struct { int w[0x70 / 4]; } B_1DB9A0;
typedef struct { int w[0x78 / 4]; } C_1DB9A0;
typedef struct { int w[3]; } R_1DB9A0;
extern void func_001CEE10(int* it, void* map);
extern void func_001CEE00(int* dst, int* src);
extern void func_001DE2D0(int* it, void* map, short* key);
extern A_1DB9A0* func_001DB850(A_1DB9A0* a, void* val);
extern void func_001DB8C0(B_1DB9A0* b, short key, A_1DB9A0* a);
extern C_1DB9A0* func_001DBA60(C_1DB9A0* c, B_1DB9A0* b);
extern void func_001DBA50(R_1DB9A0* r, void* map, C_1DB9A0* c);
void* func_001DB9A0(void* map, short* key, void* val)
{
    int e[1];
    int f[1];
    int t[1];
    R_1DB9A0 r;
    C_1DB9A0 c;
    B_1DB9A0 b;
    A_1DB9A0 a;
    func_001CEE10(t, map);
    func_001CEE00(e, t);
    func_001DE2D0(f, map, key);
    if (f[0] == e[0]) {
        func_001DB8C0(&b, *key, func_001DB850(&a, val));
        func_001DBA50(&r, map, func_001DBA60(&c, &b));
    }
    return map;
}