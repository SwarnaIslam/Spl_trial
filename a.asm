.data
label :.word 9
#data
.text
li $a0,9    #something
li $v0,  1
syscall

move $a0,$v0
li $v0 1
syscall
#.data