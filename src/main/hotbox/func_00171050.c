/* 32-byte copy as one GCC-style lq/sq asm (q0,q1 outputs first, then d, s) gives retail register choice. */
typedef struct Bounds {
    __int128 q[2];
} Bounds;

extern void Hotbox_ComputeNpcBounds(Bounds* out, void* a, void* b);

typedef struct Obj {
    char pad[0x70];
    Bounds b;
} Obj;

#pragma peephole off
void func_00171050(void* self, Obj* o, void* a, void* b) {
    Bounds t;
    Hotbox_ComputeNpcBounds(&t, a, b);
    { void* d = &o->b; void* s = &t; __int128 q0, q1; __asm__ volatile("lq %0, 0(%3); lq %1, 0x10(%3); sq %0, 0(%2); sq %1, 0x10(%2)" : "=&r"(q0), "=&r"(q1) : "r"(d), "r"(s) : "memory"); }
}

