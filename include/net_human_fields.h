#ifndef NET_HUMAN_FIELDS_H
#define NET_HUMAN_FIELDS_H
/* Replicated cNetHuman record and field-registration parameters. */
typedef struct {
    unsigned char f00, f01; char p02[2];
    int f04;
    int f08;
    signed char f0C; char p0D[3];
    int f10, f14, f18;
    short f1C; char p1E[2];
    unsigned char f20, f21; short f22;
    char p24[4];
    unsigned char f28, f29; char p2A[2];
    int f2C;
    short f30; unsigned char f32, f33;
    unsigned char f34, f35; char p36[2];
    float f38;
    int f3C, f40;
    int f44, f48, f4C;
    unsigned char f50, f51, f52; char p53;
    int f54;
    char p58[4];
} NetHumanRecord;
typedef struct { int max; int ver; int flags; unsigned char mode; } NetHumanFieldParams;
#endif
