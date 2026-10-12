#include "types.h"
typedef struct CxRouteBits { unsigned long long zero:1; unsigned long long first:1; unsigned long long second:1; } CxRouteBits;
typedef struct CxPathFollower2 {
    char pad[0x4C]; int start; int fallback; int previous; int unk58; int current;
    CxRouteBits flags;
    char pad64[12];
    void* actor; void* buffer;
} CxPathFollower2;
extern char D_004FFB50[];
extern char g_NpcRouteMgr[];
extern void* Service_Lookup(void*,void*);
extern int NpcRoute_Request(void*,void*,int,int,int,int,int,int,long long);
unsigned char func_0015FA70(CxPathFollower2* self,int kind,int region) {
    void* manager=Service_Lookup(D_004FFB50,g_NpcRouteMgr);
    int start=self->start;
    int previous=-1;
    if(self->flags.first || self->flags.second) {
        if(start<0) {start=self->fallback;previous=self->previous;}
    }
    return NpcRoute_Request(manager,self->actor,start,previous,self->current,-1,region,kind,(long long)(int)self->buffer);
}

