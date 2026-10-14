/*
 * main/game: range (6 files, 00135B90-00135E70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop
#include "types.h"
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

/* merge_units: begin func_00135B90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_00135B90)
#pragma pop /* merge_units */
/* merge_units: end func_00135B90 */

/* merge_units: begin func_00135C10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_00135C10)
#pragma pop /* merge_units */
/* merge_units: end func_00135C10 */

/* merge_units: begin func_00135C90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_MID(func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_00135C90 */

/* merge_units: begin func_00135D10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_SHALLOW(func_00135D10)
#pragma pop /* merge_units */
/* merge_units: end func_00135D10 */

/* merge_units: begin func_00135D80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00135D80)
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
extern char D_004EA0B0[];
extern char D_004D90A0[];
extern void Receiver_Construct(LosReceiver_f3* r, void* type);
extern LosVec_f3* Vec4_GetZero(void);
extern void Vec4_Assign(LosVec_f3* d, LosVec_f3* s);
extern void func_00136060(void* buf);
extern void func_00136020(LosSub_f3* sub, int arg, LosQuery_f3* q);
extern void ScalarCollection_Init(void* c);
LosReceiver_f3* LosReceiver_Construct(LosReceiver_f3* self, int arg)
{
    LosQuery_f3 q;
    LosSub_f3* sub;
    Receiver_Construct(self, D_004EA0B0);
    self->vtable = D_004D90A0;
    Vec4_Assign(&q.from, Vec4_GetZero());
    Vec4_Assign(&q.to, Vec4_GetZero());
    q.active = 0;
    q.data = q.buf;
    q.count = 0;
    func_00136060(q.buf);
    q.cap = 4;
    q.f110 = 0;
    q.f114 = 0;
    q.f118 = 0;
    sub = &self->sub;
    func_00136020(sub, arg, &q);
    sub->ready = 1;
    q.active = 0;
    ScalarCollection_Init(self->coll30);
    ScalarCollection_Init(self->coll3C);
    self->f48 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00135E70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00135E70 */
