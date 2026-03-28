# Ramanuja Mohanty
# 03/27/26
# Assignment 6

.data
    str:    .asciiz "abcde"
    newline: .asciiz "\n"

.text
main:
    la   $t0, str
    li   $t1, 0

loop_check:
    lb   $t2, 0($t0)
    beq  $t2, $zero, end_loop

loop_body:
    addi $t1, $t1, 1
    addi $t0, $t0, 1

    lb   $t2, 0($t0)
    bne  $t2, $zero, loop_body

end_loop:
    li   $v0, 1
    move $a0, $t1
    syscall

    li   $v0, 4
    la   $a0, newline
    syscall

    li   $v0, 10
    syscall
