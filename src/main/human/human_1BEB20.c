#pragma cplusplus on

#include "types.h"
#include "vector_erase_destroy.h"

/* Erase a range from a vector of 60-byte elements. */
DEFINE_ERASE_ELEMENT(Elem60, 60)
DEFINE_VECTOR_ERASE_DESTROY(std_vector_imp_cSkaSliderValue_erase, Elem60, std_msl_copy_cSkaSliderValue_copy, cSkaSliderValue_dtor)
