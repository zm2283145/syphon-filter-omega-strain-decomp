/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern int cLoader_LoadNILights(int a0, int a1);
extern int cLoader_LoadNIObjs(int a0, int a1, int a2);

/* Initialise NI event lights, then NI event objects. */
int cLoader_LoadNIEvents(int a0, int a1, int a2) {
    cLoader_LoadNILights(a0, a1);
    return cLoader_LoadNIObjs(a0, a1, a2);
}
