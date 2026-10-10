#include "types.h"
typedef struct { char d[0x180]; } RootElem_3AECE0;
typedef struct { int pad0; int count; RootElem_3AECE0* data; unsigned char flag; } RootColl_3AECE0;
typedef struct { signed char c; } Tag_3AECE0;
extern void func_003B6840(RootColl_3AECE0* self, RootElem_3AECE0* first, RootElem_3AECE0* last, Tag_3AECE0 tag);
RootColl_3AECE0* RootCollection_Copy(RootColl_3AECE0* self, RootColl_3AECE0* o) {
    if (self != o) {
        Tag_3AECE0 tag;
        func_003B6840(self, o->data, o->data + o->count, tag);
    }
    self->flag = o->flag;
    return self;
}