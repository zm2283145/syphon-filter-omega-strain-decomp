#pragma cplusplus on

#include "network_value_event_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004DFD80[];
extern char D_004E0E60[];
extern int D_00572190;
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
int NetRegisterMessageStart(void);
int cMessage_RegisterFields(NetworkValuePacket* packet);
int NetMessageField(NetworkValuePacket* packet, void* destination, int size, int count);
int NetRegisterApplicationMessage(int* type, NetworkValueHandler callback);
int Event_PackHeader(NetworkValueEvent* self, int first, int* type, int third,
                      int fourth, unsigned int capacity, NetworkValuePacket* packet);
int cActivateMsg_ActivateCallback(int first, int second, int third, const NetworkValuePacket* packet);
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
extern "C" NetworkValueEvent* cActivateMsg_Clone(const NetworkValueEvent* source)
{
    NetworkValueEvent* result;
    {
        AllocGuard guard;
        result = (NetworkValueEvent*)cMemMan_Allocate(0, sizeof(NetworkValueEvent), "ActivateMsg.hh", 0x18);
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
extern "C" bool cActivateMsg_InitNet(void)
{
    bool success = false;
    NetworkValuePacket packet;
    if (!NetRegisterMessageStart() && cMessage_RegisterFields(&packet) &&
        !NetMessageField(&packet, &packet.value, 4, 1) &&
        !NetMessageField(&packet, &packet.state, 1, 1) &&
        !NetRegisterApplicationMessage(&D_00572190, cActivateMsg_ActivateCallback))
        success = true;
    return success;
}

/* Pack the payload when the retail capacity and output-type requirements hold. */
extern "C" int cActivateMsg_Pack(NetworkValueEvent* self, int first, int* type, int third,
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
