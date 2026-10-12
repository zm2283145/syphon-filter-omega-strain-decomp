#include "types.h"
#include "call_global_hook.h"

extern void func_00100B10(void);
void (*D_00485E80)(void) = func_00100B10;

/* Call the installed hook. */
#pragma tailcall off
DEFINE_CALL_GLOBAL_HOOK(func_00100AB0)
#pragma tailcall reset
