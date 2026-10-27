#include "types.h"
typedef struct { int w[3]; } Ent34F670;
typedef struct { int w[4]; } Sub34F670;
typedef struct { int base[4]; Ent34F670 ents[5]; Sub34F670 sub; } T34F670;
typedef struct { char pad[0x70]; int v70[3]; } S34F670;
extern void std_vector_deleter_MissionStats_clear(void* v);
extern void cString_ctor_void(T34F670* t);
extern void MissionStats_StatData_ctor(Ent34F670* e);
extern void cArray_StatsRequirement_ctor(Sub34F670* s);
extern void std_vector_imp_MissionStats_resize(void* v, int n, T34F670* value);
extern void std_vector_deleter_StatsRequirement_dtor(Sub34F670* s, int flags);
extern void String_Dtor(T34F670* t, int flags);
void GuiMissionStatistics_SetupMissionStats(S34F670* o)
{
    T34F670 t;
    T34F670* tp;
    Ent34F670* p;
    Sub34F670* m;
    std_vector_deleter_MissionStats_clear(o->v70);
    tp = &t;
    cString_ctor_void(tp);
    p = tp->ents;
    do {
        MissionStats_StatData_ctor(p);
        p++;
    } while (p != (Ent34F670*)&tp->sub);
    cArray_StatsRequirement_ctor(&tp->sub);
    std_vector_imp_MissionStats_resize(o->v70, 0x11, &t);
    m = &t.sub;
    if (m) {
        if (m) {
            if (m) std_vector_deleter_StatsRequirement_dtor(m, 0);
        }
    }
    String_Dtor(&t, 0);
}

