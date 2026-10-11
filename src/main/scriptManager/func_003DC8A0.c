#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct VObj_3DC8A0 { virtual void dtor(int f); };
typedef struct { char pad[0x10]; int refs; } RefA_3DC8A0;
typedef struct { char pad[0x38]; int refs; } RefB_3DC8A0;
typedef struct { int pad0; int count; void** data; int padC; } Vec_3DC8A0;
typedef struct {
    Vec_3DC8A0 v0; Vec_3DC8A0 v10; Vec_3DC8A0 v20; Vec_3DC8A0 v30;
    Vec_3DC8A0 v40; Vec_3DC8A0 v50; Vec_3DC8A0 v60; Vec_3DC8A0 v70;
    void* p80; void* p84; void* p88;
} Self_3DC8A0;
extern "C" {
extern char D_004BD4C0[];
void Mem_Free(int pool, void* p, char* file, int line);
void func_0013A040(void* p, int f);
void func_00145F10(void* p, int f);
void** func_002151B0(void* v, int i);
void func_00397F80(void* p, int f);
void func_003D8160(void* p, int f);
void func_003D8250(void* p, int f);
VObj_3DC8A0** func_003DC060(void* v, int i);
void** func_003DC070(void* v, int i);
void func_003DCE80(void* p, int f);
void operator_delete(void* p);
}
static inline void Free_3DC8A0(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BD4C0, line); }
static inline void FreeV_3DC8A0(VObj_3DC8A0* o, int line) { AllocGuard g; o->dtor(-1); Mem_Free(0, o, D_004BD4C0, line); }

#pragma opt_strength_reduction off
extern "C" Self_3DC8A0* func_003DC8A0(Self_3DC8A0* self, short f)
{
    if (self) {
        Free_3DC8A0(self->p80, 0xB29);
        if (self->p84) Free_3DC8A0(self->p84, 0xB2C);
        if (self->p88) Free_3DC8A0(self->p88, 0xB2F);
        {
            int n = self->v60.count; int i;
            for (i = 0; i < n; i++) Free_3DC8A0(*func_002151B0(&self->v60, i), 0xB35);
            self->v60.count = 0;
        }
        {
            int i; int n = self->v20.count;
            for (i = 0; i < n; i++)
                if (self->v20.data[i]) Free_3DC8A0(*func_003DC070(&self->v20, i), 0xB3D);
        }
        {
            int n = self->v0.count; int i;
            for (i = 0; i < n; i++) {
                RefA_3DC8A0* r = (RefA_3DC8A0*)self->v0.data[i];
                if (r) r->refs--;
            }
        }
        {
            int n = self->v10.count; int i;
            for (i = 0; i < n; i++) {
                RefB_3DC8A0* r = (RefB_3DC8A0*)self->v10.data[i];
                if (r) r->refs--;
            }
        }
        {
            VObj_3DC8A0* o; int n = self->v50.count; int i;
            for (i = 0; i < n; i++) { o = *func_003DC060(&self->v50, i); FreeV_3DC8A0(o, 0xB4B); }
        }
        {
            int n = self->v70.count; int i;
            for (i = 0; i < n; i++) Free_3DC8A0(*func_002151B0(&self->v70, i), 0xB4F);
        }
        if (&self->v70) func_00145F10(&self->v70, -1);
        if (&self->v60) func_00145F10(&self->v60, -1);
        if (&self->v50) func_003DCE80(&self->v50, -1);
        if (&self->v40) func_0013A040(&self->v40, -1);
        if (&self->v30) func_0013A040(&self->v30, -1);
        if (&self->v20) func_00397F80(&self->v20, -1);
        if (&self->v10) func_003D8250(&self->v10, -1);
        if (self) func_003D8160(self, -1);
        if (f > 0) operator_delete(self);
    }
    return self;
}