#include "types.h"
typedef struct { int id; int f4; int f8; char name[0x18]; int f24; int f28; } E44EDC0;
typedef struct { int pad0; int count; } L44EDC0;
typedef struct {
    char p0[0x8C]; char l8C[0x1C]; char lA8[0x1C]; char lC4[0x1C]; char lE0[0x38];
    L44EDC0 list; char p120[0x22C4]; void* l23E4; void* l23E8; char p23EC[4]; void* l23F0; void* l23F4;
} S44EDC0;
extern int Name_Compare48(void*, void*, int);
extern int Lobby_GetTime(void);
extern void func_0044EFF0(S44EDC0*, void*, E44EDC0*);
extern E44EDC0* LobbyArray_At(L44EDC0*, int);
extern void LobbyArray_Append(L44EDC0*, E44EDC0*);
extern void* memcpy(void*, const void*, int);
extern void* memset(void*, int, int);

static inline E44EDC0* Find44EDC0(L44EDC0* list, int id)
{
    int n;
    int i;
    E44EDC0* e;
    if (id == 0)
        return 0;
    n = list->count;
    for (i = 0; i < n; i++) {
        e = LobbyArray_At(list, i);
        if (id == e->id)
            return e;
    }
    return 0;
}

void func_0044EDC0(S44EDC0* s, int id, int a2, int a3, int a4, void* name)
{
    E44EDC0* e;
    unsigned char changed;
    E44EDC0 tmp;

    if (name && id) {
    e = Find44EDC0(&s->list, id);
    changed = 0;
    if (e) {
        if (e->f4 != a2 || e->f8 != a3 || e->f24 != a4 || Name_Compare48(e->name, name, 0x18) != 0) {
            e->f24 = a4;
            e->f4 = a2;
            changed = 1;
            e->f8 = a3;
            e->f28 = Lobby_GetTime();
            memcpy(e->name, name, 0x18);
        }
    } else {
        memset(&tmp, 0, sizeof(tmp));
        tmp.f24 = a4;
        tmp.id = id;
        tmp.f4 = a2;
        tmp.f8 = a3;
        tmp.f28 = Lobby_GetTime();
        memcpy(tmp.name, name, 0x18);
        LobbyArray_Append(&s->list, &tmp);
        e = &tmp;
        changed = 1;
    }
    if (changed) {
        func_0044EFF0(s, s->lC4, e);
        func_0044EFF0(s, s->l8C, e);
        func_0044EFF0(s, s->lA8, e);
        func_0044EFF0(s, s->lC4, e);
        func_0044EFF0(s, s->lE0, e);
        func_0044EFF0(s, s->l23F0, e);
        func_0044EFF0(s, s->l23F4, e);
        func_0044EFF0(s, s->l23E4, e);
        func_0044EFF0(s, s->l23E8, e);
    }
    }
}



