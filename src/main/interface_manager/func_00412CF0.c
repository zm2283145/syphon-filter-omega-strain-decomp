#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Str412CF0 { int a; int b; int c; };
struct TagChar412CF0 { char c; };
struct ArcInfo412CF0 { int pad0; int count; };
struct Arc412CF0 { char pad[0x148]; ArcInfo412CF0* info; };
struct Ent412CF0 {
    Str412CF0 name;     /* 0x00 */
    void* data;         /* 0x0C */
    int ref;            /* 0x10 */
    Arc412CF0* arc;     /* 0x14 */
};
struct Self412CF0 {
    Ent412CF0 e[20];    /* 0x000 */
    void* f1E0;         /* 0x1E0 */
};
struct Hog412CF0 { char pad[0xA8]; };

extern "C" {
extern char D_004BEF30[];
extern void* D_00539248;
void Interface_Dtor(void* p, int flags);
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_0036E5D0(Hog412CF0* h);
void FileMan_Release(Hog412CF0* h, int flags);
char* Archive_GetMemberName(Arc412CF0* a, int i);
void Hog_Register(Hog412CF0* h, char* name, Arc412CF0* a, int z);
int FileMan_FindMember(Hog412CF0* h);
void func_003816F0(void* mgr, Hog412CF0* h);
Str412CF0* String_Replace(Str412CF0* self, unsigned int pos, unsigned int n, const char* first, const char* last, TagChar412CF0 tag);
void ArchiveList_CloseNamed(void* t, Arc412CF0* a);
}

static inline void* GetData(Self412CF0* self, int idx)
{
    if (idx < 0 || idx >= 20)
        return 0;
    return self->e[idx].data;
}

/* Interface manager: release slot idx; when its refcount drops to zero, frees the
 * loaded data, unregisters every hog entry of its archive, clears the name and
 * closes the archive. The mixed slot-address forms reproduce retail CSE/addu order. */
extern "C" void func_00412CF0(Self412CF0* self, int idx)
{
    Arc412CF0* arc;
    int n;
    int i;
    void** pd;
    Arc412CF0** pa;
    void* obj;
    int off;

    if (GetData(self, idx) == 0)
        return;
    self->e[idx].ref--;
    if (self->e[idx].ref != 0)
        return;
    pd = &self->e[idx].data;
    obj = *pd;
    {
        AllocGuard g;
        Interface_Dtor(obj, -1);
        Mem_Free(0, obj, D_004BEF30, 0x15B);
    }
    off = idx * (int)sizeof(Ent412CF0);
    pa = &((Ent412CF0*)(off + (int)self))->arc;
    arc = *pa;
    {
        Hog412CF0 h;
        func_0036E5D0(&h);
        n = arc->info->count;
        for (i = 0; i < n; i++) {
            Hog_Register(&h, Archive_GetMemberName(arc, i), arc, 0);
            FileMan_FindMember(&h);
            func_003816F0(D_00539248, &h);
        }
        FileMan_Release(&h, -1);
    }
    {
        TagChar412CF0 tag;
        String_Replace((Str412CF0*)((char*)self + idx * (int)sizeof(Ent412CF0)), 0, (unsigned int)-1, 0, 0, tag);
    }
    *pd = 0;
    ArchiveList_CloseNamed(self->f1E0, *pa);
}


