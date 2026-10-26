#include "types.h"
#pragma optimization_level 1

extern int* std_vector_deleter_cSkaBlendSequenceItem_data_void(void);

/* Returns the first word of the object returned by std_vector_deleter_cSkaBlendSequenceItem_data_void. */
int std_vector_imp_cSkaBlendSequenceItem_begin_void_2(void) {
    return *std_vector_deleter_cSkaBlendSequenceItem_data_void();
}
