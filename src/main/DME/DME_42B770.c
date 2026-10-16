#pragma cplusplus on

#include "network_admission.h"

/* Test admission flags and the current player count without reserving a slot. */
extern "C" unsigned char func_0042B770(void)
{
    return room_available();
}
