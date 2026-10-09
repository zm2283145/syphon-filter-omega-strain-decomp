/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern int Loader_InitNIEventLights(int a0, int a1);
extern int Loader_InitNIEventObjects(int a0, int a1, int a2);

/* Initialise NI event lights, then NI event objects. */
int Loader_InitNIEvents(int a0, int a1, int a2) {
    Loader_InitNIEventLights(a0, a1);
    return Loader_InitNIEventObjects(a0, a1, a2);
}
