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
void Mem_Free(int pool, void* p, char* file, int line);
extern void* D_00539248;                            /* texture manager */
void func_003EF120(InterfaceModel* p, int flags);   /* InterfaceModel dtor */
void func_00381260(void* p);
void operator_delete(void* p);
}
/* Destructor: delete the model, then let the texture manager release its textures. */
extern "C" Interface* Interface_Dtor(Interface* self, short flag)
{
    if (self) {
        InterfaceModel* b = self->model;
        {
            AllocGuard g;
            func_003EF120(b, -1);
            Mem_Free(0, b, "interface.cc", 0x45);
        }
        func_00381260(D_00539248);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E79F0 */

/* merge_units: begin func_003E7AD0 */
#pragma push /* merge_units */
extern int func_003F05A0(InterfaceModel*, void*);   /* recursive over the model tree */

/* Forward arg to func_003F05A0 on the model (if loaded). */
void func_003E7AD0(Interface* self, void* arg) {
    if (self->model != 0) {
        func_003F05A0(self->model, arg);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003E7AD0 */

/* merge_units: begin func_003E7B00 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern void FileMan_FindMember(void*);
extern unsigned char* FileMan_ReadData(void*);
extern int D_0055C0B8;                              /* u16 read from the interface file header */
extern char D_004BDEC8[];                           /* "interface.cc" */
extern void* Mem_Alloc(int, int, char*, int);
extern InterfaceModel* func_003EF660(void*, unsigned char**, void*, int); /* InterfaceModel ctor from data */
extern void* func_003EEB30(InterfaceModel*, char*); /* find element by name */
extern void* func_003EF010(void*);
extern float func_003EE740(void*);
extern void func_003F4510(void*, int, float, float);
}
#pragma opt_propagation off
/* Constructor: build the model from the interface file src and set up its "preview" element. */
extern "C" Interface* Interface_Ctor(Interface* o, void* src) {
    unsigned char* p;
    InterfaceModel* m;
    void* s;
    o->model = 0;
    o->preview = 0;
    FileMan_FindMember(src);
    p = FileMan_ReadData(src);
    p++;
    p++;
    D_0055C0B8 = *(unsigned short*)p;
    p += 2;
    {
        AllocGuard g;
        m = (InterfaceModel*)Mem_Alloc(0, INTERFACE_MODEL_SIZE, D_004BDEC8, 0x2F);
    }
    if (m) m = func_003EF660(m, &p, src, 0);
    o->model = m;
    o->model->unk60 = 1;
    s = func_003EEB30(o->model, "preview");
    if (s) {
        o->preview = func_003EF010(s);
        func_003F4510(o->preview, 1, -20.0f, 20.0f + func_003EE740(s));
    }
    return o;
}
#pragma opt_propagation reset
#pragma pop /* merge_units */
/* merge_units: end func_003E7B00 */