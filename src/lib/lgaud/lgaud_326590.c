/*
 * lib/lgaud: 4 files, 00326590-00326690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326590 */
typedef struct { char days[12]; } MonthTable;
typedef struct { char pad[5]; unsigned char day; unsigned char month; unsigned char year; } Date;
extern const unsigned int D_004B8620[4];
void subdate(Date* d)
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
extern void adddate(T326638* t);
void addhour(T326638* t)
{
    if (++t->hour == 24) {
        t->hour = 0;
        adddate(t);
    }
}
/* merge_units: end func_00326638 */

/* merge_units: begin func_00326668 */
typedef struct { unsigned char a, b, min, hour; } T326668;
#if 0 /* merge_units */
extern void subdate(T326668* t);
#endif /* merge_units */
#define subdate(a0) (subdate((Date *)(a0))) /* merge_units */

void subhour(T326668* t)
{
    if (t->hour == 0) {
        t->hour = 23;
        subdate(t);
    } else {
        t->hour--;
    }
}
#undef subdate /* merge_units */
/* merge_units: end func_00326668 */

/* merge_units: begin func_00326690 */
typedef struct { unsigned char a, b, min, d; } T326690;
extern void convertfrombcd(T326690* t);
#if 0 /* merge_units */
extern void addhour(T326690* t);
#endif /* merge_units */
#define addhour(a0) (addhour((T326638 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void subhour(T326690* t);
#endif /* merge_units */
#define subhour(a0) (subhour((T326668 *)(a0))) /* merge_units */

extern void converttobcd(T326690* t);
void AdjustTime(T326690* t, int delta)
{
    int d;
    convertfrombcd(t);
    d = t->min + delta;
    if (d >= 0) {
        while (d >= 60) { addhour(t); d -= 60; }
    } else {
        while (d < 0) { d += 60; subhour(t); }
    }
    t->min = d;
    converttobcd(t);
}
#undef addhour /* merge_units */
#undef subhour /* merge_units */
/* merge_units: end func_00326690 */
