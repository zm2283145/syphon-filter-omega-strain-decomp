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
