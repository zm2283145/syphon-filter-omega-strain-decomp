/*
 * SFOGame/Source/game: 7 files, 00130D10-00130F20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00130D10 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int *cMemMan_Allocate(int, int, char *, int);                     
int Libc_Strcpy(int *, int);                          
#if 0 /* merge_units */
int std_vector_tVUMNamePairPtr_push_back(int, int **);
#endif /* merge_units */
void std_vector_tVUMNamePairPtr_push_back(); /* merge_units */
                       
int strlen(int);                                    
extern char D_0049A890;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void cGameSystem_AddVUMGOBJ(int arg0, int arg1, int arg2, int arg3) {
    int temp_s4;
    int *var_s4;
    int *sp6C;
    int *temp_s3_2;
    int *temp_s2;
    int temp_s3;

    temp_s3 = strlen(arg2) + 1;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s3_2 = (char *)(cMemMan_Allocate(0, temp_s3, &D_0049A890, 0x92C));
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    var_s4 = NULL;
    g_ProfileLockDepth -= 1;
    Libc_Strcpy(temp_s3_2, arg2);
    if (arg3 != 0) {
        temp_s4 = strlen(arg3) + 1;
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        var_s4 = (char *)(cMemMan_Allocate(0, temp_s4, &D_0049A890, 0x933));
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
        Libc_Strcpy(var_s4, arg3);
    }
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s2 = (char *)(cMemMan_Allocate(0, 0xC, &D_0049A890, 0x937));
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    sp6C = temp_s2;
    g_ProfileLockDepth -= 1;
    *temp_s2 = arg1;
    F_(sp6C, 0x4, int) = (int)(temp_s3_2);
    F_(sp6C, 0x8, int) = (int)(var_s4);
    std_vector_tVUMNamePairPtr_push_back(arg0 + 0x2C, &sp6C);
}
static inline void merge_flush_func_00130D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00130D10 */

/* merge_units: begin func_00130F20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void std_vector_pod_int_insert(IndexedList* list, int* end, int n, void* arg);

void std_vector_tVUMNamePairPtr_push_back(IndexedList* list, void* arg) {
    std_vector_pod_int_insert(list, list->base + list->count, 1, arg);
}
static inline void merge_flush_func_00130F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00130F20 */

/* merge_units: begin func_00130F40 */
#pragma push /* merge_units */
#include "vslot_pad.h"

#pragma opt_strength_reduction off
extern int String_CompareNoCase(const char* a, const char* b);

typedef struct Entry {
    int value;
    const char* name;
    const char* alias;
} Entry;

typedef struct Table {
    char pad0[0x30];
    int count;
    Entry** entries;
} Table;

int cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(Table* t, const char* name, int* out)
{
    int i;
    for (i = 0; i < t->count; i++) {
        Entry* e = t->entries[i];
        if (!String_CompareNoCase(e->name, name) || (e->alias && !String_CompareNoCase(e->alias, name))) {
            *out = e->value;
            return 1;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00130F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00130F40 */

/* merge_units: begin func_00131010 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off


int cGameSystem_FindVUMGOBJ_charP_charP_cVUMGOBJPP(Table* t, const char* name, const char* alias, int* out)
{
    int i;
    for (i = 0; i < t->count; i++) {
        Entry* e = t->entries[i];
        if (!String_CompareNoCase(e->name, name) && e->alias && !String_CompareNoCase(e->alias, alias)) {
            *out = e->value;
            return 1;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00131010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00131010 */

/* merge_units: begin func_001310F0 */
#pragma push /* merge_units */
#pragma cplusplus on
class AlObj_r {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int on);
    virtual void Deactivate(int on);
    char pad4[8];
    int id;
    char pad10[0x1C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    bool IsActive() { return b2D && b2C && !b2E; }
};
typedef struct AlNode_r { struct AlNode_r* next; struct AlNode_r* prev; AlObj_r* obj; } AlNode_r;
typedef struct { char pad[0xC4]; int list; int padC8; AlNode_r* head; } AlList_r;
struct AlEq_r { char c; };
struct AlPred_r { AlEq_r op; AlObj_r** ref; AlPred_r(const AlEq_r& e, AlObj_r** r) : op(e), ref(r) {} };
extern "C" {
extern AlObj_r* D_00583878;
extern int D_0058387C;
extern void std_list_imp_voidPtr_remove_if(int* list, AlPred_r pred);
void cGameSystem_RemoveCamera(AlList_r* l, AlObj_r* o);
}
static inline void AlSetCurrent_r(AlObj_r* o)
{
    int def[1];
    int* p;
    D_00583878 = o;
    if (o) {
        p = &o->id;
    } else {
        def[0] = -1;
        p = def;
    }
    D_0058387C = *p;
}
void cGameSystem_RemoveCamera(AlList_r* l, AlObj_r* o)
{
    if (o) {
        AlEq_r eq;
        AlObj_r* next;
        std_list_imp_voidPtr_remove_if(&l->list, AlPred_r(eq, &o));
        if (o->IsActive())
            o->Deactivate(1);
        next = l->head->obj;
        if (next && !next->IsActive()) {
            next->Activate(1);
            AlSetCurrent_r(next);
        } else {
            AlSetCurrent_r(0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001310F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001310F0 */

/* merge_units: begin func_00131240 */
#pragma push /* merge_units */
#pragma cplusplus on
class AlObj_f3 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void Activate(int on);
    virtual void Deactivate(int on);
    char pad4[8];
    int id;
};
typedef struct AlNode_f3 { struct AlNode_f3* next; struct AlNode_f3* prev; AlObj_f3* obj; } AlNode_f3;
typedef struct { char pad[0xC4]; int list; int padC8; AlNode_f3* head; } AlList_f3;
extern "C" {
#if 0 /* merge_units */
extern AlObj_f3* D_00583878;
#endif /* merge_units */
#define D_00583878 (*(AlObj_f3 **)&D_00583878) /* merge_units */



extern void std_list_deleter_voidPtr_erase_listdeleter(AlNode_f3** out, int* list, AlNode_f3** it);
AlObj_f3* cGameSystem_PopCamera(AlList_f3* l);
}
static inline void AlSetCurrent_f3(AlObj_f3* o)
{
    int def[1];
    int* p;
    D_00583878 = o;
    if (o) {
        p = &o->id;
    } else {
        def[0] = -1;
        p = def;
    }
    D_0058387C = *p;
}
AlObj_f3* cGameSystem_PopCamera(AlList_f3* l)
{
    AlNode_f3* ret[1];
    AlNode_f3* it[1];
    AlObj_f3* obj;
    AlObj_f3* next;
    AlNode_f3** hp;
    AlNode_f3* n;
    hp = &l->head;
    n = *hp;
    obj = n->obj;
    it[0] = n;
    std_list_deleter_voidPtr_erase_listdeleter(ret, &l->list, it);
    obj->Deactivate(1);
    next = (*hp)->obj;
    if (next) {
        next->Activate(1);
        AlSetCurrent_f3(next);
    } else {
        AlSetCurrent_f3(0);
    }
    return obj;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00131240(void) {}
#undef D_00583878 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00131240 */

/* merge_units: begin func_00131320 */
#pragma push /* merge_units */
#pragma cplusplus on
class Obj_1320 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Attach(int on);
    virtual void Detach(int on);
    char pad[8];
    int id;
};
struct C_1320 { int pad0; int pad4; Obj_1320* cur; };
struct S_1320 { char pad[0xC4]; int list; int pad8; C_1320* ctl; };
extern "C" {
#if 0 /* merge_units */
extern Obj_1320* D_00583878;
#endif /* merge_units */
#define D_00583878 (*(Obj_1320 **)&D_00583878) /* merge_units */



void std_list_cCAMERA_GOBJPtr_push_front(void* list, Obj_1320** o);
}
extern "C" void cGameSystem_PushCamera(S_1320* self, Obj_1320* o)
{
    int m1;
    int* p;
    if (self->list) {
        Obj_1320* c = self->ctl->cur;
        if (c)
            c->Detach(1);
    }
    o->Attach(1);
    D_00583878 = o;
    if (o)
        p = &o->id;
    else {
        m1 = -1;
        p = &m1;
    }
    D_0058387C = *p;
    std_list_cCAMERA_GOBJPtr_push_front(&self->list, &o);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00131320(void) {}
#undef D_00583878 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00131320 */
