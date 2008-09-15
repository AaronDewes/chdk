void __attribute__((naked,noinline)) init_file_modules_task(){
 asm volatile(
                "STMFD   SP!, {R4,LR}\n"
                "BL      _Unmount_FileSystem\n" // + 
                "BL      sub_FFA968A8\n"
                "SUBS    R4, R0, #0\n"
                "MOV     R0, #0x5000\n"
                "MOV     R1, #0\n"
                "ADD     R0, R0, #6\n"
                "BEQ     loc_FF98B2BC\n"
                "BL      sub_FF964DEC\n"
"loc_FF98B2BC:\n"
                "BL      sub_FFA968C0_my\n"  //----------------->
                "MOV     R0, #0x5000\n"
                "CMP     R4, #0\n"
                "MOV     R1, R4\n"
                "ADD     R0, R0, #6\n"
                "LDMNEFD SP!, {R4,PC}\n"
                "LDMFD   SP!, {R4,LR}\n"
                "B       sub_FF964DEC\n"

 );
}

void __attribute__((naked,noinline)) sub_FFA968C0_my(){
 asm volatile(
                "STR     LR, [SP,#-4]!\n"
                "BL      Mount_FileSystem_my\n"  //-------------->
                "MOV     R1, #0x40000\n"
                "MOV     R0, #0x320000\n"
                "BL      sub_FF866D84\n"
                "BL      sub_FF868100\n"
                "BL      sub_FF8663A4\n"
                "BL      sub_FF9A337C\n"
                "AND     R0, R0, #0xFF\n"
                "BL      sub_FF82DC30\n"
                "BL      sub_FF9A337C\n"
                "AND     R0, R0, #0xFF\n"
                "BL      sub_FF85ED80\n"
                "BL      sub_FF9A338C\n"
                "AND     R0, R0, #0xFF\n"
                "BL      sub_FF82DCA8\n"
                "LDR     R2, =0xAA18\n"
                "MOV     R3, #1\n"
                "STR     R3, [R2]\n"
                "LDR     PC, [SP],#4\n"
 );
}

void __attribute__((naked,noinline)) Mount_FileSystem_my(){
 asm volatile(
                "STMFD   SP!, {R4,R5,LR}\n"
                "MOV     R4, #0\n"
                "MOV     R0, R4\n"
                "BL      sub_FF869720\n"
                "MOV     R0, R4\n"
                "BL      sub_FF869770\n"
                "MOV     R0, R4\n"
                "BL      sub_FF869A84_my\n"  //----------------->
                "MOV     R5, R0\n"
                "MOV     R0, R4\n"
                "BL      sub_FF869B0C\n"
                "LDR     R4, =0x2C538\n"
                "AND     R5, R5, R0\n"
                "MOV     R2, R5\n"
                "MOV     R0, R4\n"
                "LDR     R1, [R4,#0x3C]\n"
                "BL      sub_FF869C84\n"
                "STR     R0, [R4,#0x40]\n"
                "LDMFD   SP!, {R4,R5,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FF869A84_my(){
 asm volatile(
                "STMFD   SP!, {R4-R7,LR}\n"
                "LDR     R7, =0x2CE8\n"
                "LDR     R3, [R7]\n"
                "MOV     R4, R0\n"
                "CMP     R3, #0\n"
                "ADD     R3, R4, R4,LSL#1\n"
                "RSB     R3, R4, R3,LSL#3\n"
                "LDR     R6, =0x2C570\n"
                "MOV     R5, R3,LSL#2\n"
                "MOV     R1, R4\n"
                "BNE     loc_FF869AF8\n"
                "LDR     R0, [R6,R5]\n"
                "BL      sub_FF869818_my\n"  //----------------->
                "SUBS    R3, R0, #0\n"
                "MOV     R1, R4\n"
                "BEQ     loc_FF869AD0\n"
                "LDR     R0, [R6,R5]\n"
                "BL      sub_FF869968\n"
                "MOV     R3, R0\n"
"loc_FF869AD0:\n"
                "CMP     R3, #0\n"
                "MOV     R0, R4\n"
                "BEQ     loc_FF869AE4\n"
                "BL      sub_FF868EE8\n"
                "MOV     R3, R0\n"
"loc_FF869AE4:\n"
                "CMP     R3, #0\n"
                "MOV     R0, R3\n"
                "MOVNE   R3, #1\n"
                "STRNE   R3, [R7]\n"
                "LDMFD   SP!, {R4-R7,PC}\n"
"loc_FF869AF8:\n"
                "MOV     R0, #1\n"
                "LDMFD   SP!, {R4-R7,PC}\n"

 );
}

void __attribute__((naked,noinline)) sub_FF869818_my(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n"
                "MOV     R5, R1\n"
                "MOV     R8, R5,LSL#1\n"
                "ADD     R3, R8, R5\n"
                "LDR     R2, =0x2C574\n"
                "SUB     SP, SP, #8\n"
                "RSB     R3, R5, R3,LSL#3\n"
                "LDR     R1, [R2,R3,LSL#2]\n"
                "MOV     R6, #0\n"
                "STR     R6, [SP]\n"
                "MOV     R7, R0\n"
                "STR     R6, [SP,#4]\n"
                "CMP     R1, #5\n"
                "LDRLS   PC, [PC,R1,LSL#2]\n"
                "B       loc_FF869914\n"
                ".long loc_FF8698B8\n"
                ".long loc_FF86986C\n"
                ".long loc_FF86986C\n"
                ".long loc_FF86986C\n"
                ".long loc_FF86986C\n"
                ".long loc_FF869904\n"
"loc_FF86986C:\n"
                "MOV     R0, #2\n"
                "MOV     R1, #0x200\n"
                "MOV     R2, #0\n"
                "BL      sub_FF812954\n"
                "SUBS    R6, R0, #0\n"
                "BEQ     loc_FF86994C\n"
                "ADD     R12, R8, R5\n"
                "RSB     R12, R5, R12,LSL#3\n"
                "LDR     R4, =0x2C584\n"
                "MOV     R0, R7\n"
                "MOV     R1, #0\n"
                "MOV     R2, #1\n"
                "MOV     R3, R6\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R4,R12,LSL#2]\n"
                "CMP     R0, #1\n"
                "BNE     loc_FF8698C0\n"
                "MOV     R0, #2\n"
                "BL      sub_FF8129A0\n"
"loc_FF8698B8:\n"
                "MOV     R0, #0\n"
                "B       loc_FF86994C\n"
"loc_FF8698C0:\n"
                "MOV     R0, R7\n"
                "BL      sub_FF87CDB4\n"
                "MOV     R1, R0\n"
                "ADD     R2, SP, #4\n"
                "MOV     R3, SP\n"
                "MOV     R0, R6\n"

                "STMFD   SP!, {R4-R11,LR}\n" // +
                "BL      mbr_read\n"    //-----------> 
                "LDMFD   SP!, {R4-R11,LR}\n" // +

          //    "BL      sub_FF868FEC\n"  // original  
                "MOV     R4, R0\n"
                "MOV     R0, #2\n"
                "BL      sub_FF8129A0\n"
                "CMP     R4, #0\n"
                "BNE     loc_FF869924\n"
                "MOV     R0, R7\n"
                "STR     R4, [SP,#4]\n"
                "BL      sub_FF87CDB4\n"
                "STR     R0, [SP]\n"
                "B       loc_FF869924\n"
"loc_FF869904:\n"
                "MOV     R3, #0\n"
                "MOV     R2, #0x2000\n"
                "STMEA   SP, {R2,R3}\n"
                "B       loc_FF869924\n"
"loc_FF869914:\n"
                "MOV     R1, #0x280\n"
                "LDR     R0, =0xFF8695F8\n"
                "ADD     R1, R1, #1\n"
                "BL      sub_FF813E68\n"
"loc_FF869924:\n"
                "LDR     R2, =0x2C538\n"
                "ADD     R3, R8, R5\n"
                "LDMFD   SP, {R0,R12}\n"
                "RSB     R3, R5, R3,LSL#3\n"
                "MOV     R3, R3,LSL#2\n"
                "ADD     R1, R2, #0x48\n"
                "ADD     R2, R2, #0x44\n"
                "STR     R0, [R1,R3]\n"
                "STR     R12, [R2,R3]\n"
                "MOV     R0, #1\n"
"loc_FF86994C:\n"
                "ADD     SP, SP, #8\n"
                "LDMFD   SP!, {R4-R8,PC}\n"
 );
}

