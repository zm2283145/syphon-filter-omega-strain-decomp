#pragma cplusplus on
#include "types.h"
struct C5Sub {
    int a;
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void Method30(); /* +0x30 */
};
struct C5Light { char pad[0x60]; C5Sub* sub; };
extern "C" void cGOBJ_Deactivate(C5Light* p);
extern "C" void cGameDirectionalLight_Deactivate(C5Light* p) {
    cGOBJ_Deactivate(p);
    p->sub->Method30();
}