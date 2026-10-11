#pragma cplusplus on

#include "network_value_event_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BF940[];
extern char D_004DFD80[];
extern char D_004E0E60[];
extern int D_00572190;
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
int func_002E9A10(void);
int func_003C9C30(NetworkValuePacket* packet);
int func_002E9A98(NetworkValuePacket* packet, void* destination, int size, int count);
int func_002E9F08(int* type, NetworkValueHandler callback);
int Event_PackHeader(NetworkValueEvent* self, int first, int* type, int third,
                      int fourth, unsigned int capacity, NetworkValuePacket* packet);
int func_00428EF0(int first, int second, int third, const NetworkValuePacket* packet);
}

static inline void copy_event_base(NetworkValueEvent* destination, const NetworkValueEvent* source)
{
    destination->vtable = D_004DFD80;
    destination->header[0] = source->header[0];
    destination->header[1] = source->header[1];
    destination->header[2] = source->header[2];
    destination->header[3] = source->header[3];
    destination->header[4] = source->header[4];
    destination->header[5] = source->header[5];
    destination->header[6] = source->header[6];
    destination->baseState = source->baseState;
}

/* Allocate an event clone and preserve its base header and value payload. */
extern "C" NetworkValueEvent* func_00428CD0(const NetworkValueEvent* source)
{
    NetworkValueEvent* result;
    {
        AllocGuard guard;
        result = (NetworkValueEvent*)Mem_Alloc(0, sizeof(NetworkValueEvent), D_004BF940, 0x18);
    }
    if (result) {
        copy_event_base(result, source);
        result->vtable = D_004E0E60;
        result->value = source->value;
        result->state = source->state;
    }
    return result;
}

/* Register the value-event payload fields and its receive callback. */
extern "C" bool func_00428DE0(void)
{
    bool success = false;
    NetworkValuePacket packet;
    if (!func_002E9A10() && func_003C9C30(&packet) &&
        !func_002E9A98(&packet, &packet.value, 4, 1) &&
        !func_002E9A98(&packet, &packet.state, 1, 1) &&
        !func_002E9F08(&D_00572190, func_00428EF0))
        success = true;
    return success;
}

/* Pack the payload when the retail capacity and output-type requirements hold. */
extern "C" int func_00428E70(NetworkValueEvent* self, int first, int* type, int third,
                            int fourth, unsigned int capacity, NetworkValuePacket* packet)
{
    Event_PackHeader(self, first, type, third, fourth, capacity, packet);
    int result = -1;
    if (capacity > 16) {
        packet->value = self->value;
        packet->state = self->state;
        if (type) {
            *type = D_00572190;
            result = 16;
        }
    }
    return result;
}
