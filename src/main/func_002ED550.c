#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma tailcall off


extern void NetMsg_RegisterTypeInner(void* msg, int kind, void* arg);

/* Registers a message type with kind 2. */
void func_002ED550(void* msg, void* arg) {
    NetMsg_RegisterTypeInner(msg, 2, arg);
}


#pragma pop
