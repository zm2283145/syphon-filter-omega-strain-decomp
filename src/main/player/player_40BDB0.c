/*
 * main/player: 4 files, 0040BDB0-0040BF10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040BDB0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cBaseObjListPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0040BDB0 */

/* merge_units: begin func_0040BEA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_reserve(int, int);

int std_vector_cBaseObjListPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_cBaseObjListPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040BEA0 */

/* merge_units: begin func_0040BED0 */
#pragma push /* merge_units */
#include "GobjMan_types.h"

extern GobjEntry* D_00571770;
extern GobjId D_00571774;

/* Publish the local player and retain its ID for subsequent validity checks. */
void nGobjManager_SetPlayer(GobjEntry* player)
{
    GobjId missing;
    const GobjId* id;
    D_00571770 = player;
    if (player)
        id = &player->id;
    else {
        missing.word = -1;
        id = &missing;
    }
    D_00571774.word = id->word;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040BED0 */

/* merge_units: begin func_0040BF10 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; } Tgt40BF10;
typedef struct { Tgt40BF10* obj; int serial; } Ref40BF10;
#if 0 /* merge_units */
extern Ref40BF10 D_00571770;
#endif /* merge_units */
#define D_00571770 (*(Ref40BF10*)&D_00571770) /* merge_units */

Tgt40BF10* nGobjManager_GetPlayer(void) {
    Tgt40BF10* obj = D_00571770.obj;
    unsigned char valid = 1;
    if (!((obj != 0) ^ 1)) {
        if (obj->serial != D_00571770.serial) {
            valid = 0;
        }
    }
    return valid ? obj : 0;
}
#undef D_00571770 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040BF10 */
