#include "SFOLobby.h"
extern int* LobbyArray_At(LobbyArray* t, int i);
/* Finds the element of t whose first word equals id. */
int* func_00450A90(LobbyArray* t, int id) {
    int n;
    int i;
    if (!t || !(n = t->count)) return 0;
    for (i = 0; i < n; i++) {
        int* e = LobbyArray_At(t, i);
        if (id == *e) return e;
    }
    return 0;
}
