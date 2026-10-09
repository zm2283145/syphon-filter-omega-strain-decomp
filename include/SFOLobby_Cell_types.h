#ifndef SFOLOBBY_CELL_TYPES_H
#define SFOLOBBY_CELL_TYPES_H

/* Lobby cell object (partial). Cached data is refreshed by func_00449A00 once
 * the refresh interval D_00497800 has elapsed since lastUpdate. */
typedef struct LobbyCell {
    char pad0000[0x2480];
    int unk2480;            /* 0x2480 */
    char pad2484[0x2588 - 0x2484];
    int lastUpdate;         /* 0x2588 time of last refresh, 0 = never */
    char pad258C[0x2594 - 0x258C];
    char unk2594[0x265C - 0x2594]; /* 0x2594 embedded sub-object */
    unsigned char unk265C;  /* 0x265C */
    unsigned char unk265D;  /* 0x265D */
} LobbyCell;

#endif
