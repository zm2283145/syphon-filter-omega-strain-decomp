#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
float SoftFloat_U64ToFloat(int);                             
int func_003698B0();                                

int func_00288260(int arg0) {
    F_(arg0, 0x4C, float) = (float) (SoftFloat_U64ToFloat(func_003698B0()) / 1000.0f);
    return 0;
}
