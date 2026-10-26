#include "types.h"

/* Codec parameters filled in by nciGetInfoSase3200. */
typedef struct NellyInfo {
    char pad00[0x3C];
    unsigned short frameSamples; /* 0x3C */
    char pad3E[0x22];
    unsigned long frameBits;     /* 0x60 */
    char pad68[0x38];
} NellyInfo;

extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_004BFA40[]; /* "nellymoser_wrapper.c" */
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void* memset(void* d, int c, unsigned int n);

extern int D_00582660;
extern int D_00582658;
extern int D_00582570;
extern int D_00582578;
extern int D_00582580;
extern int D_00582588;

/* Four 0x18-byte frame buffers: pcm, pcmLen, data, dataCap, dataLen, flags. */
extern char* D_005825B0;
extern unsigned short D_005825B4;
extern char* D_005825B8;
extern unsigned short D_005825BC;
extern short D_005825BE;
extern char D_005825C0;
extern unsigned short D_005825C2;
extern unsigned char D_005825C4;
extern char* D_005825D0;
extern char* D_005825D8;
extern unsigned short D_005825DC;
extern short D_005825DE;
extern char D_005825E0;
extern unsigned short D_005825E2;
extern unsigned char D_005825E4;
extern char* D_005825F0;
extern char* D_005825F8;
extern unsigned short D_005825FC;
extern short D_005825FE;
extern char D_00582600;
extern unsigned short D_00582602;
extern unsigned char D_00582604;
extern char* D_00582610;
extern char* D_00582618;
extern unsigned short D_0058261C;
extern short D_0058261E;
extern char D_00582620;
extern unsigned short D_00582622;
extern unsigned char D_00582624;
extern char* D_00582628;
extern char* D_00582638;
extern char* D_00582648;

extern void* sfo_malloc_42C960();
extern void* sfo_malloc_2CA9B0();
void nciSetCallocFunction(void* fn);
void nciSetFreeFunction(void* fn);
void nciEnableVu0Optimizations(int n);
void nciGetInfoSase3200(NellyInfo* info);
void nciInitDecodeSase3200(int* h);
void nciInitEncodeSase3200(int* h);
void nciEnableVAD(int h);
void nciSetVADSilenceDuration(int h, int n);
void nciSetVADEnergyTrigLevel(int h, int n);
void nciDisableVoiceFontsSase3200(int h);

static inline void* nm_alloc(unsigned int size, int line)
{
    void* p;
    if (g_ProfileLockEnabled)
        Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = Mem_Alloc(0, size, D_004BFA40, line);
    if (g_ProfileLockEnabled)
        Alloc_Unlock(9);
    g_ProfileLockDepth--;
    return p;
}

/* Initialise the Nellymoser codec wrapper once: hooks, buffers and streams. */
void NellyWrap_Init(void)
{
    NellyInfo info;
    int n;
    if (D_00582660)
        return;
    nciSetCallocFunction(sfo_malloc_42C960);
    nciSetFreeFunction(sfo_malloc_2CA9B0);
    nciEnableVu0Optimizations(1);
    memset(&D_005825B0, 0, 0x18);
    memset(&D_005825D0, 0, 0x18);
    memset(&D_005825F0, 0, 0x18);
    memset(&D_00582610, 0, 0x18);
    D_00582570 = 0;
    D_00582578 = 0;
    D_00582580 = 0;
    D_00582588 = 0;
    nciGetInfoSase3200(&info);
    n = info.frameBits >> 3;
    if (info.frameBits & 7)
        n++;
    D_005825B0 = nm_alloc(info.frameSamples * 2, 0x93);
    memset(D_005825B0, 0, info.frameSamples * 2);
    D_005825B4 = info.frameSamples;
    D_005825B8 = nm_alloc(n + 2, 0x99);
    memset(D_005825B8, 0, n + 2);
    D_005825BE = 0;
    D_005825BC = n + 2;
    D_005825C0 = 0;
    D_005825C2 = 0;
    D_005825C4 = 0;
    D_005825D0 = nm_alloc(info.frameSamples * 2, 0xA7);
    memset(D_005825D0, 0, info.frameSamples * 2);
    D_005825D8 = nm_alloc(n + 2, 0xAC);
    memset(D_005825D8, 0, n + 2);
    D_005825DE = 0;
    D_005825DC = n + 2;
    D_005825E0 = 0;
    D_005825E2 = 0;
    D_005825E4 = 0;
    D_005825F0 = D_005825D0;
    D_005825F8 = nm_alloc(n + 2, 0xBD);
    memset(D_005825F8, 0, n + 2);
    D_005825FE = 0;
    D_005825FC = n + 2;
    D_00582600 = 0;
    D_00582602 = 0;
    D_00582604 = 0;
    D_00582610 = D_005825D0;
    D_00582618 = nm_alloc(n + 2, 0xCC);
    memset(D_00582618, 0, n + 2);
    D_0058261E = 0;
    D_0058261C = n + 2;
    D_00582620 = 0;
    D_00582622 = 0;
    D_00582624 = 0;
    nciInitDecodeSase3200(&D_00582578);
    nciInitDecodeSase3200(&D_00582580);
    nciInitDecodeSase3200(&D_00582588);
    nciInitEncodeSase3200(&D_00582570);
    D_00582628 = nm_alloc(0x280, 0xDF);
    D_00582638 = nm_alloc(0x280, 0xE0);
    D_00582648 = nm_alloc(0x280, 0xE1);
    memset(D_00582628, 0, 0x280);
    memset(D_00582638, 0, 0x280);
    memset(D_00582648, 0, 0x280);
    nciEnableVAD(D_00582570);
    {
        int h = D_00582570;
        nciSetVADSilenceDuration(h, 100);
        nciSetVADEnergyTrigLevel(h, 100);
    }
    nciDisableVoiceFontsSase3200(D_00582570);
    D_00582658 = 0;
    D_00582660 = 1;
}