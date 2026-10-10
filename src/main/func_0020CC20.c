#include "types.h"
#pragma optimization_level 1

/* Empty tag object passed by value. */
typedef struct Tag {
    signed char unused;
} Tag;

extern void func_0020CC50(int, int, Tag);

/* Forwards to func_0020CC50 with a default tag. */
void func_0020CC20(int a, int b) {
    Tag tag;
    func_0020CC50(a, b, tag);
}
