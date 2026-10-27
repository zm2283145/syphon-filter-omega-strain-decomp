#pragma cplusplus on
#include "types.h"
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

