typedef struct { unsigned int prev_size; unsigned int size; } *mchunkptr;
extern char *D_00489748[];
struct mallinfo { int arena; int ordblks; };
extern struct mallinfo D_00489B78;
const unsigned int D_00489B60[2] = { 0xFFFFFFFF, 0x0 };
extern void func_001261B0(void *);
extern void func_00126230(void *);
extern char *func_00128658(void *, int);
#define top ((mchunkptr)(D_00489748[2]))
int func_00124058(void *ptr, unsigned int pad)
{
    long top_size;
    long extra;
    char *current_brk;
    char *new_brk;
    unsigned long pagesz = 4096;

    func_001261B0(ptr);
    top_size = top->size & ~3;
    extra = ((top_size - pad - 16 + (pagesz - 1)) / pagesz - 1) * pagesz;
    if (extra < (long)pagesz) {
        func_00126230(ptr);
        return 0;
    } else {
        current_brk = (char *)(func_00128658(ptr, 0));
        if (current_brk != (char *)(top) + top_size) {
            func_00126230(ptr);
            return 0;
        } else {
            new_brk = (char *)(func_00128658(ptr, -extra));
            if (new_brk == (char *)(-1)) {
                current_brk = (char *)(func_00128658(ptr, 0));
                top_size = current_brk - (char *)top;
                if (top_size >= (long)16) {
                    D_00489B78.arena = current_brk - (*(char **)D_00489B60);
                    top->size = top_size | 1;
                }
                func_00126230(ptr);
                return 0;
            } else {
                top->size = (top_size - extra) | 1;
                D_00489B78.arena -= extra;
                func_00126230(ptr);
                return 1;
            }
        }
    }
}

