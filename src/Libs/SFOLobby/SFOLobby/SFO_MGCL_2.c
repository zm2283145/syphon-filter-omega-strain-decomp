/*
 * Libs/SFOLobby/SFOLobby/SFO_MGCL: 5 files, 00444DD0-00444FF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00444DD0 */
#pragma push /* merge_units */
#include "types.h"
extern signed char D_00584232;
extern signed char D_00584233;
void func_00444DD0(int d0, int arg1) {
    switch (arg1) {
    case 0:
        D_00584233 = 1;
        break;
    default:
        D_00584233 = 0;
        break;
    }
    D_00584232 = 1;
}
static inline void merge_flush_func_00444DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00444DD0 */

/* merge_units: begin func_00444E10 */
#pragma push /* merge_units */
#include "SFOLobby_Callback_types.h"

extern unsigned char D_00584239;
extern unsigned char D_0058423A;
extern char D_005842DC[0x9C];

/* Save a successful callback's payload and record its completion status. */
void Callback_MGCLServerAuthentication(int unused0, int unused1, int unused2, const LobbyPayloadResult* result)
{
    D_00584239 = 1;
    if (result->status) {
        D_0058423A = 0;
    } else {
        memcpy(D_005842DC, result->payload, sizeof(D_005842DC));
        D_0058423A = 1;
    }
}
static inline void merge_flush_func_00444E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00444E10 */

/* merge_units: begin func_00444E70 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int MGCLClose();                                
extern unsigned char D_00584518;

int SFOMGCL_Close_API(void) {
    int temp_v0;

    if (D_00584518 == 0) {
        return 0;
    }
    temp_v0 = MGCLClose();
    if (temp_v0 == 0) {
        D_00584518 = 0;
    }
    return temp_v0;
}
static inline void merge_flush_func_00444E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00444E70 */

/* merge_units: begin func_00444EC0 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(char *, char *);                            
int MGCLInitialize(int *, int *);                    
int NetGetMyIpAddress(char *);                               
int KM_GetSoftwareID();                                
int memset(int *, int, int);                              
extern signed char D_00584231;
extern char D_00584242;
extern char D_00584262;
extern char D_00584282;
extern char D_005842A2;
extern int D_005842C4;
extern char Callback_ServerEndGame;
extern char Callback_ServerJoinGame;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off

#pragma opt_dead_assignments off
int SFOMGCL_Initialize_API(void) {
    struct { int f20[4]; int f30; int f34; int f38; char * f3C; char * f40; int f44; int f48; int f4C[4]; int f5C; } sl;
    int temp_v0;
    int keep;

    if (D_00584518 != 0) {
        D_00584231 = 1;
        return 0;
    }
    memset(&sl.f30, 0, 0x20);
    memset(&sl.f5C, 0, 4);
    sl.f30 = 0;
    sl.f34 = 0;
    sl.f3C = &Callback_ServerJoinGame;
    sl.f38 = 0;
    sl.f44 = 0;
    sl.f40 = &Callback_ServerEndGame;
    sl.f48 = 0x20;
    sl.f4C[0] = KM_GetSoftwareID();
    keep = temp_v0 = MGCLInitialize(&sl.f30, &sl.f5C);
    if (temp_v0 != 0) {
        return keep;
    }
    
    D_00584231 = 1;
    NetGetMyIpAddress(sl.f20);
    Libc_Strcpy(&D_00584242, sl.f20);
    Libc_Strcpy(&D_00584262, "2002");
    Libc_Strcpy(&D_00584282, sl.f20);
    Libc_Strcpy(&D_005842A2, "2002");
    D_00584518 = (D_005842C4 = 1); 
    return temp_v0;
}
#pragma pop
static inline void merge_flush_func_00444EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00444EC0 */

/* merge_units: begin func_00444FF0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
                            
#if 0 /* merge_units */
int memset(char *, int, int);
#endif /* merge_units */
#define memset(a0, a1, a2) (memset((int *)(a0), (a1), (a2))) /* merge_units */
                                
static const unsigned int dat_004C0B48[2] = { 0x0, 0x0 };
extern char D_00584220;
extern signed char D_00584234;
extern signed char D_00584235;
extern signed char D_00584236;
extern signed char D_00584237;
extern signed char D_00584238;
#if 0 /* merge_units */
extern signed char D_00584239;
#endif /* merge_units */
#define D_00584239 (*(signed char*)&D_00584239) /* merge_units */

#if 0 /* merge_units */
extern signed char D_0058423A;
#endif /* merge_units */
#define D_0058423A (*(signed char*)&D_0058423A) /* merge_units */

extern signed char D_0058423B;
extern int D_0058423C;
extern signed char D_00584240;
extern signed char D_00584241;
#if 0 /* merge_units */
extern signed char D_00584242;
#endif /* merge_units */
#define D_00584242 (*(signed char*)&D_00584242) /* merge_units */

#if 0 /* merge_units */
extern signed char D_00584262;
#endif /* merge_units */
#define D_00584262 (*(signed char*)&D_00584262) /* merge_units */

#if 0 /* merge_units */
extern signed char D_00584282;
#endif /* merge_units */
#define D_00584282 (*(signed char*)&D_00584282) /* merge_units */

#if 0 /* merge_units */
extern signed char D_005842A2;
#endif /* merge_units */
#define D_005842A2 (*(signed char*)&D_005842A2) /* merge_units */

extern signed char D_005842C8;
extern signed char D_00584378;
extern short D_0058438A;
extern short D_0058438C;
extern short D_0058438E;
extern short D_00584390;

int SFOMGCL_Initialize_Module(short arg0, short arg1, short arg2, short arg3) {
    memset(&D_00584220, 0, 0x2F8);
    Libc_Strcpy(&D_00584220, &(*(char*)dat_004C0B48));
    D_0058438A = arg0;
    D_005842C4 = -1;
    D_0058438C = arg1;
    D_0058438E = arg2;
    D_00584390 = arg3;
    D_00584231 = 0;
    D_00584232 = 0;
    D_00584233 = 0;
    D_00584234 = 0;
    D_00584235 = 0;
    D_00584236 = 0;
    D_00584237 = 0;
    D_00584238 = 0;
    D_00584239 = 0;
    D_0058423A = 0;
    D_0058423B = 0;
    D_00584240 = 0;
    D_00584241 = 0;
    D_0058423C = 0;
    D_00584242 = 0;
    D_00584262 = 0;
    D_00584282 = 0;
    D_005842A2 = 0;
    D_005842C8 = 0;
    D_00584378 = 0;
    return 1;
}
#undef memset /* merge_units */
#undef D_00584239 /* merge_units */
#undef D_0058423A /* merge_units */
#undef D_00584242 /* merge_units */
#undef D_00584262 /* merge_units */
#undef D_00584282 /* merge_units */
#undef D_005842A2 /* merge_units */
static inline void merge_flush_func_00444FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00444FF0 */
