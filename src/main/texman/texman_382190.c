/*
 * main/texman: range (2 files, 00382190-00382540)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00382190 */
#pragma push /* merge_units */
#pragma cplusplus on

struct TexInfo {
    char pad[0xE];
    unsigned short hE;
    char pad10[0xA];
    unsigned short h1A;
};

struct TexEntry {
    char pad[0x44];
    TexInfo* info;
    char pad48[8];
    unsigned long tex0;
    char pad58[8];
    unsigned char u60;
    unsigned char u61;
    unsigned char u62;
};

struct TexCache {
    unsigned int base;
    unsigned int size;
    TexEntry** entries;
    int cap;
    int count;
    unsigned char u14;
    unsigned char u15;
    unsigned char u16;
    int u18;
    short list[(0x41C - 0x1C) / 2];
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

struct DmaBuf {
    char pad[0x10];
    int cur;
};

extern "C" {
extern char D_00537F80[];
extern DmaBuf* D_00537F88;
extern int D_00539330;
extern int D_00539340[][1024];
long* func_00375C30(void* q, int i, int id, int qwc, int addr, int flag);
void func_003BB360(TexEntry* e, unsigned int lo, unsigned int hi);
}

static inline void TexCache_Reset(TexCache* self)
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
    self->u48C = self->base;
}

extern "C" void func_00382190(TexCache* self)
{
    bool dirty = false;
    unsigned int addr;
    int i;
    long* p;

    self->u16 = 1;
    addr = self->size;
    for (i = 0; i < self->u18; i++) {
        TexEntry* e = *(TexEntry**)((int)self->entries + self->list[i]*4);
        if (self->u14 && e && (e->u60 & e->u61) && ((int)(e->tex0 & 0x3FFF) & 0x1F)) {
            e->u60 = 0;
            e->u61 = 0;
        }
        if (e && !(e->u60 & e->u61)) {
            if (self->u14) addr -= 0x20;
            addr -= e->info->hE + e->info->h1A;
            dirty = 1;
            if (addr < self->u48C) self->u488 = 1;
        }
    }
    if (self->u488) {
        TexCache_Reset(self);
        dirty = 1;
    }
    if (dirty) {
        D_00539340[!D_00539330][self->u480] = D_00537F88->cur;
        int j;
        for (j = 0; j < self->u18; j++) {
            TexEntry* e = self->entries[self->list[j]];
            if (e && !(e->u60 & e->u61)) {
                if (self->u14) self->size = (self->size - 0x20) & ~0x1F;
                self->size -= e->info->hE + e->info->h1A;
                func_003BB360(e, self->size, self->size + (e->info->hE + e->info->h1A) - 4);
            }
        }
        p = func_00375C30(D_00537F80, 2, 7, 2, 0, 0);
        *p++ = 0x1000000000008001;
        *p++ = 0xE;
        *p++ = 0;
        *p++ = 0x3F;
        p = func_00375C30(D_00537F80, 1, 1, 1, 0, 1);
        p[0] = 0;
        if (self->u488 || !self->u480) {
            p[1] = 0x93000000;
            p[2] = 0x93000000;
            if (self->u484) {
                if (self->u489) *(int*)(self->u484 + 8) = 0x13000000;
                else *(int*)self->u484 = 0x13000000;
            }
            self->u488 = 0;
            self->u489 = 1;
        } else {
            p[1] = 0x93000000;
            p[2] = 0;
            self->u489 = 0;
        }
        self->u484 = (int)(p + 1);
        self->u480++;
    }
    self->u14 = 0;
    self->u15 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00382190 */

/* merge_units: begin func_00382540 */
#pragma push /* merge_units */
#pragma cplusplus on


extern "C" {
}

extern "C" void func_00382190(TexCache* self);

extern "C" void func_00382540(TexCache* self)
{
    bool dirty;
    unsigned int addr;
    int i;
    long* p;

    if (self->u15) {
        func_00382190(self);
        return;
    }
    self->u16 = 1;
    dirty = false;
    addr = self->u48C;
    for (i = 0; i < self->u18; i++) {
        TexEntry* e = *(TexEntry**)((int)self->entries + self->list[i]*4);
        if (self->u14 && e && (e->u60 & e->u61) && ((int)(e->tex0 & 0x3FFF) & 0x1F)) {
            e->u60 = 0;
            e->u61 = 0;
        }
        if (e && !(e->u60 & e->u61)) {
            if (self->u14) addr += 0x20;
            addr += e->info->hE + e->info->h1A;
            dirty = 1;
            if (addr >= self->size) self->u488 = 1;
        }
    }
    if (self->u488) {
        TexCache_Reset(self);
        dirty = 1;
    }
    if (dirty) {
        D_00539340[!D_00539330][self->u480] = D_00537F88->cur;
        int j;
        for (j = 0; j < self->u18; j++) {
            TexEntry* e = self->entries[self->list[j]];
            if (e && !(e->u60 & e->u61)) {
                if (self->u14) self->u48C = (self->u48C + 0x20) & ~0x1F;
                func_003BB360(e, self->u48C, self->u48C + (e->info->hE + e->info->h1A) - 4);
                self->u48C += e->info->hE + e->info->h1A;
            }
        }
        p = func_00375C30(D_00537F80, 2, 7, 2, 0, 0);
        *p++ = 0x1000000000008001;
        *p++ = 0xE;
        *p++ = 0;
        *p++ = 0x3F;
        p = func_00375C30(D_00537F80, 1, 1, 1, 0, 1);
        p[0] = 0;
        if (self->u488 || !self->u480) {
            p[1] = 0x93000000;
            p[2] = 0x93000000;
            if (self->u484) {
                if (self->u489) *(int*)(self->u484 + 8) = 0x13000000;
                else *(int*)self->u484 = 0x13000000;
            }
            self->u488 = 0;
            self->u489 = 1;
        } else {
            p[1] = 0x93000000;
            p[2] = 0;
            self->u489 = 0;
        }
        self->u484 = (int)(p + 1);
        self->u480++;
    }
    self->u14 = 0;
    self->u15 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00382540 */
