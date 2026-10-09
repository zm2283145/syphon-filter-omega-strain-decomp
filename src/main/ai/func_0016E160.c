/*
 * Matched functions (byte-identical with the retail executable).
 * Copies the second word of a pair over the first.
 */

#include "types.h"

typedef struct WordPair {
    int first;
    int second;
} WordPair;

void func_0016E160(WordPair* p) {
    p->first = p->second;
}
