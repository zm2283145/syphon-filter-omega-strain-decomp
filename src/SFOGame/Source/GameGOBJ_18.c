/*
 * SFOGame/Source/GameGOBJ: 2 files, 002128A0-00212920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002128A0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int nGobjManager_LookupGOBJ_cObjectIdR(int *);                     
int NetGetObject(void **);                         
extern unsigned char D_005723C8;

#pragma push
#pragma opt_common_subs off
void func_002128A0(void) {
    struct { char pad10[4]; int f14; int f18[2]; } sl;
    int temp_v0;
    int temp_v0_2;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (NetGetObject(sl.f18) == 0) {
        temp_v0 = F_(sl.f18[0], 0x1C, int);
        sl.f14 = F_(temp_v0, 0x10, unsigned short) | (F_(temp_v0, 0xE, unsigned short) << 0x10);
        temp_v0_2 = nGobjManager_LookupGOBJ_cObjectIdR(&sl.f14);
        if (temp_v0_2 != NULL) {
            (void)*(volatile int*)((char*)temp_v0_2 + 0xD0); F_(temp_v0_2, 0xD0, int) = 0;
        }
    }
    D_005723C8 = 0;
}
#pragma pop
static inline void merge_flush_func_002128A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002128A0 */

/* merge_units: begin func_00212920 */
#pragma push /* merge_units */
typedef struct { int unk0; int unk4; char pad[4]; unsigned char unkC; char pad2[0x1F]; } NetInit;

extern int D_004F5480;
extern int NetRegisterObjectStart(void);
extern int cPathedGOBJ_RegisterPathedGobj(NetInit* init);
extern int NetRegisterStructure(int* handle, const char* name, int n);
extern void NetRegisterRemoteObjectCallback(int handle, void (*a)(), void (*b)(), void (*c)());
extern void cPathedGOBJ_PathedGobjCreationCallback();
extern void cPathedGOBJ_PathedGobjUpdateCallback();
extern void func_002128A0();

/* Initializes the network service, opens the named handle and registers its callbacks. */
void cPathedGOBJ_InitNet(void)
{
    NetInit init;
    int handle;
    init.unk0 = 0;
    init.unk4 = 0;
    init.unkC = 0;
    if (NetRegisterObjectStart())
        return;
    if (!cPathedGOBJ_RegisterPathedGobj(&init))
        return;
    if (NetRegisterStructure(&handle, "NetPathedGobj", 0x20))
        return;
    D_004F5480 = handle;
    NetRegisterRemoteObjectCallback(handle, cPathedGOBJ_PathedGobjCreationCallback, cPathedGOBJ_PathedGobjUpdateCallback, func_002128A0);
}
static inline void merge_flush_func_00212920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00212920 */
