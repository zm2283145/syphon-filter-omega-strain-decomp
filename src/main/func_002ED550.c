#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma tailcall off


extern void NetIRegisterMessage(void* msg, int kind, void* arg);

/* Registers a message type with kind 2. */
void NetIRegisterApplicationMessage(void* msg, void* arg) {
    NetIRegisterMessage(msg, 2, arg);
}


#pragma pop
