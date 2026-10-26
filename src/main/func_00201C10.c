#include "types.h"
extern int* MotionChildArr_GetData(void);
/* Return the value pointed to by MotionChildArr_GetData(). */
int std_vector_imp_cSkaBlendSequenceItem_begin_void(void)
{
    return *MotionChildArr_GetData();
}
