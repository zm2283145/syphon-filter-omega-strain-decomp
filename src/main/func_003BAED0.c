#include "types.h"

/* Texture base page (in 32-block units) of the referenced entry, 0 if none. */
typedef struct { unsigned char pad[0x50]; unsigned long long tex0; } Tex_3BAED0;
typedef struct { int pad0[2]; Tex_3BAED0** entries; } Table_3BAED0;
typedef struct { int pad0; int index; } Ref_3BAED0;
extern Table_3BAED0* D_00539248;

unsigned int func_003BAED0(Ref_3BAED0* r)
{
    if (r->index != -1)
        return (unsigned int)(int)(D_00539248->entries[r->index]->tex0 & 0x3FFF) >> 5;
    return 0;
}