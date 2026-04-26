rbsywt: lodd 4093		; wait until receiver
        subd mask:		; not busy
        jneg rbsywt:
        retn