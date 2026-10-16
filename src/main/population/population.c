/*
 * main/population: 2 files, 00178C60-00178D40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00178C60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
#include "population.h"
/* flag > 0: also delete the object (-1 = destroy in place). */
extern "C" Population* Population_Dtor(Population* self, short flag)
{
    if (self) {
        if (self->ownsData) {
            void* b = self->data;
            AllocGuard g;
            Mem_Free(1, b, "population.cc", 0x43);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00178C60 */

/* merge_units: begin func_00178D40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "population.h"
/* FileManEntry (fileman_entry.h) on the stack; kept as a 0xA0-byte local type. */
typedef struct { int a[0x28]; } H178;
extern "C" {
extern int sprintf(char*, const char*, ...);
extern void func_0036E540(H178*, char*, void*, int);
extern int FileMan_FindMember(H178*);
extern void func_0036E140(H178*, char*, int, int);
extern int FileMan_GetSize(H178*);
extern void* Mem_Alloc(int, int, char*, int);
extern char D_0049CDA0[];
extern char D_0048B2F8[];
extern void FileMan_LoadMemberSync(H178*, void**, int);
extern void func_0036DEC0(H178*);
extern void* FileMan_ReadData(H178*);
extern void FileMan_Release(H178*, int);
}
extern "C" Population* Population_Load(Population* p, char* name, void* arg) {
    char buf[0x90];
    H178 h;
    sprintf(buf, "%s.pop", name);
    func_0036E540(&h, buf, arg, 0);
    if ((unsigned char)FileMan_FindMember(&h)) {
        void* m;
        sprintf(buf, "%s\\%s\\DATA.POP", D_0048B2F8, name, name);
        func_0036E140(&h, buf, 0, 0);
        FileMan_FindMember(&h);
        p->size = FileMan_GetSize(&h);
        p->ownsData = 1;
        {
        int sz = p->size;
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        m = Mem_Alloc(1, sz, D_0049CDA0, 0x27);
        }
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        p->data = m;
        FileMan_LoadMemberSync(&h, &p->data, p->size);
        func_0036DEC0(&h);
    } else {
        p->ownsData = 0;
        p->data = FileMan_ReadData(&h);
        p->size = FileMan_GetSize(&h);
    }
    p->cursor = p->data;
    p->count = *(int*)p->cursor;
    p->cursor = (char*)p->cursor + 4;
    FileMan_Release(&h, -1);
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_00178D40 */
