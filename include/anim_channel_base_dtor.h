#ifndef ANIM_CHANNEL_BASE_DTOR_H
#define ANIM_CHANNEL_BASE_DTOR_H

/*
 * Deleting destructor of AnimChannelBase (vtable D_004DA380), nothing to
 * destroy: restore the vtable, delete when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" {
extern char D_004DA380[];
void operator_delete(void* allocation);
}

struct AnimChannelBaseObj {
    void* vtable;
};

#define DEFINE_ANIM_CHANNEL_BASE_DTOR(name)                                   \
    extern "C" AnimChannelBaseObj* name(AnimChannelBaseObj* self,             \
                                        short deleteFlag)                     \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = D_004DA380;                                        \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* ANIM_CHANNEL_BASE_DTOR_H */