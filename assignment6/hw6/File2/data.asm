numoff: 48
nxtchr: 0
lpcnt:  0
mask:   10
on:     8
nl:     10
cr:     13
c1:     1
cn1:	-1
c255:   255
pprmpt: 0			; pointer to the prompt string below
prompt: "PLEASE ENTER AN INTEGER BETWEEN 1 AND 32767"
ofstr:	"OVERFLOW, NO SUM POSSIBLE" ; string printed if overflow
sumstr:	"THE SUM OF THESE INTEGERS IS:" ; sum string
d1:	0			; first digit of result
d2:	0			; second digit of result
d3:	0	    		; third digit of result
d4:	0			; fourth digit of result
d5:	0			; fifth digit of result
pdig:	0			; ptr to digits
num1:	0			; first number read in
num2:	0			; second number read in
rslt:	0			; num1 + num2
numcnt:	2			; to keep track of nums read in
quot:	0			; temp. quotient when dividing
pchar:	0			; character to print
igzer:	0			; flag to ignore 0 chars or not
resadr:	0			; address to return the result in
retadr:	0			; address to return to