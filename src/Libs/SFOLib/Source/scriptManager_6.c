/*
 * Libs/SFOLib/Source/scriptManager: 6 files, 003DC030-003DC540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003DC030 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

int* cArray_VarDefPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

/* push_back: inserts one value at the end. */
int std_vector_SubScriptPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

int* std_vector_SubScriptPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

int* std_vector_intPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_003DC030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DC030 */

/* merge_units: begin func_003DC080 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BDC18[];
extern char D_004BDC28[];
char D_004BDC38[] = "scriptFile.hh";
char D_004BDC48[] = "scriptFile.hh";
char D_004BDC58[] = "scriptFile.hh";
void* cMemMan_Allocate(int heap, int size, char* file, int line);
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
void cFileIO_dtor(void* p, int flag);
int* cFileIO_ctor_charP_int(void* p, char* name, int mode);
void cFileMan_Close(void* h);
int cFileMan_Open(void* h);
void cFileMan_EncodeFilename_charP_cFileIOP_bool(void* h, char* name, int* f, int a);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(void* h, char* name, int size, int a);
char* strrchr(const char* s, int c);
}
struct S_003DC080 { int* file; int size; char hog[0xA4 - 8]; void* pA4; int a8; int ac; int b0; int b4; unsigned char b8; };
static inline void* New_003DC080(int size, char* f, int line) { AllocGuard g; return cMemMan_Allocate(0, size, f, line); }
static inline void DelF_003DC080(int* p, char* f, int line) { if (p) { AllocGuard g; cFileIO_dtor(p, -1); cMemMan_Deallocate(0, p, f, line); } }
static inline void DelG_003DC080(int* p, char* f, int line) { AllocGuard g; cFileIO_dtor(p, -1); cMemMan_Deallocate(0, p, f, line); }
static inline void Del_003DC080(void* p, char* f, int line) { if (p) { AllocGuard g; cMemMan_Deallocate(0, p, f, line); } }
extern "C" void ScriptFileBuff_open(S_003DC080* s, char* name, int mode)
{
    int* f;
    s->pA4 = 0;
    s->a8 = 0;
    s->ac = 0;
    s->b4 = 0;
    s->b0 = 0;
    if (s->file) {
        cFileMan_Close(s->hog);
        if (s->file) {
            DelG_003DC080(s->file, D_004BDC28, 0x45);
            s->file = 0;
        }
        s->size = 0;
        Del_003DC080(s->pA4, D_004BDC18, 0x4B);
        s->a8 = 0;
        s->pA4 = 0;
        s->ac = 0;
        s->b8 = 0;
    }
    if (mode == 0) {
        if (s->size == 0) {
            f = (int*)New_003DC080(0xC8, D_004BDC58, 0x6E);
            if (f) f = cFileIO_ctor_charP_int(f, name, 1);
            s->file = f;
            if (*s->file >= 0) {
                cFileMan_EncodeFilename_charP_cFileIOP_bool(s->hog, name, s->file, 0);
            } else {
                DelG_003DC080(s->file, D_004BDC48, 0x74);
                s->file = 0;
            }
        }
        if (!s->file && s->size) {
            char* p = strrchr(name, '\\');
            name = p ? p + 1 : name;
            cFileMan_EncodeFilename_charP_cHogFileR_bool(s->hog, name, s->size, 0);
            s->b8 = (unsigned char)cFileMan_Open(s->hog) == 0;
            return;
        }
    } else if (mode == 1) {
        f = (int*)New_003DC080(0xC8, D_004BDC38, 0x84);
        if (f) f = cFileIO_ctor_charP_int(f, name, 0x202);
        s->file = f;
    } else {
        s->file = 0;
    }
    s->b8 = s->file != 0;
}
static inline void merge_flush_func_003DC080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DC080 */

/* merge_units: begin func_003DC470 */
#pragma push /* merge_units */
int* cArray_EnumDefPtr_opIndex(PtrVec* v, int i); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern PtrVec* D_00554F30;  /* global enum table (ScriptEnum* entries, ids start at 10) */
#if 0 /* merge_units */
extern ScriptEnum** cArray_EnumDefPtr_opIndex(PtrVec* v, int i);
#endif /* merge_units */
#define cArray_EnumDefPtr_opIndex(a0, a1) ((ScriptEnum * *)cArray_EnumDefPtr_opIndex((a0), (a1))) /* merge_units */


extern int cScriptInterpreter_SymbolTable_remapEnum(Script* script, int localId);

/* First word of member 'index' of the script-local enum 'localId'. */
int cScriptInterpreter_SymbolTable_remapEnumVal(Script* script, int localId, int index) {
    int id = cScriptInterpreter_SymbolTable_remapEnum(script, localId);
    ScriptEnum* e = *cArray_EnumDefPtr_opIndex(D_00554F30, id - 10);
    return e->members[index].unk0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DC470(void) {}
#undef cArray_EnumDefPtr_opIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DC470 */

/* merge_units: begin func_003DC4C0 */
#pragma push /* merge_units */
int* cArray_EnumDefPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

/* Maps a script-local enum id (>= 10) to the global enum id. */
int cScriptInterpreter_SymbolTable_remapEnum(Script* script, int localId) {
    int i = localId - 10;

    return script->enumMap[i];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DC4C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DC4C0 */

/* merge_units: begin func_003DC4F0 */
#pragma push /* merge_units */
typedef struct { int x0[0x38/4]; int* x38; int x3C[3]; int* x48; } ScrDC4F0;
int cScriptInterpreter_SymbolTable_remapType(ScrDC4F0* s, int t) {
    if (t >= 100) { t -= 100; t = s->x38[t]; }
    else if (t >= 10) { t -= 10; t = s->x48[t]; }
    return t;
}
static inline void merge_flush_func_003DC4F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DC4F0 */

/* merge_units: begin func_003DC540 */
#pragma push /* merge_units */
extern ScriptManager D_00555070;
extern ScriptEnumEntry* cScriptInterpreter_considerEnum(ScriptManager* manager, int a1, int a3, int t0);

/* Resolves an enum through the script manager and stores its global id in script->enumMap[slot]. */
ScriptEnumEntry* cScriptInterpreter_SymbolTable_addEnum(Script* script, int a1, int slot, int a3, int t0) {
    ScriptEnumEntry* entry = cScriptInterpreter_considerEnum(&D_00555070, a1, a3, t0);
    script->enumMap[slot] = entry->id;
    return entry;
}
static inline void merge_flush_func_003DC540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DC540 */
