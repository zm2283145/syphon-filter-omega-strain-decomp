#include "types.h"
#pragma optimization_level 1

/* Empty tag object passed by value. */
typedef struct Tag {
    signed char unused;
} Tag;

extern void std_distance_cSkaTransBLENDP_cSkaTransBLENDP_randomaccessiteratortag(int, int, Tag);

/* Forwards to std_distance_cSkaTransBLENDP_cSkaTransBLENDP_randomaccessiteratortag with a default tag. */
void std_distance_cSkaTransBLENDP_cSkaTransBLENDP(int a, int b) {
    Tag tag;
    std_distance_cSkaTransBLENDP_cSkaTransBLENDP_randomaccessiteratortag(a, b, tag);
}
