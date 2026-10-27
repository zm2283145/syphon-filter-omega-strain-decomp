/*
 * main/NPCInfoObject: range (3 files, 004355D0-00435F30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "npc_auth.h"
#include "npc_info_rec.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_004355D0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004BFCA0[];
extern unsigned char D_005721B8;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721D0;
extern unsigned char D_00582778;
extern unsigned char D_00582780;
void* cMemMan_Allocate(int heap, int size, char* file, int line);
void cNPCInfoObject_CreateNPCInfoStruct(int a);
void cNPCInfoObject_CheckForScheduledRequest(int a);
}
struct E_004355D0 {
    int id;
    unsigned char a, b;
    unsigned char c[4];
    unsigned char d[4];
    char pad[2];
    void Init() { id = -1; a = 0xFF; b = 0xFF; c[0] = 0; d[0] = 1; c[1] = 0; d[1] = 1; c[2] = 0; d[2] = 1; c[3] = 0; d[3] = 1; }
};
extern "C" {
extern E_004355D0* D_005827F0;
extern E_004355D0* D_005827F8;
extern E_004355D0* D_00582800;
extern E_004355D0* D_00582808;
extern E_004355D0* D_00582810;
}
inline void* operator new(unsigned int, void* p) { return p; }
static inline void* New_004355D0(int size, int line) { AllocGuard g; return cMemMan_Allocate(0, size, D_004BFCA0, line); }
static inline void Del_004355D0(void* p, int line) { if (p) { AllocGuard g; cMemMan_Deallocate(0, p, D_004BFCA0, line); } }
#define NEWARR(dst, line) { E_004355D0* p = (E_004355D0*)New_004355D0(sizeof(E_004355D0) * 29, line); if (p) { E_004355D0* q = p; do { q->Init(); q++; } while (q != p + 29); } dst = p; }
extern "C" void cNPCInfoObject_Setup(int arg)
{
    if (D_005721B8) return;
    if (D_005721D0) {
        if (D_00582778 && !D_00582780) {
            if (g_IsMultiplayer ? D_005721C0 : 1) {
                E_004355D0* p0 = D_005827F0;
                E_004355D0* p1 = D_005827F8;
                E_004355D0* p2 = D_00582800;
                E_004355D0* p3 = D_00582808;
                E_004355D0* p4 = D_00582810;
                cNPCInfoObject_CreateNPCInfoStruct(arg);
                Del_004355D0(p0, 0x24E);
                Del_004355D0(p1, 0x251);
                Del_004355D0(p2, 0x254);
                Del_004355D0(p3, 0x257);
                Del_004355D0(p4, 0x25A);
                D_00582780 = 1;
            }
        }
        cNPCInfoObject_CheckForScheduledRequest(arg);
        return;
    }
    if (!D_00582778 && g_IsMultiplayer) {
        NEWARR(D_005827F0, 0x269);
        NEWARR(D_005827F8, 0x26A);
        NEWARR(D_00582800, 0x26B);
        NEWARR(D_00582808, 0x26C);
        NEWARR(D_00582810, 0x26D);
        D_00582778 = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004355D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004355D0 */

/* merge_units: begin func_00435D80 */
#pragma push /* merge_units */
#if 0 /* merge_units */
void Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */

#if 0 /* merge_units */
void EnableIntc(int);
#endif /* merge_units */
#define EnableIntc(a0) (EnableIntc((a0))) /* merge_units */

#if 0 /* merge_units */
void* cMemMan_Allocate(int, int, char*, int);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */

void std_list_tNPCInfoPtr_push_back(char*, NpcInfoMsg**);
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_00582B30[];

void cNPCInfoObject_DisconnectOwner(int self, int key, unsigned char v)
{
    int h;
    NpcInfoMsg* m;
    NpcInfoRec* r;
    if (NpcAuth_IsLocal()) {
        r = cNPCInfoObject_Find(key, &h);
        if (r) {
            NpcInfoMsg* t;
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            t = (NpcInfoMsg*)cMemMan_Allocate(0, 0x14, D_004BFCA0, 0x20E);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
            if (t) NPC_INFO_COPY(*t, r)
            m = t;
            if (m) {
                m->a6[r->b4] = 0;
                m->state = r->b4;
                m->b4 = v;
                m->f10 = h;
                r->a6[r->b4] = 0;
                r->b4 = v;
                std_list_tNPCInfoPtr_push_back(D_00582B30, &m);
                func_00434920(self, h);
            }
        }
    }
}
#undef Alloc_Lock /* merge_units */
#undef EnableIntc /* merge_units */
#undef cMemMan_Allocate /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00435D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00435D80 */

/* merge_units: begin func_00435F30 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern NpcInfoRec* D_005827F0;
#endif /* merge_units */
#define D_005827F0 (*(NpcInfoRec **)&D_005827F0) /* merge_units */

#if 0 /* merge_units */
extern NpcInfoRec* D_005827F8;
#endif /* merge_units */
#define D_005827F8 (*(NpcInfoRec **)&D_005827F8) /* merge_units */

#if 0 /* merge_units */
extern NpcInfoRec* D_00582800;
#endif /* merge_units */
#define D_00582800 (*(NpcInfoRec **)&D_00582800) /* merge_units */

#if 0 /* merge_units */
extern NpcInfoRec* D_00582808;
#endif /* merge_units */
#define D_00582808 (*(NpcInfoRec **)&D_00582808) /* merge_units */

#if 0 /* merge_units */
extern NpcInfoRec* D_00582810;
#endif /* merge_units */
#define D_00582810 (*(NpcInfoRec **)&D_00582810) /* merge_units */

extern int D_00582A78;
extern int D_00582A80;
extern int D_00582A88;
extern int D_00582A90;
extern int D_00582A98;
void cNPCInfoObject_Setup(int self);
#if 0 /* merge_units */
NpcInfoRec* cNPCInfoObject_Find(int* key, int* out);
#endif /* merge_units */
#define cNPCInfoObject_Find(a0, a1) (cNPCInfoObject_Find((int)(a0), (a1))) /* merge_units */

void func_00434920(int self, int h);
void cNPCInfoObject_AddPendingAdd(int self, NpcInfoMsg* m);

void cNPCInfoObject_Add(int self, int* key, unsigned char v)
{
    cNPCInfoObject_Setup(self);
    if (D_00582780) {
        NpcInfoMsg m;
        int j;
        m.key = -1;
        m.b4 = 0xFF;
        m.state = 0xFF;
        for (j = 0; j < 4; j++) { m.a6[j] = 0; m.aA[j] = 1; }
        m.f10 = 0;
        m.key = *key;
        m.b4 = v;
        cNPCInfoObject_AddPendingAdd(self, &m);
        func_00434920(self, D_00582A78);
        func_00434920(self, D_00582A80);
        func_00434920(self, D_00582A88);
        func_00434920(self, D_00582A90);
        func_00434920(self, D_00582A98);
    } else {
        int i = 0;
        NpcInfoRec* r = cNPCInfoObject_Find(key, 0);
        if (!r) {
            for (i = 0; i != 29; i++) if (D_005827F0[i].key == -1) { r = &D_005827F0[i]; break; }
            if (i == 29) {
                for (i = 0; i != 29; i++) if (D_005827F8[i].key == -1) { r = &D_005827F8[i]; break; }
                if (i == 29)
                    for (i = 0; i != 29; i++) if (D_00582800[i].key == -1) { r = &D_00582800[i]; break; }
                if (i == 29)
                    for (i = 0; i != 29; i++) if (D_00582808[i].key == -1) { r = &D_00582808[i]; break; }
                if (i == 29)
                    for (i = 0; i != 29; i++) if (D_00582810[i].key == -1) { r = &D_00582810[i]; break; }
            }
        }
        if (i < 29) r->key = *key;
    }
}
#undef D_005827F0 /* merge_units */
#undef D_005827F8 /* merge_units */
#undef D_00582800 /* merge_units */
#undef D_00582808 /* merge_units */
#undef D_00582810 /* merge_units */
#undef cNPCInfoObject_Find /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00435F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00435F30 */
