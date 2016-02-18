
.L3:
        movq    stderr(%rip), %rsi
        movq    -8(%rbp), %rax
        movzbl  (%rax), %eax
        movsbl  %al,%edi
        call    fputc
        addq    , -8(%rbp)
.L2:
        movq    -8(%rbp), %rax
        movzbl  (%rax), %eax
        testb   %al, %al
        jne     .L3
        leave
        ret

