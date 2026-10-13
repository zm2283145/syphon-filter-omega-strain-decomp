#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "fileman_entry.h"
extern "C" {
extern char D_004BE7F0[];
extern char D_004BE800[];
void* Mem_Alloc(int, int, char*, int);
void Mem_Free(int,void*,char*,int);
int func_0036DEF0(void*);
int FileMan_GetSize(void*);
void func_0036D990(void*, char**, int);
void func_0036DEC0(void*);
int func_00128C68(char*, char*, ...);
}
inline int AtEnd(char* a, char* b) { return a >= b; }
struct SortEnt { char name[16]; int a, b, c, d, e, f, g, h; };
struct App { char pad[0xEC]; int count; char pad2[0x11C10 - 0xF0]; SortEnt ents[1]; };
extern "C" void Appearance_LoadPartSortTable(App* self, char* path) {
 if (self->count != 0) return;
 FileManEntry fe;
 char* buf;
 func_0036E4B0(&fe, path, 0, 0);
 int count = 0;
 if ((unsigned char)func_0036DEF0(&fe)) { func_0036E220(&fe, -1); return; }
 int size = FileMan_GetSize(&fe);
 int blocks = (size + 0x10) >> 4;
 char* p;
 {
  AllocGuard g;
  p = (char*)Mem_Alloc(0, blocks << 4, D_004BE7F0, 0x9E8);
 }
 buf = p;
 func_0036D990(&fe, &buf, size);
 func_0036DEC0(&fe);
 char* base = buf;
 char* dst = base;
 char* src = base;
 char* end = base + size;
 while (src < end) {
  int c = *src++;
  *dst++ = c;
  if (c == 0) dst--;
  if (c == '#') dst--;
  if (c == '$') dst--;
  if (c == '*') dst--;
  if (c == '\t') dst--;
  if (c == '\n') dst--;
  if (c == '/') {
   c = *src++;
   while (!AtEnd(src, end) && c != '\r') c = *src++;
  }
  if (c == '\r') {
   dst[-1] = 0;
   src++;
   int r = func_00128C68(base, D_004BE800, self->ents[count].name, &self->ents[count].a, &self->ents[count].b, &self->ents[count].c, &self->ents[count].d, &self->ents[count].e, &self->ents[count].f, &self->ents[count].g, &self->ents[count].h);
   if (r == 9) { count++; }
   else if (r != -1) { *(__int128*)self->ents[count].name = 0; }
   dst = base;
  }
 }
 self->count = count;
 char* q = buf;
 {
  AllocGuard g;
  Mem_Free(0, q, D_004BE7F0, 0xA1D);
 }
 func_0036E220(&fe, -1);
}





