#include "types.h"
typedef struct { char pad[0xC]; int id; } Who_F240;
typedef struct { Who_F240* who; int id; float val; int z; unsigned char b; } Ev_F240;
typedef struct { char pad[0x160]; int limit; char pad164[2]; unsigned char flag; char pad167[0x1B8 - 0x167]; char* list; } S_F240;
void std_list_deleter_cLookAtListItem_insert(void* out, void* list, void* pos, Ev_F240* e);
void NpcLook_AddPoint(S_F240* self, Who_F240* who, int t, float val)
{
    if (t >= self->limit) {
        int m1;
        char out[4];
        void* pos;
        Ev_F240 e;
        int* p;
        char* list;
        *(&e.id) = -2;
        e.who = who;
        if (who) p = &who->id; else { m1 = -1; p = &m1; }
        e.id = *p;
        e.val = val;
        e.b = 0;
        e.z = 0;
        list = self->list;
        if (list) {
            pos = list + 4;
            std_list_deleter_cLookAtListItem_insert(out, list, &pos, &e);
        }
        self->flag = 1;
    }
}