import struct, sys
from elftools.elf.elffile import ELFFile
f = r"D:\Claude\Syphon Filter Omega Strain\local\prototypes\SCUS_973.97_early_proto.elf"
e = ELFFile(open(f,"rb"))
d = e.get_section_by_name(".line").data()
lo, hi = int(sys.argv[1],16), int(sys.argv[2],16)
off = 0; n=0
while off < len(d):
    ln, base = struct.unpack_from("<II", d, off)
    if ln == 0: break
    end = off + ln
    p = off + 8
    while p + 10 <= end:
        line, col, delta = struct.unpack_from("<IHI", d, p)
        a = base + delta
        if lo <= a < hi: print(hex(a), line, col)
        p += 10
    off = end
