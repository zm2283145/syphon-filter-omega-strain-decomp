#include "types.h"
typedef struct { char days[12]; } MonthTable;
typedef struct { char pad[5]; unsigned char day; unsigned char month; unsigned char year; } Date;
const unsigned int D_004B8620[4] = { 0x1E1F1C1F, 0x1F1F1E1F, 0x1F1E1F1E, 0x0 };
/* Advances a BCD-free date by one day (handles leap February and year wrap at 99). */
void func_003264D8(Date* d)
{
    MonthTable t = (*(MonthTable*)D_004B8620);
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
