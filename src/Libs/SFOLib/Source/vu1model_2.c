/*
 * Libs/SFOLib/Source/vu1model: 1 file, 00377570
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00377570 */
#pragma push /* merge_units */
#include "types.h"
#pragma mpwc_relax on
int Alloc_Lock();
int EnableIntc();
void* cMemMan_Allocate(int, int, char*, int);
int cFileMan_EncodeFilename_charP_cFileManR();
int cFileMan_EncodeFilename_charP_cFileIOP_bool();
int cFileMan_dtor();
int cFileMan_ctor_void();
short cTexMan_AddTextureFromFile_cFileManR(int, void*);
int sprintf();
int strlen(const char*);
extern char D_004BC170;
extern char D_004BC180;
extern char D_004BC190;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern int g_TextureMgr;

typedef struct {
    int pad0;
    int flags;
    char p8[0x14 - 0x8];
    int count;
    char p18[0x70 - 0x18];
    char names[1];
} MdlDesc;

typedef struct {
    int pad0;
    MdlDesc* desc;
    short* ids;
    char pC[0x24 - 0xC];
    int flags;
} Mdl;

void cVU1Model_LoadTextures(Mdl* self, int arg1) {
    char buf[0x50];
    int name[0x28];
    int size;
    short* ids;
    char* s;
    int i;

    size = self->desc->count * 2;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    ids = cMemMan_Allocate(0, size, &D_004BC170, 0x131);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    self->ids = ids;
    s = self->desc->names;
    for (i = 0; i < self->desc->count; i++) {
        cFileMan_ctor_void(name);
        sprintf(buf, &D_004BC180, s);
        cFileMan_EncodeFilename_charP_cFileManR(name, buf, arg1);
        self->ids[i] = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, name);
        if (self->ids[i] == -1) {
            cFileMan_EncodeFilename_charP_cFileIOP_bool(name, &D_004BC190, 0, 0);
            self->ids[i] = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, name);
        }
        s += strlen(s) + 1;
        cFileMan_dtor(name, -1);
    }
    if (self->desc->flags & 1) {
        self->flags |= 0x400000;
    } else if (self->desc->flags & 2) {
        self->flags |= 0x800000;
    } else {
        self->flags |= 0x200000;
    }
}
static inline void merge_flush_func_00377570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00377570 */
