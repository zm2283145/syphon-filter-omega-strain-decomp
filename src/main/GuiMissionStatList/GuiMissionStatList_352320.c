/*
 * main/GuiMissionStatList: 3 files, 00352320-00352460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00352320 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int std_vector_pod_StatType_ctor(Member3527A0* dst, Member3527A0* src);

/* Rec352320 copy constructor. */
Rec352320* MissionStats_StatsRequirement_ctor(Rec352320* self, Rec352320* src) {
    Member352320* body;

    self->unk00 = src->unk00;
    body = &self->unk04;
    std_vector_pod_StatType_ctor(&body->unk00, &src->unk04.unk00);
    body->unk0C = src->unk04.unk0C;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00352320 */

/* merge_units: begin func_00352380 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "owned_buffer8_dtor.h"

DEFINE_OWNED_BUFFER8_DTOR(std_vector_pod_StatType_dtor, D_004BACB8)
#pragma pop /* merge_units */
/* merge_units: end func_00352380 */

/* merge_units: begin func_00352460 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct E2460 { int a; TStr s; unsigned char c; };
struct V2460 { unsigned int cap; unsigned int count; E2460* data; };
extern "C" {
extern char D_004BAC10[];
extern char D_004BAC88[];
extern char D_004BACC8[];
void std_vector_pod_StatType_opAssign(TStr* d, const TStr* s);
void MissionStats_StatsRequirement_dtor(E2460* p, int f);
void* Mem_PlacementNew(unsigned int size, void* p);
#if 0 /* merge_units */
void MissionStats_StatsRequirement_ctor(void* d, const E2460* s);
#endif /* merge_units */
#define MissionStats_StatsRequirement_ctor(a0, a1) ((void)MissionStats_StatsRequirement_ctor((Rec352320 *)(a0), (Rec352320 *)(a1))) /* merge_units */

void std_vector_deleter_StatsRequirement_clear(V2460* v);
void opDelete_StatsRequirementP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line);
}
static inline const unsigned int& Min2460(const unsigned int& a, const unsigned int& b) { return b < a ? b : a; }
static inline E2460* Alloc2460(unsigned int n) { AllocGuard g; return (E2460*)Mem_Alloc(0, n * sizeof(E2460), D_004BAC88, 0x5C); }

extern "C" void std_vector_imp_StatsRequirement_do_assign(V2460* v, const E2460* first, const E2460* last)
{
    unsigned int n = last - first;
    if (n <= v->cap) {
        const unsigned int& m = Min2460(n, v->count);
        E2460* p = v->data;
        E2460* e = p + m;
        for (; p < e; p++, first++) {
            p->a = first->a;
            std_vector_pod_StatType_opAssign(&p->s, &first->s);
            p->c = first->c;
        }
        if (n < v->count) {
            E2460* e2 = v->data + v->count;
            for (; p < e2; p++)
                MissionStats_StatsRequirement_dtor(p, -1);
            v->count = n;
        } else if (v->count < n) {
            for (; first != last; first++, p++) {
                void* m = Mem_PlacementNew(sizeof(E2460), p);
                if (m)
                    MissionStats_StatsRequirement_ctor(m, first);
                v->count++;
            }
        }
    } else {
        if (n > 0x4CCCCC) {
            Libc_Fprintf(D_00489738->stream, D_004BAC10);
            Libc_Abort();
        }
        std_vector_deleter_StatsRequirement_clear(v);
        if (v->data) {
            if (v->data)
                opDelete_StatsRequirementP_int_bool_charP_etc(v->data, 0, 0, D_004BACC8, 100);
            v->data = 0;
            v->cap = 0;
        }
        {
            E2460** pd = &v->data;
            *pd = Alloc2460(n);
        }
        v->cap = n;
        {
            E2460* p = v->data;
            for (; first != last; first++, p++) {
                void* m = Mem_PlacementNew(sizeof(E2460), p);
                if (m)
                    MissionStats_StatsRequirement_ctor(m, first);
                v->count++;
            }
        }
    }
}
#undef MissionStats_StatsRequirement_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00352460 */
