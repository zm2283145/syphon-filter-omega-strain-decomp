/*
 * Libs/SFOLib/Source/particle: 5 files, 003A3550-003A3670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A3550 */
#pragma push /* merge_units */
#include "types.h"
#include "iter_return_copy.h"

/* Return the end iterator. */
DEFINE_ITER_END(std_list_cParticleDefinitionPtr_end_void)
static inline void merge_flush_func_003A3550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3550 */

/* merge_units: begin func_003A3580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Small container helpers.
 */


Word* cConstLListIterator_cParticleDefinitionPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003A3580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3580 */

/* merge_units: begin func_003A3590 */
#pragma push /* merge_units */
/* Return the begin iterator. */
DEFINE_ITER_BEGIN(std_list_cParticleDefinitionPtr_begin_void)
static inline void merge_flush_func_003A3590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3590 */

/* merge_units: begin func_003A35C0 */
#pragma push /* merge_units */
#pragma opt_propagation off

/* Look up a resource by its lower-cased short name (up to 16 chars, stops at '.'). */
typedef struct { __int128 q; } Name_3A35C0;
extern Name_3A35C0 D_0053BAB0;
extern char Libc_Tolower(char c);
extern void GetEffectID__15cParticleSystemCFRC1(void* self, char* name);

void cParticleSystem_GetEffectID(void* self, const char* s)
{
    Name_3A35C0* name = &D_0053BAB0;
    unsigned int i;
    char* o;
    int c;
    name->q = 0;
    for (i = 0, o = (char*)name; i < 16 && (c = s[i]) != 0 && c != '.'; i++)
        *o++ = Libc_Tolower(c);
    GetEffectID__15cParticleSystemCFRC1(self, (char*)name);
}
#pragma opt_propagation reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A35C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A35C0 */

/* merge_units: begin func_003A3670 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
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
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(PIt* out, PList* l, PIt* first, PIt* last);
void cTexMan_RemoveTexture(int a, int b, int c);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
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
        cTexMan_RemoveTexture(g_TextureMgr, d->tex, 0);
        {
            AllocGuard g;
            d->Destroy(-1);
            cMemMan_Deallocate(0, d, D_004BC5D0, 0x4A7);
        }
        it.n = it.n->next;
    }
    PIt r;
    PIt first;
    PIt last;
    last.n = &lib->defs.header;
    first.n = lib->defs.header.next;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, &lib->defs, &first, &last);
    int i;
    for (i = 0; i < 4; i++) {
        PBuf* s = &D_0053B560[i];
        void* p = s->p;
        if (p) {
            {
                AllocGuard g2;
                cMemMan_Deallocate(0, p, D_004BC5D0, 0xD65);
            }
            s->n = 0;
            s->p = 0;
        }
    }
}
static inline void merge_flush_func_003A3670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3670 */
