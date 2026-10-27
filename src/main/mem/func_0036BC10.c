#include "types.h"
typedef struct Blk {
    unsigned int size : 28;
    unsigned int flags : 4;
    struct Blk* f4;
    struct Blk* f8;
    int fC;
} Blk;
typedef struct Heap {
    Blk bins[128];
    Blk* last;
    char* base;
    char* cur;
} Heap;
extern char D_004BBE70[];
extern char D_004BBF50[];
extern void printf(char* fmt, ...);
extern void cMemChunk_SetPrev(Blk* b, Blk* v);
extern void cMemChunk_SetNext(Blk* b, Blk* v);
extern Blk* cMemChunk_GetNext(Blk* b);
extern Blk* cMemBin_FindBin(Heap* h, unsigned int size);
extern unsigned int cMemChunk_GetSize(Blk* b);

void cMemBin_Deallocate(Heap* h, char* ptr, char* file, int line)
{
    Blk* b;
    Blk* p;
    Blk* tgt;
    Blk* it;
    unsigned int sz;
    unsigned char merged;
    unsigned int s;

    b = (Blk*)(ptr - 0x10);
    if ((char*)b < h->base || (char*)b > h->cur) {
        printf(D_004BBE70, file, line);
        return;
    }
    tgt = cMemBin_FindBin(h, cMemChunk_GetSize(b));
    it = tgt;
    sz = cMemChunk_GetSize(b);
    while (cMemChunk_GetNext(it) != tgt && cMemChunk_GetSize(cMemChunk_GetNext(it)) < sz) {
        if ((char*)cMemChunk_GetNext(it) < h->base || (char*)cMemChunk_GetNext(it) > h->cur) {
            printf(D_004BBF50, it);
            cMemChunk_SetNext(it, tgt);
            break;
        }
        it = cMemChunk_GetNext(it);
    }
    cMemChunk_SetPrev(b, it);
    cMemChunk_SetNext(b, cMemChunk_GetNext(it));
    cMemChunk_SetPrev(cMemChunk_GetNext(it), b);
    cMemChunk_SetNext(it, b);
    if (h->last < tgt) h->last = tgt;
    merged = 0;
    *(unsigned int*)b = *(unsigned int*)b & 0x7FFFFFFF;
    while (!((h->base < (char*)b) ^ 1) && (p = (Blk*)((char*)b - ((int*)b)[-1])) != 0 && !(*(unsigned int*)p & 0x80000000)) {
        merged = 1;
        b->f4->f8 = b->f8;
        b->f8->f4 = b->f4;
        s = p->size + b->size;
        b = p;
        *(unsigned int*)((char*)p + s - 4) = s;
        *(unsigned int*)p = s;
    }
    while ((p = (Blk*)((char*)b + b->size), !((p != 0) ^ 1)) && (char*)p < h->cur && !(*(unsigned int*)p & 0x80000000)) {
        merged = 1;
        p->f4->f8 = p->f8;
        p->f8->f4 = p->f4;
        s = b->size + p->size;
        *(unsigned int*)((char*)b + s - 4) = s;
        *(unsigned int*)b = s;
    }
    if (merged) {
        b->f4->f8 = b->f8;
        b->f8->f4 = b->f4;
        tgt = cMemBin_FindBin(h, cMemChunk_GetSize(b));
        it = tgt;
        sz = cMemChunk_GetSize(b);
        while (cMemChunk_GetNext(it) != tgt && cMemChunk_GetSize(cMemChunk_GetNext(it)) < sz) {
            if ((char*)cMemChunk_GetNext(it) < h->base || (char*)cMemChunk_GetNext(it) > h->cur) {
                printf(D_004BBF50, it);
                cMemChunk_SetNext(it, tgt);
                break;
            }
            it = cMemChunk_GetNext(it);
        }
        cMemChunk_SetPrev(b, it);
        cMemChunk_SetNext(b, cMemChunk_GetNext(it));
        cMemChunk_SetPrev(cMemChunk_GetNext(it), b);
        cMemChunk_SetNext(it, b);
        if (h->last < tgt) h->last = tgt;
    }
}
