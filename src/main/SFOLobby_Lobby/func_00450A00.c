#include "SFOLobby.h"
#define NULL 0
#pragma mpwc_relax on
int *LobbyArray_At(LobbyArray * , int);
/* Finds the accountCache entry for an account id. */
int *func_00450A00(SFOLobby * self, int id) {
    int *e;
    int n;
    int i;
    n = self->accountCache.count;
    for (i = 0; i < n; i++) {
        e = LobbyArray_At(&self->accountCache, i);
        if (id == *e) {
            return e;
        }
    }
    return NULL;
}
