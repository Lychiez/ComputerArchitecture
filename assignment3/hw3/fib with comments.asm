LOOP:   LODD PasCnt:  		; num of fibs to do in PasCnt
	JZER DONE:		; no more passes, go to done
	SUBD c1:
	STOD PasCnt:		; - - passes remaining
P1:	LODD daddr:		; load a pointer to fib arg
	PSHI			; push arg for fib on stack
	ADDD c1:
	STOD daddr:		; inc, store pointer for next d[n] 
	CALL FIB:		; call fib (arg on stack)
	INSP 1			; clear stack on fib return
P2:	PUSH			; put return AC (fib(n)) on stack
	LODD faddr:		; load a pointer to result f[n]
	POPI			; pop result off stack into f[n]
	ADDD c1:
	STOD faddr:		; inc, store pointer for next f[n]
	JUMP LOOP:		; go to top for next pass

; -------------------- Recursive implementation -----------------------

FIB:	
	LODL 1				; Load argument N from stack
	JZER FIBZER:		; if  N == 0, return 0 base case
	SUBD c1: 			; AC - N - 1
	JZER FIBONE:		; if N == 1, return 1 second base case

	PUSH				; Push (N-1) onto the stack
	CALL FIB: 			; Call Fib(N-1)
	STOD tmp:			; store FIB(N-1)
	INSP 1				; Clean stack

	LODL 1				; Load first N
	SUBD c2:			; AC = N - 2
	PUSH
	CALL FIB:			; Call Fib on (N-2)
	ADDD tmp:			; AC = FIB(N-1) + FIB(N-2)
	INSP 1
	RETN

; -------------------- End of Recursive implementation -----------------------

FIBZER:	
	LODD c0:
	RETN			; AC = 0 for fib(0)
FIBONE:	
	LODD c1:
	RETN			; AC = 1 for fib(1)

DONE:	HALT	 
.LOC 	100			; locate data beginning at 100
d0:  	3			; array of args for fib function
     	9
     	18
     	23
     	25
f0:  	0			; array of result locs for fib returns
     	0
     	0
     	0 
     	0
daddr:  d0:			; start address of fib args 
faddr:  f0:			; start address of fib results
c0: 	0			; constants 
c1: 	1
c2: 	2			; added constant 2
PasCnt: 5			; number of data elements to process
tmp:	0			; initial value for fib(2)