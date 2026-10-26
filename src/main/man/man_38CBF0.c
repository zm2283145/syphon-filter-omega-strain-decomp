/*
 * main/man: range (2 files, 0038CBF0-0038CC70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0038CBF0 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x2340];
    void* items[32];
    unsigned short count;
    char pad23c2[0x2C08 - 0x23C2];
    int x2c08;
    char pad2c0c[0x2D96 - 0x2C0C];
    short x2d96;
} F38CBF0;
extern void DELAY_DELETE_ARRAY(void*);
void ActorModel_Deactivate(F38CBF0* p)
{
    int i;
    p->x2c08 = 0;
    p->x2d96 = 0;
    for (i = 0; i < p->count; i++) {
        if (p->items[i]) {
            DELAY_DELETE_ARRAY(p->items[i]);
            p->items[i] = 0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038CBF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038CBF0 */

/* merge_units: begin func_0038CC70 */
#pragma push /* merge_units */
#include "fileman_entry.h"
extern void* cFileMan_EncodeFilename_charP_cFileIOP_bool(void* entry, const char* name, int a, int b);
extern int Fstream_GetLoader(void);
extern int Fstream_ReleaseNoCallback(int mgr, void* entry, int flag);
extern void Tex_Release(int mgr, int handle, int flags);
extern int g_TextureMgr;
typedef struct {
    char name[0x3C0];
    short cur[8];
    short prev[8];
    char pad3E0[0x40C - 0x3E0];
    unsigned char count;
    char pad40D[0x417 - 0x40D];
    signed char state;
    unsigned char dirty;
} Cc70Obj;
void ActorModel_Release(Cc70Obj* self)
{
    if (self->dirty) {
        FileManEntry e;
        char path[0x100];
        Resource_Construct(&e);
        sprintf(path, "%s.HOG", self);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&e, path, 0, 0);
        Fstream_ReleaseNoCallback(Fstream_GetLoader(), &e, 1);
        self->dirty = 0;
        FileMan_Release(&e, -1);
    }
    if (self->state < 0) {
        self->state = -2;
    } else {
        int mgr = g_TextureMgr;
        int i;
        for (i = 0; i < self->count; i++) {
            if (self->cur[i] != self->prev[i]) Tex_Release(mgr, self->prev[i], 0);
            Tex_Release(mgr, self->cur[i], 0);
        }
        self->state = -3;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038CC70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038CC70 */
