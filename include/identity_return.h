#ifndef IDENTITY_RETURN_H
#define IDENTITY_RETURN_H

/*
 * Functions that return their first argument unchanged (inline ctor or
 * conversion bodies emitted out of line, unoptimised: compile the member
 * between #pragma optimization_level 1 / reset).
 */
#define DEFINE_IDENTITY_RETURN(name)                                          \
    void* name(void* p)                                                       \
    {                                                                         \
        return p;                                                             \
    }

#endif /* IDENTITY_RETURN_H */