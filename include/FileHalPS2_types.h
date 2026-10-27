#ifndef FILEHALPS2_TYPES_H
#define FILEHALPS2_TYPES_H

/*
 * PS2 CD file HAL (FileHalPS2.cc). A FileHalFile is opened by name with
 * snd_StreamSafeCdSearchFile (snd_StreamSafeCdSearchFile) and read asynchronously in 2 KB sectors.
 */

#define CD_SECTOR_SIZE 2048
#define FILEHAL_MODE_DIRECT 0x8000  /* read straight into the caller's buffer */
#define FILEHAL_TIMEOUT_FRAMES 200

/* sceCdlFILE-style search result. */
typedef struct FileHalCdInfo {
    unsigned int lsn;           /* 0x00 first sector */
    unsigned int size;          /* 0x04 bytes */
    char name[16];              /* 0x08 */
    unsigned char date[8];      /* 0x18 */
} FileHalCdInfo;

typedef struct FileHalFile {
    int handle;                 /* 0x00: search result, -1 when closed */
    FileHalCdInfo info;         /* 0x04 */
    char pad24[4];
    int mode;                   /* 0x28: FILEHAL_MODE_DIRECT or 0 */
    int size;                   /* 0x2C: file size (0 when not found) */
    int startFrame;             /* 0x30: frame the current read was issued */
    int pollFrame;              /* 0x34: frame of the last poll */
    int timeoutFrames;          /* 0x38 */
    int bufSize;                /* 0x3C: bytes requested by the current read */
    unsigned char ownsBuf;      /* 0x40: buf was allocated by the HAL */
    char path[0x83];            /* 0x41: "\\NAME;1" */
    void* buf;                  /* 0xC4: read destination */
} FileHalFile;                  /* size 0xC8 */

#endif