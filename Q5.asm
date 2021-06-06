| declare constant for 'prime' number
num: dc.w #63
move.w num, D2

| space in storage for result
result: ds.w 1

| skip everything else if even
evencheck: move.w num, D1
	and.w #1, D1 | result is 1 if prime, 0 if not prime
	beq finished
	move.w #1, D1

| create first divisor
firstdivisor: move.w num, D0
	ror.w D0
	and.w #32767, D0

| beginning of iterating through all numbers less than half
primecheck: dec.w D0
	dec.w D0
	beq finished
	inc.w D0
	move.w num, D2

dividing: sub.w D0, D2
	bgt dividing |responsible for loop for division
	beq notprime |in case where number is a factor hence num is not prime
	bmi notafactor |for going over (resulting in -ve) and so not a factor

| number isn't a factor
| so go back and attempt repeat for next number
notafactor: jmp primecheck

| set register for result if prime
notprime: move.w #0, D1

| store result in memory
finished: move.w D1, result
