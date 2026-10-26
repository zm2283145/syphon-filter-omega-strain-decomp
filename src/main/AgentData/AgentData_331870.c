/*
 * main/AgentData: range (3 files, 00331870-00332610)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
int strcmp(const void *, const void *);

/* merge_units: begin func_00331870 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0;
static inline void W16_00331870(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00331870(int v) { W16_00331870((unsigned short)v); W16_00331870(v >> 16); }
static inline void WF_00331870(float f) { W32_00331870(*(int*)&f); }
typedef struct { int v; char pad[0x1C]; } E_00331870;
typedef struct { char pad[8]; int a[31]; int b[17]; int n; E_00331870* e; char padd0[4]; float f; char padd8[0x8AC - 0xD8]; char sub[0xB74 - 0x8AC]; unsigned char c; } S_00331870;
extern int cBitArray_224_NumChunks(S_00331870* p);
extern void cNetMsg_PutString(void* p);
void cAgentData_NetPack(S_00331870* p) {
    int i;
    int n = cBitArray_224_NumChunks(p);
    for (i = 0; i < n; i++) W32_00331870(p->b[i]);
    { int j; for (j = 0; j < 31; j++) W32_00331870(p->a[j]); }
    { int j = 0; while (j < p->n) { int k = j++; W32_00331870(p->e[k].v); } }
    cNetMsg_PutString(p->sub);
    WF_00331870(p->f);
    *D_005061D0++ = p->c;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00331870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00331870 */

/* merge_units: begin func_00332500 */
#pragma push /* merge_units */
typedef struct { int cap; int count; int* data; } PtrVec2500;
typedef struct { char pad0[0xB58]; char awards[4]; int numAwards; char pad1[0xB68 - 0xB60]; unsigned char reduced; char pad2[3]; int best; } AgentData2500;
extern int AgentData_TotalPoints(AgentData2500* a);
extern void AgentData_AppendLockedParts(PtrVec2500* v, int pts);
extern int* std_vector_charPtr_opIndex_uint_2(void* vec, int i);
extern void PtrVector_Resize(PtrVec2500* v, int n, int* fill);
#pragma opt_strength_reduction off
void AgentData_FilterAwards(AgentData2500* a, PtrVec2500* list) {
    int i;
    AgentData_AppendLockedParts(list, AgentData_TotalPoints(a));
    for (i = 0; i < a->numAwards; i++) {
        int j;
        int last;
        int* key;
        int fill;
        key = std_vector_charPtr_opIndex_uint_2(a->awards, i);
        last = list->count - 1;
        for (j = 0; last >= j; j++) {
            int* slot = &list->data[j];
            if (*slot == *key) {
                *slot = list->data[last];
                last--;
            }
        }
        fill = 0;
        PtrVector_Resize(list, last + 1, &fill);
    }
    {
        int n = list->count;
        if (a->best < 0) {
            a->best = n;
        } else if (n < a->best) {
            a->reduced = 1;
            a->best = n;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00332500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00332500 */

/* merge_units: begin func_00332610 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct PartDef {
    char name[20];
} PartDef;

typedef struct PartDefVec {
    int unk00;
    int count;
    PartDef* data;
} PartDefVec;

typedef struct PartVec {
    int unk00;
    int count;
    PartDef** data;
} PartVec;

typedef struct PartIt {
    PartDef** p;
} PartIt;

typedef struct Agent332610 {
    char pad[0xB58];
    PartVec parts;
} Agent332610;

extern PartDefVec D_00532B30;
extern char D_004B9290[];
extern void std_vector_charPtr_end(PartIt* out, PartVec* v);
extern PartIt* cArray_charPtr_Iterator_ctor_wrapiteratorR(PartIt* dst, PartIt* src);
extern void cArray_charPtr_Begin(PartIt* out, PartVec* v);
extern void cArray_charPtr_End(PartIt* out, PartVec* v);
extern int cArray_charPtr_Iterator_opNe(PartIt* a, PartIt* b);
extern PartDef** cArray_charPtr_Iterator_opMul(PartIt* it);
extern PartIt* cArray_charPtr_Iterator_opInc(PartIt* it);
extern PartIt* cArray_charPtr_Iterator_ctor_IteratorR(PartIt* dst, PartIt* src);
extern void PtrVec_PushBack_330280(PartVec* v, PartDef** value);

void cAgentData_UnlockPart(Agent332610* self, const char* name)
{
    PartDef* found;
    PartIt res;
    PartIt end;
    PartIt endTmp;
    PartIt first;
    PartIt last;
    char buf[0x88];
    int i;
    PartIt* rp;
    found = 0;
    for (i = 0; found == 0 && i < D_00532B30.count; i++) {
        if (strcmp(name, D_00532B30.data[i].name) == 0) {
            found = &D_00532B30.data[i];
        }
    }
    if (found == 0) {
        sprintf(buf, D_004B9290, name);
        return;
    }
    std_vector_charPtr_end(&endTmp, &self->parts);
    cArray_charPtr_Iterator_ctor_wrapiteratorR(&end, &endTmp);
    cArray_charPtr_Begin(&first, &self->parts);
    cArray_charPtr_End(&last, &self->parts);
    while (cArray_charPtr_Iterator_opNe(&first, &last)) {
        if (*cArray_charPtr_Iterator_opMul(&first) == found) {
            cArray_charPtr_Iterator_ctor_IteratorR(&res, &first);
            rp = &res;
            goto done;
        }
        cArray_charPtr_Iterator_opInc(&first);
    }
    cArray_charPtr_Iterator_ctor_IteratorR(&res, &last);
    rp = &res;
done:
    if (rp->p == end.p) {
        PtrVec_PushBack_330280(&self->parts, &found);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00332610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00332610 */
