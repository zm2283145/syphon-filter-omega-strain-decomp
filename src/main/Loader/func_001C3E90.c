#include "types.h"
#include "canonical_key_copy.h"
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key_1C3E90;
typedef struct { char pad[0x24]; int tree; } Map_1C3E90;
typedef struct { char pad[0xC]; Map_1C3E90* second; } Val_1C3E90;
typedef struct { char pad[0xC]; Val_1C3E90 v; } Node_1C3E90;
typedef struct { Node_1C3E90* n; } It_1C3E90;
extern char D_004FFBC0[];
extern void func_00130B00(It_1C3E90* out, void* tree);
extern void func_001C00C0(It_1C3E90* out, int tree);
extern void Tree_Successor(It_1C3E90* it);
extern void ModelCtx_FindNodeById(It_1C3E90* out, int* tree, Key_1C3E90* key);
extern void func_0018C730(It_1C3E90* out, int* tree);
extern int func_0018C710(It_1C3E90* a, It_1C3E90* b);
static inline unsigned char EqB_1C3E90(void* a, void* b) { return a == b; }
static inline int Eq_1C3E90(void* a, void* b) { return a == b; }
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
unsigned char func_001C3E90(void* mgr, char* name)
{
    It_1C3E90 it;
    It_1C3E90 end;
    It_1C3E90 b;
    It_1C3E90 e;
    It_1C3E90 f;
    It_1C3E90 g;
    Key_1C3E90 key;
    unsigned char ok = 1;
    func_00130B00(&b, D_004FFBC0);
    it.n = b.n;
    func_001C00C0(&e, (int)D_004FFBC0);
    end.n = e.n;
    while ((Eq_1C3E90(it.n, end.n) != 0) ^ 1) {
        Val_1C3E90* v = &it.n->v;
        Map_1C3E90** pm = &v->second;
        Map_1C3E90* m;
        CANONICAL_KEY_INIT_IX(key.c, name)
        m = *pm;
        ModelCtx_FindNodeById(&f, &m->tree, &key);
        func_0018C730(&g, &m->tree);
        if (!func_0018C710(&f, &g)) { ok = 0; break; }
        Tree_Successor(&it);
    }
    return ok;
}
#pragma pop


