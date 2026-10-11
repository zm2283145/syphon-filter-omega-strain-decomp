#ifndef ANIM_CHANNEL_DTOR_H
#define ANIM_CHANNEL_DTOR_H

/*
 * Deleting destructors of a class (vtable D_004DA840) derived from
 * AnimChannelBase (vtable D_004DA380) with nothing to destroy: restore
 * each vtable in turn, then delete when deleteFlag > 0.
 *   DEFINE_ANIM_CHANNEL_DTOR(name)       one inlined null test on self
 *   DEFINE_ANIM_CHANNEL_DTOR_DEEP(name)  an extra inlined null test
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" {
extern char D_004DA840[];
extern char D_004DA380[];
void operator_delete(void* allocation);
}

struct AnimChannelObj {
    void* vtable;
};

#define DEFINE_ANIM_CHANNEL_DTOR(name)                                        \
    extern "C" AnimChannelObj* name(AnimChannelObj* self, short deleteFlag)   \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = D_004DA840;                                        \
            if (self)                                                         \
                self->vtable = D_004DA380;                                    \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_ANIM_CHANNEL_DTOR_DEEP(name)                                   \
    extern "C" AnimChannelObj* name(AnimChannelObj* self, short deleteFlag)   \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                self->vtable = D_004DA840;                                    \
                if (self)                                                     \
                    self->vtable = D_004DA380;                                \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* ANIM_CHANNEL_DTOR_H */