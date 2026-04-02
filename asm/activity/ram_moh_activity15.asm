# Ramanuja Mohanty
# 04/01/26
# Activity 15

.text
main:
    # int a = 10;
    li $a0, 10          # Load argument a = 10 into $a0
    jal callee          # result = callee(a)

    # End Program
    li $v0, 10
    syscall

callee:
    # Non-leaf function: Must save $ra and $a0 (if needed later)
    addi $sp, $sp, -8   # Adjust stack for 2 items
    sw $ra, 4($sp)      # Save return address
    sw $a0, 0($sp)      # Save 'x' (needed after leaf call)

    jal leaf            # v = leaf(x) -> result in $v0

    addi $v0, $v0, 1    # v = leaf(x) + 1

    # Restore stack and return
    lw $a0, 0($sp)
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra

leaf:
    # Leaf function: No jal inside, so $ra is safe
    # y = w + 1;
    addi $v0, $a0, 1    # $v0 = w + 1
    jr $ra              # return y
