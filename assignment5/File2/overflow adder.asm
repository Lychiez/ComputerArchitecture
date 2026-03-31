; Main
MainInput:
; Set Accumulator to 0 and store into sum
    loco 0:
    stod sum
; Start value of 8 to turn on transmitter
    lodd on:
    stod 4095
    call xbsywt:
; Input First Number
    loco rangeStr:
    call nextw:
    call getInput:
    lodd binarynum:
    stod sum:
; Input Second Number
    loco rangestr:
    call nextw:
    call getInput:
    lodd binarynum:
    addd sum:
    stod sum:
; If the sum went negative, then overflow condition
    jneg OverFlow:
; Output sum
    loco sumStr:
    call nextw:
    call convert:
    lodd Czero:
    halt

; Get Input function
getInput:
    lodd on:
    stod 4093
    call rbsywt:
    lodd 4092
    subd ascii:
    push

; Get Digits function
getDigit: 
    call rbsywt:
    lodd 4092:
    stod nextChar:
    subd nl:
    jzer lasNum:
    mult 10
    lodd nextChar:
    subd ascii:
    addl 0
    stol 0
    jump getDigit:

; Save Number
lastNum:
    pop
    stod binarynum:
    lodd 4092
    loco 0
    retn

; Overflow function
    loco errorStr:
    call nextw:
    lodd Cneg1:
    halt

; Convert function
convert:
    lodd on:
    stod 4095
    lodd Cneg1:
    pushlodd mask: push
    jump answer:

; answer loop
answer:
    lodd sum:
    jzer printAns:
    lodd mask:
    push
    lodd sum:
    push
    div
    pop
    stod sum:
    pop
    insp 2
    addd ascii:
    push
    jump answer:

; print answer function
    pop
    jneg done:
    stod 4094
    call xbsywt:
    jump printAns:
    
; Helper code provided by professor for string IO from "IO_str_and_echo.asm"
nextw:
    pshi
    addd one:
    stod str:
    popjzer crnl:
    stod 4094
    push
    subd C255:
    jneg crnl:
    call sb:
    insp 1
    push
    call xbsywt:
    pop
    stod 4094
    call xbsywt:
    lodd str:
    jump nextw:

; Output carriage return and newline.
crnl:
    lodd cr:
    stod 4094
    call xbsywt:
    lodd n1:
    stod 4094
    call xbsywt
    retn

; Transmitter and receiver functions for IO
xbsywt:
    lodd 4095
    subd mask:
    jneg xbsywt:
    retn

rbsywt:
    lodd 4093
    subd mask:
    jneg rbsywt:
    retn

sb:
    loco 8

loop1:
    jzer finish:
    subd one:
    stod count:
    lodl 1
    jneg add1:
    addl 1
    stol 1
    lodd count:
    jump loop1:

add1:
    addl 1
    addd one:
    stol 1
    lodd count:
    jump loop1:

finish:
    lodl 1
    retn

done:
    retn

; Variables

rangeStr:   "PLEASE ENTER AN INTEGER BETWEEN 1 AND 32767 "
sumStr:     "THE SUM OF THESE INTEGERS IS:"
errorStr:   "OVERFLOW, NO SUM POSSIBLE"
nextChar:   0       ;; next char
binarynum:  0       ;; binary number
sum:        0       ;; Sum variable
count:      0       ;; Counter
str:        0       ;; String ptr
on:         8       ;; Start transmitter
mask:       10      ;; Mask
nl:         10      ;; ASCII value of Newline (nl)
cr:         13      ;; ASCII value of Carriage Return (cr)
Cneg1:      -1      ;; constant -1
Czero:      0       ;; constant  0
one:        1       ;; constant  1
ascii:      48      ;; constant 48 (ASCII value for 0)
C255:       255     ;; constant 255




