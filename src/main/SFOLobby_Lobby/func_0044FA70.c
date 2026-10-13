#pragma cplusplus on
#include "SFOLobby.h"
extern "C" {
int String_Copy(char *, char *);
int func_00128C68(char *, char *, ...);
void LobbyArray_SetRefreshing(LobbyArray *, int);
void LobbyArray_Copy(LobbyArray *, LobbyArray *);
int LobbyArray_Append(LobbyArray *, void *);
char *LobbyArray_At(LobbyArray *, int);
void LobbyArray_RemoveAt(LobbyArray *, int);
void LobbyArray_Clear(LobbyArray *);
int Lobby_GetTime(void);
void SFOLobby_CacheAccount(SFOLobby *, int, char *, int, LobbyPlayerInfo *);
void *memset(void *, int, int);
unsigned int strlen(char *);
extern char D_004C0F38[];
extern char D_004C0F50[];
extern SFOLobby *D_00585E60;
extern int D_00497938;
}

static inline bool IsNul(char c) { return !c; }

static inline void Grow(SFOLobby *lobby, int n)
{
    if (n != -1) {
        LobbyBuddyEntry tmp;
        memset(&tmp, 0, 0x50);
        while (lobby->listA8.count < n)
            LobbyArray_Append(&lobby->listA8, &tmp);
    }
}


typedef struct {
    int id;
    int f4;
    unsigned char f8;
    int fC;
    int f10;
} Game;

extern "C" void func_0044FA70(int d0, int d1, int d2, char *arg3)
{
    int idx;
    int key;
    int third;
    int n1;
    int n2;
    int n3;
    int n4;
    LobbyArray *list;
    Game *g;
    LobbyBuddyEntry *e;
    int slot;
    SFOLobby *lobby;
    bool ok;
    int i;
    char *p;

    if (D_00585E60 != 0) {
        list = &D_00585E60->listA8;
        if (list != 0) {
            if (func_00128C68(arg3, D_004C0F38, &idx, &key, &third) != 3)
                return;
            idx--;
            if (idx >= D_00585E60->array00.count)
                return;
            g = (Game *)LobbyArray_At(&D_00585E60->array00, idx);
            if (g == 0)
                return;
            if (key != g->id || g->f8 == 0)
                return;
            if (*(int *)(arg3 + 0x18) == 0) {
                slot = g->f10 + idx * D_00497938;
                lobby = D_00585E60;
                Grow(lobby, slot + 1);
                e = (LobbyBuddyEntry *)LobbyArray_At(list, slot);
                memset(e, 0, 0x50);
                g->f10++;
                if (g->f10 > D_00497938)
                    return;
                n4 = n3 = n2 = n1 = 0;
                char name[0x40] = {0};
                char buf[0x40];
                ok = true;
                String_Copy(buf, arg3 + 0x20);
                i = 0;
                p = buf;
                while (!IsNul(*p) && *p != 9 && i < 0x40) {
                    if (*p == ' ')
                        *p = -1;
                    p++;
                    i++;
                }
                if (func_00128C68(buf, D_004C0F50, name, &n1, &n2, &n3, &n4) != 5)
                    ok = false;
                if (name[0] != 0) {
                    p = name;
                    do {
                        if (*(unsigned char *)p == 0xFF)
                            *p = ' ';
                        p++;
                    } while (*p != 0);
                }
                if (strlen(name) > 0x1F)
                    ok = false;
                if (n1 < 1 || n1 > 4)
                    ok = false;
                if (n2 < 0 || n2 >= D_00585E60->array54.count)
                    ok = false;
                if (n3 < 0 || (unsigned int)n3 >= 6)
                    ok = false;
                if (ok) {
                    SFOLobby_CacheAccount(D_00585E60, n4, name, 0, 0);
                    {
                        SFOLobby *lb;
                        int wid;
                        int acc;
                        int j;
                        acc = n4;
                        lb = D_00585E60;
                        wid = *(int *)(arg3 + 0x1C);
                        for (j = 0; j < lb->listA8.count; j++) {
                            LobbyBuddyEntry *r = (LobbyBuddyEntry *)LobbyArray_At(&lb->listA8, j);
                            if (r->gameWorldId == wid || r->accountId == acc)
                                memset(r, 0, 0x50);
                        }
                    }
                    String_Copy(e->name, name);
                    e->f30 = *(int *)(arg3 + 0x60);
                    e->f34 = *(int *)(arg3 + 0x68);
                    e->f38 = n1;
                    e->gameWorldId = *(int *)(arg3 + 0x1C);
                    e->accountId = n4;
                    e->f40 = n2;
                    e->f44 = n3;
                    e->location = 0;
                    e->f4C = key;
                }
            }
            if (*(signed char *)(arg3 + 0x6C) != 0) {
                if (g->f10 != D_00497938) {
                    slot = g->f10 + D_00497938 * idx;
                    if (g->f10 != 0) {
                        lobby = D_00585E60;
                        Grow(lobby, slot);
                        if (slot != -1) {
                            if (slot == 0)
                                LobbyArray_Clear(&lobby->listA8);
                            else
                                while (lobby->listA8.count > slot)
                                    LobbyArray_RemoveAt(&lobby->listA8, lobby->listA8.count - 1);
                        }
                    } else {
                        lobby = D_00585E60;
                        if (slot != -1) {
                            if (slot == 0)
                                LobbyArray_Clear(&lobby->listA8);
                            else
                                while (lobby->listA8.count > slot)
                                    LobbyArray_RemoveAt(&lobby->listA8, lobby->listA8.count - 1);
                        }
                    }
                    for (; idx < (*(SFOLobby *volatile *)&D_00585E60)->array00.count; idx++) {
                        Game *o = (Game *)LobbyArray_At(&D_00585E60->array00, idx);
                        if (o->f10 == 0) {
                            o->id = 0;
                            o->f4 = 0;
                            o->f8 = 0;
                            o->fC = 0;
                            o->f10 = 0;
                            o->fC = Lobby_GetTime();
                        }
                    }
                }
                g->f8 = 0;
                g->fC = Lobby_GetTime();
                LobbyArray_SetRefreshing(list, 0);
                if (D_00585E60->outList23F0 != 0)
                    LobbyArray_Copy(D_00585E60->outList23F0, list);
            }
        }
    }
}
