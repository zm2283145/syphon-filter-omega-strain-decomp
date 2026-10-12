#define D_00485E80 D_00485E88
#include "types.h"
#include "call_global_hook.h"

extern void func_00100AE0(void);
void (*D_00485E88)(void) = func_00100AE0;

/* Call the installed hook. */
#pragma tailcall off
DEFINE_CALL_GLOBAL_HOOK(func_00100A80)
#pragma tailcall reset
