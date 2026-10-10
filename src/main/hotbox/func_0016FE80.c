#pragma cplusplus on
#include "types.h"
struct E2Who {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int IsPlayer(); /* +0x54 */
};
struct E2Owner { char pad[0x58]; E2Who* who; };
struct E2Msg { char pad[0x30]; E2Owner* owner; };
typedef union E2Arg { int i; void* p; } E2Arg;
extern "C" int cHotboxMsg_WhoPlayer(E2Who*);
extern "C" int Script_cHotboxMsg_WhoPlayer(E2Arg* args)
{
    E2Msg* msg = (E2Msg*)args[0].p;
    bool ok = false;
    bool isPlayer = false;
    if (msg->owner->who && msg->owner->who->IsPlayer()) isPlayer = true;
    if (isPlayer && msg->owner->who) ok = true;
    return cHotboxMsg_WhoPlayer(ok ? msg->owner->who : 0);
}