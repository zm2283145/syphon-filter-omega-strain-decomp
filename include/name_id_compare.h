#ifndef NAME_ID_COMPARE_H
#define NAME_ID_COMPARE_H

/*
 * Compare two entries by the names their ids map to in the global name
 * table (SFOLobbyList_GetSlot lookup, name text at +4): strcmp of both names, or
 * 0 when either id is unknown. Plain C.
 */
typedef struct NameIdKey { int pad; int id; } NameIdKey;
typedef struct NameIdMgr { char pad[0x11C]; void* table; } NameIdMgr;
extern NameIdMgr* D_005065C0;
extern char* SFOLobbyList_GetSlot(void* table, int id);
extern int strcmp(const char* a, const char* b);

#define DEFINE_NAME_ID_COMPARE(name)                                  \
    int name(NameIdKey* a, NameIdKey* b)                              \
    {                                                                 \
        char* x = SFOLobbyList_GetSlot(D_005065C0->table, a->id);            \
        char* y = SFOLobbyList_GetSlot(D_005065C0->table, b->id);            \
        if (!x || !y)                                                 \
            return 0;                                                 \
        return strcmp(x + 4, y + 4);                                  \
    }

#endif /* NAME_ID_COMPARE_H */