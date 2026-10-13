#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BC2B8[];
extern int D_00539328;
extern int D_00539330;
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void func_00383660(void* self);
int AddIntcHandler(int cause, void* handler, int next);
void func_00381FB0(void);
int TexCache_LoadErrorTexture(void* self);
}

static inline void MemClear_3831(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v0, n, 0xF
        or $a0, $a0, $v0
        nop
        bgtz $a0, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
        .set reorder
    done:
    }
}

struct TexEntry {
    char pad[0x50];
    unsigned long tex0;
    char pad58[8];
    unsigned char u60;
    unsigned char u61;
    unsigned char u62;
};

struct TexCache {
    unsigned int base;
    int size;
    TexEntry** entries;
    int cap;
    int count;
    unsigned char u14;
    unsigned char u15;
    unsigned char u16;
    int u18;
    char pad1C[0x41C - 0x1C];
    char m41C[0xC];
    char m428[0xC];
    char m434[0xC];
    char zero440[0x40];
    int u480;
    int u484;
    unsigned char u488;
    unsigned char u489;
    unsigned int u48C;
    int handler;
};

#pragma opt_rotateloops off
#pragma opt_strength_reduction off
/* TexCache constructor: allocate the entry table, hook interrupt 5, reset VRAM state. */
extern "C" TexCache* TexMan_Construct(TexCache* self, unsigned int base, int cap)
{
    int i;
    func_00383660(self->m41C);
    func_00383660(self->m428);
    func_00383660(self->m434);
    self->base = base;
    self->size = 0x4000;
    self->cap = cap;
    {
        TexEntry** p;
        int sz = self->cap * 4;
        {
            AllocGuard g;
            p = (TexEntry**)Mem_Alloc(0, sz, D_004BC2B8, 0x3A);
        }
        self->entries = p;
    }
    for (i = 0; i < self->cap; i++)
        self->entries[i] = 0;
    self->count = 0;
    self->u18 = 0;
    self->u14 = 0;
    self->u15 = 0;
    self->u16 = 1;
    self->handler = AddIntcHandler(5, (void*)func_00381FB0, 0);
    Alloc_Unlock(5);
    *(volatile int*)0x10003010 = 4;
    {
        TexEntry** p = self->entries;
        int n = self->count;
        while (n > 0) {
            TexEntry* e = *p++;
            if (e && !e->u62 && (unsigned int)(int)(e->tex0 & 0x3FFF) >= self->base) {
                e->u60 = 0;
                e->u61 = 0;
            }
            n--;
        }
    }
    self->u48C = self->base;
    self->u480 = 0;
    D_00539328 = 0;
    D_00539330 = 0;
    self->u484 = 0;
    self->u488 = 0;
    self->u489 = 0;
    MemClear_3831(self->zero440, 0x40);
    TexCache_LoadErrorTexture(self);
    return self;
}




