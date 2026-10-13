#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "Objective_types.h"

extern "C" {
extern char D_004A5D88[];
void* Mem_Alloc(int pool, int size, char* file, int line);
cObjective* Objective_Ctor(void* self, int stage);
}

extern "C" int ObjMan_AddObjective(cObjectiveMan* m, int stage)
{
    if (stage == -1) {
        if (m->globalCount < 32) {
            cObjective* o;
            {
                AllocGuard guard;
                o = (cObjective*)Mem_Alloc(0, 0x8C, D_004A5D88, 0x363);
            }
            if (o)
                o = Objective_Ctor(o, stage);
            m->globalObjectives[m->globalCount] = o;
            m->globalCount++;
            o->id = m->nextId;
            m->nextId++;
            return m->nextId - 1;
        }
    } else {
        if (m->stageCounts[stage] < 32) {
            cObjective* o;
            {
                AllocGuard guard;
                o = (cObjective*)Mem_Alloc(0, 0x8C, D_004A5D88, 0x36E);
            }
            if (o)
                o = Objective_Ctor(o, stage);
            m->stageObjectives[stage][m->stageCounts[stage]] = o;
            m->stageCounts[stage]++;
            o->id = m->nextId;
            m->nextId++;
            return m->nextId - 1;
        }
    }
    return 0;
}

