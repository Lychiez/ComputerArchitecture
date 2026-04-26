writeint:
    lodl 1
    stod rslt:
    stod quot:		; start by putting rslt: into quot:
loopc:	
    loco 10			; loop for extracting digits from rslt:
	push			; set up for div (quot: / 10)
	lodd quot:
	push
	div				; do quot: / 10
	pop
	stod quot:		; pop and store quot:
	lodd pdig:		; store remainder into pdig's addr.
	popi
	insp 2			; okay to overwrite 2 nums used for div
	lodd pdig:		; get pdig to point to previous digit
	subd c1:
	stod pdig:
	lodd quot:		; if quotient != 0, loop again
	jnze loopc:		; else the num is separated into digits
prntr:	
    loco d1:		; start by making pdig point to the first
	stod pdig:		; char in the result string
	loco 6			; set loop counter up to 5 digits (+1)
	stod lpcnt:
loopp:	
    lodd lpcnt:		; loop for printing result
	subd c1:
	stod lpcnt:		
	jzer donep:		; if lpcnt = 0, done printing result
	lodd pdig:
	pshi
	addd c1:		; set pdig up to point to next char
	stod pdig:
	lodd pchar:		; get digit into pchar
	pop
	jnze contin:		; if char != 0, move on
	push
	lodd igzer:		; we ignore only leading 0's
	jzer loopp:		; if it's leading, loop
	loco 1			; otherwise, set the flag so we
	stod igzer:		; no longer ignore 0's
	pop			
contin: push			; ensure we're no longer ignoring
	loco 1			; 0 characters if a non-zero has been
	stod igzer:		; found
	pop
	addd numoff:		; else, += 48 to make ascii value
	push			; push string on
	call xbsywt:		; wait for xmtr
	pop				; get string back
	stod 4094		; print char
	call xbsywt:		; wait for xmtr again
	jump loopp:		; and loop again
donep:  
    lodd cr:		; print carriage return
    stod 4094		
    call xbsywt:
    lodd nl:		; print new line
    stod 4094
    call xbsywt:
    lodd on:                
    stod 4093
    retn