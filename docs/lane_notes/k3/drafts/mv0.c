#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct LinkMB { int data; LinkMB* prev; LinkMB* next; int pad; };

struct cMemBin {
    LinkMB mBins[128];
    LinkMB* mFirst;
    char* mStart;
    char* mCur;
    int mSize;
    int mUsed;
    int mHandle;
    void Init(int handle, char* start, char* end);
};

struct cMemMan {
    unsigned char mInitFlag;
    char pad1[7];
    int mCurBin;
    char padC[0xC];
};

extern "C" {
extern cMemMan D_00533C98;
extern cMemBin D_00533CB0[4];
extern char D_0059A980[];
extern char D_0059C980[];
extern char D_01FF0000[];
extern char D_004BBE58[];
extern char D_004BBE50[];
int printf(const char*, ...);
void* memset(void*, int, unsigned int);
char* cMemBin_Allocate(cMemBin* pool, int size, char* file, int line);
void cMemBin_Deallocate(cMemBin* pool, void* block, char* file, int line);
void cMemMan_Init_void(void);
}

inline void cMemBin::Init(int handle, char* start, char* end)
{
    mUsed = 0;
    mFirst = mBins;
    mCur = start;
    mStart = start;
    mHandle = handle;
    mSize = (unsigned long)end - (unsigned long)start;
    for (int i = 0; i < 128; i++) {
        mBins[i].data = 0;
        mBins[i].prev = &mBins[i];
        mBins[i].next = &mBins[i];
    }
    memset(mStart, 0x2A, (unsigned long)end - (unsigned long)start);
}

static inline char* AllocMM(int size, char* file, int line)
{
    char* p;
    if (!D_00533C98.mInitFlag) cMemMan_Init_void();
    int pool = D_00533C98.mCurBin;
    if (size == 0) return 0;
    p = cMemBin_Allocate(&D_00533CB0[pool], size, file, line);
    if (p) p[-0xC] = (p[-0xC] & 0xF0) + (char)pool;
    return p;
}

static inline void FreeMM(char* block, char* file, int line)
{
    if (block) {
        char pool = block[-0xC] & 0xF;
        cMemBin_Deallocate(&D_00533CB0[pool], block, file, line);
    }
}

extern "C" void cMemMan_Init_void(void)
{
    if (D_00533C98.mInitFlag) return;
    D_00533CB0[0].mHandle = -1;
    D_00533CB0[1].mHandle = -1;
    D_00533CB0[2].mHandle = -1;
    D_00533CB0[3].mHandle = -1;
    int stack = (int)D_01FF0000;
    printf(D_004BBE58, stack);
    D_00533C98.mCurBin = 0;
    D_00533C98.mInitFlag = 1;
    if (stack != -1) {
        D_00533CB0[0].Init(0, D_0059A980, (char*)stack);
        char* memFull;
        {
            AllocGuard g;
            memFull = AllocMM((unsigned long)(char*)stack - (unsigned long)D_0059C980, D_004BBE50, 0x579);
        }
        {
            AllocGuard g;
            FreeMM(memFull, D_004BBE50, 0x57A);
        }
    } else {
        D_00533CB0[0].Init(0, D_0059A980, (char*)0x2000000);
        char* memFull;
        {
            AllocGuard g;
            memFull = AllocMM((unsigned long)0x2000000 - (unsigned long)D_0059C980, D_004BBE50, 0x57F);
        }
        {
            AllocGuard g;
            FreeMM(memFull, D_004BBE50, 0x580);
        }
    }
}
