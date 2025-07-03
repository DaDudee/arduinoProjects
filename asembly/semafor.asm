;
; arduino.asm
;
; Created: 28/11/2021 09:56:39
; Author : uporabnik
;


; Replace with your application code

loop:
	sbi DDRB, 4
	sbi PORTB, 4
	call one_sec_delay
	sbi DDRB, 3
	sbi PORTB, 3
	call one_sec_delay
	sbi DDRB, 2
	sbi PORTB, 2
	call one_sec_delay

	rjmp loop

one_sec_delay:
        ldi     r20, 20
        ldi     r21, 255
        ldi     r22, 255
delay:  dec     r22
        brne    delay
        dec     r21
        brne    delay
        dec     r20
        brne    delay

        ret


