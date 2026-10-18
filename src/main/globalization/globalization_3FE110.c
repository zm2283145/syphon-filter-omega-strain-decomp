/*
 * main/globalization: range (2 files, 003FE110-003FE1F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int Mem_Free();
void *memcpy();
int strlen(const char *);

/* merge_units: begin func_003FE110 */
#pragma push /* merge_units */
extern unsigned char D_0055D470;
extern int func_00326130(int);
void Language_FromSystem(int arg) {
    int r = func_00326130(arg);
    if (r >= 0 && r < 7) {
        switch (r) {
        case 1:
            if (arg) D_0055D470 = 1;
            else D_0055D470 = 0;
            break;
        case 2: D_0055D470 = 2; break;
        case 5: D_0055D470 = 3; break;
        case 4: D_0055D470 = 4; break;
        case 3: D_0055D470 = 5; break;
        case 0: D_0055D470 = 6; break;
        }
    } else {
        D_0055D470 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FE110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FE110 */

/* merge_units: begin func_003FE1F0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
void FileHal_Dtor(void*,int);
void func_0036DEC0(void*);
void FileMan_Release(void*,int);
void Resource_Construct(void*);
void FileMan_Open(void*,char*,int);
void* FileMan_ReadData(void*);
int FileMan_GetSize(void*);
void func_003FEED0(void*);
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
char String_ToLower(char);
void func_003FE800(void*, void*, int, char*);
void func_003FE640(void*);
void PtrVec_PushBack_330280(void*, char**);
}
struct Stream {
 void* file; int size; char hog[0x9C]; void* owned; char* a8; char* ac; int b0; int b4; unsigned char ready; char pad[3];
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
   PtrVec_PushBack_330280(D_0055CA70, &str);
  }
  ok = true;
 }
 return ok;
}
#pragma pop
#undef strlen /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FE1F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FE1F0 */
