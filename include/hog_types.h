#ifndef HOG_TYPES_H
#define HOG_TYPES_H

/*
 * HOG archive (hog.cc): a header with an entry-offset table and a name
 * table, followed by the entry data. A hog is either resident (whole file
 * loaded) or streamed (header only; entries read on demand).
 */

#include "FileHalPS2_types.h"

#define HOG_RESIDENT 1
#define HOG_STREAMED 2

typedef struct HogHeader {
    int unk0;                   /* 0x00 */
    unsigned int count;         /* 0x04 number of entries */
    int offsetsOff;             /* 0x08 -> int offsets[count + 1] */
    int namesOff;               /* 0x0C -> name table */
    int headerSize;             /* 0x10 entry data starts here */
} HogHeader;

typedef struct Hog {
    char name[0x80];            /* 0x000 archive file name */
    FileHalFile file;           /* 0x080 */
    HogHeader* hdr;             /* 0x148 */
    unsigned char mode;         /* 0x14C 0 (unloaded), HOG_RESIDENT or HOG_STREAMED */
    char pad14D[3];
    int cursor;                 /* 0x150 */
    char* cursorName;           /* 0x154 */
    void* buf;                  /* 0x158 resident: whole file; streamed: entry buffer */
    char* names;                /* 0x15C name table */
    int* offsets;               /* 0x160 entry offsets (relative to headerSize) */
    int pool;                   /* 0x164 allocation pool */
} Hog;

#endif