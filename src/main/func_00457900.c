#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiWidget_ctor(void*);
void func_0036E5D0(void*);
int* func_0012F2B0(void*);
int* func_0015AC90(int*, int);
extern char D_004C1CE0[];
extern void* const D_004E1290[];
}
typedef struct {
    int type;
    char pad04[0xC];
    __int128 name;
    void* voice;
    int voiceId;
    char pad28[8];
    int x30;
    int x34;
    int x38;
    char pad3C[0xC];
    char a[0x9C];
    char b[0x9C];
    int x180;
    short x184;
    char x186;
} SndReq;
typedef struct {
    void* vt;
    char pad[0x4C];
    SndReq r;
} W57900;
static inline void SndReq_Ctor(SndReq* p, void* voice) {
    int tmp;
    p->voiceId = -2;
    p->voice = 0;
    func_0036E5D0(p->a);
    func_0036E5D0(p->b);
    p->type = -1;
    p->name = -1;
    p->voice = voice;
    int* r = voice ? func_0012F2B0(voice) : func_0015AC90(&tmp, -1);
    p->voiceId = *r;
    p->x30 = 0;
    p->x34 = 0;
    p->x38 = 0;
    p->x184 = -1;
    p->x180 = 0;
    p->x186 = 0;
}
#pragma opt_dead_code off
extern "C" W57900* func_00457900(void) {
    W57900* p;
    {
        AllocGuard g;
        p = (W57900*)Mem_Alloc(0, 0x1E0, D_004C1CE0, 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vt = (void*)D_004E1290;
        SndReq* r = &p->r;
        SndReq_Ctor(r, 0);
    }
    return p;
}


