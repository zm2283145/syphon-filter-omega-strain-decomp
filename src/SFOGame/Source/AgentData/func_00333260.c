#pragma cplusplus on
#include "types.h"
/* cAgentData_GetRequirements: fills `out` with the award items of group `idx` of award type
 * `type`: for type 4 the shared item table entries (with the group's states), otherwise one
 * item per element built from its localisation key; type 4 also appends the closing item once
 * the agent's award element completes. */
struct Item { char* text; void* name; char state; int a; int b; int c; int agent; };
struct IV { int a; int count; Item* data; };
struct Grp { int a; int b; int count; char* states; int pad; };
struct TEnt { int a; int b; char* names; int pad[3]; };
struct TType { int a; int b; TEnt* ents; int pad; };
struct AwardP { unsigned char done; };
struct AgentAw { char pad[0xAB0]; struct { Grp* grps; int pad[3]; } type[4]; AwardP* elem; };
extern "C" {
extern TType D_00532A70[];
extern Item* D_00532BB8;
extern int D_00532BB4;
extern void* D_00532AB8;
void func_00299500(IV* v);
void* nGlobalization_GetStringTag(void* name);
char* nGlobalization_GetString_charP(void* name);
int nGlobalization_GetStringIndex(int k);
int cAgentData_GetWpnIndex(int k);
void std_vector_imp_tRequirementInfo_insert(IV* v, Item* pos, int n, Item* val);
void cAgentData_UpdateAchievement(void* self, AwardP* p, void* q, int force);
void cAgentData_GetRequirements(AgentAw* a, unsigned char type, int idx, IV* out);
}
#pragma opt_strength_reduction off
static inline bool IsDone(AwardP* p) { bool r = false; if (p) r = p->done != 0; return r; }
extern "C" void cAgentData_GetRequirements(AgentAw* a, unsigned char type, int idx, IV* out)
{
    Grp* g;
    int i;
    g = &((AgentAw*)a)->type[type].grps[idx]; /* the cast gives retail's a+off add order */
    func_00299500(out);
    for (i = 0; i < g->count; i++) {
        Item item;
        Item* ip;
        if (type == 4) {
            ip = &D_00532BB8[i];
            ip->state = g->states[i];
        } else {
            void* name;
            int off = idx * sizeof(TEnt);
            char st = g->states[i];
            name = nGlobalization_GetStringTag(((TEnt*)((char*)D_00532A70[type].ents + off))->names + i);
            item.text = nGlobalization_GetString_charP(name);
            item.name = name;
            item.state = st;
            void* k = 0;
            item.agent = k ? cAgentData_GetWpnIndex(nGlobalization_GetStringIndex(0)) : -1;
            item.a = 0;
            item.b = 0;
            item.c = 0;
            ip = &item;
        }
        std_vector_imp_tRequirementInfo_insert(out, &out->data[out->count], 1, ip);
    }
    if (type == 4) {
        AwardP* p = a->elem;
        cAgentData_UpdateAchievement(a, p, D_00532AB8, 0);
        if (IsDone(p)) {
            Item* it = &D_00532BB8[D_00532BB4 - 1];
            it->state = 2;
            std_vector_imp_tRequirementInfo_insert(out, &out->data[out->count], 1, it);
        }
    }
}
