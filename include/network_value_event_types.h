#ifndef NETWORK_VALUE_EVENT_TYPES_H
#define NETWORK_VALUE_EVENT_TYPES_H

struct NetworkValueEvent {
    void* vtable;
    int header[7];
    signed char baseState;
    char pad21[3];
    int value;
    unsigned char state;
    char pad29[3];
};

struct NetworkValuePacket {
    unsigned int header;
    unsigned int objectId;
    int value;
    unsigned char state;
    char pad0D[3];
};

typedef int (*NetworkValueHandler)(int, int, int, const NetworkValuePacket*);

#endif
