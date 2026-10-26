/*
 * main/game: range (4 files, 0012FBD0-0012FCD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* merge_units: begin func_0012FBD0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cEndLevelMsg_dtor, D_004DADB0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0012FBD0 */

/* merge_units: begin func_0012FC30 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad0[0x3C]; char x3C[0x26]; unsigned char b62; char pad1[0xB4-0x63]; void* pB4; } Obj_0012FC30;
extern "C" {
void EventQueue_ClearAll(void);
void FrontEnd_TeardownGui(void* p);
void MsgQueue_ClearPending(void);
void Archive_ReleaseAll(void* p);
}
extern "C" void cGameSystem_ShutdownFrontEnd(Obj_0012FC30* o)
{
    EventQueue_ClearAll();
    if (o->b62) FrontEnd_TeardownGui(o->pB4);
    MsgQueue_ClearPending();
    Archive_ReleaseAll(o->x3C);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012FC30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012FC30 */

/* merge_units: begin func_0012FC80 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad0[0x62]; unsigned char b62; char p63; unsigned char b64; char pad1[0xB4-0x65]; void* pB4; } Obj_0012FC80;
extern "C" {
void FrontEnd_UpdateGui(void* p);
void FrontEnd_DrawGui(void* p);
}
extern "C" void cGameSystem_UpdateFrontEnd(Obj_0012FC80* o)
{
    if (o->b62 || o->b64) {
        FrontEnd_UpdateGui(o->pB4);
        FrontEnd_DrawGui(o->pB4);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012FC80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012FC80 */

/* merge_units: begin func_0012FCD0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x2B]; unsigned char b2B; } Sub_0012FCD0;
typedef struct { char pad0[0x62]; unsigned char b62; char p63; unsigned char b64; char pad1[0xB4-0x65]; Sub_0012FCD0* pB4; } Obj_0012FCD0;
extern "C" {
void Awards_Init(void);
void FrontEnd_FirstEntry(void* p);
}
extern "C" void cGameSystem_InitFrontEnd(Obj_0012FCD0* o)
{
    Awards_Init();
    if (o->b64) {
        o->pB4->b2B = 1;
        FrontEnd_FirstEntry(o->pB4);
    } else if (o->b62) {
        FrontEnd_FirstEntry(o->pB4);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012FCD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012FCD0 */
