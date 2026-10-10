#include "types.h"
typedef struct { float m[4]; } E2Quat;
typedef struct { char pad[0xA0]; unsigned char dirty; } E2Ident;
typedef struct { char pad[0x160]; int f160; } E2Root;
extern E2Ident* Root_IdentityAccessor(E2Root*);
extern void* func_001A7DE0(void*);
extern void func_001325F0(void*, void*);
extern int func_001A0280(E2Root*);
extern void func_00132840(E2Quat*);
extern void* func_001A73C0(E2Root*, E2Quat*);
extern void func_001A7D80(void*, void*);
extern void Root_PropagateChildren(E2Root*);
void Root_SetWorldOrientationReset(E2Root* r, void* q) {
    E2Quat tmp;
    func_001325F0(func_001A7DE0((char*)Root_IdentityAccessor(r) + 0x50), q);
    if (func_001A0280(r)) {
        func_00132840(&tmp);
        func_001A7D80(func_001A7DE0((char*)Root_IdentityAccessor(r) + 0x50), func_001A73C0(r, &tmp));
    }
    Root_IdentityAccessor(r)->dirty = 1;
    Root_PropagateChildren(r);
    r->f160 = 0;
}