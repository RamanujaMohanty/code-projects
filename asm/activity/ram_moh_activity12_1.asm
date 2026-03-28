# Ramanuja Mohanty
# 03/27/26
# Activity 12-1

.data
    str: .space 6

.text
main:
    la   $t0, str          # ptr_str = &str[0]
    li   $t1, 0            # i = 0
    li   $t2, 0xa          # value = 0xa

loop_cond_1:
    slti $t3, $t1, 6       # if i < 6 (same as i <= 5)
    beq  $t3, $zero, end_1

loop_body_1:
    sb   $t2, 0($t0)       # *ptr_str = 0xa
    addi $t0, $t0, 1       # ptr_str++
    addi $t1, $t1, 1       # i++

    slti $t3, $t1, 6
    bne  $t3, $zero, loop_body_1

end_1:
    li   $v0, 10
    syscall
