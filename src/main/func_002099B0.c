#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma push
#pragma optimization_level 1
int cAllocator_cSkaBlendSequenceItem_max_size(void) {
    return 0x800000;
}
#pragma pop
