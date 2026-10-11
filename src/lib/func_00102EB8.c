typedef struct { char pad[6]; short x6; } GsInfo2EB8;
extern GsInfo2EB8 *func_00102A18(void);

void func_00102EB8(unsigned long *db)
{
    if (func_00102A18()->x6 == 1) {
        *(volatile unsigned long *)0x12000000 = db[0];
        *(volatile unsigned long *)0x12000070 = db[2];
        *(volatile unsigned long *)0x12000080 = db[3];
        *(volatile unsigned long *)0x120000C0 = db[4];
    } else {
        *(volatile unsigned long *)0x12000000 = db[0];
        *(volatile unsigned long *)0x12000020 = db[1];
        *(volatile unsigned long *)0x12000090 = db[2];
        *(volatile unsigned long *)0x120000A0 = db[3];
        *(volatile unsigned long *)0x120000E0 = db[4];
    }
}