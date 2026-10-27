/*
 * Libs/SFOLib/Source/scriptManager: 5 files, 003E2510-003E2650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E2510 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_cGroupPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_003E2510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E2510 */

/* merge_units: begin func_003E2520 */
#pragma push /* merge_units */
typedef struct { int n; int a[5000]; } FA_003E2520;
extern int D_004938E0;
static inline void fill_003E2520(FA_003E2520 *s, int n, int *v) {
    int i;
    for (i = s->n; i <= (int)(n - 1); i++) *(int *)((char *)s->a + (i << 2)) = *v;
    s->n = n;
}
void cArray_FixedCapacity_int_5000_ResizeActual(FA_003E2520 *s, unsigned int n, int *v) {
    if (n < 5001U) {
        fill_003E2520(s, n, v);
        return;
    }
    fill_003E2520(s, 5000, &D_004938E0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E2520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E2520 */

/* merge_units: begin func_003E25C0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } T25C0;
extern void std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_2(T25C0* t, void* n);
extern void operator_delete(void* p);
T25C0* cAssocArray_int_cArray_FuncDefPtrPtr_dtor(T25C0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_2(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E25C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E25C0 */

/* merge_units: begin func_003E2630 */
#pragma push /* merge_units */
void func_003E2630(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_003E2640(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
static inline void merge_flush_func_003E2630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E2630 */

/* merge_units: begin func_003E2650 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma push
#pragma inline_depth(12)
#pragma bool off
#pragma opt_strength_reduction off
extern "C" {
extern unsigned char D_004938D0;
extern unsigned char D_00559F18;
extern char D_004BDC18[];
extern char D_004BDC28[];
void cMemMan_Deallocate(int,void*,char*,int);
void cFileIO_dtor(void*,int);
void cFileMan_Close(void*);
void cFileMan_dtor(void*,int);
void cFileMan_ctor_void(void*);
void cScriptBase_sm_printf(char*,...);
void cScriptBase_SetGameSymsAdded();
void ScriptFileBuff_open(void*,char*,int);
void cScriptInterpreter_exportData(void*,void*);
}
struct TypeRec { char pad[0x34]; void (*init)(int); };
struct Registry { int n; int count; TypeRec** data; };
extern "C" Registry* D_00554F28;
struct Self { char pad[0x4E88]; int contextA,contextB; };
struct Stream {
 void* file; int size; char hog[0x9C]; void* owned; int a8,ac,b0,b4; unsigned char ready; char pad[3];
 Stream() { cFileMan_ctor_void(hog); file=0;size=0; }
 __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Stream() {
  cFileMan_Close(hog);
  { void* p=file; if(p) { { AllocGuard g; cFileIO_dtor(p,-1); cMemMan_Deallocate(0,p,D_004BDC28,0x45); } file=0; } }
  size=0;
  { void* p=owned; if(p) { AllocGuard g; cMemMan_Deallocate(0,p,D_004BDC18,0x4B); } }
  a8=0;owned=0;ac=0;ready=0;
  cFileMan_dtor(hog,-1);
 }
};
extern "C" int cScriptInterpreter_Init(Self* self,int one,int two) {
 self->contextA=two; self->contextB=one;
 cScriptBase_SetGameSymsAdded();
 int count=D_00554F28->count;
 for(int i=0;i<count;i++) D_00554F28->data[i]->init(0);
 if(D_004938D0 || D_00559F18) {
  if(D_00559F18) {
   char* name="release.sss"; Stream s;
   ScriptFileBuff_open(&s,name,1);
   if(s.ready) { cScriptInterpreter_exportData(self,&s);cScriptBase_sm_printf("symbols exported to %s",name); }
   else cScriptBase_sm_printf("couldn't export script symbols");
  }
 }
 return !D_00559F18;
}
#pragma pop
static inline void merge_flush_func_003E2650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E2650 */
