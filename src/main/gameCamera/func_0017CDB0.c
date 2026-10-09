/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Vector of 16-byte records: +4 count, +8 data. */
typedef struct VecRecordList {
    int unk0;
    int count;
    char* data;
} VecRecordList;

extern int VecRecordList_Insert(VecRecordList* list, char* pos, int n, int value);

/* Appends one record at the end of the list. */
int func_0017CDB0(VecRecordList* list, int value) {
    return VecRecordList_Insert(list, list->data + (list->count << 4), 1, value);
}
