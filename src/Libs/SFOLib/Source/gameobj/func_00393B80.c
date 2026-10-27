/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int std_vector_imp_cSkaSliderValue_resize(void* v, int a1, int a2);
extern int std_vector_imp_cSkaSwitchValue_resize(void* v, int a1, int a2);

int cArray_cSkaSwitchValue_ResizeActual(void* v, int a1, int a2) {
    return std_vector_imp_cSkaSwitchValue_resize(v, a1, a2);
}

int cSkaAnimationSet_SwitchParamCount(char* self) {
    return *(int*)(self + 0x58);
}

/* Clears a two-word pair. */
int* cSkaSwitchValue_ctor(int* p) {
    p[0] = 0;
    p[1] = 0;
    return p;
}

int cArray_cSkaSliderValue_ResizeActual(void* v, int a1, int a2) {
    return std_vector_imp_cSkaSliderValue_resize(v, a1, a2);
}

int cSkaAnimationSet_SliderParamCount(char* self) {
    return *(int*)(self + 0x54);
}
