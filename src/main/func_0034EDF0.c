#pragma cplusplus on
#include "types.h"

enum { MODE_0, MODE_1, MODE_2 };

typedef struct { int id; char pad4[4]; unsigned char state; char pad9[0x1C - 9]; } EEDF0;

struct LEDF0 {
    int a0;
    int count;
    EEDF0* data;
    unsigned char aC;
    int size() const { return count; }
};

typedef struct { char pad0[0x48]; void* tbl; } OEDF0;

extern "C" char D_004FFB50[];
extern "C" char D_004BA9E8[];
extern "C" void func_00296F20(LEDF0* l);
extern "C" void func_00299270(LEDF0* l, int flags);
extern "C" void* Agent_GetSelected(void* list, int idx);
extern "C" void func_00333260(void* ag, int a, int b, LEDF0* l);
extern "C" int Loc_LookupText(const char* key);
extern "C" void func_00421290(void* t, int id, int i, int mode);

extern "C" void func_0034EDF0(OEDF0* self)
{
    void* ag = Agent_GetSelected(D_004FFB50, -1);
    LEDF0 l;
    int text;
    int i;
    func_00296F20(&l);
    l.aC = 1;
    func_00333260(ag, 4, 0, &l);
    text = Loc_LookupText(D_004BA9E8);
    for (i = 0; i < l.size(); i++) {
        EEDF0* e = (EEDF0*)((int)l.data + i * sizeof(EEDF0));
        int id = text;
        int mode;
        if (e->state == 0) {
            mode = MODE_2;
        } else {
            id = e->id;
            mode = e->state == 2 ? MODE_0 : MODE_1;
        }
        func_00421290(self->tbl, id, i, mode);
    }
    func_00299270(&l, 0);
}
