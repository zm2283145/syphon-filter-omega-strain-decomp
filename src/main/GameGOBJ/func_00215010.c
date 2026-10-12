#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void Mem_Free(int, void*, char*, int);
int strlen(const char*);
void String_Copy(char*, const char*);
extern char D_004A4550[];
}

typedef struct NameVec {
    int unk0;
    int count;
    char** data;
} NameVec;

extern "C" char** func_002151B0(NameVec* v, int i);

typedef struct cElevatorGOBJ {
    char pad[0xF8];
    NameVec names;
} cElevatorGOBJ;

extern "C" void cElevatorGOBJ_SetFloorName(cElevatorGOBJ* self, int i, char* name) {
    char* p;
    char* q;
    char** slot;
    int n;
    char*** pd;
    if (i >= 0 && i < self->names.count) {
        pd = &self->names.data;
        if ((*pd)[i]) {
            p = *func_002151B0(&self->names, i);
            AllocGuard g;
            Mem_Free(0, p, D_004A4550, 0x697);
        }
        slot = &(*pd)[i];
        n = strlen(name) + 1;
        {
            AllocGuard g;
            q = (char*)Mem_Alloc(0, n, D_004A4550, 0x699);
        }
        *slot = q;
        String_Copy((*pd)[i], name);
    }
}
