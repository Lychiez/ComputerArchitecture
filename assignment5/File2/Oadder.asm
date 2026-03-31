; Main
MainInput:  lodd on:
            stod 4095
            call xbsywt:

; Input First Number
            loco rangeStr:
            call nextw:
            call getInput:
            lodd binarynum:
            stod sum:

; Input Second Number
            loco rangeStr:
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
            lodd zero:

            halt

; Get Input function
getInput:   lodd on:
            stod 4093
            call rbsywt:
            lodd 4092
            subd ascii:
            push

; Get Digits function
getDigit:   call rbsywt:
            lodd 4092
            stod nextChar:
            subd nl:
            jzer lastNum:
            mult 10
            lodd nextChar:
            subd ascii:
            addl 0
            stol 0
            jump getDigit:

; Save Number
lastNum:    pop
            stod binarynum:
            lodd 4092
            loco 0
            retn

; Overflow function
OverFlow:   loco errorStr:
            call nextw:
            lodd neg1:
            halt

; Convert function
convert:    lodd on:
            stod 4095
            lodd neg1:
            push
            lodd mask:
            push
            jump answer:

; answer loop
answer:     lodd sum:
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
printAns:   pop
            jneg done:
            stod 4094
            call xbsywt:
            jump printAns:

; Code below is given
; Helper code provided by professor for string IO 
; from "IO_str_and_echo.asm"
; for use in the assignment
nextw:      pshi
            addd one:
            stod str:
            pop
            jzer crnl:
            stod 4094
            push
            subd c255:
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
crnl:       lodd cr:
            stod 4094
            call xbsywt:
            lodd nl:
            stod 4094
            call xbsywt:
            retn

; Transmitter and receiver functions for IO
xbsywt:     lodd 4095
            subd mask:
            jneg xbsywt:
            retn

rbsywt:     lodd 4093
            subd mask:
            jneg rbsywt:
            retn

; SB falls through to loop1
sb:         loco 8

loop1:      jzer finish:
            subd one:
            stod count:
            lodl 1
            jneg add1:
            addl 1
            stol 1
            lodd count:
            jump loop1:

add1:       addl 1
            addd one:
            stol 1
            lodd count:
            jump loop1:

finish:     lodl 1
            retn

done:       
            retn


; Variables


; NOTE:
; 4092 = input buffer
; 4093 = receiver address
; 4094 = output buffer
; 4095 = transmitter address

rangeStr:   "Enter an integer between 1 and 32767: "
sumStr:     "The sum of these numbers is:"
errorStr:   "Overflow, no sum possible!"
neg1:      -1      ;; constant -1
zero:      0       ;; constant  0
one:        1       ;; constant  1
ascii:      48      ;; constant 48 (ASCII value for 0)
c255:       255     ;; constant 255
nextChar:   0       ;; next char
binarynum:  0       ;; binary number
sum:        0       ;; Sum variable
count:      0       ;; Counter
str:        0       ;; String ptr
on:         8       ;; Start transmitter
mask:       10      ;; Mask
nl:         10      ;; ASCII value of Newline (nl)
cr:         13      ;; ASCII value of Carriage Return (cr)
