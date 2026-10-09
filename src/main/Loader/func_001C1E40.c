/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern char D_0048B2F8[];   /* game data root directory name */
extern int D_004FFC30;
extern int func_00236FF0(char* root, int a1);
extern int func_00260A50(int a0);

/* Call func_00236FF0 with the game data root and a2, then func_00260A50 on D_004FFC30. */
int func_001C1E40(int a0, int a1, int a2) {
    func_00236FF0(D_0048B2F8, a2);
    return func_00260A50(D_004FFC30);
}
