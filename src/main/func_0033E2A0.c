#pragma cplusplus on
#include "types.h"
struct V33E { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual void v25(int); };
typedef struct { void* vt; char pad[0x90]; unsigned char b94; char p95[3]; int f98; int f9c; int fa0; int fa4; } O33E2;
extern "C" {
extern int func_0033EF10(O33E2*, int, int);
extern void func_0041E0F0(O33E2*, int, int, int, int);
}
extern "C" int func_0033E2A0(O33E2* o, int id, int flag) {
    if (id == o->f9c) {
        if (o->b94 && flag) {
            if (func_0033EF10(o, 0, 0)) ((V33E*)o)->v25(0);
        } else {
            func_0033EF10(o, 0, 1);
            func_0041E0F0(o, o->f9c, 6, (int)"onPressed", 0);
        }
        return 1;
    }
    if (id == o->f98) {
        func_0033EF10(o, 2, 1);
        func_0041E0F0(o, o->f98, 6, (int)"onPressed", 0);
        return 1;
    }
    if (id == o->fa0) {
        func_0033EF10(o, 1, 1);
        func_0041E0F0(o, o->fa0, 6, (int)"onPressed", 0);
        return 1;
    }
    if (id == o->fa4) {
        func_0033EF10(o, 3, 1);
        func_0041E0F0(o, o->fa4, 6, (int)"onPressed", 0);
        return 1;
    }
    return 0;
}
