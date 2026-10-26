#include "types.h"
#include "call_global_hook.h"

extern void std_dthandler(void);
void (*D_00485E80)(void) = std_dthandler;

/* Call the installed hook. */
#pragma tailcall off
DEFINE_CALL_GLOBAL_HOOK(std_terminate)
#pragma tailcall reset
