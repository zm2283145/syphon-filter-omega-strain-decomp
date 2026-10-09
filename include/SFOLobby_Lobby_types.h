#ifndef SFOLOBBY_LOBBY_TYPES_H
#define SFOLOBBY_LOBBY_TYPES_H

/* Lobby object (partial): holds a list sub-object at +0x38 whose count is at +0x3C. */
typedef struct LobbyLobby {
    char pad00[0x38];
    char list[4];           /* 0x38 list sub-object */
    int count;              /* 0x3C number of entries in the list */
} LobbyLobby;

#endif
