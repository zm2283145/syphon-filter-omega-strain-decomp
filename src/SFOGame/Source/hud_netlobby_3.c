/*
 * SFOGame/Source/hud_netlobby: 4 files, 0027B690-0027B880
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027B690 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_B690 { int p; };
extern "C" {
void cMemMan_Deallocate(int, void*, char*, int);
Raw_B690 std_list_deleter_voidPtr_begin_void(void*);
Raw_B690 std_list_GameInfoPtr_end(void*);
void std_list_GameInfoPtr_generic_iterator_ctor(char**, const Raw_B690&);
void cLListIterator_GameInfoPtr_ctor(char**, const Raw_B690&);
void cInterfaceElement_Destroy(void*);
void cInterface_dtor(void*, int);
#if 0 /* merge_units */
void std_list_GameInfoPtr_dtor(void*, int);
#endif /* merge_units */
void* std_list_GameInfoPtr_dtor(void* self, short deleteFlag); /* merge_units */
#define std_list_GameInfoPtr_dtor(a0, a1) ((void)std_list_GameInfoPtr_dtor((a0), (short)(a1))) /* merge_units */

void operator_delete(void*);
extern char D_004A9270;
}
extern "C" char* cHudNetLobby_dtor(char* self, short flag) {
    if (self) {
        char* end;
        {
            char* e;
            char* n;
            char* it;
            std_list_GameInfoPtr_generic_iterator_ctor(&it, std_list_deleter_voidPtr_begin_void(self + 0x2C));
            n = it;
            while ((cLListIterator_GameInfoPtr_ctor(&end, std_list_GameInfoPtr_end(self + 0x2C)), n != end)) {
                e = F_(n, 0x8, char*);
                {
                    AllocGuard g;
                    if (e) { if (F_(e, 0x14, void*)) cInterfaceElement_Destroy(F_(e, 0x14, void*)); }
                    cMemMan_Deallocate(0, e, &D_004A9270, 0x68);
                }
                n = F_(n, 0x4, char*);
            }
        }
        {
            char* p = F_(self, 0x0, char*);
            AllocGuard g;
            cInterface_dtor(p, -1);
            cMemMan_Deallocate(0, p, &D_004A9270, 0x6A);
        }
        if (self + 0x2C) std_list_GameInfoPtr_dtor(self + 0x2C, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
#undef std_list_GameInfoPtr_dtor /* merge_units */
static inline void merge_flush_func_0027B690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027B690 */

/* merge_units: begin func_0027B880 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_GameInfoPtr_dtor)
static inline void merge_flush_func_0027B880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027B880 */

/* merge_units: begin func_0027B900 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern char D_00504040;
extern int D_00504058;
extern void std_list_deleter_voidPtr_ctor_void(ScalarCollection*);
extern int* LoadInterface_charP_cHogFileR(int, int);
extern int cInterfaceModel_Activate(int, int, int);

/* Constructor: init embedded collection, acquire a handle and clear all fields. */
Unk27B900* cHudNetLobby_ctor(Unk27B900* self, int a1, int a2) {
    std_list_deleter_voidPtr_ctor_void(&self->list);
    self->unk50 = 3658;
    self->handle = LoadInterface_charP_cHogFileR(a2, a1);
    cInterfaceModel_Activate(*self->handle, 0, 1);
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk04 = 0;
    self->unk0C = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk14 = 0;
    self->unk28 = 0;
    self->unk54 = 0;
    self->unk55 = 0;
    self->unk56 = 0;
    D_00504040 = 0;
    return self;
}

int cNetTaserMsg_GetMsgId(void) {
    return D_00504058;
}
static inline void merge_flush_func_0027B900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027B900 */

/* merge_units: begin func_0027B9C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"
#include "v4_asm_copy.h"

/* Clone a network message (payload ends with a 16-byte vector at 0x40). */
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
extern "C" { char D_004A92A8[] = "netTaserMsg.hh"; }
DEFINE_NET_MSG_CLONE(cNetTaserMsg_Clone, 0x50, D_004A92A8, 0x22, D_004DCDA0,
                     NMC_B(0x24); NMC_W(0x28); NMC_W(0x2C); NMC_UB(0x30); NMC_W(0x34);
                     { char* d = (char*)p + 0x40; char* s = (char*)self + 0x40; V4Copy(d, s); })
static inline void merge_flush_func_0027B9C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027B9C0 */
