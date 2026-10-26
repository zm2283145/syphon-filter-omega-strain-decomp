#include "types.h"
#include "call_global_hook.h"

/* Call the installed hook. */
#pragma tailcall off
DEFINE_CALL_GLOBAL_HOOK(std_duhandler)
#pragma tailcall reset
