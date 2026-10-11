#pragma cplusplus on
#include "types.h"
struct N41F960 { int id; N41F960 *next; virtual int v0(); };
extern "C" {
int func_00128E80(int, int);
extern N41F960 *D_00572118;
}
extern "C" int func_0041F960(int arg0) {
    N41F960 *n;
    for (n = D_00572118; n != 0; n = n->next) {
        if (func_00128E80(arg0, n->id) == 0) {
            return n->v0();
        }
    }
    return 0;
}