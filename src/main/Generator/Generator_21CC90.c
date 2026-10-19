/*
 * main/Generator: range (2 files, 0021CC90-0021CDD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0021CC90 */
#pragma push /* merge_units */
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
extern unsigned char g_IsMultiplayer;
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
    if (g_IsMultiplayer) {
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CC90 */

/* merge_units: begin func_0021CDD0 */
#pragma push /* merge_units */
#pragma cplusplus on
class F8Sub_21C {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB(); virtual void v22(); virtual void Enable(int v);
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; F8Sub_21C* sub; } F8Gen_21C;
typedef struct { F8Sub_21C* target; int arg; } F8Ctx_21C;
extern "C" {
#if 0 /* merge_units */
F8Gen_21C* GObj_IdentityB(int h);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((F8Gen_21C *)GObj_IdentityB((a0))) /* merge_units */

}
static inline unsigned char F8IsA(F8Gen_21C* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char F8IsB(F8Gen_21C* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" int Script_cGenerator_EnableBy(F8Ctx_21C* c)
{
    F8Gen_21C* g = GObj_IdentityB(c->arg);
    F8Sub_21C* t = c->target;
    if (g_IsMultiplayer) {
        int v = -1;
        if (g) {
            if (F8IsA(g) || F8IsB(g)) {
                int tmp[1];
                func_00436C00(tmp);
                v = func_00434440(tmp, &g->id);
                func_00436BA0(tmp, -1);
            } else {
                v = ((g->id & 0x7F000000) >> 24) - 1;
            }
        }
        t->Enable(v);
    } else {
        t->Enable(-1);
    }
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CDD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CDD0 */
