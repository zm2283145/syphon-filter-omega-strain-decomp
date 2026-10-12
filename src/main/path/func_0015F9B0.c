#include "types.h"
typedef struct CxPathNode { char pad[0x7C]; int region; } CxPathNode;
typedef struct CxPathFollower { char pad[0x5C]; int current; char gap60[0x10]; void* actor; void* buffer; } CxPathFollower;
extern char D_004FFB50[];
extern char g_NpcRouteMgr[];
extern void* Service_Lookup(void*, void*);
extern CxPathNode* NpcPath_GetNode(int);
extern int NpcRoute_Request(void*,void*,int,int,int,int,int,int,long long);
int func_0015F9B0(CxPathFollower* self,int start,int destination,int useRegion) {
    int region=-1;
    void* manager=Service_Lookup(D_004FFB50,g_NpcRouteMgr);
    if(useRegion && destination>=0) region=NpcPath_GetNode(destination)->region;
    return NpcRoute_Request(manager,self->actor,start,-1,self->current,destination,region,useRegion,(long long)(int)self->buffer);
}

