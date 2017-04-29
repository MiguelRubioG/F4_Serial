			AREA	delay, CODE
			EXPORT	_delay_ms		;make _delay_ms visible
			ALIGN
_delay_ms	PROC
			
			PUSH {r4, lr}
outer		MOV  r1, #56000   ; ??? 24000=(72,000,000/1000)/3
inner   	SUBS r1, r1, #1 
			BNE  inner
			SUBS r0, r0, #1
			BNE  outer
			POP	 {r4, pc}
			ENDP
			END
