#!/bin/bash
# ir.sh draft.c : print unscheduled preheader (after busy-wait) of cMan_ManDMA
f=$1; t=/tmp/claude-0/ir_$$.c
sed 's/^#pragma cplusplus on/#pragma cplusplus on\n#pragma schedule off/' $f > $t
python lab_raw.py $t cMan_ManDMA 0x385D40 0x386AD0 -v | grep '^[+ ]' | sed 's/^.//' | awk '/andi v0,v0,0x100/{p=1} p{print} /^b L/{if(p)exit}'
rm -f $t
