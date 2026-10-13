#pragma cplusplus on
#include "types.h"
extern "C" {
typedef struct { char pad[0x14C]; unsigned char active; char pad2[0x168 - 0x14D]; unsigned char keep; char pad3[3]; } O96E0;
typedef struct N96E0 { struct N96E0* prev; struct N96E0* next; O96E0 obj; } N96E0;
typedef struct { int m0; N96E0* list; } T96E0;
extern N96E0* func_003F9520(void* list);
extern void* func_003F95F0(void* self);
extern void func_003F95E0(N96E0** out, void* v);
extern int String_CompareNoCase(const char* a, const char* b);
extern int Hog_Load(O96E0* o, const char* name, unsigned char stream, int pool);
extern void func_0036D630(O96E0* o);
extern void func_0036D5D0(O96E0* o, int f);
extern void func_003F9B30(N96E0** out, T96E0* self, void* pos, O96E0* v);
}
/* the enum ternary into the unsigned char parameter gives li/movz/andi */
enum ArchiveLoadMode { ARCHIVE_RESIDENT, ARCHIVE_STREAMED };

/*
 * Find the archive called name (case-insensitive) in the list; (re)load it
 * when it is not loaded in the requested mode. Otherwise append a new entry
 * at the front of the list, load it and clear its keep flag.
 */
extern "C" O96E0* Archive_Open(T96E0* self, const char* name, int stream, int pool)
{
    N96E0* e;
    N96E0* n;
    O96E0 tmp;
    N96E0* r;
    void* pos;
    O96E0* o;
    for (n = func_003F9520(&self->list)->next; func_003F95E0(&e, func_003F95F0(self)), n != e; n = n->next) {
        if (!String_CompareNoCase((char*)&n->obj, name)) {
            if (stream ? !(n->obj.active == 2) : !(n->obj.active != 0))
                Hog_Load(&n->obj, name, stream ? ARCHIVE_STREAMED : ARCHIVE_RESIDENT, pool);
            return &n->obj;
        }
    }
    func_0036D630(&tmp);
    pos = &self->list;
    func_003F9B30(&r, self, &pos, &tmp);
    func_0036D5D0(&tmp, -1);
    o = &self->list->obj;
    Hog_Load(o, name, stream ? ARCHIVE_STREAMED : ARCHIVE_RESIDENT, pool);
    o->keep = 0;
    return o;
}
