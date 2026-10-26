#define D_00485E80 D_00485E88
#include "types.h"
#include "call_global_hook.h"

extern void std_duhandler(void);
void (*D_00485E88)(void) = std_duhandler;

/* Call the installed hook. */
#pragma tailcall off
DEFINE_CALL_GLOBAL_HOOK(std_unexpected)
#pragma tailcall reset
