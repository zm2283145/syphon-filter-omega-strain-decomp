/*
 * main/interface: 3 files, 003E79F0-003E7B00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E79F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "interface_types.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
extern void* g_TextureMgr;                            /* texture manager */
void cInterfaceModel_dtor(InterfaceModel* p, int flags);   /* InterfaceModel dtor */
void cTexMan_Flush(void* p);
void operator_delete(void* p);
}
/* Destructor: delete the model, then let the texture manager release its textures. */
extern "C" Interface* cInterface_dtor(Interface* self, short flag)
{
    if (self) {
        InterfaceModel* b = self->model;
        {
            AllocGuard g;
            cInterfaceModel_dtor(b, -1);
            cMemMan_Deallocate(0, b, "interface.cc", 0x45);
        }
        cTexMan_Flush(g_TextureMgr);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E79F0 */

/* merge_units: begin func_003E7AD0 */
#pragma push /* merge_units */
extern int cInterfaceModel_Refresh(InterfaceModel*, void*);   /* recursive over the model tree */

/* Forward arg to cInterfaceModel_Refresh on the model (if loaded). */
void cInterface_Refresh(Interface* self, void* arg) {
    if (self->model != 0) {
        cInterfaceModel_Refresh(self->model, arg);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003E7AD0 */

/* merge_units: begin func_003E7B00 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern void cFileMan_Open(void*);
extern unsigned char* cFileMan_Read_void(void*);
extern int D_0055C0B8;                              /* u16 read from the interface file header */
extern char D_004BDEC8[];                           /* "interface.cc" */
extern void* cMemMan_Allocate(int, int, char*, int);
extern InterfaceModel* cInterfaceModel_ctor(void*, unsigned char**, void*, int); /* InterfaceModel ctor from data */
extern void* cInterfaceModel_GetChild(InterfaceModel*, char*); /* find element by name */
extern void* cInterfaceModel_CreateInstance(void*);
extern float cInterfaceModel_NumFrames(void*);
extern void cAnimator_StartAnimation(void*, int, float, float);
}
#pragma opt_propagation off
/* Constructor: build the model from the interface file src and set up its "preview" element. */
extern "C" Interface* cInterface_ctor(Interface* o, void* src) {
    unsigned char* p;
    InterfaceModel* m;
    void* s;
    o->model = 0;
    o->preview = 0;
    cFileMan_Open(src);
    p = cFileMan_Read_void(src);
    p++;
    p++;
    D_0055C0B8 = *(unsigned short*)p;
    p += 2;
    {
        AllocGuard g;
        m = (InterfaceModel*)cMemMan_Allocate(0, INTERFACE_MODEL_SIZE, D_004BDEC8, 0x2F);
    }
    if (m) m = cInterfaceModel_ctor(m, &p, src, 0);
    o->model = m;
    o->model->unk60 = 1;
    s = cInterfaceModel_GetChild(o->model, "preview");
    if (s) {
        o->preview = cInterfaceModel_CreateInstance(s);
        cAnimator_StartAnimation(o->preview, 1, -20.0f, 20.0f + cInterfaceModel_NumFrames(s));
    }
    return o;
}
#pragma opt_propagation reset
#pragma pop /* merge_units */
/* merge_units: end func_003E7B00 */