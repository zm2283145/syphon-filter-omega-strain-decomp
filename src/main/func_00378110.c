/*
 * Matched functions (byte-identical with the retail executable).
 * Script natives forwarding a texture id to the global texture manager.
 */

#include "loose03_types.h"

extern int D_0053924C;          /* texture manager instance */
extern void Global_DecTexture(int mgr, int id);
extern void Global_IncTexture(int mgr, int id);

int Script_DecTexture(int* args) {
    int part[1];

    part[0] = args[0];
    Global_DecTexture(D_0053924C, *(int*)part);
    return 0;
}

int Script_IncTexture(int* args) {
    int part[1];

    part[0] = args[0];
    Global_IncTexture(D_0053924C, *(int*)part);
    return 0;
}
