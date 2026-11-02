/*
 * Libs/SFOLib/Source/HeadSet: 12 files, 004373A0-00437640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004373A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004BFD10[]; void cMemMan_Deallocate(int pool, void* p, char* file, int line); }
extern "C" void cAllocator_node_deallocate_nodeP_uint_17(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        cMemMan_Deallocate(0, node, D_004BFD10, 0x64);
    }
}
static inline void merge_flush_func_004373A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004373A0 */

/* merge_units: begin func_00437440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */


void* std_tree_pair_tNPCInfoPtr_value_compare_node_alloc(char* self) {
    return self + 4;
}

void cAllocator_pair_tNPCInfoPtr_destroy(void) {
}

void* std_tree_pair_tNPCInfoPtr_value_compare_alloc(void* self) {
    return self;
}

Map* std_tree_pair_tNPCInfoPtr_value_compare_ctor(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
static inline void merge_flush_func_00437440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437440 */

/* merge_units: begin func_00437490 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00437490;
extern void std_tree_pair_tNPCInfoPtr_value_compare_destroy(R1Tree_00437490* t, void* n);
extern void operator_delete(void* p);
R1Tree_00437490* std_tree_pair_tNPCInfoPtr_value_compare_dtor(R1Tree_00437490* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_tNPCInfoPtr_value_compare_destroy(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
static inline void merge_flush_func_00437490(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437490 */

/* merge_units: begin func_004374F0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_004374F0;
typedef struct { R1Tree_004374F0 tree; } R1Own_004374F0;
#if 0 /* merge_units */
extern void std_tree_pair_tNPCInfoPtr_value_compare_dtor(R1Tree_004374F0* t, short del);
#endif /* merge_units */
#define std_tree_pair_tNPCInfoPtr_value_compare_dtor(a0, a1) ((void)std_tree_pair_tNPCInfoPtr_value_compare_dtor((R1Tree_00437490 *)(a0), (a1))) /* merge_units */


R1Own_004374F0* cAssocArray_tNPCInfoPtr_bool_dtor(R1Own_004374F0* o, short del)
{
    if (o) {
        R1Tree_004374F0* t = &o->tree;
        if (t)
            std_tree_pair_tNPCInfoPtr_value_compare_dtor(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef std_tree_pair_tNPCInfoPtr_value_compare_dtor /* merge_units */
static inline void merge_flush_func_004374F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004374F0 */

/* merge_units: begin func_00437550 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_tNPCInfoPtr_dtor, func_00135C90)
static inline void merge_flush_func_00437550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437550 */

/* merge_units: begin func_004375B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between NPCInfoObject.cc (ends 0x00437490) and GenInfoObject.cc.
 */


/* Clears four bytes. */
char* cNPCInfoObject_tBoolStruct_ctor(char* bytes) {
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 0;
    return bytes;
}
static inline void merge_flush_func_004375B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004375B0 */

/* merge_units: begin func_004375D0 */
#pragma push /* merge_units */
extern volatile unsigned char D_005723C8;
extern volatile int D_00582CF0;

/* Reset the shared NPC information state. */
void HeadsetSemaphore_NetHumanDeleteCallback(void)
{
    if (D_005723C8 == 0)
        D_005723C8 = 1;
    D_00582CF0 = 0;
    D_005723C8 = 0;
}
static inline void merge_flush_func_004375D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004375D0 */

/* merge_units: begin func_00437600 */
#pragma push /* merge_units */
typedef struct { int unk0; int value; } Entry4;
extern void* D_00583870;
#if 0 /* merge_units */
extern void NetGetObject(Entry4** out, void* key);
#endif /* merge_units */
int NetGetObject(void*, void*); /* merge_units */
#define NetGetObject(a0, a1) ((void)NetGetObject((void *)(a0), (a1))) /* merge_units */


/* Looks up the global key and returns the entry's value, or -1 if not found. */
int HeadsetSemaphore_GetOwner(void)
{
    Entry4* entry;
    NetGetObject(&entry, D_00583870);
    if (entry)
        return entry->value;
    return -1;
}
#undef NetGetObject /* merge_units */
static inline void merge_flush_func_00437600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437600 */

/* merge_units: begin func_00437640 */
#pragma push /* merge_units */
#include "net_local_id.h"
#pragma inline_depth(10)
#pragma opt_dead_code off
typedef struct { int f0; int f4; } P_437640;
#if 0 /* merge_units */
extern unsigned char D_005723C8;
#endif /* merge_units */
#define D_005723C8 (*(unsigned char*)&D_005723C8) /* merge_units */

extern unsigned char D_00582B88;
extern unsigned char D_00582D28;
extern unsigned char D_00582D20;
extern unsigned char D_00583050;
extern void* D_00497548;
extern int D_00582D08;
extern unsigned char D_00583860;
#if 0 /* merge_units */
int NetGetObject(P_437640** out, void* s);
#endif /* merge_units */
#define NetGetObject(a0, a1) (NetGetObject((void *)(a0), (a1))) /* merge_units */

void NetReleaseObjectPrivateOwnership(void* s);
int lgAudStartRecording(void* p);
int lgAudStopRecording(void* p);
int cDME_GetTime(int v);

static inline int Owner_437640(void)
{
    P_437640* p;
    NetGetObject(&p, D_00583870);
    return p ? p->f4 : -1;
}

static inline void Release_437640(void)
{
    int o = Owner_437640();
    if (o == NetLocalId()) {
        NetReleaseObjectPrivateOwnership(D_00583870);
        D_00582D28 = 1;
    }
    if (D_00582B88) {
        if (lgAudStopRecording(D_00497548) == 0x80000006) D_00582B88 = 0;
        D_00582D08 = cDME_GetTime(1) + 2000;
    }
    D_00583860 = 0;
}

void func_00437640(int id, void* sess, int kind)
{
    P_437640* x;
    P_437640* h;
    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (NetGetObject(&h, sess) == 0 && kind == -2 && h->f4 == NetLocalId()) {
        if (D_00583860) {
            if (D_00582B88) {
                int r = lgAudStartRecording(D_00497548);
                if (r == 0) D_00583050 = 1;
                else if (r == 0x80000006) D_00582B88 = 0;
            }
            D_00583860 = 0;
            D_00582D20 = 1;
        } else {
            Release_437640();
        }
    }
    if (0) NetGetObject(&x, 0); /* dead under opt_dead_code off: reserves retail's unused 0x2C stack slot */
    D_005723C8 = 0;
}
#undef D_005723C8 /* merge_units */
#undef NetGetObject /* merge_units */
static inline void merge_flush_func_00437640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437640 */

/* merge_units: begin func_00437830 */
#pragma push /* merge_units */
#include "NetObjectMgr_types.h"


#if 0 /* merge_units */
extern int D_00582CF0;
#endif /* merge_units */
#define D_00582CF0 (*(int*)&D_00582CF0) /* merge_units */

#if 0 /* merge_units */
extern int NetGetObject(NetSessionEntry** result, void* key);
#endif /* merge_units */
#define NetGetObject(a0, a1) (NetGetObject((void *)(a0), (a1))) /* merge_units */



/* Cache the selected session entry's value when lookup succeeds. */
void HeadsetSemaphore_NetHeadsetSemaphoreCreationCallback(void* unused, void* key)
{
    NetSessionEntry* result[2];
    if (!D_005723C8)
        D_005723C8 = 1;
    if (!NetGetObject(result, key)) {
        int value = result[0]->value;
        D_00583870 = key;
        D_00582CF0 = value;
    }
    D_005723C8 = 0;
}
#undef D_00582CF0 /* merge_units */
#undef NetGetObject /* merge_units */
static inline void merge_flush_func_00437830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437830 */

/* merge_units: begin func_004378A0 */
#pragma push /* merge_units */
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm78A0;
extern int NetRegisterObjectStart(void);
extern int NetObjectField(int* db, int offset, int size, int count, int type, Prm78A0* prm);
extern int NetRegisterStructure(int* table, char* name, int size);
extern int NetRegisterRemoteObjectCallback(int table, void* a, void* b, void* c);
extern int D_00583868;
#if 0 /* merge_units */
extern void HeadsetSemaphore_NetHeadsetSemaphoreCreationCallback();
#endif /* merge_units */

#if 0 /* merge_units */
extern void func_00437640();
#endif /* merge_units */

#if 0 /* merge_units */
extern void HeadsetSemaphore_NetHumanDeleteCallback();
#endif /* merge_units */
#define HeadsetSemaphore_NetHumanDeleteCallback() (HeadsetSemaphore_NetHumanDeleteCallback()) /* merge_units */


unsigned char HeadsetSemaphore_InitNet(void)
{
    int db;
    Prm78A0 prm;
    unsigned char ok;
    ok = 0;
    prm.max = 1000;
    prm.ver = 1;
    prm.mode = 0;
    prm.flags = 0;
    if (NetRegisterObjectStart() == 0 &&
        NetObjectField(&db, 0, 1, 1, 1, &prm) == 0 &&
        NetRegisterStructure(&D_00583868, "HeadsetSemaphore", 1) == 0) {
        NetRegisterRemoteObjectCallback(D_00583868, HeadsetSemaphore_NetHeadsetSemaphoreCreationCallback, func_00437640, HeadsetSemaphore_NetHumanDeleteCallback);
        ok = 1;
    }
    return ok;
}
#undef HeadsetSemaphore_NetHumanDeleteCallback /* merge_units */
static inline void merge_flush_func_004378A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004378A0 */

/* merge_units: begin func_00437950 */
#pragma push /* merge_units */
#pragma inline_depth(10)
typedef struct { int f0; int f4; } P_437950;
#if 0 /* merge_units */
void NetGetObject(P_437950** out, void* s);
#endif /* merge_units */
#define NetGetObject(a0, a1) ((void)NetGetObject((void *)(a0), (a1))) /* merge_units */


int NetRequestObjectPrivateOwnership(void* s);

static inline int Owner_437950(void)
{
    P_437950* p;
    NetGetObject(&p, D_00583870);
    return p ? p->f4 : -1;
}

static inline int OwnerW_437950(void) { return Owner_437950(); }
static inline void Release_437950(void)
{
    int o = Owner_437950();
    if (o == NetLocalId()) {
        NetReleaseObjectPrivateOwnership(D_00583870);
        D_00582D28 = 1;
    }
    if (D_00582B88) {
        if (lgAudStopRecording(D_00497548) == 0x80000006) D_00582B88 = 0;
        D_00582D08 = cDME_GetTime(1) + 2000;
    }
    D_00583860 = 0;
}

void func_00437950(int on)
{
    if (D_00582B88) {
        if (!on) {
            Release_437950();
        } else if (on) {
            if (D_00582D08 < cDME_GetTime(1)) {
                int o = OwnerW_437950();
                if (o != NetLocalId()) {
                    D_00583860 = 1;
                    if (NetRequestObjectPrivateOwnership(D_00583870)) D_00583860 = 0;
                }
            }
        }
    } else {
        Release_437950();
    }
}
#undef NetGetObject /* merge_units */
static inline void merge_flush_func_00437950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437950 */
