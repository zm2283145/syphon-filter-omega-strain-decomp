/*
 * Libs/SFOLobby/SFOLobby/SFO_MGCL: 3 files, 00445130-00445230
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00445130 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(char *, int);                              
int MGCLEndGameResponse(char *);                               
int memset(char *, int, int);                                
extern short D_0058438E;

void Callback_ServerEndGame(int d0, int d1, int d2, int arg3) {
    struct { int f20[5]; char pad34[1]; signed char f35[11]; } sl;

    memset(sl.f20, 0, 0x16);
    if (D_0058438E > 0) {
        sl.f35[0] = 0;
        Libc_Strcpy(sl.f20, arg3);
    } else {
        sl.f35[0] = -0xC;
        Libc_Strcpy(sl.f20, arg3);
    }
    MGCLEndGameResponse(sl.f20);
}
static inline void merge_flush_func_00445130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00445130 */

/* merge_units: begin func_004451B0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
int MGCLJoinGameResponse(void *);
int func_003A6BB0(void);
#if 0 /* merge_units */
int memset(void *, int, int);
#endif /* merge_units */
#define memset(a0, a1, a2) (memset((char *)(a0), (a1), (a2))) /* merge_units */

int strncpy(void *, char *, int);
}
typedef struct { char name[0x15]; signed char f15; signed char f16; char pad[0x51]; } Req445;
#pragma bool off
static inline int nz445(int x) { return x != 0; }
extern "C" int Callback_ServerJoinGame(int d0, int d1, int d2, char *arg3) {
    Req445 r;
    memset(&r, 0, 0x68);
    strncpy(r.name, arg3, 0x15);
    r.f15 = nz445(func_003A6BB0()) ^ 1;
    r.f16 = 0;
    /* barrier: empty asm keeps the branchy return (b + delay slot) shape */
    int v; if (MGCLJoinGameResponse(&r) != 0) { v = -0xC; asm { .set reorder } } else v = 0; return v;
}
#pragma bool reset
#undef memset /* merge_units */
static inline void merge_flush_func_004451B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004451B0 */

/* merge_units: begin func_00445230 */
#pragma push /* merge_units */
#include "SFOLobby_Callback_types.h"

extern unsigned char D_00584237;
extern unsigned char D_00584238;

/* Record callback completion separately from its success status. */
void func_00445230(int unused0, int unused1, int unused2, LobbyStatusResult* result)
{
    D_00584237 = 1;
    if (!result->status)
        D_00584238 = 1;
    else
        D_00584238 = 0;
}
static inline void merge_flush_func_00445230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00445230 */
