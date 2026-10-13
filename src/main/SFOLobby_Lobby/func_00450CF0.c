#include "SFOLobby.h"
#define NULL 0
#pragma mpwc_relax on
int Lobby_GetTime();
LobbyAccountEntry *LobbyArray_At(LobbyArray * , int);
int memset(LobbyPlayerInfo * , int, int);
extern int D_00497848;              /* cached info lifetime */
typedef struct { LobbyStatPair x[0x60]; } Pairs_0CF0;
static inline LobbyAccountEntry* Find_0CF0(SFOLobby* self, int id) {
    int n = self->accountCache.count;
    int i;
    for (i = 0; i < n; i++) {
        LobbyAccountEntry* e = LobbyArray_At(&self->accountCache, i);
        if (id == e->accountId) return e;
    }
    return NULL;
}
/* Copies the cached player info of an account into out when it is still fresh;
 * otherwise clears out and returns 0. */
int func_00450CF0(SFOLobby * self, int id, LobbyPlayerInfo * out) {
    LobbyStatPair *src;
    LobbyStatPair *dst;
    int n;
    LobbyAccountEntry *e;
    e = Find_0CF0(self, id);
    if ((e != NULL) && (e->hasInfo != 0) && ((Lobby_GetTime() - e->infoTime) < D_00497848)) {
        src = e->info.pairs;
        dst = out->pairs;
        n = 0x60;
        out->b0 = e->info.b0;
        out->b1 = e->info.b1;
        out->b2 = e->info.b2;
        out->b3 = e->info.b3;
        out->h4 = e->info.h4;
        out->h6 = e->info.h6;
        out->h8 = e->info.h8;
        out->hA = e->info.hA;
        out->hC = e->info.hC;
        out->hE = e->info.hE;
        out->w10 = e->info.w10;
        out->w14 = e->info.w14;
        out->w18 = e->info.w18;
        out->w1C = e->info.w1C;
        out->w20 = e->info.w20;
        out->w24 = e->info.w24;
        *(Pairs_0CF0*)dst = *(Pairs_0CF0*)src;
        out->wE8 = e->info.wE8;
        out->wEC = e->info.wEC;
        out->wF0 = e->info.wF0;
        out->ip = e->info.ip;
        out->bF8 = e->info.bF8;
        out->bF9 = e->info.bF9;
        return 1;
    }
    memset(out, 0, 0xFC);
    return 0;
}
