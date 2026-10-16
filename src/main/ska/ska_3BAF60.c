/*
 * Matched functions (byte-identical with the retail executable).
 * Look up a texture by the index stored in a handle and return a size field
 * of its info header. Original translation unit not identified yet.
 */

#include "loose03_types.h"

extern TexRegistry* D_00539248;

int func_003BAF60(int* handle) {
    return D_00539248->entries[*handle]->info->unk06;
}

int func_003BAF90(int* handle) {
    return D_00539248->entries[*handle]->info->unk04;
}
