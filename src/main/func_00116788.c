#include "types.h"

extern void InitTLB(void);

void TerminateLibrary(void) {
    InitTLB();
}
