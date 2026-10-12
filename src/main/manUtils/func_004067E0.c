#include "types.h"
typedef struct { char first[16]; char second[16]; } H2Pair;
typedef struct { char hdr[0x40]; H2Pair pairs[32]; } H2Pack;
extern int String_CompareN(char* a, char* b, int n);
/* Body kind from the mesh family of the first part pair. */
int Appearance_GetBodyKind(H2Pack* p) {
    char* name;
    int i;
    char c;
    for (i = 0; i < 32; i++) {
        name = p->pairs[i].first;
        if (String_CompareN(name + 1, "BODY", 4) == 0)
            return 2;
        c = name[0];
        if (c == '1')
            return 1;
        if (c == '2')
            return 0;
        if (c == 0)
            return i > 0 ? 2 : 1;
    }
    return 2;
}