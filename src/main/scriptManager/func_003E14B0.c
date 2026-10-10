#include "types.h"

extern void* func_003E1520(void* p);
extern int cScriptInterpreter_CheckAllReferences(void* p);

/* Script native: checks all references of the interpreter's script. */
unsigned char Script_cScriptInterp_CheckAllReferences(void** self)
{
    return cScriptInterpreter_CheckAllReferences(func_003E1520(*self));
}
