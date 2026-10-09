#ifndef GAMELIGHT_TYPES_H
#define GAMELIGHT_TYPES_H

/* Types for the gameLight directory. Layouts are provisional. */

/* Light parameters written by the setters 0x00179490 / 0x00179520 / 0x00179530. */
typedef struct GameLightParams {
    char pad00[0x08];
    int unk08;                  /* 0x08 */
    char pad0C[0x04];
    float unk10;                /* 0x10 */
    float unk14;                /* 0x14 */
} GameLightParams;

#endif
