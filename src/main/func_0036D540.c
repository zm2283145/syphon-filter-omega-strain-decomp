#include "types.h"

typedef struct ChunkHdr {
    int unk00;
    int unk04;
    int dataOffset;  /* 0x08 */
    int startOffset; /* 0x0C */
} ChunkHdr;

typedef struct ChunkReader {
    char name[0x148];      /* 0x000 */
    ChunkHdr* hdr;         /* 0x148 */
    unsigned char loaded;  /* 0x14C */
    char pad14D[3];
    int pos;               /* 0x150 */
    char* cursor;          /* 0x154 */
    char* base;            /* 0x158 */
    char* start;           /* 0x15C */
    char* data;            /* 0x160 */
    int user;              /* 0x164 */
} ChunkReader;

extern void String_Copy(char* dst, const char* src);

/* Binds a loaded chunk buffer to the reader; returns 0. */
int func_0036D540(ChunkReader* r, const char* name, char* buffer, int user) {
    String_Copy(r->name, name);
    r->loaded = 1;
    r->base = buffer;
    r->hdr = (ChunkHdr*)r->base;
    r->start = r->base + r->hdr->startOffset;
    r->data = r->base + r->hdr->dataOffset;
    r->pos = 0;
    r->user = user;
    r->cursor = r->start;
    return 0;
}
