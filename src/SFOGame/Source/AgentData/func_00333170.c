/*
 * cAgentData_FindRequirement: finds the range definition of table D_00532A70[type] that
 * contains the localised key and returns the matching byte of the agent's
 * per-type record (used by cAgentData_UnlockRequirement to set a flag byte).
 */

/* Range definition (24 bytes). */
typedef struct RangeDef {
    int unk00;
    int unk04;
    int start;
    int len;
    int unk10;
    int unk14;
} RangeDef;

/* Global definition table per type (16 bytes, PtrVec layout). */
typedef struct RangeTable {
    int unk00;
    int count;
    RangeDef* data;
    int unk0C;
} RangeTable;

/* Agent-side record (20 bytes). */
typedef struct RangeRec {
    char pad00[0xC];
    unsigned char* bytes;
    int unk10;
} RangeRec;

typedef struct RangeRecVec {
    int unk00;
    int count;
    RangeRec* data;
    int unk0C;
} RangeRecVec;

typedef struct AgentRanges {
    char pad00[0xAA8];
    RangeRecVec recs[5];
} AgentRanges;

extern RangeTable D_00532A70[5];
extern int nGlobalization_GetStringIndex(const char* key);

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
unsigned char* cAgentData_FindRequirement(AgentRanges* self, unsigned char type, const char* key) {
    int k = nGlobalization_GetStringIndex(key);
    int i;
    int s;
    int l;
    RangeTable* t;
    RangeDef* defs;
    int* pc;
    i = 0;
    if (i < D_00532A70[type].count) {
        t = &D_00532A70[type];
        defs = t->data;
        pc = &t->count;
        do {
            RangeDef* d = defs + i;
            s = d->start;
            l = d->len;
            if (k >= s && k < s + l) {
                RangeRecVec* rv = &self->recs[type];
                return (*(RangeRec(*)[])rv->data)[i].bytes + (k - s);
            }
            i++;
        } while (i < *pc);
    }
    return 0;
}
