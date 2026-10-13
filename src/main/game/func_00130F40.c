#pragma opt_strength_reduction off
extern int String_CompareNoCase(const char* a, const char* b);

typedef struct Entry {
    int value;
    const char* name;
    const char* alias;
} Entry;

typedef struct Table {
    char pad0[0x30];
    int count;
    Entry** entries;
} Table;

int func_00130F40(Table* t, const char* name, int* out)
{
    int i;
    for (i = 0; i < t->count; i++) {
        Entry* e = t->entries[i];
        if (!String_CompareNoCase(e->name, name) || (e->alias && !String_CompareNoCase(e->alias, name))) {
            *out = e->value;
            return 1;
        }
    }
    return 0;
}

