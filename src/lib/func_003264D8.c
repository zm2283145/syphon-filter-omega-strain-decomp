#include "types.h"
typedef struct { char days[12]; } MonthTable;
typedef struct { char pad[5]; unsigned char day; unsigned char month; unsigned char year; } Date;
extern MonthTable D_004B8620;
/* Advances a BCD-free date by one day (handles leap February and year wrap at 99). */
void func_003264D8(Date* d)
{
    MonthTable t = D_004B8620;
    d->day++;
    if ((d->year & 3) == 0) {
        t.days[1] = 29;
    }
    if (t.days[d->month - 1] < d->day) {
        d->day = 1;
        d->month++;
        if (d->month == 13) {
            if (d->year == 99) d->year = 0;
            else d->year++;
            d->month = 1;
        }
    }
}
