# Ramanuja Mohanty
# 04/01/26
# Assignment 7

.data
newline: .asciiz "\n"

.text
main:
    li $s0, 2           # i = 2 (Loop counter)

main_loop:
    bgt $s0, 4, main_end # if i > 4, exit

    move $a0, $s0       # arg = i
    jal poly            # result = poly(i)

    # Print result
    move $a0, $v0
    li $v0, 1
    syscall

    # Print newline
    la $a0, newline
    li $v0, 4
    syscall

    addi $s0, $s0, 1    # i++
    j main_loop

main_end:
    li $v0, 10
    syscall

poly:
    addi $sp, $sp, -12
    sw $ra, 8($sp)
    sw $s0, 4($sp)      # Save i/arg
    sw $s1, 0($sp)      # Save temp1

    move $s0, $a0       # Preserve arg in $s0

    # temp1 = pow(arg, 4)
    move $a0, $s0
    li $a1, 4
    jal pow
    move $s1, $v0       # s1 = temp1

    # result = pow(arg, 3)
    move $a0, $s0
    li $a1, 3
    jal pow             # v0 = result

    add $v0, $s1, $v0   # result = temp1 + result
    addi $v0, $v0, 1    # result = result + 1

    lw $s1, 0($sp)
    lw $s0, 4($sp)
    lw $ra, 8($sp)
    addi $sp, $sp, 12
    jr $ra

pow:
    li $v0, 1           # product = 1
    li $t0, 0           # i = 0
pow_loop:
    bge $t0, $a1, pow_ret # if i >= arg1, return
    mul $v0, $v0, $a0   # product *= arg0
    addi $t0, $t0, 1    # i++
    j pow_loop
pow_ret:
    jr $ra
