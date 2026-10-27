/*
 * main/gobj: 2 files, 003D2600-003D2630
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D2600 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cLListIterator_cAnimTexturePtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cAnimTexturePtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cAnimTexturePtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D2600 */

/* merge_units: begin func_003D2630 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int std_list_deleter_voidPtr_erase_listdeleter(char *, int, char *);                     
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(char *, int *);                        
int cLList_cAnimTexturePtr_End(char *, int);                          
int cLList_cAnimTexturePtr_Begin(char *, int);                          
int cLListIterator_cAnimTexturePtr_ctor_cLListIteratorR(int *, char *);                        
int opNe_cLListIteratorR_cLListIteratorR_10(char *, char *);                        
int cLListIterator_cAnimTexturePtr_opInc(char *);                               
int *cLListIterator_cAnimTexturePtr_opMul(char *);                            
int cLListIterator_cAnimTexturePtr_opAssign(char *, char *);                          
int cLListIterator_cAnimTexturePtr_ctor_void(char *);                               

void cAnimTexMan_Remove(int arg0, int arg1) {
    int sp4C;
    int sp48;
    int sp44;
    int sp40;
    int sp3C;
    int sp38;
    int sp34;

    cLListIterator_cAnimTexturePtr_ctor_void(&sp3C);
    cLList_cAnimTexturePtr_Begin(&sp38, arg0);
    cLListIterator_cAnimTexturePtr_opAssign(&sp3C, &sp38);
    cLList_cAnimTexturePtr_End(&sp34, arg0);
    while (opNe_cLListIteratorR_cLListIteratorR_10(&sp3C, &sp34) != 0) {
        { int v = *cLListIterator_cAnimTexturePtr_opMul(&sp3C); if (v == arg1) break; }
        cLListIterator_cAnimTexturePtr_opInc(&sp3C);
        cLList_cAnimTexturePtr_End(&sp34, arg0);
    }
    cLListIterator_cAnimTexturePtr_ctor_cLListIteratorR(&sp4C, &sp3C);
    sp48 = sp4C;
    std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp40, &sp48);
    std_list_deleter_voidPtr_erase_listdeleter(&sp44, arg0, &sp40);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D2630 */
