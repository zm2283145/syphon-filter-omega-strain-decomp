#ifndef AGENT_RECORD_HAS_H
#define AGENT_RECORD_HAS_H

/*
 * cAgentData_Has* lookups: find the localised key in a global definition
 * table (count/table globals, 24-byte entries), refresh the matching
 * 20-byte record of the agent (record array pointer at recsOffset) with
 * func_00335350(self, rec, def, 0), and return the record's done flag.
 * Wrap the macro in #pragma opt_strength_reduction off / reset.
 * C++ only (#pragma cplusplus on before including).
 */
struct AgentRecordDef { int id; int pad[5]; };
struct AgentRecord { unsigned char done; char pad[19]; };

extern "C" {
int Loc_FindKeyThunk(const char* key);
void func_00335350(void* self, AgentRecord* r, AgentRecordDef* e, int f);
}

#define DEFINE_AGENT_RECORD_HAS(name, countSym, tableSym, recsOffset)          \
    extern "C" int countSym;                                                  \
    extern "C" AgentRecordDef* tableSym;                                      \
    static inline AgentRecord* name##_get(char* self, int k)                  \
    {                                                                         \
        int i;                                                                \
        for (i = 0; i < countSym; i++) {                                      \
            AgentRecordDef* e = &tableSym[i];                                 \
            if (e->id == k) {                                                 \
                AgentRecord* r = &(*(AgentRecord**)(self + (recsOffset)))[i]; \
                func_00335350(self, r, e, 0);                                 \
                return r;                                                     \
            }                                                                 \
        }                                                                     \
        return 0;                                                             \
    }                                                                         \
    extern "C" bool name(char* self, const char* key)                         \
    {                                                                         \
        AgentRecord* r = name##_get(self, Loc_FindKeyThunk(key));             \
        return (r ? (int)(r->done != 0) : 0) != 0;                            \
    }

#endif /* AGENT_RECORD_HAS_H */