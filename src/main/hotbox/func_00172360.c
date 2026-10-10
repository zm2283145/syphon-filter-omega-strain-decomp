#include "types.h"
typedef struct G7N2 { struct G7N2* prev; struct G7N2* next; } G7N2;
extern G7N2* func_0013ADF0(void* p);
void* func_00172360(char* obj, int n)
{
    G7N2* node = func_0013ADF0(obj + 4)->next;
    if (n >= 0) {
        while (n > 0) { node = node->next; n--; }
    } else {
        while (n < 0) { node = node->prev; n++; }
    }
    return (char*)node + 8;
}