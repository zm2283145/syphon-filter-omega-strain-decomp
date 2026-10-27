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
extern void* g_TextureMgr;
void cInterface_dtor(void* p, int flags);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void cFileMan_ctor_void(Hog412CF0* h);
void cFileMan_dtor(Hog412CF0* h, int flags);
char* cHogFile_GetBlockName(Arc412CF0* a, int i);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog412CF0* h, char* name, Arc412CF0* a, int z);
int cFileMan_Open(Hog412CF0* h);
void cTexMan_RemoveTextureFromFile(void* mgr, Hog412CF0* h);
Str412CF0* std_basic_string_char_char_traits_char_do_replace(Str412CF0* self, unsigned int pos, unsigned int n, const char* first, const char* last, TagChar412CF0 tag);
void cHogList_Close(void* t, Arc412CF0* a);
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
extern "C" void cInterfaceManager_RemoveInterface(Self412CF0* self, int idx)
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
        cInterface_dtor(obj, -1);
        cMemMan_Deallocate(0, obj, D_004BEF30, 0x15B);
    }
    off = idx * (int)sizeof(Ent412CF0);
    pa = &((Ent412CF0*)(off + (int)self))->arc;
    arc = *pa;
    {
        Hog412CF0 h;
        cFileMan_ctor_void(&h);
        n = arc->info->count;
        for (i = 0; i < n; i++) {
            cFileMan_EncodeFilename_charP_cHogFileR_bool(&h, cHogFile_GetBlockName(arc, i), arc, 0);
            cFileMan_Open(&h);
            cTexMan_RemoveTextureFromFile(g_TextureMgr, &h);
        }
        cFileMan_dtor(&h, -1);
    }
    {
        TagChar412CF0 tag;
        std_basic_string_char_char_traits_char_do_replace((Str412CF0*)((char*)self + idx * (int)sizeof(Ent412CF0)), 0, (unsigned int)-1, 0, 0, tag);
    }
    *pd = 0;
    cHogList_Close(self->f1E0, *pa);
}


