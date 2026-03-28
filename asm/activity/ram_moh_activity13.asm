# Ramanuja Mohanty
# 03/27/26
# Activity 13

.text
main:
    li   $s0, 10

    move $a0, $s0
    jal  callee
    move $s1, $v0

    li   $v0, 10
    syscall

callee:
    addi $sp, $sp, -4
    sw   $ra, 0($sp)

    addi $t0, $a0, 1
    move $v0, $t0

    lw   $ra, 0($sp)
    addi $sp, $sp, 4
    jr   $ra
