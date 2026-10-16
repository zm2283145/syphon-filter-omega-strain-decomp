/*
 * Matched functions (byte-identical with the retail executable).
 * manUtils.cc
 */

#include "types.h"

extern void Appearance_PackText(int dst, int text, int a2);
extern int FileMan_ReadData(int a0);

/* Convert a1 with FileMan_ReadData and pack the result with Appearance_PackText. */
void Skeleton_BuildInFrame(int dst, int a1, int a2) {
    Appearance_PackText(dst, FileMan_ReadData(a1), a2);
}
