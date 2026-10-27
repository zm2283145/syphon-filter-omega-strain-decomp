typedef struct E { unsigned char* ptr; unsigned int n; unsigned char data[1]; } E;
typedef struct X { char pad[0x58]; char* tab; char pad2[0x68-0x5C]; unsigned int flags; } X;
typedef struct A { int a0; X* x; } A;

void cVU1Model_UpdateLighting(A* a, int idx, unsigned char on) {
    unsigned char cur;
    E* e;
    cur = (a->x->flags >> idx) & 1;
    if (cur != on) {
        a->x->flags ^= 1 << idx;
        e = *(E**)(a->x->tab + idx * 8 + 4);
        while (*(int*)e != 0) {
            unsigned char* s = e->data;
            unsigned char* d = e->ptr;
            unsigned int i;
            if (on) {
                for (i = 0; i < e->n; i++) {
                    *d++ += s[0];
                    *d++ += s[1];
                    *d++ += s[2];
                    s += 4;
                }
            } else {
                for (i = 0; i < e->n; i++) {
                    *d++ -= s[0];
                    *d++ -= s[1];
                    *d++ -= s[2];
                    s += 4;
                }
            }
            e = (E*)((char*)e + (e->n * 4 + 8));
        }
    }
}
