/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of Sky: only the slots used here are named (vtable offset in comments). */
struct Sky {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Show(int hide); /* +0x60 */
};

typedef struct cEnvSettings { char pad[0xA4]; Sky* sky; /* +0xA4 */ } cEnvSettings;

/* Script native: hides the environment's sky object (virtual +0x60 with 1), if any. Returns 0. */
extern "C" int Script_cEnvSettings_SkyOff(ScriptArg* args)
{
    Sky* sky = ((cEnvSettings*)args[0].p)->sky;
    if (sky)
        sky->Show(1);
    return 0;
}
