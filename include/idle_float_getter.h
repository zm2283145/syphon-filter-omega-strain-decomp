#ifndef IDLE_FLOAT_GETTER_H
#define IDLE_FLOAT_GETTER_H

/*
 * Float field getters shared by one class (identical bodies, different
 * field): return idleValue (0.0f or 1.0f) unless the handle at +0x1064 is -1,
 * otherwise the float at `offset`. Plain C.
 */
#define DEFINE_IDLE_FLOAT_GETTER(name, offset, idleValue)                     \
    float name(char* self)                                                    \
    {                                                                         \
        if (*(int*)(self + 0x1064) != -1)                                     \
            return (idleValue);                                               \
        return *(float*)(self + (offset));                                    \
    }

#endif /* IDLE_FLOAT_GETTER_H */

