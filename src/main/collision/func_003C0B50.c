#include "types.h"

typedef struct { char pad[3]; unsigned char format; char pad2[0x14]; int offset; } ImageHdr;
typedef struct { int unk0; ImageHdr** image; } ImageRef;
extern unsigned char* func_00183B20(ImageHdr* hdr, int* offset);

/* Reads one texel byte at (x, y) from an image whose row stride depends on its format. */
void func_003C0B50(unsigned char* out, ImageRef* ref, int* coord)
{
    int off16;
    int off32;
    int off64;
    ImageHdr* hdr;
    int y;
    int x;
    unsigned char* row;
    x = coord[1];
    hdr = *ref->image;
    y = coord[0];
    if (hdr->format < 4) {
        off64 = hdr->offset;
        row = func_00183B20(hdr, &off64) + y * 64;
    } else if (hdr->format < 5) {
        off32 = hdr->offset;
        row = func_00183B20(hdr, &off32) + y * 32;
    } else {
        off16 = hdr->offset;
        row = func_00183B20(hdr, &off16) + y * 16;
    }
    row += x;
    *out = row[0xB];
}
