#include "types.h"
typedef struct { int pad0; int count; int pad8; int padC; int dataOffset; } H36D3C0;
typedef struct {
    char pad[0x148]; H36D3C0* hdr; unsigned char loaded; char pad14D[0xB];
    char* base; char* names; int* offsets;
} S36D3C0;
extern int String_CompareNoCase(char* a, char* b);
char* cHogFile_GetBlock_charP_bool(S36D3C0* o, char* name)
{
    int i;
    char* s;
    H36D3C0* h;
    if (!o->loaded) return 0;
    s = o->names;
    for (i = 0; i < o->hdr->count; i++) {
        char* cur = s;
        while (*s++) ;
        if (String_CompareNoCase(name, cur) == 0) break;
    }
    h = o->hdr;
    if (i >= h->count) i = -1;
    if (i == -1) return 0;
    if (!o->loaded) return 0;
    return o->base + h->dataOffset + o->offsets[i];
}
