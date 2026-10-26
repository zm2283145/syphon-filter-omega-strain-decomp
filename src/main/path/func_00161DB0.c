#include "types.h"
/* N5c route scoring walk: step along the node list until a scored node or a target is found */
typedef struct Pt1RwNode {
    char pad0[0x10];
    int a;
    int b;
    int c;
    int d;
} Pt1RwNode;
typedef struct Pt1RwSelf {
    char pad0[0x10];
    char list[0x8];
    Pt1RwNode* cur;
    char pad1C[0x2C - 0x1C];
    int active;
    char pad30[0x468 - 0x30];
    int mask;
    unsigned char mode;
    char pad46D[0x474 - 0x46D];
    unsigned char status;
    char pad475[3];
    int target;
    int target2;
    unsigned char reverse;
    unsigned char retry;
} Pt1RwSelf;
extern void cNodeRequest_SetNodeLOSResultForRestOfList(Pt1RwSelf* s, int id, int flag);
extern void cNodeRequest_SetCompanionNodeLOSResultForRestOfList(Pt1RwSelf* s, int id, int flag);
extern Pt1RwNode* NpcNodeSearch_PopFront(void* list, Pt1RwNode* n);
extern void NpcRoute_RequestLosChecks(Pt1RwSelf* s, int id, int mask);

void NpcRoute_HandleLosResult(Pt1RwSelf* s, unsigned char* flag)
{
    Pt1RwNode* cur = s->cur;
    int found = 0;
    if (!s->reverse)
        cNodeRequest_SetNodeLOSResultForRestOfList(s, cur->a, !*flag);
    else
        cNodeRequest_SetCompanionNodeLOSResultForRestOfList(s, cur->b, !*flag);
    do {
        Pt1RwNode* n = s->cur;
        if (n->b < 0) {
            if (n->c == (s->mode != 2)) {
                s->target = n->a;
                s->target2 = -1;
                s->status = 2;
            }
            n = NpcNodeSearch_PopFront(s->list, n);
        } else if (!s->reverse) {
            if (n->c == (s->mode != 2))
                s->reverse = 1;
            else
                n = NpcNodeSearch_PopFront(s->list, n);
        } else {
            if (n->d != (s->mode != 2)) {
                s->target = n->a;
                s->target2 = n->b;
                s->status = 2;
            }
            n = NpcNodeSearch_PopFront(s->list, n);
            s->reverse = 0;
        }
        if (s->reverse) {
            if (n->d < 0) {
                NpcRoute_RequestLosChecks(s, n->b, ~s->mask);
                found = 1;
            }
        } else if ((s->target < 0 || s->retry) && s->active && s->cur->c < 0) {
            NpcRoute_RequestLosChecks(s, s->cur->a, s->mask);
            found = 1;
        }
    } while (s->status != 2 && !found && s->active);
}