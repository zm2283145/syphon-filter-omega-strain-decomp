/*
 * main/ska: 4 files, 003BB060-003BB2F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BB060 */
#pragma push /* merge_units */
/* Bind the texture pair, reset the batch flags, then append each id to the
 * 512-entry draw list unless it repeats the last entry. */
typedef struct Mgr {
    char pad0[0x14];
    unsigned char f14;
    unsigned char f15;
    unsigned char f16;
    char pad17;
    unsigned int count;
    short list[0x200];
} Mgr;
typedef struct Pair { int a; int b; } Pair;
extern Mgr* g_TextureMgr;
extern void cTexMan_LockVram(Mgr*, int);
extern void TexMan_UploadSlots(Mgr*);

static inline void Push(Mgr* m, int id)
{
    if (m->count < 0x200) {
        if (m->count == 0 || m->list[m->count - 1] != id) {
            m->list[m->count++] = id;
        }
    }
}

void cUserFrameEnv_Activate(Pair* p)
{
    Mgr* m;
    cTexMan_LockVram(g_TextureMgr, p->a);
    if (p->b != -1) cTexMan_LockVram(g_TextureMgr, p->b);
    m = g_TextureMgr;
    m->f14 = 1;
    m->f15 = 1;
    m->count = 0;
    m->f16 = 0;
    Push(g_TextureMgr, p->a);
    if (p->b != -1) Push(g_TextureMgr, p->b);
    TexMan_UploadSlots(g_TextureMgr);
}
#pragma pop /* merge_units */
/* merge_units: end func_003BB060 */

/* merge_units: begin func_003BB180 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[4]; unsigned short w; unsigned short h; } Pt2_Dim;
typedef struct { char pad[0x44]; Pt2_Dim* dim; } Pt2_Tex;
typedef struct { char pad[8]; Pt2_Tex** tex; } Pt2_TexTbl;
#if 0 /* merge_units */
extern Pt2_TexTbl* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(Pt2_TexTbl **)&g_TextureMgr) /* merge_units */

extern char g_Video[];
extern void XLib_ClearActiveBuffer(void*, int, int, int, int, int);
void cUserFrameEnv_Clear(int* id, int arg1) {
    Pt2_Dim* d = (*(Pt2_Tex**)((int)g_TextureMgr->tex + *id * 4))->dim;
    XLib_ClearActiveBuffer(g_Video, d->w, d->h, arg1, 1, 0);
}
#undef g_TextureMgr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BB180 */

/* merge_units: begin func_003BB1C0 */
#pragma push /* merge_units */
typedef struct F1RT3BB { int color; int depth; int colorFmt; int depthFmt; unsigned char hasDepth; } F1RT3BB;
#if 0 /* merge_units */
extern void* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(void **)&g_TextureMgr) /* merge_units */

extern void Libc_Strcpy(char* dst, char* src);
extern void Libc_Strcat(char* dst, char* src);
extern int cTexMan_AddTexture(void* mgr, char* name, int w, int h, int fmt);
void cUserFrameEnv_Init(F1RT3BB* rt, char* name, int w, int h, int fmt, int depth)
{
    char cname[0x40];
    char dname[0x40];
    Libc_Strcpy(cname, name);
    Libc_Strcpy(dname, name);
    Libc_Strcat(dname, "_zbuf");
    rt->colorFmt = fmt == 16 ? 2 : fmt == 24;
    rt->depthFmt = depth == 16 ? 0x3A : depth == 24 ? 0x31 : 0x30;
    rt->hasDepth = depth > 0;
    rt->color = -1;
    rt->depth = -1;
    rt->color = cTexMan_AddTexture(g_TextureMgr, cname, w, h, fmt);
    if (depth) rt->depth = cTexMan_AddTexture(g_TextureMgr, dname, w, h, depth);
}
#undef g_TextureMgr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BB1C0 */

/* merge_units: begin func_003BB2F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cUserFrameEnv_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003BB2F0 */
