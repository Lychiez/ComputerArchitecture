  ;test program for NAND and RSHIFT
nand:	LODD d1:
	PUSH
	LODD d2:
	PUSH
	NAND
	STOD nandans:
	HALT  ;AC has NAND value
	LODD d1:
	PUSH
	LODD d5:
	PUSH
	NAND
	STOD nandans:
	HALT  ;AC has NAND value
rshift:	LODD d1:
	RSHIFT 0
	HALT  ;AC has shifted value
	LODD d2:
	RSHIFT 3
	HALT  ;AC has shifted value
	LODD d3:
	RSHIFT 7
	HALT  ;AC has shifted value
	LODD d4:
	RSHIFT 15
	HALT  ;AC has shifted value
	LODD d5:
	RSHIFT 4
	HALT  ;AC has shifted value
	.LOC 30
d1:	  3451	; 0000 1101 0111 1011
d2:	  8192  ; 0010 0000 0000 0000
d3:	 -8192  ; 1110 0000 0000 0000
d4:	-32768  ; 1000 0000 0000 0000
d5:	   944  ; 0000 0011 1011 0000
nandans:     0
