#include "SFOLobby.h"
#pragma mpwc_relax on
/* inbox element (0xAC bytes). */
typedef struct {
    int type;                       /* 0 game invite, 1 other request */
    int f4;
    int id;
} InboxEntry_450F30;
int func_00446560(SFOLobby * , InboxEntry_450F30 * , int);
int func_00449360(SFOLobby * , int, int, char *);
InboxEntry_450F30 * LobbyArray_At(LobbyArray * );
int LobbyArray_RemoveAt(LobbyArray * , int);
/* Answers inbox entry index (accept when accept != 0) and removes it. */
int func_00450F30(SFOLobby * self, int index, int accept) {
    int type;
    InboxEntry_450F30 * e;
    if (index < self->inbox.count) {
        e = LobbyArray_At(&self->inbox);
        type = e->type;
        switch (type) {
        case 0:
            if (accept != 0) {
                func_00449360(self, e->id, 1, "Accept");
            } else {
                func_00449360(self, e->id, 2, "Decline");
            }
            break;
        case 1:
            func_00446560(self, e, accept);
            break;
        }
        LobbyArray_RemoveAt(&self->inbox, index);
    }
    return 1;
}
