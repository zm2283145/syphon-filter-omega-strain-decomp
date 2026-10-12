#include "types.h"
typedef struct { int pad0; int count; } H36D2A0;
typedef struct { char pad[0x148]; H36D2A0* hdr; unsigned char loaded; char pad14D[0xF]; char* names; } S36D2A0;
extern int String_CompareNoCase(char* a, char* b);
int func_0036D2A0(S36D2A0* o, char* name)
{
    int i;
    char* s;
    if (!o->loaded) return 0;
    s = o->names;
    for (i = 0; i < o->hdr->count; i++) {
        char* cur = s;
        while (*s++) ;
        if (String_CompareNoCase(name, cur) == 0) break;
    }
    if (i >= o->hdr->count) i = -1;
    return i;
}
