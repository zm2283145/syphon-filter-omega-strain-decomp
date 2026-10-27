#include "types.h"
#define NULL 0
#pragma mpwc_relax on
typedef struct List44 {
    int unk0;
    int count;
} List44;
typedef struct Ent44 {
    int id;
    char pad4[0x20];
    int state;
    int time;
} Ent44;
typedef struct Obj44 {
    char pad0[0x39];
    unsigned char active;
    char pad3A[0x130 - 0x3A];
    int key;
} Obj44;
typedef struct Lobby44 {
    char pad0[0x118];
    List44 list;
    char pad120[0x2418 - 0x120];
    char name[1];
} Lobby44;
void Libc_Strcpy(char *, char *);
int SFOLobby_GetMillisecs(void);
Ent44 *SFOLobbyList_GetSlot(List44 *, int);
Obj44 *SFOLobby_FindAgentData(Lobby44 *, int);
void MediusGetGameInfo(char *, void *);
extern int D_00497860;
extern int D_00497878;
extern char D_004C0EF0;
extern int D_00585E50;
extern void SFOLobby_Callback_RefreshGameInfo(void);

typedef struct {
    char a[0x15];
    char b[0x13];
    int id;
} Msg44EBD0;

inline Ent44 *Find44(Lobby44 *l, int id) {
    int n = l->list.count;
    int j;
    Ent44 *e;
    for (j = 0; j < n; j++) {
        e = SFOLobbyList_GetSlot(&l->list, j);
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}

void SFOLobby_CollectGameInfo(Lobby44 *arg0, List44 *arg1) {
    Msg44EBD0 msg;
    int now;
    int i;
    Ent44 *e;
    Obj44 *obj;
    int st;
    int eid;
    Ent44 *found;
    int id;
    int n;
    int j;
    int age;

    if (arg1 == NULL || arg1->count == 0) {
        return;
    }
    now = SFOLobby_GetMillisecs();
    if (now - D_00585E50 < D_00497860) {
        return;
    }
    D_00585E50 = now;
    for (i = 0; i < arg1->count; i++) {
        e = SFOLobbyList_GetSlot(arg1, i);
        st = e->state;
        eid = e->id;
        if (st == 3) {
            continue;
        }
        if (st == 2) {
            continue;
        }
        obj = SFOLobby_FindAgentData(arg0, eid);
        if (obj == NULL || obj->active == 0) {
            continue;
        }
        id = obj->key;
        if (id == 0) {
            found = NULL;
        } else {
            found = Find44(arg0, id);
        }
        age = 0x270F;
        if (found != NULL) {
            age = now - found->time;
        }
        if (found == NULL || D_00497878 < age) {
            id = obj->key;
            if (id != 0) {
                Libc_Strcpy(msg.a, &D_004C0EF0);
                Libc_Strcpy(msg.b, arg0->name);
                msg.id = id;
                MediusGetGameInfo(msg.a, SFOLobby_Callback_RefreshGameInfo);
            }
        }
    }
}
