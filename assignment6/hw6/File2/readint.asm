readint:
call rbsywt:
lodd 4092
subd numoff:
push

nxtdig:
call rbsywt:
lodd 4092
stod nxtchr:
subd nl:
jzer endnum:
mult 10
lodd nxtchr:
subd numoff:
addl 0
jump nxtdig:

endnum:
pop
retn