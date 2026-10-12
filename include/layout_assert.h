#ifndef LAYOUT_ASSERT_H
#define LAYOUT_ASSERT_H

/*
 * Compile-time layout checks (negative-array typedef trick; emits no code or
 * data). Works in MW C/C++ and ee-gcc 2.9x.
 *   LAYOUT_SIZE(SoundRequest, 0x190);
 *   LAYOUT_OFFSET(SoundRequest, a, 0x48);
 * Names must be unique per translation unit (the type and field form the name).
 */
#define LAYOUT_SIZE(type, size) \
    typedef char layout_size_##type[(sizeof(type) == (size)) ? 1 : -1]
#define LAYOUT_OFFSET(type, field, off) \
    typedef char layout_off_##type##_##field[((unsigned int)&((type*)0)->field == (off)) ? 1 : -1]

#endif /* LAYOUT_ASSERT_H */
