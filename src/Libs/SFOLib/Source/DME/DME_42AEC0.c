/*
 * main/DME: 3 files, 0042AEC0-0042AFC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042AEC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_005724B0;
extern int NetRequestServersOnSubnet(void* callback);
extern int NetUpdate(void);
extern int cDME_SvrResponseCallback(int, int);

/* Sets D_005724B0 to 3 and installs cDME_SvrResponseCallback via NetRequestServersOnSubnet; falls back to NetUpdate on failure. */
int cDME_CreateServerList(void) {
    int ret;

    D_005724B0 = 3;
    ret = NetRequestServersOnSubnet(cDME_SvrResponseCallback);
    if (ret == 0) {
        ret = NetUpdate();
    }
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042AEC0 */

/* merge_units: begin func_0042AF00 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetGetClientVersion(char *);                               
int NetSetDefaultInitializeParams(char *);                               
int NetInitialize(char *, char *);                        
int NetRegisterMallocFreeCallbacks(char *, char *);                        
int NetSetBufferSize(int, int);                            
extern signed char D_00572418;
extern signed char D_00572419;
extern signed char D_0057241A;
extern signed char D_0057241B;
#if 0 /* merge_units */
extern signed char D_005724B0;
#endif /* merge_units */
#define D_005724B0 (*(signed char*)&D_005724B0) /* merge_units */

extern char Sfo_Malloc;
extern char sfo_free;

void cDME_Init(void) {
    int sp40[8];
    int sp20[8];
    int sp10[4];
    int temp_v0;

    D_00572418 = 0;
    D_00572419 = 0;
    D_0057241A = 0;
    D_0057241B = 0;
    temp_v0 = NetRegisterMallocFreeCallbacks(&Sfo_Malloc, &sfo_free);
    if (temp_v0 == 0) {
        if (temp_v0 == 0) {
            NetSetDefaultInitializeParams(sp40);
            if (NetInitialize(sp40, sp20) == 0) {
                NetGetClientVersion(sp10);
                if (NetSetBufferSize(0x6000, 0x6000) == 0) {
                    D_005724B0 = 1;
                }
            } else {
                D_005724B0 = 2;
            }
        } else {
            D_005724B0 = 2;
        }
    }
}
#undef D_005724B0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042AF00 */

/* merge_units: begin func_0042AFC0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int NetGetClientVersion(char* buffer);
#endif /* merge_units */
#define NetGetClientVersion(a0) (NetGetClientVersion((a0))) /* merge_units */

#if 0 /* merge_units */
extern int NetSetBufferSize(int first, int second);
#endif /* merge_units */
#define NetSetBufferSize(a0, a1) (NetSetBufferSize((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern unsigned char D_005724B0;
#endif /* merge_units */
#define D_005724B0 (*(unsigned char*)&D_005724B0) /* merge_units */


/* Read the library version and update connection state when setup returns zero. */
void cDME_Init_PostLobby(void)
{
    char version[16];
    NetGetClientVersion(version);
    if (!NetSetBufferSize(0x6000, 0x6000))
        D_005724B0 = 1;
}
#undef NetGetClientVersion /* merge_units */
#undef NetSetBufferSize /* merge_units */
#undef D_005724B0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042AFC0 */
