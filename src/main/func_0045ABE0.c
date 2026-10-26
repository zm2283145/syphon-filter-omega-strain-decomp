#include "types.h"
extern void sceInsockGetsockname(void);
/* Wrapper around sceInsockGetsockname. */
#pragma tailcall off
void sceNetGlueGetsockname(void) { sceInsockGetsockname(); }
#pragma tailcall reset
