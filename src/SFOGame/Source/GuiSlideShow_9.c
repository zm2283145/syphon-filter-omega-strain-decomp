/*
 * SFOGame/Source/GuiSlideShow: 7 files, 00328570-003287B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00328570 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

DEFINE_DIRECT_BASE_DTOR(std_vector_imp_Slide_dtor, std_vector_deleter_Slide_dtor)
static inline void merge_flush_func_00328570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328570 */

/* merge_units: begin func_003285D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* std_vector_imp_Slide_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_003285D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003285D0 */

/* merge_units: begin func_003285F0 */
#pragma push /* merge_units */
typedef struct { char d[0x20]; } E285F0;
typedef struct { char pad[0x4C]; int count; E285F0* items; } T285F0;E285F0* GuiSlideShow_GetSection(T285F0* self, int i)
{
    if (i < 0 || self->count <= i) return 0;
    return &self->items[i];
}
static inline void merge_flush_func_003285F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003285F0 */

/* merge_units: begin func_00328630 */
#pragma push /* merge_units */
#include "loose02_types.h"

extern void std_vector_deleter_Section_clear(void* rec);

void GuiSlideShow_Clear(Obj328630* self) {
    std_vector_deleter_Section_clear(self->unk48);
    self->unk58 = -1;
}
static inline void merge_flush_func_00328630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328630 */

/* merge_units: begin func_00328660 */
#pragma push /* merge_units */
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { int pad[3]; int id; } Voice_328660;
typedef struct {
    char base[0x48];
    char a[0xC];
    unsigned char a0C;
    char pad55[3];
    int x58;
    char pad5C[0x10];
    int x6C;
    int x70;
    int x74;
    int x78;
    int x7C;
    int x80;
    char pad84[0xC];
    SoundRequest req;
} Obj_328660;
extern char D_004DE710[];
extern void GuiWidget_ctor(void* self);
extern void std_vector_Section_ctor(void* p);
extern void std_vector_deleter_Section_clear(void* p);
static inline void Req_Init_328660(SoundRequest* p, int type, __int128 name, Voice_328660* voice, int x180) {
    int tmp; int* r = &tmp;
    p->type = type;
    *(__int128*)p->name = name;
    p->voice = voice;
    if (voice) r = &voice->id; else tmp = -1;
    p->voiceId = *r;
    p->x30 = 0; p->x34 = 0; p->x38 = 0;
    p->x184 = -1;
    p->x180 = x180;
}
Obj_328660* GuiSlideShow_ctor(Obj_328660* o)
{
    SoundRequest* p;
    char* pa;
    GuiWidget_ctor(o);
    *(char**)o = D_004DE710;
    pa = o->a;
    std_vector_Section_ctor(pa);
    pa[0xC] = 1;
    o->x6C = 0;
    o->x70 = 0;
    o->x74 = 0;
    o->x78 = 0;
    o->x7C = 0;
    o->x80 = 0;
    p = &o->req;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init_328660(p, -1, -1, 0, 0);
    p->x186 = 0;
    std_vector_deleter_Section_clear(pa);
    o->x58 = -1;
    return o;
}
static inline void merge_flush_func_00328660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328660 */

/* merge_units: begin func_00328740 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nested_null_dtor.h"

DEFINE_NESTED_NULL_DTOR3(cArray_Section_dtor, std_vector_deleter_Section_dtor)
static inline void merge_flush_func_00328740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328740 */

/* merge_units: begin func_003287B0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_NESTED_NULL_DTOR2(std_vector_Section_dtor, std_vector_deleter_Section_dtor)
static inline void merge_flush_func_003287B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003287B0 */
