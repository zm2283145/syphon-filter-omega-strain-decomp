#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma push
#pragma inline_depth(12)
extern "C" {
extern char D_004BDC18[];
extern char D_004BDC28[];
extern char D_004BDC68[];
extern char D_004BE440[];
extern char* D_0055D460;
extern char D_0055CA70[];
void* Mem_Alloc(int, int, char*, int);
void Mem_Free(int,void*,char*,int);
void FileHal_Dtor(void*,int);
void func_0036DEC0(void*);
void func_0036E220(void*,int);
void func_0036E5D0(void*);
void FileMan_Open(void*,char*,int);
void* FileMan_ReadData(void*);
int FileMan_GetSize(void*);
void func_003FEED0(void*);
void* memcpy(void*, const void*, unsigned int);
unsigned int strlen(const char*);
char String_ToLower(char);
void String_Copy(char*, const char*);
void func_003FE800(void*, void*, int, char*);
void func_003FE640(void*);
void func_00330280(void*, char**);
}
struct Stream {
 void* file; int size; char hog[0x9C]; void* owned; char* a8; char* ac; int b0; int b4; unsigned char ready; char pad[3];
 Stream() { func_0036E5D0(hog); file=0;size=0; }
 __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Stream() {
  func_0036DEC0(hog);
  { void* p=file; if(p) { { AllocGuard g; FileHal_Dtor(p,-1); Mem_Free(0,p,D_004BDC28,0x45); } file=0; } }
  size=0;
  { void* p=owned; if(p) { AllocGuard g; Mem_Free(0,p,D_004BDC18,0x4B); } }
  a8=0;owned=0;ac=0;ready=0;
  func_0036E220(hog,-1);
 }
};
struct LocEntry { char pad[0x10]; };
struct Loc { int f0; int count; LocEntry* entries; };
extern "C" bool Loc_ReadPoolFile(Loc* self, char* name) {
 char* str;
 Stream s;
 char key[0x10];
 FileMan_Open(&s, name, 0);
 bool ok = false;
 if (s.ready) {
  s.ac = (char*)FileMan_ReadData(s.hog);
  s.b4 = FileMan_GetSize(s.hog);
  s.a8 = s.ac;
  s.owned = 0;
  int* pc = (int*)s.a8; s.a8 += 4;
  int count = *pc;
  func_003FEED0(self);
  for (int i = 0; i < count; i++) {
   memcpy(key, s.a8, 0x10);
   s.a8 += 0x10;
   char* k = key;
   int len = strlen(k);
   for (int j = 0; j < len; j++) { *k = String_ToLower(*k); k++; }
   int* pn = (int*)s.a8; s.a8 += 4;
   char* tmp;
   int n = *pn;
   if (n) {
    AllocGuard g;
    tmp = (char*)Mem_Alloc(0, n, D_004BDC68, 0xF9);
   } else {
    tmp = 0;
   }
   if (tmp) {
    String_Copy(tmp, s.a8);
    s.a8 += ((unsigned int)(n + 3) >> 2) * sizeof(int);
   }
   String_Copy(D_0055D460, tmp);
   str = D_0055D460;
   D_0055D460 += strlen(tmp) + 1;
   {
    AllocGuard g;
    Mem_Free(0, tmp, D_004BE440, 0x83);
   }
   func_003FE800(self, &self->entries[self->count], 1, key);
   func_003FE640(D_0055CA70);
   func_00330280(D_0055CA70, &str);
  }
  ok = true;
 }
 return ok;
}
#pragma pop



