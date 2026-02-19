LOOP:   
	LODD PasCnt:		; num of fibs to do in PasCnt
	JZER DONE:			; no more passes, go to done
	SUBD c1:			; - - passes remaining
	STOD PasCnt:		; load a pointer to fib arg
P1:	
	LODD daddr:			; inc, store pointer for next d[n] 
	PSHI				; call fib (arg on stack)
	ADDD c1:			; clear stack on fib return
	STOD daddr:			; put return AC (fib(n)) on stack
	CALL FIB:			; load a pointer to result f[n]
	INSP 1				; pop result off stack into f[n]
P2:	
	PUSH				; inc, store pointer for next f[n]
	LODD faddr:			; go to top for next pass
	POPI				; pop result off stack into f[n]
	ADDD c1:			
	STOD faddr:			; inc, store pointer for next f[n]
	JUMP LOOP:			; go to top for next pass

; -------------------- Recursive implementation -----------------------

FIB:	
	LODL 1				; Load argument N from stack
	JZER FIBZER:		; if N == 0 return 0 base case
	SUBD c1:			; AC = N - 1
	JZER FIBONE:		; if N == 1, return 1 second base case
	PUSH				; Push (N-1) as argument for recursive call

	CALL FIB:			; Recursive call on FIB(N-1)
	PUSH				; Store FIB(N-1) onto stack
	LODL 1				; Load the value from the stack
	SUBD c1:			; Subtract c1 (1) from AC
	PUSH				; Push FIB(N-2) as argument for recursive call
	CALL FIB:			; Call FIB(N-2)

CLEAN:
	INSP 1				; Clear FIB(N-2) from the stack (top most value)
	ADDL 0				; Store the result into AC
	INSP 2				; Clear arguments from the stack
	RETN				; Return

FIBZER:	
	LODD c0:
	RETN

FIBONE:	
	LODD c1:
	RETN			

; -------------------- End of Recursive implementation -----------------------

DONE:	HALT	 
.LOC 	100		
d0:  	3			
     	9
     	18
     	23
     	25
f0:  	0			
     	0
     	0
     	0 
     	0
daddr:  d0:			
faddr:  f0:			
c0: 	0			
c1: 	1	
PasCnt: 5			