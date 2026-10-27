/*
 * Libs/SFOLib/Source/scriptManager: 3 files, 003DF350-003DF400
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003DF350 */
#pragma push /* merge_units */
#include "types.h"
#include "scriptManager_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);
extern OwnedVec* std_vector_imp_cObjectId_ctor(OwnedVec* v);

int* std_vector_StringPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

int* cArray_charPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

int* cArray_intPtr_opIndex_int_2(PtrVec* v, int i) {
    return v->data + i;
}

/* push_back: inserts one value at the end. */
int std_vector_cGroupPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

OwnedVec* cArray_cObjectId_ctor(OwnedVec* v) {
    std_vector_imp_cObjectId_ctor(v);
    v->unk0C = 1;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DF350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DF350 */

/* merge_units: begin func_003DF3D0 */
#pragma push /* merge_units */
/* Clears the three PtrVec words. */
OwnedVec* std_vector_imp_cObjectId_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int* cArray_FuncDefPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DF3D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DF3D0 */

/* merge_units: begin func_003DF400 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma push
#pragma inline_depth(12)
#pragma opt_strength_reduction off
#pragma opt_propagation off
struct SchedObject { virtual void v0(); virtual void* clone(); };
struct Type { char* name; char pad4[0x41]; unsigned char cloneable; char pad46[6]; unsigned char objectId; };
struct Param { int kind; };
struct Desc { char pad[0x10]; Param** params; };
struct Self { char pad[0x4EA0]; int owner; };
struct Event { char pad[0x1C]; int id; };
struct Pair { int key; Event* value; };
extern "C" {
extern char D_004BD4C0[];
extern char D_0055A0F0[];
extern int D_0055A100;
void* cMemMan_Allocate(int,int,char*,int);
int strlen(char*);
void Libc_Strcpy(char*,char*);
void cScriptInterpreter_error(Self*,char*,...);
Type* cScriptBase_getClass(int);
int cScriptInterpreter_UseIdInsteadOfPointer(Self*,Desc*,Type*);
void* cScriptInterpreter_PackPtr(void*);
int String_CompareNoCase(char*,char*);
Event* SchedCallback_ctor(Event*,int,Desc*,void**,int,int);
void nCallback_SetCallback(Event*);
void std_tree_pair_int_value_compare_insert_one_pairR(void*,void*,Pair*);
}
static inline void* Alloc(int size,int line) { AllocGuard g;return cMemMan_Allocate(0,size,D_004BD4C0,line); }
extern "C" int cScriptInterpreter_Schedule(Self* self0,Desc* desc0,void** args,int count,float delay) {
 void** ptr;
 Self* self=self0; Desc* desc=desc0;
 int ret[2];
 Pair pair;
 int i=0;
 if(0<count) { ptr=args; do {
  int k=desc->params[i]->kind;
  if(k==3) {
   char* str=(char*)*ptr;
   if(!str) {cScriptInterpreter_error(self,"string param(#%d) null in schedule call",i);return -1;}
   int len=strlen(str);
   char* copy=(char*)Alloc(len+1,0x76D);
   Libc_Strcpy(copy,str);*ptr=copy;
  } else if(k>=100) {
   Type* type=cScriptBase_getClass(k);
   if(type) {
    if(type->objectId) { if(!cScriptInterpreter_UseIdInsteadOfPointer(self,desc,type)) *ptr=cScriptInterpreter_PackPtr(*ptr); }
    else if(type->cloneable) *ptr=((SchedObject*)*ptr)->clone();
    else if(String_CompareNoCase(type->name,"group")) {cScriptInterpreter_error(self,"can't schedule a function with that param type");return -1;}
   }
  }
 i++;ptr++;
 } while(i<count); }
 Event* ev=(Event*)Alloc(0x20,0x791);
 if(ev) ev=SchedCallback_ctor(ev,(int)(1000.0f*delay),desc,args,count,self->owner);
 nCallback_SetCallback(ev);
 pair.key=D_0055A100;pair.value=ev;
 std_tree_pair_int_value_compare_insert_one_pairR(ret,D_0055A0F0,&pair);
 ev->id=D_0055A100;
 return D_0055A100++;
}
#pragma pop
static inline void merge_flush_func_003DF400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DF400 */
