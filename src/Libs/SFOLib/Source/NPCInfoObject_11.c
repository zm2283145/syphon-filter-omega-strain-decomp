/*
 * Libs/SFOLib/Source/NPCInfoObject: 3 files, 00434740-00434BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00434740 */
#pragma push /* merge_units */
#include "NetObjectMgr_types.h"
#include "types.h"

extern unsigned int D_00582B60;
extern unsigned int D_00582B68;
extern unsigned int D_00582B70;
extern unsigned int D_00582B78;
extern unsigned int D_00582B80;
extern unsigned char D_005827C8;
extern unsigned char D_005827D0;
extern unsigned char D_005827D8;
extern unsigned char D_005827E0;
extern unsigned char D_005827E8;
extern void* D_00582A78;
extern void* D_00582A80;
extern void* D_00582A88;
extern void* D_00582A90;
extern void* D_00582A98;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern int D_00494178;

extern unsigned int cDME_GetTime(int clock);
extern int NetRequestObjectPrivateOwnership(void* key);
extern int NetGetObject(NetSessionEntry** entry, void* key);
extern int NetGetMyClientIndex(int* id, int session);
extern void cNPCInfoObject_NPCInfoUpdateCallback(int peer, void* key, int mode);

static inline void service_slot(unsigned int* deadline, unsigned char* pending,
                                void** key, unsigned int interval)
{
    unsigned int previous = *deadline;
    if (previous < cDME_GetTime(1)) {
        if (*pending && !NetRequestObjectPrivateOwnership(*key))
            *pending = 0;
        *deadline = cDME_GetTime(1) + interval;
    }
}

static inline int current_peer(void)
{
    int session = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}

/* Service five pending NPC requests on their independent polling intervals. */
void cNPCInfoObject_CheckForScheduledRequest(void)
{
    service_slot(&D_00582B60, &D_005827C8, &D_00582A78, 120);
    service_slot(&D_00582B68, &D_005827D0, &D_00582A80, 150);
    service_slot(&D_00582B70, &D_005827D8, &D_00582A88, 180);
    service_slot(&D_00582B78, &D_005827E0, &D_00582A90, 210);
    service_slot(&D_00582B80, &D_005827E8, &D_00582A98, 240);
}

/* Queue a remote-peer request by key, or process a local/missing entry directly. */
void func_00434920(void* unused, void* key)
{
    NetSessionEntry* entry;
    NetGetObject(&entry, key);
    if (entry && entry->id != current_peer()) {
        if (key == D_00582A78)
            D_005827C8 = 1;
        else if (key == D_00582A80)
            D_005827D0 = 1;
        else if (key == D_00582A88)
            D_005827D8 = 1;
        else if (key == D_00582A90)
            D_005827E0 = 1;
        else if (key == D_00582A98)
            D_005827E8 = 1;
    } else {
        cNPCInfoObject_NPCInfoUpdateCallback(current_peer(), key, -2);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434740 */

/* merge_units: begin func_00434AA0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
char * cMemMan_Allocate(int, int, char *, int);                      
#if 0 /* merge_units */
int std_list_tNPCInfoPtr_push_back(char *, void **);
#endif /* merge_units */
Iter * std_list_tNPCInfoPtr_push_back(); /* merge_units */
                      
extern char D_004BFCA0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_00582AF0;

void cNPCInfoObject_AddPendingAdd(int d0, char * arg1) {
    char * sp3C;
    char * temp_s0;

    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s0 = cMemMan_Allocate(0, 0x14, &D_004BFCA0, 0x30B);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x4, unsigned char) = F_(arg1, 0x4, unsigned char);
        F_(temp_s0, 0x0, int) = F_(arg1, 0x0, int);
        F_(temp_s0, 0x5, unsigned char) = F_(arg1, 0x5, unsigned char);
        F_(temp_s0, 0x6, unsigned char) = F_(arg1, 0x6, unsigned char);
        F_(temp_s0, 0xA, unsigned char) = F_(arg1, 0xA, unsigned char);
        F_(temp_s0, 0x7, unsigned char) = F_(arg1, 0x7, unsigned char);
        F_(temp_s0, 0xB, unsigned char) = F_(arg1, 0xB, unsigned char);
        F_(temp_s0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
        F_(temp_s0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
        F_(temp_s0, 0x9, unsigned char) = F_(arg1, 0x9, unsigned char);
        F_(temp_s0, 0xD, unsigned char) = F_(arg1, 0xD, unsigned char);
        F_(temp_s0, 0x10, int) = F_(arg1, 0x10, int);
    }
    sp3C = temp_s0;
    std_list_tNPCInfoPtr_push_back(&D_00582AF0, &sp3C);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434AA0 */

/* merge_units: begin func_00434BB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "npc_types.h"

extern Iter* std_list_deleter_voidPtr_insert(Iter* out, Tree* t, Iter* hint, int value);

/* map insert(value): inserts with an end() hint, result iterator in it[1]. */
Iter* std_list_tNPCInfoPtr_push_back(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}
static inline void merge_flush_func_00434BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00434BB0 */
