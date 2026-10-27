#include "types.h"
typedef struct { int id; int f4; int f8; char name[0x18]; int f24; int f28; } E44EDC0;
typedef struct { int pad0; int count; } L44EDC0;
typedef struct {
    char p0[0x8C]; char l8C[0x1C]; char lA8[0x1C]; char lC4[0x1C]; char lE0[0x38];
    L44EDC0 list; char p120[0x22C4]; void* l23E4; void* l23E8; char p23EC[4]; void* l23F0; void* l23F4;
} S44EDC0;
extern int Libc_Memcmp(void*, void*, int);
extern int SFOLobby_GetMillisecs(void);
extern void SFOLobby_RefreshGameInfo(S44EDC0*, void*, E44EDC0*);
extern E44EDC0* SFOLobbyList_GetSlot(L44EDC0*, int);
extern void SFOLobbyList_Append(L44EDC0*, E44EDC0*);
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
        e = SFOLobbyList_GetSlot(list, i);
        if (id == e->id)
            return e;
    }
    return 0;
}

void SFOLobby_RefreshGameData(S44EDC0* s, int id, int a2, int a3, int a4, void* name)
{
    E44EDC0* e;
    unsigned char changed;
    E44EDC0 tmp;

    if (name && id) {
    e = Find44EDC0(&s->list, id);
    changed = 0;
    if (e) {
        if (e->f4 != a2 || e->f8 != a3 || e->f24 != a4 || Libc_Memcmp(e->name, name, 0x18) != 0) {
            e->f24 = a4;
            e->f4 = a2;
            changed = 1;
            e->f8 = a3;
            e->f28 = SFOLobby_GetMillisecs();
            memcpy(e->name, name, 0x18);
        }
    } else {
        memset(&tmp, 0, sizeof(tmp));
        tmp.f24 = a4;
        tmp.id = id;
        tmp.f4 = a2;
        tmp.f8 = a3;
        tmp.f28 = SFOLobby_GetMillisecs();
        memcpy(tmp.name, name, 0x18);
        SFOLobbyList_Append(&s->list, &tmp);
        e = &tmp;
        changed = 1;
    }
    if (changed) {
        SFOLobby_RefreshGameInfo(s, s->lC4, e);
        SFOLobby_RefreshGameInfo(s, s->l8C, e);
        SFOLobby_RefreshGameInfo(s, s->lA8, e);
        SFOLobby_RefreshGameInfo(s, s->lC4, e);
        SFOLobby_RefreshGameInfo(s, s->lE0, e);
        SFOLobby_RefreshGameInfo(s, s->l23F0, e);
        SFOLobby_RefreshGameInfo(s, s->l23F4, e);
        SFOLobby_RefreshGameInfo(s, s->l23E4, e);
        SFOLobby_RefreshGameInfo(s, s->l23E8, e);
    }
    }
}



