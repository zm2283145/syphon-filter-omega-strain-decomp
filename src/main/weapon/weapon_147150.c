/*
 * main/weapon: range (2 files, 00147150-00147390)
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
int strlen(const char *);

/* merge_units: begin func_00147150 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {
extern char D_0049B1D0[];
extern char D_0049B308[];
void* Mem_Alloc(int pool, int size, char* file, int line);
char* strrchr(const char* s, int c);
void Hog_Register(void* h, char* name, int x, int f);
int FileMan_FindMember(void* h);
int WeaponDb_GetShellRecord(void* self, int x);
void ManModel_ctor(void* o, char* name, int idx, int x, int a, int b, int c, int d);
void WeaponDb_CloneModel(void* self, char* name, void* o);
int Fstream_GetLoader(void);
void AsyncLoader_QueueLoad(int q, void* h, void* cb, void* o, int a, int b, int c);
void WeaponDb_LoadCallback(void);
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
    if ((unsigned char)FileMan_FindMember(self->hog)) return;
    x = 0;
    if (idx >= 0) x = WeaponDb_GetShellRecord(self, ((R7150*)((char*)self->recs + idx * 0x140))->x10C);
    {
        *out = new (SD_Alloc(sizeof(O7150), 0x153)) O7150;
    }
    ManModel_ctor(*out, buf, idx, x, a, 1, b, c);
    WeaponDb_CloneModel(self, buf, *out);
    AsyncLoader_QueueLoad(Fstream_GetLoader(), self->hog, (void*)WeaponDb_LoadCallback, *out, 0, 1, 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00147150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00147150 */

/* merge_units: begin func_00147390 */
#pragma push /* merge_units */
extern void WeaponDb_LoadResources(void* self);
extern void FileMan_Release(void* p, int flag);
extern void cDB_dtor(void* self, int flag);
extern void operator_delete(void* p);
void* cWeaponDB_dtor(char* self, short flag)
{
    if (self) {
        WeaponDb_LoadResources(self);
        FileMan_Release(self + 0x1C, -1);
        cDB_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00147390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00147390 */
