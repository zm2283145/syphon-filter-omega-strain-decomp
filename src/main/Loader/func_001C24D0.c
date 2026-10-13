#pragma cplusplus on
#include "types.h"
#include "pop_reader.h"
#include "Loader_types.h"
#include "alloc_guard.h"

struct ActTerrain {
    char pad[0x4c];
    int kind;
};

extern "C" {
void* func_001698C0();
void func_00165E60(void*, const char*, int);
void* Mem_Alloc(int, int, const char*, int);
void Mem_Free(int, void*, const char*, int);
ActTerrain* IdMgr_FindCollision(int, int);
void Terrain_ReadActRecord(void*, PopReader*);
void Terrain_ApplyInl(void*, PopReader*, LoaderOwnedVec*);
void KeyVector_Reserve(void*, int);
void KeyVector_PushBack(void*, int*, int, int*);
void func_001C29F0(void*);
void Actor_VirtualLeaf175230(void*);
void func_00175240(void*, int);
extern char D_0049EE88[], D_0049F0D0[];
extern int D_004EE780;
}

static inline int ActRead(PopReader* r)
{
    int n = *(int*)r->cur;
    r->cur += 4;
    return n;
}

/* new KeyVector (owning) */
static inline LoaderOwnedVec* NewVec()
{
    LoaderOwnedVec* p;
    {
        AllocGuard g;
        p = (LoaderOwnedVec*)Mem_Alloc(0, 0x10, D_0049EE88, 0x2b0);
    }
    if (p) {
        func_001C29F0(p);
        p->owns = 1;
    }
    return p;
}

static inline void Push(LoaderOwnedVec* v, int* k)
{
    KeyVector_PushBack(v, v->vec.data + v->vec.count, 1, k);
}

extern "C" void Loader_InitActivationMap(void* unused, PopReader* r)
{
    int key;
    func_00165E60(func_001698C0(), D_0049F0D0, 0);
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    if ((unsigned char)Pop_FindTag(r, 0x3a544341)) {
        int n = ActRead(r);
        for (int i = 0; i < n; i++) {
            int a = ActRead(r), b = ActRead(r);
            ActTerrain* t = IdMgr_FindCollision(a, b);
            if (t && t->kind == D_004EE780)
                Terrain_ReadActRecord(t, r);
            else {
                int count = ActRead(r);
                r->cur += count * 4;
            }
        }
    } else if ((unsigned char)Pop_FindTag(r, 0x3a4c4341)) {
        int n = ActRead(r);
        LoaderOwnedVec** lists;
        int bytes = n * 4;
        {
            AllocGuard g;
            lists = (LoaderOwnedVec**)Mem_Alloc(0, bytes, D_0049EE88, 0x2a8);
        }
        for (int i = 0; i < n; i++) {
            int count = ActRead(r);
            lists[i] = NewVec();
            KeyVector_Reserve(lists[i], count / 2);
            for (int j = 0; j < count / 2; j++) {
                int a = ActRead(r), b = ActRead(r);
                key = b | (a << 16);
                Push(lists[i], &key);
            }
        }
        if ((unsigned char)Pop_FindTag(r, 0x3a4c4e49)) {
            int count = ActRead(r);
            for (int i = 0; i < count; i++) {
                int a = ActRead(r), b = ActRead(r), index = ActRead(r);
                ActTerrain* t = IdMgr_FindCollision(a, b);
                if (t && t->kind == D_004EE780)
                    Terrain_ApplyInl(t, r, lists[index]);
            }
        }
        for (int i = 0; i < n; i++) {
            Actor_VirtualLeaf175230(lists[i]);
            LoaderOwnedVec* p = lists[i];
            {
                AllocGuard g;
                if (p) {
                    if (p) {
                        if (p)
                            func_00175240(p, 0);
                    }
                }
                Mem_Free(0, p, D_0049EE88, 0x2e1);
            }
        }
        {
            AllocGuard g;
            Mem_Free(0, lists, D_0049EE88, 0x2e4);
        }
    }
}
