/*
 * main/human: range (2 files, 001B06F0-001B0740)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_001B06F0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkeletonBBoxContribution_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001B06F0 */

/* merge_units: begin func_001B0740 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __register_global_object(int *, char *, char *);        
int std_vector_cSkeletonCenterOfMassContributionPtr_push_back(int, int **);                       
extern signed char D_004EE9E0;
extern char D_004EE9E8;
extern char D_004EE9F8;
extern char D_004EEA08;
extern char D_004EEA18;
extern char D_004EEA28;
extern char D_004EEA38;
extern char D_004EEA48;
extern char D_004EEA58;
extern char D_004EEA68;
extern char D_004EEA78;
extern int D_004EEA90;
extern int D_004EEA94;
extern int D_004EEA98;
extern int D_004EEA9C;
extern int D_004EEAA0;
extern int D_004EEAA4;
extern int D_004EEAA8;
extern int D_004EEAAC;
extern int D_004EEAB0;
extern int D_004EEAB4;
extern int D_004EEAB8;
extern int D_004EEABC;
extern int D_004EEAC0;
extern int D_004EEAC4;
extern int D_004EEAC8;
extern int D_004EEACC;
extern int D_004EEAD0;
extern int D_004EEAD4;
extern int D_004EEAD8;
extern int D_004EEADC;
extern char cSkeletonCenterOfMassContribution_dtor;

void InitStatics_CenterOfMass(int arg0) {
    int var_s2;
    int *sp4C;
    int *var_s1;

    if (D_004EE9E0 == 0) {
        D_004EEA90 = 2;
        D_004EEA94 = 0x3FA00000;
        __register_global_object(&D_004EEA90, &cSkeletonCenterOfMassContribution_dtor, &D_004EE9E8);
        D_004EEA98 = 5;
        D_004EEA9C = 0x3FA00000;
        __register_global_object(&D_004EEA98, &cSkeletonCenterOfMassContribution_dtor, &D_004EE9F8);
        D_004EEAA0 = 4;
        D_004EEAA4 = 0x3E800000;
        __register_global_object(&D_004EEAA0, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA08);
        D_004EEAA8 = 6;
        D_004EEAAC = 0x3E800000;
        __register_global_object(&D_004EEAA8, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA18);
        D_004EEAB0 = 7;
        D_004EEAB4 = 0x3D4CCCCD;
        __register_global_object(&D_004EEAB0, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA28);
        D_004EEAB8 = 0xB;
        D_004EEABC = 0x3D4CCCCD;
        __register_global_object(&D_004EEAB8, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA38);
        D_004EEAC0 = 0x11;
        D_004EEAC4 = 0x3E19999A;
        __register_global_object(&D_004EEAC0, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA48);
        D_004EEAC8 = 0x12;
        D_004EEACC = 0x3E19999A;
        __register_global_object(&D_004EEAC8, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA58);
        D_004EEAD0 = 0x13;
        D_004EEAD4 = 0x3CCCCCCD;
        __register_global_object(&D_004EEAD0, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA68);
        D_004EEAD8 = 0x14;
        D_004EEADC = 0x3CCCCCCD;
        __register_global_object(&D_004EEAD8, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA78);
        D_004EE9E0 = 1;
    }
    var_s2 = 0;
    var_s1 = &D_004EEA90;
    do {
        sp4C = var_s1;
        std_vector_cSkeletonCenterOfMassContributionPtr_push_back(arg0, &sp4C);
        var_s2 += 1;
        var_s1 += 2;
    } while (var_s2 < 0xA);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B0740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B0740 */
