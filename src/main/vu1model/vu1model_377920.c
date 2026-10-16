/*
 * main/vu1model: 3 files, 00377920-00377C30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00377920 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x58]; int n; } MatL;
typedef struct { int pad0; int count; int pad8; int mat; } MeshL;
typedef struct { int id; int pad; } LightL;
typedef struct {
    char pad0[0x10];
    int nMesh;
    char pad14[4];
    int n18;
    int nLight;
    char pad20[0x1C];
    float f3C;
    char pad40[0xC];
    float f4C;
    MatL* mats;
    MeshL* meshes;
    LightL* lights;
    LightL* p5C;
    LightL* p60;
    unsigned char loaded;
} HdrL;
typedef struct {
    char* base;
    HdrL* hdr;
    char pad8[8];
    int cnt;
    int n14;
    int tris;
    char pad1C[0x10];
    unsigned char ok;
} ModelL;
extern "C" {
extern char D_00535D20[];
extern void FileMan_FindMember(void* f);
extern void FileMan_LoadMemberSync(void* f, ModelL* m, int z);
extern void func_0036DEC0(void* f);
extern void Model_BindTextures(ModelL* m, void* t);
extern void Model_FoldMaterialFlags(ModelL* m);
extern void Model_PatchMscal(ModelL* m);
extern void Model_SetupExtraTable(ModelL* m);
extern void Model_SetupMaterialFx(ModelL* m);
extern void LightMgr_Register(void* mgr, int id, ModelL* m, int i);
}
/* Relocates a freshly read model header in place, then counts triangles, binds textures,
   registers lights and sizes the draw list. */
extern "C" void Model_Load(ModelL* m, void* f, void* tex) {
    FileMan_FindMember(f);
    FileMan_LoadMemberSync(f, m, 0);
    func_0036DEC0(f);
    m->hdr = (HdrL*)m->base;
    if (!m->hdr->loaded) {
        m->hdr->mats = (MatL*)((int)m->base + (int)m->hdr->mats);
        m->hdr->meshes = (MeshL*)((int)m->base + (int)m->hdr->meshes);
        m->hdr->f3C = 1.0f;
        m->hdr->f4C = 1.0f;
        m->hdr->p5C = (LightL*)((int)m->base + (int)m->hdr->p5C);
        m->hdr->p60 = (LightL*)((int)m->base + (int)m->hdr->p60);
        m->n14 = (m->hdr->p60 - m->hdr->p5C) >> 1;
    }
    if (m->hdr->n18 == 0 || m->hdr->nMesh == 0) {
        m->ok = 0;
        return;
    }
    m->tris = 0;
    for (int i = 0; i < m->hdr->nMesh; i++) {
        m->tris += m->hdr->meshes[i].count * 2;
    }
    Model_BindTextures(m, tex);
    if (!m->hdr->loaded) {
        Model_FoldMaterialFlags(m);
        Model_PatchMscal(m);
        Model_SetupExtraTable(m);
    }
    for (int j = 0; j < m->hdr->nLight; j++) {
        LightMgr_Register(D_00535D20, m->hdr->lights[j].id, m, j);
    }
    m->cnt = 0;
    for (int i = 0; i < m->hdr->nMesh; i++) {
        MeshL* me = &m->hdr->meshes[i];
        int n = m->hdr->mats[me->mat].n;
        if (n == 1) {
            m->cnt++;
        } else {
            m->cnt += me->count * n;
        }
    }
    Model_SetupMaterialFx(m);
    m->hdr->loaded = 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00377920 */

/* merge_units: begin func_00377BD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "self_call_dtor.h"

DEFINE_SELF_CALL_DTOR(func_00377BD0, Model_Unload)
#pragma pop /* merge_units */
/* merge_units: end func_00377BD0 */

/* merge_units: begin func_00377C30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Rec377C30 constructor: zero all words, set the flag byte. */
Rec377C30* func_00377C30(Rec377C30* self) {
    self->unk[0] = 0;
    self->unk[1] = 0;
    self->unk[2] = 0;
    self->unk[3] = 0;
    self->unk[4] = 0;
    self->unk[5] = 0;
    self->unk[6] = 0;
    self->unk[7] = 0;
    self->unk[8] = 0;
    self->unk[9] = 0;
    self->unk[10] = 0;
    self->unk2C = 1;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00377C30 */
