xbsywt: lodd 4095		; wait until transmitter
        subd mask:		; not busy
        jneg xbsywt:
        retn