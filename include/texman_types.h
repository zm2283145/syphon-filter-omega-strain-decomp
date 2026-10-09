#ifndef TEXMAN_TYPES_H
#define TEXMAN_TYPES_H

/* Types for the texman directory. Layouts are provisional. */

/* Linked node: link word at +4, value at +8. */
typedef struct TexListNode {
    struct TexListNode* unk00;  /* 0x00 */
    struct TexListNode* next;   /* 0x04 */
    int value;                  /* 0x08 */
} TexListNode;

typedef struct TexListIter {
    TexListNode* node;
} TexListIter;

/* Reference-counted texture entry. */
typedef struct TexEntry {
    char pad00[0x64];
    int refCount;               /* 0x64 */
} TexEntry;

/* Texture manager state reset by 0x003820C0. */
typedef struct TexManager {
    char pad000[0x480];
    int unk480;                 /* 0x480 */
    int unk484;                 /* 0x484 */
    unsigned char unk488;       /* 0x488 */
    unsigned char unk489;       /* 0x489 */
} TexManager;

#endif
