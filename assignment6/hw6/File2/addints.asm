addints:
    lodd num1
    push
    lodd num2
    addl 0
    jneg overflow
    pop
    retn
overflow:
    pop
    lodd cn1
    retn