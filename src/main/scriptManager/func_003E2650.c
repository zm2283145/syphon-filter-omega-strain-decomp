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
void Mem_Free(int,void*,char*,int);
void FileHal_Dtor(void*,int);
void func_0036DEC0(void*);
void FileMan_Release(void*,int);
void Resource_Construct(void*);
void Script_PrintWarning(char*,...);
void Script_SaveSymbolMarks();
void FileMan_Open(void*,char*,int);
void func_003DDC30(void*,void*);
}
struct TypeRec { char pad[0x34]; void (*init)(int); };
struct Registry { int n; int count; TypeRec** data; };
extern "C" Registry* D_00554F28;
struct Self { char pad[0x4E88]; int contextA,contextB; };
struct Stream {
 void* file; int size; char hog[0x9C]; void* owned; int a8,ac,b0,b4; unsigned char ready; char pad[3];
 Stream() { Resource_Construct(hog); file=0;size=0; }
 __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Stream() {
  func_0036DEC0(hog);
  { void* p=file; if(p) { { AllocGuard g; FileHal_Dtor(p,-1); Mem_Free(0,p,D_004BDC28,0x45); } file=0; } }
  size=0;
  { void* p=owned; if(p) { AllocGuard g; Mem_Free(0,p,D_004BDC18,0x4B); } }
  a8=0;owned=0;ac=0;ready=0;
  FileMan_Release(hog,-1);
 }
};
extern "C" int ScriptMgr_ExportSymbols(Self* self,int one,int two) {
 self->contextA=two; self->contextB=one;
 Script_SaveSymbolMarks();
 int count=D_00554F28->count;
 for(int i=0;i<count;i++) D_00554F28->data[i]->init(0);
 if(D_004938D0 || D_00559F18) {
  if(D_00559F18) {
   char* name="release.sss"; Stream s;
   FileMan_Open(&s,name,1);
   if(s.ready) { func_003DDC30(self,&s);Script_PrintWarning("symbols exported to %s",name); }
   else Script_PrintWarning("couldn't export script symbols");
  }
 }
 return !D_00559F18;
}
#pragma pop

