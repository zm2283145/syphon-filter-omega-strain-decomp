typedef struct { unsigned char a, b, min, d; } T326690;
extern void func_00326408(T326690* t);
extern void func_00326638(T326690* t);
extern void func_00326668(T326690* t);
extern void func_00326470(T326690* t);
void func_00326690(T326690* t, int delta)
{
    int d;
    func_00326408(t);
    d = t->min + delta;
    if (d >= 0) {
        while (d >= 60) { func_00326638(t); d -= 60; }
    } else {
        while (d < 0) { d += 60; func_00326668(t); }
    }
    t->min = d;
    func_00326470(t);
}