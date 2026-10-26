typedef struct {
    int valid;
    int nbits;
    int byte;
    int shift;
} Field_b6e0;

typedef struct {
    char hdr[0x14];
    Field_b6e0 f[50]; /* sizeof == 0x334 */
} Dev_b6e0;

extern Dev_b6e0 D_004FBB88[];

int scePad2GetButtonInfo(int dev, unsigned char *data, int idx)
{
    Field_b6e0 e = D_004FBB88[dev].f[idx];
    unsigned char v;

    if (e.valid != 0) {
        switch (e.nbits) {
        case 1:
            if ((data[e.byte] >> e.shift) & 1) return 0;
            return 1;
        case 8:
            v = data[e.byte] >> e.shift;
            if (e.shift != 0) {
                e.byte++;
                v |= data[e.byte] << (8 - e.shift);
            }
            return v;
        default:
            return -1;
        }
    }
    return -1;
}
