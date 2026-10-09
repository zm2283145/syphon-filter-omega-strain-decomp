#ifndef MOVIESUBTITLES_TYPES_H
#define MOVIESUBTITLES_TYPES_H

/* Four-float colour/vector. */
typedef struct SubVec4 {
    float x, y, z, w;
} SubVec4;

/* Subtitle text/layout block reset by func_00412050 (at least 0xB0 bytes). */
typedef struct SubtitleBlock {
    char pad00[0x50];
    char unk50[0x60 - 0x50];    /* 0x50 */
    int base;                   /* 0x60 text buffer base address */
    int unk64;                  /* 0x64 */
    int unk68;                  /* 0x68 current row */
    int unk6C;                  /* 0x6C */
    int unk70;                  /* 0x70 */
    int unk74;                  /* 0x74 */
    char pad78[0x80 - 0x78];
    SubVec4 color;              /* 0x80 initialised to white (1,1,1,1) */
    int unk90;                  /* 0x90 */
    int unk94;                  /* 0x94 */
    int unk98;                  /* 0x98 */
    int unk9C;                  /* 0x9C initialised to 0x749DC5AE */
    float unkA0;                /* 0xA0 initialised to -1.0f */
    int unkA4;                  /* 0xA4 initialised to 3 */
    int unkA8;                  /* 0xA8 initialised to 1 */
    char unkAC;                 /* 0xAC */
} SubtitleBlock;

/* One 0x110-byte entry of the owner's array at +0x1F0. */
typedef struct SubtitleEntry {
    char pad000[0x90];
    char unk090[0x10];          /* 0x090 */
    char unk0A0[0x110 - 0xA0];  /* 0x0A0 */
} SubtitleEntry;

/* Owner object (partial). */
typedef struct SubtitleOwner {
    char pad000[0x1F0];
    SubtitleEntry entries[1];   /* 0x1F0, indexed by current */
    char pad300[0xA70 - 0x300];
    int current;                /* 0xA70 index into entries */
    char padA74[0xEC0 - 0xA74];
    char unkEC0[4];             /* 0xEC0 */
} SubtitleOwner;

#endif
