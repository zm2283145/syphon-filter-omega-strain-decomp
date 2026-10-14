/*
 * main/guiWidget: 8 files, 0041F7A0-0041FAF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041F7A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_0041F7A0)
#pragma pop /* merge_units */
/* merge_units: end func_0041F7A0 */

/* merge_units: begin func_0041F820 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "obj_list_dtor_shallow.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_SHALLOW(func_0041F820)
#pragma pop /* merge_units */
/* merge_units: end func_0041F820 */

/* merge_units: begin func_0041F890 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int key; char name[4]; } Data_41F890;
typedef struct Node_41F890 { int pad0; struct Node_41F890* next; Data_41F890* data; } Node_41F890;
typedef struct { Node_41F890* p; } It_41F890;
typedef struct { int w[1]; } Raw_41F890;
extern "C" {
void func_0013B180(Raw_41F890* out, void* list);
void func_0028C0B0(It_41F890* out, Raw_41F890* raw);
void func_0028C0A0(Raw_41F890* out, void* list);
void func_0028C090(It_41F890* out, Raw_41F890* raw);
int String_AssignCStr_1C43A0(void* s, const char* key);
}
extern "C" Data_41F890* func_0041F890(void* o, const char* key)
{
    It_41F890 last;
    It_41F890 first;
    Raw_41F890 rawFirst;
    Raw_41F890 rawEnd;
    Node_41F890* n;
    func_0013B180(&rawFirst, o);
    func_0028C0B0(&first, &rawFirst);
    for (n = first.p; (func_0028C0A0(&rawEnd, o), func_0028C090(&last, &rawEnd), n != last.p); n = n->next) {
        if (!String_AssignCStr_1C43A0(n->data->name, key))
            return n->data;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041F890 */

/* merge_units: begin func_0041F960 */
#pragma push /* merge_units */
#pragma cplusplus on
struct N41F960 { int id; N41F960 *next; virtual int v0(); };
extern "C" {
int String_CompareNoCase(int, int);
extern N41F960 *D_00572118;
}
extern "C" int func_0041F960(int arg0) {
    N41F960 *n;
    for (n = D_00572118; n != 0; n = n->next) {
        if (String_CompareNoCase(arg0, n->id) == 0) {
            return n->v0();
        }
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041F960 */

/* merge_units: begin func_0041F9E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

#if 0 /* merge_units */
extern L4FreeNode* D_00572118;    /* free-list head */
#endif /* merge_units */
#define D_00572118 (*(L4FreeNode **)&D_00572118) /* merge_units */


/* Pushes node onto the free list. */
void FreeList_Push(L4FreeNode* node) {
    node->next = D_00572118;
    D_00572118 = node;
}
#undef D_00572118 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041F9E0 */

/* merge_units: begin func_0041FA00 */
#pragma push /* merge_units */
typedef struct { int words[3]; } SsoString;
typedef struct { char unused; } Allocator; /* empty allocator object passed by value */
extern int strlen(const char* s); /* strlen */
extern void String_Reserve(SsoString* s, int capacity);
extern void* String_Replace(SsoString* s, int pos, int count, const char* first, const char* last, Allocator alloc);

/* String constructor from a C string. */
SsoString* func_0041FA00(SsoString* self, const char* text)
{
    Allocator alloc;
    int len;
    self->words[0] = 0;
    self->words[1] = 0;
    self->words[2] = 0;
    len = strlen(text);
    String_Reserve(self, len);
    String_Replace(self, 0, 0, text, text + len, alloc);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041FA00 */

/* merge_units: begin func_0041FA80 */
#pragma push /* merge_units */
/* Short-string-optimized string: bit 0 of the first byte marks heap storage. */
typedef struct SsoString_0041FA80 {
    union {
        struct { unsigned char isLong : 1; unsigned char shortLen : 7; } s;
        int flags;
    } h;
    int longLen;
    char* longData;
} SsoString_0041FA80;
extern int String_Compare(SsoString_0041FA80* a, int pos, int len, const char* data, int n);

/* Compares the string with a C string (compare(0, size(), text, strlen(text))). */
int String_CompareCStr(SsoString_0041FA80* self, const char* text)
{
    int n = strlen(text);
    int len;
    if (!(self->h.flags & 1))
        len = (unsigned char)self->h.s.shortLen;
    else
        len = self->longLen;
    return String_Compare(self, 0, len, text, n);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041FA80 */

/* merge_units: begin func_0041FAF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BF3E0[] = "basic_string: out_of_range"; }
extern "C" { char D_004BF400[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_0041FAF0, D_004BF3E0, D_004BF400, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00494120, D_00494128, func_00125FE8, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_0041FAF0 */
