/*
 * main/skeleton: range (2 files, 003AA270-003AA290)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003AA270 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Stores value into *dst; volatile mirrors the original stack temporary. */
int* func_003AA270(int* dst, int value) {
    volatile int tmp = value;

    *dst = tmp;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AA270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AA270 */

/* merge_units: begin func_003AA290 */
#pragma push /* merge_units */
/* Temporary file/stream object used while loading. */
typedef struct LoadStream {
    char data[0xA0];
} LoadStream;

extern void Resource_Construct(LoadStream* s);
extern void Hog_Register(LoadStream* s, int name, int flags, int mode);
extern void Skel_ReadFile(int skel, int arg, int name, LoadStream* s);
extern void FileMan_Release(LoadStream* s, int flags);

/* Loads a skeleton through a temporary stream opened on `name`; returns 0. */
int Skel_Load(int skel, int arg, int name, int flags) {
    LoadStream stream;
    Resource_Construct(&stream);
    Hog_Register(&stream, name, flags, 0);
    Skel_ReadFile(skel, arg, name, &stream);
    FileMan_Release(&stream, -1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AA290(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AA290 */
