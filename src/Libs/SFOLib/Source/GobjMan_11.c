/*
 * Libs/SFOLib/Source/GobjMan: 1 file, 0040BCC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin player_40BCC0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Obj40BCC0 {
    char pad[0xC];
    unsigned char unkC;
} Obj40BCC0;

extern signed char D_00571C20;
extern Obj40BCC0 D_00571C40;
extern char D_00571C28;
extern void std_vector_cBaseObjListPtr_ctor(Obj40BCC0*);
extern int cArrayCapacity_Int(int*);
extern void std_vector_cBaseObjListPtr_reserve(Obj40BCC0*, int);
extern void cArray_cBaseObjListPtr_dtor(void);
extern void __register_global_object(void*, void*, void*);

#pragma push
#pragma opt_propagation off
Obj40BCC0* GetPurgeList(void) {
    if (!D_00571C20) {
        Obj40BCC0* p = &D_00571C40;
        int kind;
        kind = 0x20;
        std_vector_cBaseObjListPtr_ctor(p);
        std_vector_cBaseObjListPtr_reserve(p, cArrayCapacity_Int(&kind));
        p->unkC = 1;
        __register_global_object(p, cArray_cBaseObjListPtr_dtor, &D_00571C28);
        D_00571C20 = 1;
    }
    return &D_00571C40;
}
#pragma pop
static inline void merge_flush_player_40BCC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end player_40BCC0 */
