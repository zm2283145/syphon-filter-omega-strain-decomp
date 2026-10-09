/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"

/* List iterator dereference: address of the node payload at node +0x08. */
char* func_003EB8E0(char** self) {
    return *self + 8;
}
