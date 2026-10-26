#include "types.h"

extern int GridUpdateSpeakStatus(int);

int IsSpeakDisallowedInGrid(int a0) {
    int s0, v0, v1;

    s0 = a0;
    v0 = GridUpdateSpeakStatus(a0);
    v1 = *(int*)((char*)s0 + 104);
    v0 = 0 + -1;
    if (v1 != 0) v0 = 0;
    goto ret;
ret:
    return v0;
}
