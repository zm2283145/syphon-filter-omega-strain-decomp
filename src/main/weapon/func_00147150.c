#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
extern "C" {
extern char D_0049B1D0[];
extern char D_0049B308[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void String_Copy(char* d, const char* s);
char* strrchr(const char* s, int c);
int strlen(const char* s);
void Hog_Register(void* h, char* name, int x, int f);
int func_0036DEF0(void* h);
int func_00147880(void* self, int x);
void func_0038D530(void* o, char* name, int idx, int x, int a, int b, int c, int d);
void func_00146B80(void* self, char* name, void* o);
int func_003EBA50(void);
void AsyncLoader_QueueLoad(int q, void* h, void* cb, void* o, int a, int b, int c);
void func_00147110(void);
}
inline void* operator new(unsigned int, void* p) { return p; }
struct E7150 { E7150() {} char pad[0x20]; };
struct V7150 { float x, y, z, w; };
struct O7150 {
    char pad0[0x140];
    E7150 e[12];
    char pad2C0[0x3E0 - 0x2C0];
    V7150 mn;
    V7150 mx;
    char pad400[0x20];
    O7150() {
        mn.x = 3.4028235e38f; mn.y = 3.4028235e38f; mn.z = 3.4028235e38f; mn.w = 1.0f;
        mx.x = -3.4028235e38f; mx.y = -3.4028235e38f; mx.z = -3.4028235e38f; mx.w = 1.0f;
    }
};
struct R7150 { char pad[0x10C]; int x10C; char pad110[0x140 - 0x110]; };
struct S7150 { char pad0[0x14]; R7150* recs; char pad18[4]; char hog[0xB4 - 0x1C]; int xB4; };
static inline void* SD_Alloc(int n, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, n, D_0049B1D0, line);
}
extern "C" void WeaponDb_LoadModel(S7150* self, char* name, O7150** out, int idx, int a, int b, int c)
{
    char buf[0x100];
    char* p;
    int x;
    *out = 0;
    String_Copy(buf, name);
    p = strrchr(buf, '.');
    if (!p) p = &buf[strlen(buf)];
    String_Copy(p, D_0049B308);
    Hog_Register(self->hog, buf, self->xB4, 1);
    if ((unsigned char)func_0036DEF0(self->hog)) return;
    x = 0;
    if (idx >= 0) x = func_00147880(self, ((R7150*)((char*)self->recs + idx * 0x140))->x10C);
    {
        *out = new (SD_Alloc(sizeof(O7150), 0x153)) O7150;
    }
    func_0038D530(*out, buf, idx, x, a, 1, b, c);
    func_00146B80(self, buf, *out);
    AsyncLoader_QueueLoad(func_003EBA50(), self->hog, (void*)func_00147110, *out, 0, 1, 1);
}


