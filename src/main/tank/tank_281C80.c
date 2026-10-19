/*
 * main/tank: 4 files, 00281C80-00282160
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00281C80 */
#pragma push /* merge_units */
#include "types.h"
extern char* D_005061D0;
extern int strlen(const char* s);
static inline void W16_00281C80(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
void func_00281C80(char* str) {
    int n = strlen(str) + 1;
    int i;
    W16_00281C80(n);
    for (i = 0; i < n; i++) *D_005061D0++ = str[i];
}
#pragma pop /* merge_units */
/* merge_units: end func_00281C80 */

/* merge_units: begin func_00281E90 */
#pragma push /* merge_units */
static inline short R16_00281E90(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline char R8_00281E90(void) { return *D_005061D0++; }
void func_00281E90(char* str) {
    int n = R16_00281E90();
    int i;
    for (i = 0; i < n; i++) str[i] = R8_00281E90();
}
#pragma pop /* merge_units */
/* merge_units: end func_00281E90 */

/* merge_units: begin func_00282020 */
#pragma push /* merge_units */
static inline void W16_00282020(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00282020(int v) { W16_00282020((unsigned short)v); W16_00282020(v >> 16); }
typedef struct { char pad[0xC]; int id; } O_00282020;
void func_00282020(O_00282020* o) {
    if (o) {
        W32_00282020(o->id);
    } else {
        W32_00282020(-1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00282020 */

/* merge_units: begin func_00282160 */
#pragma push /* merge_units */
extern void Script_ReadU32(int* handle);
extern int Object_LookupById(int* handle);
/* Look up a handle and store the result in *out. */
void NetStream_ReadObject(int* out)
{
    int handle = -1;
    Script_ReadU32(&handle);
    *out = Object_LookupById(&handle);
}
#pragma pop /* merge_units */
/* merge_units: end func_00282160 */
