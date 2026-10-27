/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

void* cVector_Z_void_2(char* self) {
    return self + 8;
}

/* Clip root-motion axis Z flag set. */
int cSkaAnimData_RootHasDeltaTranslationZ(SkaClipFlags* clip) {
    return 0U < clip->axisZ;
}

void* cVector_Y_void_2(char* self) {
    return self + 4;
}

/* Clip root-motion axis Y flag set. */
int cSkaAnimData_RootHasDeltaTranslationY(SkaClipFlags* clip) {
    return 0U < clip->axisY;
}

/* Clip root-motion axis X flag set. */
int cSkaAnimData_RootHasDeltaTranslationX(SkaClipFlags* clip) {
    return 0U < clip->axisX;
}

void* cVector_X_void_2(void* self) {
    return self;
}

Iter16* cSkaAnimDataFrame_ConstIterator_opInc(Iter16* it) {
    it->p += 16;
    return it;
}
