#include "types.h"
typedef struct { char pad[0x48]; } Tmp;
typedef struct { char pad[4]; char name[0x50]; int count1; int count2; } Def;
typedef struct { char pad[0x24]; Def* def; char p2[0x50]; char list1[0x10]; char list2[0x18]; char sub[1]; } S;
typedef struct { int a, b; } Pair;
extern void RootCollection_InitFromModel(void*, void*);
extern void AnimChannel_Construct(Tmp*);
extern void AnimChannels_ClearCount(Tmp*, float);
extern void ChannelVector_Resize(void*, int, Tmp*);
extern void func_001AEFE0(Tmp*, int);
extern void func_001BE020(void*, int, Pair*);
/* Binds a definition: copies its name and fills both lists with default entries. */
void func_003634D0(S* s, Def* def)
{
    Tmp tmp;
    Pair p;
    s->def = def;
    RootCollection_InitFromModel(s->sub, def->name);
    AnimChannel_Construct(&tmp);
    AnimChannels_ClearCount(&tmp, 0.0f);
    ChannelVector_Resize(s->list1, def->count1, &tmp);
    func_001AEFE0(&tmp, -1);
    p.a = 0;
    p.b = 0;
    func_001BE020(s->list2, def->count2, &p);
}
