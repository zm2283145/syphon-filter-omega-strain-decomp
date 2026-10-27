#ifndef MSG_CLONE_H
#define MSG_CLONE_H
/*
 * Message clone (virtual copy): new T(*self) with the copy constructors
 * inlined as member-by-member copies (base vtable, base members, class
 * vtable, own members). cMemMan_Allocate under the allocator guard.
 *   MSG_CLONE_BEGIN(name, size, fileSym, line)  F(type,off) = S(type,off); ...  MSG_CLONE_END
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"
extern "C" void* cMemMan_Allocate(int pool, int size, char* file, int line);
struct MsgCloneObj { void* vt; };
#define F(ty, off) (*(ty*)((char*)p + (off)))
#define S(ty, off) (*(ty*)((char*)self + (off)))
#define MSG_CLONE_BEGIN(name, size, fileSym, line)                         \
    extern "C" MsgCloneObj* name(MsgCloneObj* self) {                      \
        MsgCloneObj* p;                                                    \
        {                                                                  \
            AllocGuard g;                                                  \
            p = (MsgCloneObj*)cMemMan_Allocate(0, (size), fileSym, (line));       \
        }                                                                  \
        if (p) {
#define MSG_CLONE_END                                                      \
        }                                                                  \
        return p;                                                          \
    }
#endif