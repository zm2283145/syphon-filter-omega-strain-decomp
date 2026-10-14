/*
 * main/texman: range (3 files, 00383020-003831D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00383020 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct ListNode_383150 ListNode_383150;
typedef struct {
    int size;
    ListNode_383150* sentinelPrev;
    ListNode_383150* first;
} List_383150;
extern "C" List_383150* func_00383150(List_383150* self, short deleteFlag); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int RemoveIntcHandler(int, int);                            
int func_00381080(char * );                            
#if 0 /* merge_units */
int func_00383150(char * , int);
#endif /* merge_units */
#define func_00383150(a0, a1) ((int)func_00383150((List_383150 *)(a0), (short)(a1))) /* merge_units */
                         
int operator_delete(char * );                          
extern char D_004BC2B8;
extern unsigned char D_00533880;
}
extern "C" char * func_00383020(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        Alloc_Lock(5);
        RemoveIntcHandler(5, F_(arg0, 0x490, int));
        func_00381080(arg0);
        temp_s2 = F_(arg0, 0x8, int);
        {
            AllocGuard g;
        Mem_Free(0, temp_s2, &D_004BC2B8, 0x6E);
        }
        temp_a0 = arg0 + 0x434;
        if (temp_a0 != NULL) {
            func_00383150(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x428;
        if (temp_a0_2 != NULL) {
            func_00383150(temp_a0_2, 0);
        }
        temp_a0_3 = arg0 + 0x41C;
        if (temp_a0_3 != NULL) {
            func_00383150(temp_a0_3, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
#undef func_00383150 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00383020(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00383020 */

/* merge_units: begin func_00383150 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor of a list: erase [first, sentinel), then delete. */



extern "C" {
void func_00383420(ListNode_383150** result, List_383150* list,
                   ListNode_383150** first, ListNode_383150** last);
#if 0 /* merge_units */
int operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((char *)(a0))) /* merge_units */

}

extern "C" List_383150* func_00383150(List_383150* self, short deleteFlag)
{
    if (self) {
        if (self) {
            if (self) {
                ListNode_383150* result;
                ListNode_383150* first;
                ListNode_383150* last;
                last = (ListNode_383150*)&self->sentinelPrev;
                first = self->first;
                func_00383420(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00383150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00383150 */

/* merge_units: begin func_003831D0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
#if 0 /* merge_units */
extern char D_004BC2B8[];
#endif /* merge_units */
#define D_004BC2B8 ((char*)&D_004BC2B8) /* merge_units */

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
#undef D_004BC2B8 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003831D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003831D0 */
