#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BDC18[];
extern char D_004BDC28[];
char D_004BDC38[] = "scriptFile.hh";
char D_004BDC48[] = "scriptFile.hh";
char D_004BDC58[] = "scriptFile.hh";
void* Mem_Alloc(int heap, int size, char* file, int line);
void Mem_Free(int heap, void* p, char* file, int line);
void FileHal_Dtor(void* p, int flag);
int* FileHal_Ctor(void* p, char* name, int mode);
void cFileMan_Close(void* h);
int FileMan_FindMember(void* h);
void cFileMan_EncodeFilename_charP_cFileIOP_bool(void* h, char* name, int* f, int a);
void Hog_Register(void* h, char* name, int size, int a);
char* strrchr(const char* s, int c);
}
struct S_003DC080 { int* file; int size; char hog[0xA4 - 8]; void* pA4; int a8; int ac; int b0; int b4; unsigned char b8; };
static inline void* New_003DC080(int size, char* f, int line) { AllocGuard g; return Mem_Alloc(0, size, f, line); }
static inline void DelF_003DC080(int* p, char* f, int line) { if (p) { AllocGuard g; FileHal_Dtor(p, -1); Mem_Free(0, p, f, line); } }
static inline void DelG_003DC080(int* p, char* f, int line) { AllocGuard g; FileHal_Dtor(p, -1); Mem_Free(0, p, f, line); }
static inline void Del_003DC080(void* p, char* f, int line) { if (p) { AllocGuard g; Mem_Free(0, p, f, line); } }
extern "C" void FileMan_Open(S_003DC080* s, char* name, int mode)
{
    int* f;
    s->pA4 = 0;
    s->a8 = 0;
    s->ac = 0;
    s->b4 = 0;
    s->b0 = 0;
    if (s->file) {
        cFileMan_Close(s->hog);
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
            if (f) f = FileHal_Ctor(f, name, 1);
            s->file = f;
            if (*s->file >= 0) {
                cFileMan_EncodeFilename_charP_cFileIOP_bool(s->hog, name, s->file, 0);
            } else {
                DelG_003DC080(s->file, D_004BDC48, 0x74);
                s->file = 0;
            }
        }
        if (!s->file && s->size) {
            char* p = strrchr(name, '\\');
            name = p ? p + 1 : name;
            Hog_Register(s->hog, name, s->size, 0);
            s->b8 = (unsigned char)FileMan_FindMember(s->hog) == 0;
            return;
        }
    } else if (mode == 1) {
        f = (int*)New_003DC080(0xC8, D_004BDC38, 0x84);
        if (f) f = FileHal_Ctor(f, name, 0x202);
        s->file = f;
    } else {
        s->file = 0;
    }
    s->b8 = s->file != 0;
}