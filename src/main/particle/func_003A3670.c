#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "alloc_guard.h"
/* cParticleSystem_Clear: destroy every loaded particle definition (releasing its texture), empty the list, free the four shared buffers */
struct PDef { virtual void Destroy(int flags); char pad4[0x74 - 4]; int tex; };
typedef struct PNode { struct PNode* prev; struct PNode* next; PDef* d; } PNode;
union PItU { PNode* n; };
typedef struct { PNode* n; } PIt;
typedef struct { int pad; PNode header; } PList;
struct PLib { int pad0; PList defs; };
struct PBuf { void* p; int n; int pad[2]; };
extern "C" {
extern int g_TextureMgr;
extern PBuf D_0053B560[4];
extern char D_004BC5D0[];
void std_list_cParticleDefinitionPtr_begin_void_2(PIt* out, PList* l);
PIt* cLListIterator_cParticleDefinitionPtr_ctor(PIt* dst, PIt* src);
void std_list_cParticleDefinitionPtr_end_void_2(PIt* out, PList* l);
void ObjectList_EraseRange(PIt* out, PList* l, PIt* first, PIt* last);
void Tex_Release(int a, int b, int c);
void Mem_Free(int pool, void* p, char* file, int line);
void cParticleSystem_Clear(PLib* lib);
}
static inline void Begin_(PIt* out, PList* l) { PIt t; std_list_cParticleDefinitionPtr_begin_void_2(&t, l); cLListIterator_cParticleDefinitionPtr_ctor(out, &t); }
static inline void End_(PIt* out, PList* l) { PIt t; std_list_cParticleDefinitionPtr_end_void_2(&t, l); cLListIterator_cParticleDefinitionPtr_ctor(out, &t); }
void cParticleSystem_Clear(PLib* lib)
{
    PItU it;
    PIt b;
    PIt e;
    Begin_(&b, &lib->defs);
    it = *(PItU*)&b;
    while (End_(&e, &lib->defs), it.n != e.n) {
        PDef* d = it.n->d;
        Tex_Release(g_TextureMgr, d->tex, 0);
        {
            AllocGuard g;
            d->Destroy(-1);
            Mem_Free(0, d, D_004BC5D0, 0x4A7);
        }
        it.n = it.n->next;
    }
    PIt r;
    PIt first;
    PIt last;
    last.n = &lib->defs.header;
    first.n = lib->defs.header.next;
    ObjectList_EraseRange(&r, &lib->defs, &first, &last);
    int i;
    for (i = 0; i < 4; i++) {
        PBuf* s = &D_0053B560[i];
        void* p = s->p;
        if (p) {
            {
                AllocGuard g2;
                Mem_Free(0, p, D_004BC5D0, 0xD65);
            }
            s->n = 0;
            s->p = 0;
        }
    }
}
