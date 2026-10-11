#ifndef GRID16_FLAG_TEST_H
#define GRID16_FLAG_TEST_H

/*
 * Bit 0 of cell (x, y) of a 16x16 byte grid held through the pointer
 * tableSym; 0 when the grid is missing or (x, y) is out of range. Plain C.
 */
#define DEFINE_GRID16_FLAG_TEST(name, tableSym)                               \
    extern unsigned char* tableSym;                                           \
    int name(int x, int y)                                                    \
    {                                                                         \
        if (tableSym && x > -1 && x < 16 && y > -1 && y < 16)                 \
            return (tableSym + x * 16)[y] & 1;                                \
        return 0;                                                             \
    }

#endif /* GRID16_FLAG_TEST_H */