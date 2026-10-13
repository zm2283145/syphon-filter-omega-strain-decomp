#pragma cplusplus on
#include "types.h"
typedef struct Node3FA780 { char pad[0x14]; int a; unsigned char flag; char pad19[3]; int b; } Node3FA780;
extern "C" {
extern unsigned char D_005724B0;
extern char D_0055C7A0[];
extern void func_003FA8B0(Node3FA780** out, void* map);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node3FA780** out, void* in);
extern void Tree_Successor(Node3FA780** it);
}
static inline int Eq3FA780(Node3FA780* a, Node3FA780* b) { return a == b; }
static inline int Has3FA780(Node3FA780* n) { return n->b != 0; }
#pragma push
#pragma opt_propagation off
extern "C" bool func_003FA780(int* outA, unsigned char* outFlag, int* outB)
{
    bool found = false;
    if (D_005724B0 != 7) {
        Node3FA780* it[1];
        Node3FA780* end[1];
        Node3FA780* b[1];
        int tmp[1];
        func_003FA8B0(b, D_0055C7A0);
        it[0] = b[0];
        for (func_0021D360(tmp, D_0055C7A0), func_0021D350(end, tmp); Eq3FA780(it[0], end[0]) ^ 1; func_0021D360(tmp, D_0055C7A0), func_0021D350(end, tmp)) {
            if (!(Has3FA780(it[0]) ^ 1)) {
                found = true;
                *outFlag = it[0]->flag;
                *outA = it[0]->a;
                *outB = it[0]->b;
                it[0]->b = 0;
                break;
            }
            Tree_Successor(it);
        }
    }
    return found;
}
#pragma pop


