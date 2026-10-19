/*
 * main/NetObj: range (6 files, 003FB8D0-003FBCD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "net_local_id.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003FB8D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PsObj { char pad[0xC]; int serial; };
struct PsRef {
    PsObj* obj;
    int serial;
    PsObj* Get()
    {
        PsObj* o = obj;
        return (o == 0 || o->serial == serial) ? o : 0;
    }
};
struct PsNode { char pad[0x10]; PsRef ref; };
struct PsIt { PsNode* p; };
extern "C" {
extern char D_0055C770[];
void func_003FC000(PsIt*, void*, int*);
void func_003FB8C0(PsIt*, void*);
PsIt* func_003FB8B0(PsIt*, PsIt*);
void func_003FB750(int);
}
extern "C" PsObj* PlayerSlots_Get(int key)
{
    PsIt e2;
    PsIt it;
    PsIt e;
    PsNode* n;
    PsObj* o;
    bool isnull;
    unsigned char valid;
    PsRef* r;
    PsObj* got;
    func_003FC000(&it, D_0055C770, &key);
    n = it.p;
    func_003FB8C0(&e, D_0055C770);
    func_003FB8B0(&e2, &e);
    if ((n == e2.p) ^ 1) {
        r = &n->ref;
        valid = 1;
        o = r->obj;
        isnull = !o;
        if (!isnull && o->serial != r->serial) valid = 0;
        got = valid ? o : 0;
        if (got) return r->Get();
        func_003FB750(key);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FB8D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FB8D0 */

/* merge_units: begin func_003FB9C0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned int h; } Obj_B9C0;
typedef struct { Obj_B9C0* o; int id; } Pair_B9C0;
typedef struct { int k; Pair_B9C0 p; } Ent_B9C0;
extern unsigned char D_005724B0;
Ent_B9C0* func_003FBF40(void* map, int* key);
int func_00436C00(void* ctx);
int func_00436BA0(void* ctx, int n);
void func_00435F30(void* ctx, unsigned int* h, int owner);
void func_003FB9C0(Obj_B9C0* o)
{
    int k[1];
    char ctx[4];
    int tmp[1];
    Ent_B9C0* r;
    k[0] = ((o->h & 0x7F000000) >> 24) - 1;
    if (k[0] < 0) k[0] = 0;
    r = func_003FBF40(D_0055C770, k);
    r->p.o = o;
    {
        Pair_B9C0* pr = &r->p;
        int* p;
        if (o) p = (int*)&o->h; else { tmp[0] = -1; p = tmp; }
        pr->id = *p;
    }
    if (g_IsMultiplayer && D_005724B0 != 7) {
        unsigned int own;
        func_00436C00(ctx);
        own = (o->h & 0x7F000000) >> 24;
        if (own - 1 == NetLocalId())
            func_00435F30(ctx, &o->h, ((o->h & 0x7F000000) >> 24) - 1);
        func_00436BA0(ctx, -1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FB9C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FB9C0 */

/* merge_units: begin func_003FBB10 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int val; } E4Node;
extern char D_0055C7A0[];
extern void func_001BB080(E4Node** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(E4Node** out, void* in);
static inline int E4Eq(E4Node* a, E4Node* b) { return a == b; }
#pragma bool off
int* NetMap_Lookup(int key)
{
    E4Node* end[1]; E4Node* it[1]; int tmp[1]; int k[1];
    E4Node* n;
    k[0] = key;
    func_001BB080(it, D_0055C7A0, k);
    n = it[0];
    func_0021D360(tmp, D_0055C7A0);
    func_0021D350(end, tmp);
    if (E4Eq(n, end[0]) ^ 1) { int* p = &n->val; if (*p) return p; } return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FBB10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FBB10 */

/* merge_units: begin func_003FBBA0 */
#pragma push /* merge_units */
#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (g_IsMultiplayer) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetGame_InitLocalSlot(int *, int);                        
extern int D_00494178;
extern int D_0055C7B0;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;

int func_003FBBA0(void) {
    int var_a0;

    D_0055C7B0 += 1;
    LOCALID_(var_a0)
    return D_0055C7B0 + (var_a0 * 0x3E8);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FBBA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FBBA0 */

/* merge_units: begin func_003FBC40 */
#pragma push /* merge_units */
#pragma mpwc_relax on
                        
int func_004343E0(int, int);
extern int D_0055C988;

int func_003FBC40(int arg0) {
    int var_s0;

    LOCALID_(var_s0)
    return var_s0 == func_004343E0(D_0055C988, arg0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FBC40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FBC40 */

/* merge_units: begin func_003FBCD0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Alloc_Lock(int, int, int);                          
int Alloc_Unlock(int);                                  
int NetMap_Clear(int *);                              
int func_003FC080(char *);                               
int func_00436380(char *);                               
#if 0 /* merge_units */
int func_00436BA0(char *, int);
#endif /* merge_units */
#define func_00436BA0(a0, a1) (func_00436BA0((void *)(a0), (a1))) /* merge_units */
                            
#if 0 /* merge_units */
int func_00436C00(char *);
#endif /* merge_units */
#define func_00436C00(a0) (func_00436C00((void *)(a0))) /* merge_units */
                               
int func_0043ACE0(char *);                               
int func_0043B190(char *);                               
extern signed char D_00493A10;
extern signed char D_00493A11;
extern signed char D_00493A12;
extern signed char D_00493A13;
extern char D_004BE228;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
#if 0 /* merge_units */
extern char D_0055C770;
#endif /* merge_units */
#define D_0055C770 (*(char*)&D_0055C770) /* merge_units */

extern signed char D_0055C780;
extern signed char D_0055C781;
extern signed char D_0055C782;
extern signed char D_0055C783;
#if 0 /* merge_units */
extern int D_0055C7A0;
#endif /* merge_units */
#define D_0055C7A0 (*(int*)&D_0055C7A0) /* merge_units */

extern char D_0055C7C0;
#if 0 /* merge_units */
extern char *D_0055C988;
#endif /* merge_units */
#define D_0055C988 (*(char **)&D_0055C988) /* merge_units */

extern int D_0055C990;
extern int D_0055C9A0;
extern int D_0055C9A4;
extern int D_0055C9A8;
extern int D_0055C9AC;
extern int D_0055C9B0;

void NetSession_Cleanup(void) {
    int sp2C;
    int sp28;
    char *temp_s0;
    char *var_a0;
    char *var_v1;
    int var_a1;
    int var_a2;

    D_0055C990 = 0;
    if (D_0055C7A0 > 0) {
        NetMap_Clear(&D_0055C7A0);
    }
    func_003FC080(&D_0055C770);
    func_00436C00(&sp2C);
    func_00436380(&sp2C);
    func_0043B190(&sp28);
    func_0043ACE0(&sp28);
    var_a2 = 0;
    var_a0 = &D_0055C7C0;
    do {
        F_(var_a0, 0x14, signed char) = 0;
        F_(var_a0, 0x18, int) = 0;
        var_a1 = 0;
        F_(var_a0, 0x94, short) = 0;
        var_v1 = var_a0;
loop_4:
        F_(var_v1, 0x1C, int) = 0;
        F_(var_v1, 0x20, int) = 0;
        var_a1 += 6;
        F_(var_v1, 0x24, int) = 0;
        F_(var_v1, 0x28, int) = 0;
        F_(var_v1, 0x2C, int) = 0;
        F_(var_v1, 0x30, int) = 0;
        var_v1 += 0x18;
        if (var_a1 < 0x1E) {
            goto loop_4;
        }
        var_a2 += 1;
        var_a0 += 0x98;
    } while (var_a2 < 3);
    temp_s0 = D_0055C988;
    if (temp_s0 != NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9, var_a1, var_a2);
        }
        g_ProfileLockDepth += 1;
        func_00436BA0(temp_s0, -1);
        Mem_Free(0, temp_s0, &D_004BE228, 0x12E);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        D_0055C988 = NULL;
        g_ProfileLockDepth -= 1;
    }
    D_0055C780 = 0;
    D_0055C781 = 0;
    D_0055C782 = 0;
    D_0055C783 = 0;
    D_00493A10 = 2;
    D_00493A11 = 2;
    D_00493A12 = 2;
    D_00493A13 = 2;
    D_0055C9A0 = 0;
    D_0055C9A4 = 0;
    D_0055C9A8 = 0;
    D_0055C9AC = 0;
    D_0055C9B0 = 0;
    func_00436BA0(&sp2C, -1);
}
#undef func_00436BA0 /* merge_units */
#undef func_00436C00 /* merge_units */
#undef D_0055C770 /* merge_units */
#undef D_0055C7A0 /* merge_units */
#undef D_0055C988 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FBCD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FBCD0 */
