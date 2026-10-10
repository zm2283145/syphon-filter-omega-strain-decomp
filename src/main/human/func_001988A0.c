#include "types.h"
typedef struct { char d[0xF8]; } DqElemD4;
typedef struct { DqElemD4** node; DqElemD4** first; int pad; DqElemD4** last; DqElemD4* cur; DqElemD4* end; } DequeIterD4;
DequeIterD4* DequeIter_Next(DequeIterD4* it)
{
    if (++it->cur == it->end) {
        if (++it->node == it->last) it->node = it->first;
        it->cur = *it->node;
        it->end = it->cur + 8;
    }
    return it;
}