/*
 * lib/lgaud: 4 files, 00326590-00326690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326590 */
typedef struct { char days[12]; } MonthTable;
typedef struct { char pad[5]; unsigned char day; unsigned char month; unsigned char year; } Date;
extern const unsigned int D_004B8620[4];
void func_00326590(Date* d)
{
    MonthTable t = (*(MonthTable*)D_004B8620);
    d->day--;
    if (d->year % 4 == 0) {
        t.days[1] = 29;
    }
    if (d->day == 0) {
        d->month--;
        if (d->month == 0) {
            if (d->year == 0) d->year = 99;
            else d->year--;
            d->month = 12;
        }
        d->day = t.days[d->month - 1];
    }
}
/* merge_units: end func_00326590 */

/* merge_units: begin func_00326638 */
typedef struct { unsigned char a, b, min, hour; } T326638;
extern void func_003264D8(T326638* t);
void func_00326638(T326638* t)
{
    if (++t->hour == 24) {
        t->hour = 0;
        func_003264D8(t);
    }
}
/* merge_units: end func_00326638 */

/* merge_units: begin func_00326668 */
typedef struct { unsigned char a, b, min, hour; } T326668;
#if 0 /* merge_units */
extern void func_00326590(T326668* t);
#endif /* merge_units */
#define func_00326590(a0) (func_00326590((Date *)(a0))) /* merge_units */

void func_00326668(T326668* t)
{
    if (t->hour == 0) {
        t->hour = 23;
        func_00326590(t);
    } else {
        t->hour--;
    }
}
#undef func_00326590 /* merge_units */
/* merge_units: end func_00326668 */

/* merge_units: begin func_00326690 */
typedef struct { unsigned char a, b, min, d; } T326690;
extern void func_00326408(T326690* t);
#if 0 /* merge_units */
extern void func_00326638(T326690* t);
#endif /* merge_units */
#define func_00326638(a0) (func_00326638((T326638 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_00326668(T326690* t);
#endif /* merge_units */
#define func_00326668(a0) (func_00326668((T326668 *)(a0))) /* merge_units */

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
#undef func_00326638 /* merge_units */
#undef func_00326668 /* merge_units */
/* merge_units: end func_00326690 */
