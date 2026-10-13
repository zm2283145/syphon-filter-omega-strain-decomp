#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_004BD3B0[];
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
void* func_0013A040(void* self, short f);
void* func_003D7280(void* self, short f);
void* func_003D7190(void* self, short f);
}

struct Item { void* data; };
struct ItemVec { int a; int count; };
extern "C" Item** func_003D7370(ItemVec* v, int i);

struct Owner {
    void* data;
    ItemVec items;
    int pad[2];
    char m14[0x10];
    char m24[0x10];
};

/* Destructor: frees the owned buffer and every item (each under the allocator lock), then destroys members. */
extern "C" Owner* func_003D6F40(Owner* self, short flag)
{
    if (self) {
        void* d = self->data;
        if (D_00533880)
            Alloc_Lock(9);
        D_00533888++;
        Mem_Free(0, d, D_004BD3B0, 0x170);
        if (D_00533880)
            Alloc_Unlock(9);
        D_00533888--;
        for (int i = 0; i < self->items.count; i++) {
            Item* it = *func_003D7370(&self->items, i);
            AllocGuard g;
            if (it) {
                void* p = it->data;
                if (D_00533880)
                    Alloc_Lock(9);
                D_00533888++;
                Mem_Free(0, p, D_004BD3B0, 0x15C);
                if (D_00533880)
                    Alloc_Unlock(9);
                D_00533888--;
            }
            Mem_Free(0, it, D_004BD3B0, 0x173);
        }
        void* m;
        m = self->m24;
        if (m)
            func_0013A040(m, -1);
        m = self->m14;
        if (m)
            func_003D7280(m, -1);
        m = &self->items;
        if (m)
            func_003D7190(m, -1);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}


