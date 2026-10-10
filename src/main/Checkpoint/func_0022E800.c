#include "types.h"
typedef struct { char pad[8]; int id; char name[1]; } CkSrc_f4;
typedef struct { void* vt; char pad4[0x20]; void* node; char* label; } CkMsg_f4;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_004F7930[];
extern char D_004DB8D0[];
extern char D_004A6698[];
extern void Event_Construct(void*, void*);
extern void* Object_LookupById(int*);
extern int strlen(const char*);
extern char* strncpy(char*, const char*, int);
extern void Alloc_Lock(int);
extern void Alloc_Unlock(int);
extern void* Mem_Alloc(int, int, char*, int);
static inline void* AllocL_f4(int size, char* file, int line)
{
    void* p;
    if (D_00533880) Alloc_Lock(9);
    D_00533888++;
    p = Mem_Alloc(0, size, file, line);
    if (D_00533880) Alloc_Unlock(9);
    D_00533888--;
    return p;
}
CkMsg_f4* cAddCheckpointMsg_ctor(CkMsg_f4* self, CkSrc_f4* src)
{
    int id[1];
    int n;
    Event_Construct(self, D_004F7930);
    self->vt = D_004DB8D0;
    id[0] = src->id;
    self->node = Object_LookupById(id);
    n = strlen(src->name) + 1;
    self->label = AllocL_f4(n, D_004A6698, 0x81);
    strncpy(self->label, src->name, n);
    return self;
}