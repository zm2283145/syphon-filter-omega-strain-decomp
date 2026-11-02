/*
 * SFOGame/Source/game: 9 files, 001359D0-00135B90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001359D0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_two_member_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "two_member_dtor.h"
#pragma pop

#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(cPlaySoundMsg_dtor_void, D_004DAE30)
static inline void merge_flush_func_001359D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001359D0 */

/* merge_units: begin func_00135A60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destructor: destroy two members, optionally delete. */
DEFINE_TWO_MEMBER_DTOR(cString_dtor, cFileMan_dtor, 0x48, 0xE4)
static inline void merge_flush_func_00135A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135A60 */

/* merge_units: begin func_00135AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_00135AD0 { void* vt; char pad[0x1C]; char m20[0x10]; char m30[0xC]; char m3C[4]; };
extern "C" {
extern "C" void cLosManager_cCollisionModelList_Game_HandleMessage();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cSystem_IsNetworked();
extern "C" void cSystem_getSOBJClassId();
extern "C" void cSystem_ScriptHandleMessage();
extern void * const D_004D90A0[];
#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_dtor(void* m, short f);
#endif /* merge_units */
void* std_basic_string_char_char_traits_char_dtor(void* self, short deleteFlag); /* merge_units */
#define std_basic_string_char_char_traits_char_dtor(a0, a1) ((void)std_basic_string_char_char_traits_char_dtor((a0), (a1))) /* merge_units */

void func_0013A130(void* m, short f);
void cSystem_dtor(void* p, short f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

}
extern "C" O_00135AD0* cLosManager_cCollisionModelList_Game_dtor(O_00135AD0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004D90A0);
        if (self->m3C) std_basic_string_char_char_traits_char_dtor(self->m3C, 0);
        if (self->m30) std_basic_string_char_char_traits_char_dtor(self->m30, 0);
        if (self->m20) { if (self->m20) { if (self->m20) func_0013A130(self->m20, 0); } }
        cSystem_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004D90A0[16] = { (void*)0x0, (void*)0x0, (void*)cLosManager_cCollisionModelList_Game_dtor, (void*)cLosManager_cCollisionModelList_Game_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)0x0 };
#undef std_basic_string_char_char_traits_char_dtor /* merge_units */
#undef operator_delete /* merge_units */
static inline void merge_flush_func_00135AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135AD0 */

/* merge_units: begin func_00135B90 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "obj_list_dtor_mid.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "obj_list_dtor_shallow.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop

#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_basic_string_char_char_traits_char_dtor)
static inline void merge_flush_func_00135B90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135B90 */

/* merge_units: begin func_00135C10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_00135C10)
static inline void merge_flush_func_00135C10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135C10 */

/* merge_units: begin func_00135C90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_MID(func_00135C90)
static inline void merge_flush_func_00135C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135C90 */

/* merge_units: begin func_00135D10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_SHALLOW(std_vector_deleter_cArray_int_dtor)
static inline void merge_flush_func_00135D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135D10 */

/* merge_units: begin func_00135D80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_int_dtor)
static inline void merge_flush_func_00135D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135D80 */

/* merge_units: begin func_00135E70 */
#pragma push /* merge_units */
typedef struct { float v[4]; } LosVec_f3;
typedef struct {
    LosVec_f3 from;
    LosVec_f3 to;
    unsigned char active; char pad21[3];
    int count;
    void* data;
    char pad2C[4];
    char buf[0xA0];
    int f110; int f114; int f118; int cap;
} LosQuery_f3;
typedef struct { char pad[0xC]; unsigned char ready; } LosSub_f3;
typedef struct {
    void* vtable; char pad4[0x1C];
    LosSub_f3 sub; char pad2D[3];
    char coll30[0xC];
    char coll3C[0xC];
    int f48;
} LosReceiver_f3;
extern char g_LosCheckService[];
#if 0 /* merge_units */
extern char D_004D90A0[];
#endif /* merge_units */
#define D_004D90A0 ((char*)&D_004D90A0) /* merge_units */

extern void cSystem_ctor(LosReceiver_f3* r, void* type);
extern LosVec_f3* cVector_GetZero(void);
extern void cVector_ctor_cVectorR(LosVec_f3* d, LosVec_f3* s);
extern void cLosResult_ctor_void(void* buf);
extern void std_vector_imp_cLosRequest_cCollisionModelList_Game_ctor(LosSub_f3* sub, int arg, LosQuery_f3* q);
extern void std_list_deleter_voidPtr_ctor_void(void* c);
LosReceiver_f3* LosReceiver_Construct(LosReceiver_f3* self, int arg)
{
    LosQuery_f3 q;
    LosSub_f3* sub;
    cSystem_ctor(self, g_LosCheckService);
    self->vtable = D_004D90A0;
    cVector_ctor_cVectorR(&q.from, cVector_GetZero());
    cVector_ctor_cVectorR(&q.to, cVector_GetZero());
    q.active = 0;
    q.data = q.buf;
    q.count = 0;
    cLosResult_ctor_void(q.buf);
    q.cap = 4;
    q.f110 = 0;
    q.f114 = 0;
    q.f118 = 0;
    sub = &self->sub;
    std_vector_imp_cLosRequest_cCollisionModelList_Game_ctor(sub, arg, &q);
    sub->ready = 1;
    q.active = 0;
    std_list_deleter_voidPtr_ctor_void(self->coll30);
    std_list_deleter_voidPtr_ctor_void(self->coll3C);
    self->f48 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00135E70(void) {}
#undef D_004D90A0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135E70 */
