/*
 * main/NPCInfoObject: range (2 files, 00432230-00432510)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "net_local_id.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00432230 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct Ent_2750 { int key; unsigned char b4; unsigned char b5; unsigned char arr[10]; };
extern "C" void func_00432510(int d0, Ent_2750* tbl, int key); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
extern "C" {}
#pragma inline_depth(10)
struct C_432230 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual int v15();
};
typedef struct { char pad[0x58]; C_432230* f58; } Obj_432230;
typedef struct { int id; unsigned char b4; unsigned char b5; unsigned char b6; unsigned char b7; unsigned char b8; unsigned char b9; char padA[6]; } T_432230;
typedef struct { int f0; int f4; char pad8[0x14]; T_432230* f1C; } P_432230;
typedef struct { int x; } L_432230;
extern "C" {
extern int D_005827F8;
extern unsigned char D_00582778;
extern int D_00582A68;
extern int D_00582A78; extern int D_00582A80; extern int D_00582A88; extern int D_00582A90; extern int D_00582A98;
extern unsigned char D_005827A0; extern unsigned char D_005827A8; extern unsigned char D_005827B0; extern unsigned char D_005827B8; extern unsigned char D_005827C0;
int NetGetObject(P_432230** out, int key);
void cNPCInfoObject_Setup(L_432230* l);
void cNPCInfoObject_DoPendingAdds(L_432230* l, T_432230* t);
void cNPCInfoObject_DoPendingActivates(L_432230* l, T_432230* t, int key);
void cNPCInfoObject_DoPendingDeactivates(L_432230* l, T_432230* t, int key);
void cNPCInfoObject_DoPendingOwnership(L_432230* l, T_432230* t, int key);
void cNPCInfoObject_DoPendingActiveTerrain(L_432230* l, T_432230* t, int key);
#if 0 /* merge_units */
void func_00432510(L_432230* l, T_432230* t, int key);
#endif /* merge_units */
#define func_00432510(a0, a1, a2) (func_00432510((int)(a0), (Ent_2750 *)(a1), (a2))) /* merge_units */

Obj_432230* Object_LookupById(int* id);
T_432230* cNPCInfoObject_Find(int* id, int f);
void cNPCInfoObject_NPCInfoUpdateCallback(int unused, int key, int code);
}

void cNPCInfoObject_NPCInfoUpdateCallback(int unused, int key, int code)
{
    P_432230* p = 0;
    int r = NetGetObject(&p, key);
    if (D_005827F8 && p && !r) {
        T_432230* t = p->f1C;
        if (code == -2 && p->f4 == NetLocalId()) {
            L_432230 lk;
            int i;
            if (!D_00582778) cNPCInfoObject_Setup(&lk);
            D_00582A68++;
            cNPCInfoObject_DoPendingAdds(&lk, t);
            cNPCInfoObject_DoPendingActivates(&lk, t, key);
            cNPCInfoObject_DoPendingDeactivates(&lk, t, key);
            cNPCInfoObject_DoPendingOwnership(&lk, t, key);
            cNPCInfoObject_DoPendingActiveTerrain(&lk, t, key);
            func_00432510(&lk, t, key);
            for (i = 0; i < 29; i++, t++) {
                int id2;
                int id;
                if (t->id != -1 && t->b4 == NetLocalId()) {
                    id = t->id;
                    Obj_432230* o = Object_LookupById(&id);
                    if (o && o->f58 && !o->f58->v15()) {
                        id2 = t->id;
                        T_432230* e = cNPCInfoObject_Find(&id2, 0);
                        if (e) {
                            e->id = -1;
                            e->b4 = 0xFF;
                            e->b6 = 0;
                            e->b7 = 0;
                            e->b8 = 0;
                            e->b9 = 0;
                        }
                    }
                }
            }
            if (key == D_00582A78) D_005827A0 = 1;
            if (key == D_00582A80) D_005827A8 = 1;
            if (key == D_00582A88) D_005827B0 = 1;
            if (key == D_00582A90) D_005827B8 = 1;
            if (key == D_00582A98) D_005827C0 = 1;
            D_00582A68--;
        }
    }
}
#undef func_00432510 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00432230(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00432230 */

/* merge_units: begin func_00432510 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_2750 { int p; };

extern "C" {
void List_Erase(int*, char*, int*);
Raw_2750 List_Begin(void*);
Raw_2750 std_list_tNPCInfoPtr_end(void*);
void std_list_tNPCInfoPtr_generic_iterator_ctor(char**, const Raw_2750&);
void cLListIterator_tNPCInfoPtr_ctor(char**, const Raw_2750&);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(int*, char**);
extern char D_00582B30;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
}
#define Begin_2750(o) std_list_tNPCInfoPtr_generic_iterator_ctor(o, List_Begin(&D_00582B30))
#define End_2750(o) cLListIterator_tNPCInfoPtr_ctor(o, std_list_tNPCInfoPtr_end(&D_00582B30))
static inline unsigned char IsHost_2510() { if (g_IsMultiplayer) return D_005721C0; return 1; }
extern "C" void func_00432510(int d0, Ent_2750* tbl, int key) {
  if (IsHost_2510() && *(int*)&D_00582B30) {
    char* end;
    {
        char* e;
        char* n;
        char* cur;
        char* it;
        Begin_2750(&it);
        n = it;
        while ((End_2750(&end), n != end)) {
            Ent_2750* f;
            e = F_(n, 0x8, char*);
            cur = n;
            n = F_(n, 0x4, char*);
            f = 0;
            if (key == F_(e, 0x10, int)) {
                int i; for (i = 0; i != 29; i++) if (tbl[i].key == F_(e, 0x0, int)) { f = &tbl[i]; break; }
                if (f) {
                    if (f->b4 != 0xFF) { f->b4 = F_(e, 0x4, unsigned char); f->b5 = 0xFF; }
                    else f->b5 = F_(e, 0x4, unsigned char);
                    f->arr[F_(e, 0x5, unsigned char)] = 0;
                }
                {
                    AllocGuard g;
                    Mem_Free(0, e, "NPCInfoObject.cc", 0x78B);
                }
                {
                    char* c;
                    int res;
                    int pos;
                    c = cur;
                    std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &c);
                    List_Erase(&res, &D_00582B30, &pos);
                }
            }
        }
    }
}
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00432510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00432510 */
