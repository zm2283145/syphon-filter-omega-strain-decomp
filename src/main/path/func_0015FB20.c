#include "types.h"
typedef struct {
    char pad[0x4C]; int node; int altNode; int altArg; char pad58[4]; int t0arg;
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char rest : 5;
    char pad61[0x70 - 0x61]; int a1arg; int stackArg;
} Route_e1;
extern char D_004FFB50[];
extern char g_NpcRouteMgr[];
extern void* Service_Lookup(void*, void*);
extern int NpcRoute_Request(void*, int, int, int, int, int, int, int, int);
unsigned char NpcRoute_RequestToNode(Route_e1* self, int arg)
{
    void* svc = Service_Lookup(D_004FFB50, g_NpcRouteMgr);
    int node = self->node;
    int extra = -1;
    if (self->b1 || self->b2) {
        if (node < 0) {
            node = self->altNode;
            extra = self->altArg;
        }
    }
    return NpcRoute_Request(svc, self->a1arg, node, extra, self->t0arg, arg, -1, 0, self->stackArg);
}