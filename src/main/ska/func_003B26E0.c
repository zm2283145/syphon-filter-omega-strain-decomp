#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
typedef __int128 Q128;
Q128 *cVector_SetZero(Q128 *arg0) {
    *arg0 = 0;
    return arg0;
}
