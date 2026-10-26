/*
 * main/GuiEquipmentModify: 5 files, 002C4530-002C4EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C4530 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004AC6F0[] = "basic_string: out_of_range"; }
extern "C" { char D_004AC710[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_002C4530, D_004AC6F0, D_004AC710, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048C0B0, D_0048C0B8, Libc_Memmove, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_002C4530 */

/* merge_units: begin func_002C4A20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004AC730[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(String_Reserve_2C4A20, D_004AC730, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_002C4A20 */

/* merge_units: begin func_002C4D60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_002C4D60)
#pragma pop /* merge_units */
/* merge_units: end func_002C4D60 */

/* merge_units: begin func_002C4E50 */
#pragma push /* merge_units */
typedef struct SsoString {
    union {
        unsigned int word;          /* 0x00, bit 0 = long mode */
        struct {
            unsigned char isLong : 1;
            unsigned char shortLen : 7;
        } bits;
    } mode;
    int longLen;                /* 0x04 */
    char* longData;             /* 0x08 */
} SsoString;

extern void String_Replace(SsoString* str, int pos, int count, const char* first, const char* last, signed char tag);

/* Assigns the range [first, last) to the string, replacing its whole contents. */
void func_002C4E50(SsoString* str, const char* first, const char* last) {
    volatile signed char tag[4]; /* empty tag argument, never initialized */
    int len;
    if (str->mode.word & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->mode.bits.shortLen;
    }
    String_Replace(str, 0, len, first, last, tag[0]);
}
#pragma pop /* merge_units */
/* merge_units: end func_002C4E50 */

/* merge_units: begin func_002C4EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V2C4EA0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual unsigned char v32(); };
struct T2C4EA0 { V2C4EA0 v; char pad[0x44]; int x48; char pad4C[0x1E4 - 0x4C]; int x1E4; };
struct S2C4EA0 { char pad[0x58]; T2C4EA0* p58; };
extern "C" void cAimWeapon_Creation(int val, S2C4EA0* s)
{
    if (s->p58) {
        unsigned char t = s->p58->v.v32();
        switch (t) {
        case 2:
            s->p58->x1E4 = val;
            break;
        case 4:
            s->p58->x48 = val;
            break;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002C4EA0 */
