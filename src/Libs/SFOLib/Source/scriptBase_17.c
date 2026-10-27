/*
 * Libs/SFOLib/Source/scriptBase: 5 files, 003D91F0-003D9240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D91F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);
#if 0 /* merge_units */
extern OwnedVec* std_vector_imp_EnumField_ctor(OwnedVec* v);
#endif /* merge_units */
OwnedVec * std_vector_imp_EnumField_ctor(); /* merge_units */


/* push_back: inserts one value at the end. */
int std_vector_EnumDefPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

OwnedVec* cArray_EnumField_ctor(OwnedVec* v) {
    std_vector_imp_EnumField_ctor(v);
    v->unk0C = 1;
    return v;
}
static inline void merge_flush_func_003D91F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D91F0 */

/* merge_units: begin func_003D9240 */
#pragma push /* merge_units */
extern void std_vector_imp_EnumField_init(OwnedVec* v, int a1, int a2);

/* Clears the three PtrVec words, then calls std_vector_imp_EnumField_init with the remaining arguments. */
OwnedVec* std_vector_imp_EnumField_ctor(OwnedVec* v, int a1, int a2) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    std_vector_imp_EnumField_init(v, a1, a2);
    return v;
}
static inline void merge_flush_func_003D9240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9240 */

/* merge_units: begin func_003D9280 */
#pragma push /* merge_units */
extern char D_00499C71[];
extern char D_00554F60[];
extern char D_004BD3D8[];
extern char* strrchr(const char* s, int c);
extern char* strncpy(char* d, const char* s, unsigned int n);
extern char* Libc_Strcat(char* d, const char* s);
char* buildNameWithPrefix(char* path)
{
    char* name;
    char* p = strrchr(path, ':');
    if (p) {
        int len; char* s;
        name = p + 1;
        for (p = p - 2; p > path && *p != ':'; p--) {
        }
        if (p > path) s = p + 1; else s = path;
        if ((*s == 'c' || *s == 'n') && (D_00499C71[s[1]] & 1)) s++;
        len = name - s;
        strncpy(D_00554F60, s, len - 2);
        D_00554F60[len - 2] = 0;
        Libc_Strcat(D_00554F60, D_004BD3D8);
    } else {
        name = path;
        D_00554F60[0] = 0;
    }
    if (*name == 'e' && (D_00499C71[name[1]] & 1)) name++;
    Libc_Strcat(D_00554F60, name);
    return D_00554F60;
}
static inline void merge_flush_func_003D9280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9280 */

/* merge_units: begin func_003D9400 */
#pragma push /* merge_units */
typedef struct { char pad[8]; char** types; } TypeTable003D9400;
extern TypeTable003D9400* D_00554F28;
extern void std_vector_int_push_back(void* list, int* value);
/* Add an accepted interface to a script type. */
void cScriptBase_declareMsgUse(int type, int iface)
{
    int i = type - 100;
    std_vector_int_push_back(D_00554F28->types[i] + 0x24, &iface);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D9400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D9400 */

/* merge_units: begin func_003D9440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern PtrVec* D_00554F28;  /* global script type table (ScriptType* entries, ids start at 100) */
#endif /* merge_units */
#define D_00554F28 (*(PtrVec **)&D_00554F28) /* merge_units */




/* Sets field +0x40 of script type 'typeId'. */
void cScriptBase_declareParent(int typeId, int value) {
    int i = typeId - 100;
    ScriptType* type = (ScriptType*)D_00554F28->data[i];

    type->unk40 = value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D9440(void) {}
#undef D_00554F28 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9440 */
