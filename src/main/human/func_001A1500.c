#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; } Sub;
typedef struct { unsigned char state; char pad[3]; char items[0x38]; Sub sub; } S;
extern void __construct_array(void* arr, void* ctor, void* dtor, int size, int count);
extern void func_0018A870(void);
extern void func_0018A210(void);
extern void func_001A1570(Sub*);
/* Constructor: clears state, constructs 7 8-byte items, inits the sub-object and sets its flag. */
S* func_001A1500(S* s) { Sub* sub; s->state = 0; __construct_array(s->items, func_0018A870, func_0018A210, 8, 7); sub = &s->sub; func_001A1570(sub); sub->flag = 1; return s; }
