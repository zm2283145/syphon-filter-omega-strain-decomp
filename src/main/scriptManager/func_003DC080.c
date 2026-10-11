#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BDC18[];
extern char D_004BDC28[];
extern char D_004BDC38[];
extern char D_004BDC48[];
extern char D_004BDC58[];
void* Mem_Alloc(int heap, int size, char* file, int line);
void Mem_Free(int heap, void* p, char* file, int line);
void func_00369700(void* p, int flag);
int* func_00369820(void* p, char* name, int mode);
void func_0036DEC0(void* h);
int func_0036DEF0(void* h);
void func_0036E140(void* h, char* name, int* f, int a);
void Hog_Register(void* h, char* name, int size, int a);
char* strrchr(const char* s, int c);
}
struct S_003DC080 { int* file; int size; char hog[0xA4 - 8]; void* pA4; int a8; int ac; int b0; int b4; unsigned char b8; };
static inline void* New_003DC080(int size, char* f, int line) { AllocGuard g; return Mem_Alloc(0, size, f, line); }
static inline void DelF_003DC080(int* p, char* f, int line) { if (p) { AllocGuard g; func_00369700(p, -1); Mem_Free(0, p, f, line); } }
static inline void DelG_003DC080(int* p, char* f, int line) { AllocGuard g; func_00369700(p, -1); Mem_Free(0, p, f, line); }
static inline void Del_003DC080(void* p, char* f, int line) { if (p) { AllocGuard g; Mem_Free(0, p, f, line); } }
extern "C" void func_003DC080(S_003DC080* s, char* name, int mode)
{
    int* f;
    s->pA4 = 0;
    s->a8 = 0;
    s->ac = 0;
    s->b4 = 0;
    s->b0 = 0;
    if (s->file) {
        func_0036DEC0(s->hog);
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
            if (f) f = func_00369820(f, name, 1);
            s->file = f;
            if (*s->file >= 0) {
                func_0036E140(s->hog, name, s->file, 0);
            } else {
                DelG_003DC080(s->file, D_004BDC48, 0x74);
                s->file = 0;
            }
        }
        if (!s->file && s->size) {
            char* p = strrchr(name, '\\');
            name = p ? p + 1 : name;
            Hog_Register(s->hog, name, s->size, 0);
            s->b8 = (unsigned char)func_0036DEF0(s->hog) == 0;
            return;
        }
    } else if (mode == 1) {
        f = (int*)New_003DC080(0xC8, D_004BDC38, 0x84);
        if (f) f = func_00369820(f, name, 0x202);
        s->file = f;
    } else {
        s->file = 0;
    }
    s->b8 = s->file != 0;
}