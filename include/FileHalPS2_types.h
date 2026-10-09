#ifndef FILEHALPS2_TYPES_H
#define FILEHALPS2_TYPES_H

/* PS2 file HAL handle object (size unknown, at least 0xC8). */
typedef struct FileHalFile {
    int handle;         /* 0x00: -1 when closed */
    char pad04[0x24];
    int unk28;          /* 0x28 */
    char pad2C[0x10];
    int unk3C;          /* 0x3C */
    char unk40;         /* 0x40 */
    char unk41;         /* 0x41 */
    char pad42[0x82];
    int unkC4;          /* 0xC4 */
} FileHalFile;

#endif
