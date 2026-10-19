/*
 * main/population: 4 files, 00178BB0-00178C60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00178BB0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct E3PopReader {
    int unk0;
    int size;      /* 0x4: buffer size in bytes */
    unsigned int base;    /* 0x8 */
    int* cur;      /* 0xC */
} E3PopReader;

/* Scans the population buffer for a tag word; leaves the cursor just after it. */
int Pop_FindTag(E3PopReader* r, int tag) {
    int off;
    int v;
    v = *r->cur;
    r->cur++;
    if (v == tag) {
        return 1;
    }
    r->cur = (int*)r->base;
    off = 0;
    v = *r->cur;
    r->cur++;
    if (v != tag) {
        do {
            r->cur = (int*)(r->base + off);
            off += 4;
            if (r->cur > (int*)(r->base + r->size)) {
                r->cur = (int*)(r->size + r->base);
                return 0;
            }
            v = *r->cur;
            r->cur++;
        } while (v != tag);
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00178BB0 */

/* merge_units: begin func_00178C50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

/* Subtract from the word at +0x0C. */
void func_00178C50(Unk0013BDE0* self, int amount) {
    self->unk0C = self->unk0C - amount;
}
#pragma pop /* merge_units */
/* merge_units: end func_00178C50 */

/* merge_units: begin func_00178C60 */
#pragma push /* merge_units */
#pragma cplusplus on
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
