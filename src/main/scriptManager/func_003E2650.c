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
void func_00369700(void*,int);
void func_0036DEC0(void*);
void func_0036E220(void*,int);
void func_0036E5D0(void*);
void func_003D7930(char*,...);
void func_003D7E30();
void func_003DC080(void*,char*,int);
void func_003DDC30(void*,void*);
}
struct TypeRec { char pad[0x34]; void (*init)(int); };
struct Registry { int n; int count; TypeRec** data; };
extern "C" Registry* D_00554F28;
struct Self { char pad[0x4E88]; int contextA,contextB; };
struct Stream {
 void* file; int size; char hog[0x9C]; void* owned; int a8,ac,b0,b4; unsigned char ready; char pad[3];
 Stream() { func_0036E5D0(hog); file=0;size=0; }
 __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Stream() {
  func_0036DEC0(hog);
  { void* p=file; if(p) { { AllocGuard g; func_00369700(p,-1); Mem_Free(0,p,D_004BDC28,0x45); } file=0; } }
  size=0;
  { void* p=owned; if(p) { AllocGuard g; Mem_Free(0,p,D_004BDC18,0x4B); } }
  a8=0;owned=0;ac=0;ready=0;
  func_0036E220(hog,-1);
 }
};
extern "C" int ScriptMgr_ExportSymbols(Self* self,int one,int two) {
 self->contextA=two; self->contextB=one;
 func_003D7E30();
 int count=D_00554F28->count;
 for(int i=0;i<count;i++) D_00554F28->data[i]->init(0);
 if(D_004938D0 || D_00559F18) {
  if(D_00559F18) {
   char* name="release.sss"; Stream s;
   func_003DC080(&s,name,1);
   if(s.ready) { func_003DDC30(self,&s);func_003D7930("symbols exported to %s",name); }
   else func_003D7930("couldn't export script symbols");
  }
 }
 return !D_00559F18;
}
#pragma pop

