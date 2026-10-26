#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int sceMpegResetDefaultPtsGap(int arg0) {
    int temp_v1;

    temp_v1 = F_(arg0, 0x40, int);
    F_(temp_v1, 0x90, long long) = 0;
    F_(temp_v1, 0x8C, int) = 0;
    return 1;
}
