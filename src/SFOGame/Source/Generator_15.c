/*
 * SFOGame/Source/Generator: 3 files, 0021DF80-0021E010
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021DF80 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetGeneratorCreateMsg_dtor, D_004DE240, cMessage_dtor)
static inline void merge_flush_func_0021DF80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021DF80 */

/* merge_units: begin func_0021DFE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(int* self, int value) {
    *self = value;
    return self;
}

int* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(int* self, int value) {
    *self = value;
    return self;
}

void* std_list_deleter_cSafePtr_cGOBJ_tail(char* self) {
    return self + 4;
}
static inline void merge_flush_func_0021DFE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021DFE0 */

/* merge_units: begin func_0021E010 */
#pragma push /* merge_units */
int cNetObj_AddSystem(int, int, void*);
int NetGetMyClientIndex(int*, int);
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
typedef struct { char pad[0xC]; int idC; int id10; } Gen_E010;
void cGenerator_InitNetwork(Gen_E010* self)
{
    int ok;
    self->id10 = self->idC;
    ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        int t = self->id10;
        int id;
        int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
        if (g_IsMultiplayer) {
            if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
            id = D_00494178;
        } else id = 0;
        cNetObj_AddSystem(t, id, self);
    }
}
static inline void merge_flush_func_0021E010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021E010 */
