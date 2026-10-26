/*
 * main/NetObj: range (2 files, 003FB4B0-003FB650)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_003FB4B0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Ctrl {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual unsigned char GetState();
};
struct NObj { char pad[0x49]; unsigned char type; char pad4A[0xE]; Ctrl* ctrl; };
struct NMap { int unk0; int unk4; };

extern "C" {
NMap* NetMap_Lookup(void);
NObj* Object_LookupById(int* id);
void* Mem_Alloc(int, int, char*, int);
void* cNPCInfoObject_ctor(void* p);
void cNPCInfoObject_SetOwner_uint_int(void* mgr, int id, int val);
extern void* D_0055C988;
extern char D_004BE228[];
}

extern "C" void cNetObj_SetOwner(int id, int val) {
    NMap* m = NetMap_Lookup();
    int key = id;
    NObj* o = Object_LookupById(&key);
    if (m) {
        if (o && o->ctrl && o->type == 2) {
            if (o->ctrl->GetState() == 2 || o->ctrl->GetState() == 1) {
            if (!D_0055C988) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 1, D_004BE228, 0x20C);
                }
                if (p) p = cNPCInfoObject_ctor(p);
                D_0055C988 = p;
            }
            cNPCInfoObject_SetOwner_uint_int(D_0055C988, id, val);
            } else {
                m->unk4 = val;
            }
        } else {
            m->unk4 = val;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FB4B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FB4B0 */

/* merge_units: begin func_003FB650 */
#pragma push /* merge_units */
typedef struct NetRecvE6 {
    int key;
    int handler;
    int context;
} NetRecvE6;

extern unsigned char g_IsMultiplayer;
extern char D_0055C7A0[];
extern signed char D_0055C9B8;
extern int D_0055C9C0;
extern int D_0055C9C4;
extern unsigned char D_0055C9C8;
extern int D_0055C9CC;
extern int D_0055C9D0;
extern NetRecvE6* NetRecvMap_Insert(void* map, int* key);

/* Binds a receiver to a net id; offline returns a static dummy slot. */
int* NetMap_BindReceiver(int id, int context, int handler)
{
    int key[1];
    key[0] = id;
    if (g_IsMultiplayer) {
        NetRecvMap_Insert(D_0055C7A0, key)->handler = handler;
        NetRecvMap_Insert(D_0055C7A0, key)->context = context;
        return &NetRecvMap_Insert(D_0055C7A0, key)->handler;
    }
    if (D_0055C9B8 == 0) {
        D_0055C9C0 = 0;
        D_0055C9C4 = -1;
        D_0055C9C8 = 0;
        D_0055C9CC = 0;
        D_0055C9D0 = 0;
        D_0055C9B8 = 1;
    }
    return &D_0055C9C0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FB650(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FB650 */
