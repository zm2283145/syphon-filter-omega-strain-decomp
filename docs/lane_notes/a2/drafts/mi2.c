#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct cMemChunk {
    unsigned int mSize;
    cMemChunk* mPrev;
    cMemChunk* mNext;
    int mPad;
};
struct cMemBin {
    cMemChunk mBin[128];
    cMemChunk* mMaxBin;
    char* mHeapStartAddr;
    char* mHeapAddr;
    unsigned int mHeapSize;
    unsigned int mBlockSize;
    int mHandle;
    void Init(int handle, char* heap, unsigned int heapSize, unsigned int blockSize);
};

extern "C" {
struct cMemMan { unsigned char mInitFlag; char pad1[7]; int mCurBin; char padC[0xC]; };
extern cMemMan D_00533C98;
extern cMemBin D_00533CB0[4];
extern char D_004BBE50[];
void cMemMan_Init_void(void);
char* cMemBin_Allocate(cMemBin* bin, unsigned int size, char* file, int line);
void memset(void* p, int c, unsigned int n);
}

inline void cMemBin::Init(int handle, char* heap, unsigned int heapSize, unsigned int blockSize)
{
    mMaxBin = mBin;
    mHeapStartAddr = mHeapAddr = heap;
    mHeapSize = heapSize;
    mBlockSize = blockSize;
    mHandle = handle;
    for (int i = 0; i < 128; i++) {
        mBin[i].mSize = 0;
        mBin[i].mPrev = &mBin[i];
        mBin[i].mNext = &mBin[i];
    }
    memset(mHeapStartAddr, 0x2A, heapSize);
}

static inline char* MemAllocate(int pool0, unsigned int size, char* file, int line)
{
    char* p;
    if (!D_00533C98.mInitFlag) cMemMan_Init_void();
    int pool = D_00533C98.mCurBin;
    if (size == 0) return 0;
    p = cMemBin_Allocate(&D_00533CB0[pool], size, file, line);
    if (p) p[-0xC] = (p[-0xC] & 0xF0) + (char)pool;
    return p;
}

static inline char* GuardAlloc(unsigned int size, char* file, int line)
{
    AllocGuard g;
    return MemAllocate(0, size, file, line);
}

extern "C" void cMemMan_Init_int_uint_uint(int binIndex, unsigned int heapSize, unsigned int blockSize)
{
    if (!D_00533C98.mInitFlag) cMemMan_Init_void();
    D_00533CB0[binIndex].Init(binIndex, GuardAlloc(heapSize == 0 ? 0xA00000 : heapSize, D_004BBE50, 0x598), heapSize, blockSize);
}
