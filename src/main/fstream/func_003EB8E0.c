/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"

/* List iterator dereference: address of the node payload at node +0x08. */
char* std_list_cFSDataPtr_generic_iterator_opMul(char** self) {
    return *self + 8;
}
