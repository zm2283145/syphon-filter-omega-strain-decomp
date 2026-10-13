#pragma cplusplus on
#include "SFOLobby.h"
extern "C" {
int String_Copy(char *, char *);
int sprintf(char *, char *, ...);
int LobbyArray_Append(LobbyArray *, void *);
char *LobbyArray_At(LobbyArray *, int);
void LobbyArray_RemoveAt(LobbyArray *, int);
void LobbyArray_Clear(LobbyArray *);
int Lobby_GetTime(void);
int func_00476998(void);
int func_00469DC8(void *, void *);
void func_0044FA70(int, int, int, char *);
void *memset(void *, int, int);
extern char D_004C0F38[];
extern int D_00497938;
extern int D_004978A8;
extern int D_004978C0;
extern int D_004978D8;
extern int D_00585FA8;
}

typedef struct {
    int id;
    int f4;
    unsigned char f8;
    int fC;
    int f10;
} Game;

typedef struct {
    char messageId[0x15];
    char sessionKey[0x11];
    char pad26[2];
    int ver;
    short page;
    short pageSize;
    char pad30[0];
} ReqGames;

typedef struct {
    LobbyArray array00;
    char pad1C[0xA8 - 0x1C];
    LobbyArray listA8;
    char padC4[0x170 - 0xC4];
    int reqCounter;
    int rangeStart;
    int rangeEnd;
    char pad17C[0x24C - 0x17C];
    int requestResult;
    char pad250[0x2418 - 0x250];
    char sessionKey[0x11];
} L60;

extern "C" void func_00450060(L60 *self)
{
    int now;
    int count;
    int sent;
    int i;
    int hi;
    int hi2;
    int lo;
    int lo2;
    int n;
    int start;
    int half;
    int end;
    int k;
    int kend;
    unsigned char found;
    Game *g;

    now = Lobby_GetTime();
    count = self->array00.count;
    sent = 0;
    for (i = 0; i < count; i++) {
        Game *gg = (Game *)LobbyArray_At(&self->array00, i);
        if (gg->f8 != 0) {
            if (gg->fC + D_004978A8 < now) {
                int id = gg->f4;
                int a = i * D_00497938;
                int b = a + D_00497938;
                if (a < self->listA8.count) {
                    if (self->listA8.count < b)
                        b = self->listA8.count;
                    while (a < b) {
                        LobbyBuddyEntry *e = (LobbyBuddyEntry *)LobbyArray_At(&self->listA8, a++);
                        if (e->f4C == id)
                            memset(e, 0, 0x50);
                    }
                }
                gg->id = 0;
                gg->f4 = 0;
                gg->f8 = 0;
                gg->fC = 0;
                gg->f10 = 0;
            } else {
                sent++;
            }
        }
    }
    if (sent >= D_00585FA8)
        return;
    for (i = count - 1; i >= 0; i--) {
        g = (Game *)LobbyArray_At(&self->array00, i);
        if (g->f10 != 0 || g->f8 != 0 || g->fC + D_004978C0 >= now)
            break;
        LobbyArray_RemoveAt(&self->array00, i);
    }
    n = count * D_00497938;
    if (n != -1) {
        if (n == 0)
            LobbyArray_Clear(&self->listA8);
        else
            while (self->listA8.count > n)
                LobbyArray_RemoveAt(&self->listA8, self->listA8.count - 1);
    }
    n = self->array00.count;
    half = D_00497938 / 2;
    start = self->rangeStart - half;
    end = self->rangeEnd + half;
    if (start < 0)
        start = 0;
    if (end < start)
        end = start;
    lo = (start - (D_00497938 - 1)) / D_00497938;
    hi = (end + (D_00497938 - 1)) / D_00497938;
    lo2 = (self->rangeStart - (D_00497938 - 1)) / D_00497938;
    hi2 = (self->rangeEnd + (D_00497938 - 1)) / D_00497938;
    if (lo > n)
        lo = n;
    else if (lo < 0)
        lo = 0;
    if (lo2 > n)
        lo2 = n;
    else if (lo2 < 0)
        lo2 = 0;
    if (lo <= hi) do {
        if (lo >= n + (D_00585FA8 - sent))
            return;
        found = 0;
        if (lo == n) {
            Game tmp;
            tmp.id = 0;
            tmp.f4 = 0;
            tmp.f8 = 0;
            tmp.fC = 0;
            tmp.f10 = 0;
            LobbyArray_Append(&self->array00, &tmp);
            n++;
            found = 1;
        } else {
            g = (Game *)LobbyArray_At(&self->array00, lo);
            if (g->f8 == 0) {
                if (g->fC + D_004978C0 < now) {
                    found = 1;
                } else if (lo >= lo2 && lo <= hi2 && g->fC + D_004978D8 < now) {
                    int a = lo * D_00497938;
                    int b = a + D_00497938;
                    if (a < self->listA8.count) {
                        if (self->listA8.count < b)
                            b = self->listA8.count;
                        while (a < b) {
                            LobbyBuddyEntry *e = (LobbyBuddyEntry *)LobbyArray_At(&self->listA8, a++);
                            if (e->name[0] == 0) {
                                found = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (found) {
            ReqGames req;
            g = (Game *)LobbyArray_At(&self->array00, lo);
            g->fC = now;
            g->f8 = 1;
            g->f4 = g->id;
            g->id = self->reqCounter++;
            g->f10 = 0;
            memset(&req, 0, 0x30);
            sprintf(req.messageId, D_004C0F38, lo + 1, g->id, g->f4);
            String_Copy(req.sessionKey, self->sessionKey);
            req.ver = func_00476998();
            req.page = lo + 1;
            req.pageSize = D_00497938;
            self->requestResult = func_00469DC8(&req, (void *)func_0044FA70);
            if (self->requestResult != 0)
                g->f8 = 0;
            sent++;
        }
        if (sent >= D_00585FA8)
            return;
    } while (++lo <= hi);
}
