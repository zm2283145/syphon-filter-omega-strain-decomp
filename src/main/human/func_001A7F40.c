#include "types.h"
typedef struct { char pad[0x24]; unsigned int type; unsigned char sub; } Ev;
typedef struct { char pad[0xA0]; unsigned char bA0; } Inv;
typedef struct { char pad[0x320C]; char anim[0x33E4 - 0x320C]; unsigned char b33E4; unsigned char b33E5; char pad33E6[2]; unsigned char b33E8;
    char pad33E9[0x3524 - 0x33E9]; Inv* inv; } Act;
extern unsigned char AnimPriority_Helper3(void*, int);
extern void AnimPriority_Helper2(void*, int, int);
extern void AnimPriority_Helper1(void*);
extern void AnimPriority_Helper0(void*, int, int);
extern void Inventory_ReleaseItem(Inv*);

int Actor_HandleEmbeddedEvent(Act* a, Ev* e)
{
    switch (e->type) {
    case -1:
        break;
    case 0:
        switch (e->sub) case 4: case 5: {
            int r;
            char* p = a->anim;
            r = AnimPriority_Helper3(p + 0xC, 3);
            AnimPriority_Helper2(p + 4, 3, 0);
            AnimPriority_Helper1(p);
            AnimPriority_Helper0(p, 3, r);
        }
        break;
    case 1:
        switch (e->sub) case 4: case 5: a->inv->bA0 = 0;
        break;
    case 2:
        switch (e->sub) case 4: case 5: {
            Inventory_ReleaseItem(a->inv);
            a->b33E4 = 0;
        }
        break;
    case 3:
        switch (e->sub) case 4: case 5: a->b33E5 = 0;
        break;
    case 4:
        switch (e->sub) case 4: case 5: a->b33E8 = 0;
        break;
    default:
        return 0;
    }
    return 1;
}




