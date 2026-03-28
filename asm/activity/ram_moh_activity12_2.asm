# Ramanuja Mohanty
# 03/27/26
# Activity 12-2

.data
    x: .space 24           # 6 integers * 4 bytes each = 24 bytes

.text
main:
    la   $t0, x            # ptr_x = &x[0]
    li   $t1, 0            # i = 0

loop_cond_2:
    slti $t3, $t1, 6       # if i < 6
    beq  $t3, $zero, end_2

loop_body_2:
    sw   $t1, 0($t0)       # *ptr_x = i
    addi $t0, $t0, 4       # ptr_x++ (increment by 4 for int)
    addi $t1, $t1, 1       # i++

    slti $t3, $t1, 6
    bne  $t3, $zero, loop_body_2

end_2:
    li   $v0, 10
    syscall
