# Ramanuja Mohanty
# 03/15/2026
# Activity 9
.data
	str: .space 6
.tex
main:
	la $t0, str		# load address of 'str' array into $t0
	li $t1, 0		# loop counter 'i'
	li $t2, 6		# loop limit
	li $t3, 0xa		# holds hex value for newline character

loop:
	add $t4, $t0. $t1	# calculate the exact address of str[i]
	sb $t3, 0($t4)		# store the 0xa into memory address

	addi $t1, $t1, 1	# i++
	blt $t1, $t2, loop	# if i < 6, branch up to loop

end_loop:
	li $v0, 10		# code 10 (exit)
	syscall
