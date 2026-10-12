#include "types.h"
typedef struct { int a[4]; } S409;
typedef struct { int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c; float f30; unsigned char b34; } O409;
extern int String_CompareNoCase(char*, char*);
extern void String_CtorCStr_13B480(S409*, char*);
extern void func_0013D680(void*, S409*);
extern void func_00138B70(S409*, int);
O409* func_004095A0(O409* o, char* a, int b, char* c, char* d, float f, unsigned char g) {
    S409 s1;
    S409 s2;
    S409 s3;
    o->f0 = 0;
    o->f4 = 0;
    o->f8 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f28 = 0;
    o->f30 = f;
    o->b34 = g;
    if (a && !String_CompareNoCase(a, "none")) {
        o->fc = -2;
    } else {
        String_CtorCStr_13B480(&s1, a);
        func_0013D680(o, &s1);
        func_00138B70(&s1, 0);
        o->fc = -1;
    }
    if (c && !String_CompareNoCase(c, "none")) {
        o->f10 = -2;
    } else if (!c || !*c) {
        o->f10 = -1;
    } else {
        o->f10 = b;
        String_CtorCStr_13B480(&s2, c);
        func_0013D680(&o->f14, &s2);
        func_00138B70(&s2, 0);
    }
    if (d && !String_CompareNoCase(d, "none")) {
        o->f2c = -2;
    } else {
        String_CtorCStr_13B480(&s3, d);
        func_0013D680(&o->f20, &s3);
        func_00138B70(&s3, 0);
        o->f2c = -1;
    }
    return o;
}
