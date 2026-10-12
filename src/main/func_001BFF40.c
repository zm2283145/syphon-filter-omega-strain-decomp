
#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_1BFF40;
typedef struct { char pad[0x18]; void* anim; } TN_1BFF40;
typedef struct { TN_1BFF40* n; } It_1BFF40;
typedef struct { char d[0xA0]; } __attribute__((aligned(16))) File_1BFF40;
extern int func_001C3E90(void* mgr, char* name);
extern int sprintf(char* buf, const char* fmt, ...);
extern void* func_003F9600(void* fs, char* path);
extern void String_CtorCStr_13B480(Str_1BFF40* s, char* c);
extern void func_001C00D0(Str_1BFF40* out, Str_1BFF40* a, char* b);
extern char* func_001692D0(Str_1BFF40* s);
extern void func_0036E540(File_1BFF40* f, char* name, void* h, int x);
extern void func_00138B70(Str_1BFF40* s, int f);
extern void* func_001C3C50(void* mgr, File_1BFF40* f);
extern void func_00130B00(It_1BFF40* out, void* tree);
extern void func_001C00C0(It_1BFF40* out, void* tree);
extern void func_003B54C0(void* anim, Str_1BFF40* name, void* r);
extern void Tree_Successor(It_1BFF40* it);
extern void func_0036E220(File_1BFF40* f, int x);
extern char D_0048B2F8[];
extern char D_004FFB8C[];
extern char D_004FFBC0[];
static inline int Eq_1BFF40(void* a, void* b) { return a == b; }
void func_001BFF40(void* mgr, char* name)
{
    It_1BFF40 it;
    It_1BFF40 b;
    It_1BFF40 e;
    Str_1BFF40 s1;
    Str_1BFF40 s2;
    Str_1BFF40 s3;
    char buf[0x88];
    File_1BFF40 file;
    void* h;
    void* r;
    if (func_001C3E90(mgr, name)) return;
    sprintf(buf, "%s\\COMMON\\SKALEVEL.HOG", D_0048B2F8);
    h = func_003F9600(D_004FFB8C, buf);
    if (!h) return;
    String_CtorCStr_13B480(&s1, name);
    func_001C00D0(&s2, &s1, ".ska");
    func_0036E540(&file, func_001692D0(&s2), h, 0);
    func_00138B70(&s2, 0);
    func_00138B70(&s1, 0);
    r = func_001C3C50(mgr, &file);
    if (r) {
        func_00130B00(&b, D_004FFBC0);
        it.n = b.n;
        func_001C00C0(&e, D_004FFBC0);
        h = e.n;
        while (Eq_1BFF40(it.n, h) ^ 1) {
            String_CtorCStr_13B480(&s3, name);
            func_003B54C0(it.n->anim, &s3, r);
            func_00138B70(&s3, 0);
            Tree_Successor(&it);
        }
    }
    func_0036E220(&file, -1);
}




