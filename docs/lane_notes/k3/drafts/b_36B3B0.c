#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct cMemChunk {
    unsigned int mSize;
    cMemChunk* mPrev;
    cMemChunk* mNext;
    int mPad;
    void Reset() { mSize = 0; mPrev = this; mNext = this; }
};
struct cMemBin {
    cMemChunk mBin[128];
    cMemChunk* mMaxBin;
    char* mHeapStartAddr;
    char* mHeapAddr;
    unsigned int mHeapSize;
    unsigned int mBlockSize;
    int mBinReadyFlag;
};

extern "C" {
extern unsigned char D_00533C98;
extern int D_00533CA0;
extern cMemBin D_00533CB0[4];
extern char D_004BBE50[];
void cMemMan_Init_void(void);
char* cMemBin_Allocate(cMemBin* bin, unsigned int size, char* file, int line);
void memset(void* p, int c, unsigned int n);
}

static inline char* MemAllocate(int pool, unsigned int size, char* file, int line)
{
    char* p;
    if (!D_00533C98) cMemMan_Init_void();
    pool = pool == 0 ? D_00533CA0 : pool;
    if (size == 0) return 0;
    p = cMemBin_Allocate(&D_00533CB0[pool], size, file, line);
    if (p) p[-0xC] = (p[-0xC] & 0xF0) + (char)pool;
    return p;
}

extern "C" void cMemMan_Init_int_uint_uint(int binIndex, unsigned int heapSize, unsigned int blockSize)
{
    unsigned int nHeapSize;
    char* heap;
    int i;
    if (!D_00533C98) cMemMan_Init_void();
    nHeapSize = heapSize == 0 ? 0xA00000 : heapSize;
    {
        AllocGuard g;
        heap = MemAllocate(0, nHeapSize, D_004BBE50, 0x598);
    }
    D_00533CB0[binIndex].mMaxBin = D_00533CB0[binIndex].mBin;
    D_00533CB0[binIndex].mHeapStartAddr = D_00533CB0[binIndex].mHeapAddr = heap;
    D_00533CB0[binIndex].mHeapSize = heapSize;
    D_00533CB0[binIndex].mBlockSize = blockSize;
    D_00533CB0[binIndex].mBinReadyFlag = binIndex;
    for (i = 0; i < 128; i++) D_00533CB0[binIndex].mBin[i].Reset();
    memset(D_00533CB0[binIndex].mHeapStartAddr, 0x2A, heapSize);
}



