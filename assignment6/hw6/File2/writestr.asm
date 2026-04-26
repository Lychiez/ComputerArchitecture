writestr:
    lodl 1          ; get argument: pointer to string
    stod pprmpt:
nextw:  
    lodd pprmpt:     ; load current pointer
    pshi            ; push first 2 chars on stack
    addd c1:         ; advance pointer
    stod pprmpt:
    pop
    jzer crnl:       ; null byte in first char => done
    stod 4094       ; print first char
    push
    subd c255:       ; isolate/check second char
    jneg crnl:       ; null second char => done
    call sb:         ; swap bytes
    insp 1
    push
    call xbsywt:
    pop
    stod 4094       ; print second char
    call xbsywt:
    jump nextw:
crnl:   
    lodd cr:
    stod 4094
    call xbsywt:
    lodd nl:
    stod 4094
    call xbsywt:
    retn