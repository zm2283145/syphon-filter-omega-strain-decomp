/*
 * main/human: 4 files, 001C00C0-001C0180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C00C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_001C00C0(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C00C0 */

/* merge_units: begin func_001C00D0 */
#pragma push /* merge_units */
typedef struct { int w[3]; } String;
extern void func_0013BCB0(String* dst, String* src);
extern void func_001C4300(String* s, int arg);
extern void String_Dtor(String* s, int flags);
/* Copies src, transforms the copy with arg, and assigns it to dst. */
int func_001C00D0(String* dst, String* src, int arg)
{
    String tmp;
    func_0013BCB0(&tmp, src);
    func_001C4300(&tmp, arg);
    func_0013BCB0(dst, &tmp);
    String_Dtor(&tmp, 0);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C00D0 */

/* merge_units: begin func_001C0130 */
#pragma push /* merge_units */
extern char D_0049EE30[]; /* format string */
extern char D_0048B2F8[];
extern int sprintf(char* buf, const char* fmt, ...); /* sprintf */
extern void ArchiveList_CloseNamed(void* target, const char* text);

/* Formats D_0048B2F8 into a local buffer and passes it to ArchiveList_CloseNamed. */
void SkaLevel_CloseArchive(void* self, void* target)
{
    char buf[0x80];
    sprintf(buf, D_0049EE30, D_0048B2F8);
    ArchiveList_CloseNamed(target, buf);
}
#pragma pop /* merge_units */
/* merge_units: end func_001C0130 */

/* merge_units: begin func_001C0180 */
#pragma push /* merge_units */
extern void Archive_Open(void* target, char* text, int a, int b);

/* Formats D_0048B2F8 with the D_0049EE30 format and passes the text to Archive_Open. */
void SkaLevel_OpenArchive(void* self, void* target)
{
    char buf[0x80];
    sprintf(buf, D_0049EE30, D_0048B2F8);
    Archive_Open(target, buf, 1, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_001C0180 */
