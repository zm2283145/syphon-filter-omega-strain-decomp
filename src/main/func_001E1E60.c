#include "types.h"

typedef struct AnimHdr {
    char pad00[3];
    unsigned char version; /* 0x03 */
    char pad04[0x14];
    int dataOffset;        /* 0x18 */
} AnimHdr;

typedef struct AnimRef {
    AnimHdr* hdr;
} AnimRef;

typedef struct AnimOwner {
    int unk00;
    AnimRef* ref; /* 0x04 */
} AnimOwner;

extern char* func_00183B20(AnimHdr* hdr, int* offset);

/* Returns the address of record `index`; the record size depends on the format version. */
char* func_001E1E60(AnimOwner* owner, int index) {
    int offset16;
    int offset32;
    int offset64;
    AnimHdr* hdr = owner->ref->hdr;
    if (hdr->version < 4) {
        offset64 = hdr->dataOffset;
        return func_00183B20(hdr, &offset64) + index * 64;
    } else if (hdr->version < 5) {
        offset32 = hdr->dataOffset;
        return func_00183B20(hdr, &offset32) + index * 32;
    } else {
        offset16 = hdr->dataOffset;
        return func_00183B20(hdr, &offset16) + index * 16;
    }
}
