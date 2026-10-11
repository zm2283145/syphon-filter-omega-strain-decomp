#ifndef STORED_EVENT_POST_H
#define STORED_EVENT_POST_H

/*
 * Post a stored event with action 4 and an angle when not yet posted: the event block at
 * blockOffset holds action (+0x28), target (+0x2C), posted flag (+0x30)
 * and angle (+0x34). Event_Send(block, target, 1), then mark posted and
 * clear the target.
 */
extern void Event_Send(void* block, int target, int flag);

typedef struct StoredEventBlock {
    char data[0x28];
    unsigned char action;
    char pad29[3];
    int target;
    unsigned char posted;
    char pad31[3];
    float angle;
} StoredEventBlock;

#define DEFINE_STORED_EVENT_POST(name, blockOffset)                           \
    typedef struct name##_Owner {                                             \
        char pad[blockOffset];                                                \
        StoredEventBlock ev;                                                  \
    } name##_Owner;                                                           \
    static inline void name##_post(name##_Owner* self, float angle)           \
    {                                                                         \
        if (self->ev.target && !self->ev.posted) {                            \
            self->ev.action = 4;                                              \
            self->ev.angle = angle;                                           \
            Event_Send(&self->ev, self->ev.target, 1);                        \
        }                                                                     \
        self->ev.posted = 1;                                                  \
        self->ev.target = 0;                                                  \
    }                                                                         \
    void name(name##_Owner* self, float angle)                                \
    {                                                                         \
        if (self->ev.target)                                                  \
            name##_post(self, angle);                                         \
    }

#endif /* STORED_EVENT_POST_H */