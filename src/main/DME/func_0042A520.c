#pragma cplusplus on

#include "network_session_types.h"

extern "C" {
extern signed char D_005724C0;
static unsigned int dat_004941A0[4] = { 0x1, 0x0, 0x0, 0x0 };
extern NetworkGameList D_005724A0;
extern NetworkGameIterator D_005724C8;
void func_0042A670(NetworkGameIterator* result, NetworkGameList* list);
void func_0042A640(NetworkGameIterator* result, NetworkGameList* list);
void func_0042A660(NetworkGameIterator* destination, const NetworkGameIterator* source);
char* strncpy(char* destination, const char* source, unsigned int count);
}

static inline int different_iterator(const NetworkGameIterator& first, const NetworkGameIterator& second)
{
    return (first.entry == second.entry) ^ 1;
}

/* Enumerate a game address and restart from the beginning after reaching the end. */
extern "C" bool func_0042A520(NetworkGameAddress* destination)
{
    NetworkGameIterator begin;
    NetworkGameIterator end;
    NetworkGameIterator rawBegin;
    NetworkGameIterator rawEnd;
    if (!D_005724C0)
        D_005724C0 = 1;
    bool found = false;
    if ((*(unsigned char*)dat_004941A0)) {
        func_0042A670(&rawBegin, &D_005724A0);
        func_0042A660(&begin, &rawBegin);
        D_005724C8 = begin;
        (*(unsigned char*)dat_004941A0) = 0;
    }
    func_0042A640(&rawEnd, &D_005724A0);
    func_0042A660(&end, &rawEnd);
    if (different_iterator(D_005724C8, end)) {
        strncpy(destination->name, (*D_005724C8.entry)->name, 16);
        destination->value = (*D_005724C8.entry)->value;
        ++D_005724C8.entry;
        found = true;
    } else {
        (*(unsigned char*)dat_004941A0) = 1;
    }
    return found;
}
