#define D_00485E80 D_00485E88
#include "types.h"
#include "call_global_hook.h"

/* Call the installed hook. */
#pragma tailcall off
DEFINE_CALL_GLOBAL_HOOK(func_00100A80)
#pragma tailcall reset
