#ifndef NETWORK_SESSION_TYPES_H
#define NETWORK_SESSION_TYPES_H

struct NetworkThreadStatus {
    char pad00[0x18];
    int priority;                 /* 0x18 */
    char pad1C[0x14];
};

struct NetworkGameAddress {
    char name[16];
    int value;                    /* 0x10 */
};

struct NetworkGameList {
    int capacity;
    int count;
    NetworkGameAddress** data;
};

union NetworkGameIterator {
    NetworkGameAddress** entry;
    unsigned int word;
};

#endif
