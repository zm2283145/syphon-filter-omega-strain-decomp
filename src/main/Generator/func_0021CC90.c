#include "types.h"
#pragma cplusplus on
class F7Sub_21C {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB(); virtual void v22(); virtual void v23(); virtual void Disable(int v);
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; F7Sub_21C* sub; } F7Gen_21C;
typedef struct { F7Sub_21C* target; int arg; } F7Ctx_21C;
extern "C" {
extern unsigned char D_005721C8;
F7Gen_21C* GObj_IdentityB(int h);
void func_00436C00(int* t);
int func_00434440(int* t, unsigned int* id);
void func_00436BA0(int* t, int f);
}
static inline unsigned char F7IsA(F7Gen_21C* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char F7IsB(F7Gen_21C* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" int Script_cGenerator_DisableBy(F7Ctx_21C* c)
{
    F7Gen_21C* g = GObj_IdentityB(c->arg);
    F7Sub_21C* t = c->target;
    if (D_005721C8) {
        int v = -1;
        if (g) {
            if (F7IsA(g) || F7IsB(g)) {
                int tmp[1];
                func_00436C00(tmp);
                v = func_00434440(tmp, &g->id);
                func_00436BA0(tmp, -1);
            } else {
                v = ((g->id & 0x7F000000) >> 24) - 1;
            }
        }
        t->Disable(v);
    } else {
        t->Disable(-1);
    }
    return 0;
}