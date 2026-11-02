/*
 * Libs/SFOLib/Source/scriptManager: 4 files, 003E1090-003E11C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E1090 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_FuncDefPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_FuncDefPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_FuncDefPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003E1090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E1090 */

/* merge_units: begin func_003E10D0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_strength_reduction off
typedef struct { int id; } VInfo3E10D0;
typedef struct { char* name; VInfo3E10D0* info; } Var3E10D0;
typedef struct { int x0; int count; Var3E10D0** items; } Tbl3E10D0;

extern Tbl3E10D0* D_00554F18;
extern char D_004BD858[];
extern int sprintf(char*, const char*, ...);
extern int String_CompareNoCase(char*, char*);

Var3E10D0* cScriptInterpreter_findVar(void* self, char* name, int id)
{
    char buf[128];
    int i;
    Var3E10D0* v;
    int n;
    n = D_00554F18->count;
    sprintf(buf, D_004BD858, name);
    for (i = 0; i < n; i++) {
        v = D_00554F18->items[i];
        if (id < 0 || id == v->info->id) {
            if (!String_CompareNoCase(v->name, name) || !String_CompareNoCase(v->name, buf)) {
                return v;
            }
        }
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_003E10D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E10D0 */

/* merge_units: begin func_003E11C0 */
#pragma push /* merge_units */
struct Script { char pad[0x4E88]; int line; char* module; };
extern char D_00559FE0[];
char D_004BD868[] = "%s\\common\\%s";
char D_004BD878[] = "%s\\%s\\%s";
char D_004BD888[] __attribute__((aligned(8))) = "."; /* 8-aligned in the original data */


char*strrchr(char*,int);
#if 0 /* merge_units */
int sprintf(char*,char*,...);
#endif /* merge_units */

void Libc_Strcpy(char*,char*);void Libc_Strcat(char*,char*);
char*cScriptInterpreter_scriptFileName(struct Script*self,char*name,char*extension,int moduleOnly){
 char*last;
 last=strrchr(name,'\\');if(last)name=last+1;
 if(moduleOnly)sprintf(D_00559FE0,D_004BD868,self->module,name);
 else sprintf(D_00559FE0,D_004BD878,self->module,self->line,name);
 last=strrchr(D_00559FE0,'.');
 if(last)Libc_Strcpy(last+1,extension);
 else {Libc_Strcat(D_00559FE0,D_004BD888);Libc_Strcat(D_00559FE0,extension);}
 return D_00559FE0;
}
static inline void merge_flush_func_003E11C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E11C0 */

/* merge_units: begin func_003E12D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x80]; const char* path; } S12D0;
typedef struct N12D0 { int m0; struct N12D0* next; S12D0* data; } N12D0;
typedef struct { char pad[0xC]; int list; } T12D0;
extern void std_list_deleter_voidPtr_begin_void(int* out, void* list);
extern void std_list_SymbolTablePtr_generic_iterator_ctor(N12D0** out, int* in);
extern void std_list_SymbolTablePtr_end(int* out, void* list);
extern void cLListIterator_SymbolTablePtr_ctor(N12D0** out, int* in);
extern const char* stripPathAndExt(const char* p);
#if 0 /* merge_units */
extern void Libc_Strcpy(char* d, const char* s);
#endif /* merge_units */
#define Libc_Strcpy(a0, a1) (Libc_Strcpy((a0), (char *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern int String_CompareNoCase(const char* a, const char* b);
#endif /* merge_units */
#define String_CompareNoCase(a0, a1) (String_CompareNoCase((char *)(a0), (char *)(a1))) /* merge_units */

S12D0* cScriptInterpreter_findContext(T12D0* self, const char* path)
{
    N12D0* e;
    N12D0* it;
    int t1;
    int t2;
    char buf[256];
    S12D0* s;
    N12D0* n;
    Libc_Strcpy(buf, stripPathAndExt(path));
    std_list_deleter_voidPtr_begin_void(&t1, &self->list);
    std_list_SymbolTablePtr_generic_iterator_ctor(&it, &t1);
    for (n = it; std_list_SymbolTablePtr_end(&t2, &self->list), cLListIterator_SymbolTablePtr_ctor(&e, &t2), n != e; n = n->next) {
        s = n->data;
        if (!String_CompareNoCase(stripPathAndExt(s->path), buf))
            return s;
    }
    return 0;
}
#undef Libc_Strcpy /* merge_units */
#undef String_CompareNoCase /* merge_units */
static inline void merge_flush_func_003E12D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E12D0 */
