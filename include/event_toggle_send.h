#ifndef EVENT_TOGGLE_SEND_H
#define EVENT_TOGGLE_SEND_H

/*
 * Toggle helpers shared by several object classes: when event sending is
 * enabled (D_005721C8), build a stack event message of type typeSym with
 * vtable vtableSym (size 0x40, target -1), post it with
 * postFn(msg, self->id) and destroy it; then store newState to the flag
 * at +0x2C. Plain C.
 */
typedef struct ToggleEventMsg {
    void* vtable;
    char pad04[0x18];
    int size;
    int pad20;
    int target;
    char pad28[0x8];
} ToggleEventMsg;

typedef struct ToggleSender {
    char pad[0x10];
    int id;
    char pad14[0x18];
    unsigned char state;
} ToggleSender;

extern unsigned char D_005721C8;
void Event_Construct(ToggleEventMsg* msg, void* type);
void cMessage_dtor(ToggleEventMsg* msg, int flags);

#define DEFINE_EVENT_TOGGLE_SEND(name, typeSym, vtableSym, postFn, newState)  \
    extern char typeSym[];                                                    \
    extern char vtableSym[];                                                  \
    void postFn(ToggleEventMsg* msg, int id);                                 \
    void name(ToggleSender* self)                                             \
    {                                                                         \
        if (D_005721C8) {                                                     \
            ToggleEventMsg msg;                                               \
            Event_Construct(&msg, typeSym);                                   \
            msg.vtable = vtableSym;                                           \
            msg.target = -1;                                                  \
            msg.size = 0x40;                                                  \
            postFn(&msg, self->id);                                           \
            msg.vtable = vtableSym;                                           \
            cMessage_dtor(&msg, 0);                                           \
        }                                                                     \
        self->state = (newState);                                             \
    }

#endif /* EVENT_TOGGLE_SEND_H */