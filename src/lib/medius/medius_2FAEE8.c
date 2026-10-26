/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int rt_list_buf_get_data_size(int a0) {
    int v0;
    int cond;

    cond = a0 == 0;
    v0 = 0;
    if (cond) goto L002FAEF4;
    v0 = *(int*)(char*)a0;
L002FAEF4:;
    goto ret;
ret:
    return v0;
}

int rt_list_buf_get_next(int a0) {
    int v0;
    int cond;

    cond = a0 == 0;
    v0 = 0;
    if (cond) goto L002FAF0C;
    v0 = *(int*)((char*)a0 + 4);
L002FAF0C:;
    goto ret;
ret:
    return v0;
}

int rt_list_buf_is_valid(int a0) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0;
    if (cond) goto L002FAF40;
    v1 = *(int*)((char*)a0 + 16);
    cond = v1 == 0;
    if (cond) goto L002FAF40;
    v1 = *(int*)((char*)a0 + 20);
    cond = v1 == 0;
    if (cond) goto L002FAF40;
    v0 = *(int*)((char*)a0 + 8);
    v0 = (unsigned int)0 < (unsigned int)v0;
L002FAF40:;
    goto ret;
ret:
    return v0;
}
