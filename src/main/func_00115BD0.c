#include "types.h"

extern int GetMemorySize(void);
extern void InitTLB32MB(void);
extern void _InitTLB(void);

/* Dispatches on GetMemorySize() == 0x2000000. */
void InitTLB(void) {
    if (GetMemorySize() == 0x2000000) {
        InitTLB32MB();
    } else {
        _InitTLB();
    }
}
