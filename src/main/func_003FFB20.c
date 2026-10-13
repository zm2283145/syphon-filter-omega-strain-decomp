#include "types.h"
typedef union { __int128 q; char c[16]; } SkmName;
typedef struct { char* data; short free; char flag; char type; char* base; } SkmPkt;
extern SkmName D_005609B0[];
extern unsigned char D_005639B6[];
extern int String_CompareN(const char*, const char*, int);
extern char D_004BE618[], D_004BE620[], D_004BE628[], D_004BE630[], D_004BE638[], D_004BE640[],
    D_004BE648[], D_004BE650[], D_004BE658[], D_004BE660[], D_004BE668[], D_004BE670[],
    D_004BE678[], D_004BE680[], D_004BE688[], D_004BE690[], D_004BE698[], D_004BE6A0[],
    D_004BE6A8[], D_004BE6B0[], D_004BE6B8[], D_004BE6C0[], D_004BE6C8[], D_004BE6D0[],
    D_004BE6E0[], D_004BE6F0[], D_004BE700[], D_004BE710[], D_004BE720[], D_004BE730[],
    D_004BE740[], D_004BE750[];

void Skm_ClassifyParts(SkmPkt* b, int a, int c)
{
    int kind = 8;
    __int128 n = D_005609B0[a].q;
    char* p = (char*)&n;
    int flag = 0;
    if (String_CompareN(D_004BE618, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE620, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE628, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE630, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE638, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE640, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE648, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE650, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE658, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE660, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE668, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE670, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE678, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE680, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE688, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE690, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE698, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE6A0, p + 1, 3) == 0) kind = kind;
    if (String_CompareN(D_004BE6A8, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE6B0, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE6B8, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE6C0, p + 1, 3) == 0) kind = 0xC;
    if (String_CompareN(D_004BE6C8, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE6D0, p + 1, 8) == 0) kind = 0x10;
    if (String_CompareN(D_004BE6E0, p + 1, 8) == 0) { kind = 0xC; flag = 0x80; }
    if (String_CompareN(D_004BE6F0, p + 1, 8) == 0) { kind = 0x14; flag = 0x80; }
    if (String_CompareN(D_004BE700, p + 1, 9) == 0) { kind = 0x14; flag = 0x80; }
    if (String_CompareN(D_004BE710, p + 1, 9) == 0) { kind = 0x14; flag = 0x80; }
    if (String_CompareN(D_004BE720, p + 1, 9) == 0 || String_CompareN(D_004BE730, p + 1, 9) == 0 ||
        String_CompareN(D_004BE740, p + 1, 9) == 0 || String_CompareN(D_004BE750, p + 1, 9) == 0)
        kind = 0xC;
    D_005639B6[a * 32 + c * 16] |= (unsigned char)(kind | flag);
}