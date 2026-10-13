#pragma cplusplus on
#include "types.h"

struct Name32 { char s[32]; };
struct Key4 { char s[4]; };
struct NIt { char* volatile p; };
struct Model { char pad[0x44]; char tree[4]; };
struct Root { Model* model; char pad4[0xC]; char attach[0xA0]; char coll[4]; };
struct Act {
    char pad0[0x2EC0];
    Root root;
    char pad2F74[0x3260 - 0x2EC0 - sizeof(Root)];
    unsigned char b3260;
    char pad3261[0x326C - 0x3261];
    void* motion[8];
    char pad328C[0x3290 - 0x328C];
    void* parts[3];
};

extern "C" {
extern char D_004FFBC0[];
extern char D_0049D058[];
extern char D_0049D068[];
extern char D_0049E7A0[];
extern char D_0049E7B0[];
extern char D_0049E7C0[];
extern char D_0049E7D0[];
extern char D_0049E7E0[];
extern char D_0049E7F0[];
extern char D_0049E800[];
extern char D_0049E810[];
extern char D_0049E818[];
extern char D_0049E820[];
extern char D_0049E828[];
void func_001AF160(NIt*, char*, char*);
void func_001AF150(NIt*, char*);
int func_001AF130(NIt*, NIt*);
Model** func_001AF120(NIt*);
void Model_Attach(void*, Model*);
void AnimModel_InitAnim(Root*);
void NamedRootMap_Find(NIt*, void*, Name32*);
void* RootCollection_FindByKey(void*, Key4*);
}

#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma always_inline on
#pragma inline_depth(8)

static inline void N32(Name32* n, char* src)
{
    unsigned char end = 0;
    int i = 0;
    char c;
    char* s = src;
    for (; i < 0x1F; i++) {
        if (s[i] == 0) end = 1;
        c = 0;
        /* empty asm: scheduling barrier only, emits no instructions */
        if (end) asm { .set reorder } else c = s[i];
        n->s[i] = c;
    }
    n->s[i] = 0;
}

static inline void K4(Key4* k, char* src)
{
    unsigned char end = 0;
    unsigned int i = 0;
    char c;
    char* s = src;
    for (; i < 4; i++) {
        if (s[i] == 0) end = 1;
        c = 0;
        /* empty asm: scheduling barrier only, emits no instructions */
        if (end) asm { .set reorder } else c = s[i];
        k->s[i] = c;
    }
}


static inline void Find(NIt* out, Model* m, Name32* n)
{
    Name32* nn = n;
    NIt f;
    NamedRootMap_Find(&f, m->tree, nn);
    *out = f;
}

static inline void* Motion(Model* m, Name32* n)
{
    NIt c2;
    NIt c1;
    Find(&c1, m, n);
    c2 = c1;
    return *(void**)(c2.p + 0x30);
}

static inline Model* Lookup3(char* name)
{
    NIt it;
    NIt end;
    func_001AF160(&it, D_004FFBC0, name);
    func_001AF150(&end, D_004FFBC0);
    Model* r;
    if (func_001AF130(&it, &end)) r = *func_001AF120(&it);
    /* empty asm: scheduling barrier only, emits no instructions */
    else { r = 0; asm { .set reorder } }
    return r;
}
static inline Model* Lookup2(char* name) { return Lookup3(name); }
static inline Model* Lookup(char* name) { return Lookup2(name); }

extern "C" Model* Npc_SetupModel(Act* a)
{
    Key4 k1;
    Key4 k2;
    Key4 k3;
    Name32 n1;
    Name32 n2;
    Name32 n3;
    Name32 n4;
    Name32 n5;
    Name32 n6;
    Name32 n7;
    Name32 n8;
    char* name = 0;
    int t = a->b3260;
    Model* m;
    if (t == 1) name = D_0049D058;
    else if (t == 2) name = D_0049D068;
    if (name) {
    m = Lookup(name);
    if (m) {
    {
        Root* r = &a->root;
        Model_Attach(r->attach, m);
        r->model = m;
        AnimModel_InitAnim(r);
    }
    N32(&n1, D_0049E7A0); a->motion[0] = Motion(m, &n1);
    N32(&n2, D_0049E7B0); a->motion[1] = Motion(m, &n2);
    N32(&n3, D_0049E7C0); a->motion[2] = Motion(m, &n3);
    N32(&n4, D_0049E7D0); a->motion[3] = Motion(m, &n4);
    N32(&n5, D_0049E7E0); a->motion[4] = Motion(m, &n5);
    N32(&n6, D_0049E7F0); a->motion[5] = Motion(m, &n6);
    N32(&n7, D_0049E800); a->motion[6] = Motion(m, &n7);
    N32(&n8, D_0049E810); a->motion[7] = Motion(m, &n8);
    K4(&k1, D_0049E818); { Root* r = &a->root; a->parts[0] = RootCollection_FindByKey(r->coll, &k1); }
    K4(&k2, D_0049E820); { Root* r = &a->root; a->parts[1] = RootCollection_FindByKey(r->coll, &k2); }
    K4(&k3, D_0049E828); { Root* r = &a->root; a->parts[2] = RootCollection_FindByKey(r->coll, &k3); }
    return m;
    }}
    return 0;
}


