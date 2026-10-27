#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int std_vector_deleter_cSkaPlaybackItem_dtor(int, int);                            
int std_vector_cBone_ctor(int );                            

void cSkeleton_DestroyBones(int arg0) {
    int temp_a0;
    int temp_s0;

    temp_a0 = arg0 + 0x18;
    if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
        std_vector_deleter_cSkaPlaybackItem_dtor(temp_a0, 0);
    }
    temp_s0 = arg0 + 0x18;
    if (temp_s0 != NULL) {
        std_vector_cBone_ctor(temp_s0);
        F_(temp_s0, 0xC, signed char) = 1;
    }
}
