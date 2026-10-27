/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern char D_0048B2F8[];   /* game data root directory name */
extern int g_VisionFxMan;
extern int nSfxLoader_LoadEffects(char* root, int a1);
extern int cVisionFxMan_UpdateTxtrIds(int a0);

/* Call nSfxLoader_LoadEffects with the game data root and a2, then cVisionFxMan_UpdateTxtrIds on g_VisionFxMan. */
int cLoader_LoadEffects(int a0, int a1, int a2) {
    nSfxLoader_LoadEffects(D_0048B2F8, a2);
    return cVisionFxMan_UpdateTxtrIds(g_VisionFxMan);
}
