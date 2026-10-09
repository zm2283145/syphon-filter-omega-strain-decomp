#ifndef COLLISION_TYPES_H
#define COLLISION_TYPES_H

/*
 * Raw collision triangle (COL file). See research HUMAN_COLLISION.md:
 * +0 signed normal coefficient, +4/+6/+8 vertex indices, +0x0A surface
 * selector, +0x0B..+0x0D edge flags (bit 0x80).
 */
typedef struct ColTri {
    float normalScale;              /* 0x00 */
    unsigned short vert[3];         /* 0x04 */
    unsigned char surface;          /* 0x0A */
    unsigned char edgeFlags[3];     /* 0x0B */
} ColTri;

/* Small {pointer, flag} record initialised by func_003C1790. */
typedef struct ColRef {
    int unk0;                       /* 0x00 */
    char unk4;                      /* 0x04 set to 1 */
} ColRef;

#endif
