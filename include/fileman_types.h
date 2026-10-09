#ifndef FILEMAN_TYPES_H
#define FILEMAN_TYPES_H

/* File manager entry (size unknown, at least 0x9C). */
typedef struct FileManEntry {
    int flags;          /* 0x00: bit 0 = has an open HAL file */
    char pad04[0x94];
    int halFile;        /* 0x98: FileHalPS2 handle passed to func_003695C0 */
} FileManEntry;

#endif
