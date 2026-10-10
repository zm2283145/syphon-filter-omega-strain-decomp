/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct Component {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int IsPlayer(); /* +0x54 */
};

typedef struct cGOBJ { char pad[0x58]; Component* component; /* +0x58 */ } cGOBJ;

/* Script native: whether the object component (+0x58) reports itself as a player (virtual +0x54). */
extern "C" int Script_IsPlayer(ScriptArg* args)
{
    cGOBJ* obj = (cGOBJ*)args[0].p;
    Component* component = obj->component;
    unsigned char result = 0;
    if (component) {
        if (component->IsPlayer())
            result = 1;
    }
    return result;
}
