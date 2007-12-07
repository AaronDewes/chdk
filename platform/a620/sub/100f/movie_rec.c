#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[15]={0x20000,0x10000,0xC000,0x5800,0x2000, 0x387A, 0x1C6A, 0x1550, 0x9C5, 0x38D, 0x7813, 0x3C45, 0x2D34, 0x14B8,0x788};
long def_table2[15]={0x1CC39,0xE666, 0xACCD,0x4F33,0x1CCD,-0x2F5B,-0x170A,-0x1148,-0x7EB,-0x2E1,-0x59F0,-0x2BC6,-0x20D5,-0xF0C,-0x579};

long table1[15], table2[15];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<15;i++) {table1[i]=(def_table1[i]*a)/b; table2[i]=(def_table2[i]*a)/b;}
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                "STMFD   SP!, {R4,LR}\n"
                "SUB     SP, SP, #4\n"
                "MOV     R4, SP\n"
                "B       loc_FFD2C1D4\n"
"loc_FFD2C124:\n"                           
                "LDR     R3, =0x73988\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #0\n"
                "BNE     loc_FFD2C1C0\n"
                "SUB     R3, R12, #1\n"
                "CMP     R3, #0xA\n"
                "LDRLS   PC, [PC,R3,LSL#2]\n"
                "B       loc_FFD2C1C0\n"
                ".long loc_FFD2C170\n"
                ".long loc_FFD2C178\n"
                ".long loc_FFD2C190\n"
                ".long loc_FFD2C198\n"
                ".long loc_FFD2C1A0\n"
                ".long loc_FFD2C180\n"
                ".long loc_FFD2C1A8\n"
                ".long loc_FFD2C188\n"
                ".long loc_FFD2C1C0\n"
                ".long loc_FFD2C1B8\n"
                ".long loc_FFD2C1B0\n"
"loc_FFD2C170:\n"                           
                                        
                "BL      sub_FFD2C254\n"
                "B       loc_FFD2C1BC\n"
"loc_FFD2C178:\n"                           
                                        
                "BL      sub_FFD2C488\n"  
                "B       loc_FFD2C1BC\n"
"loc_FFD2C180:\n"                           
                                        
                "BL      sub_FFD2C918_my\n"  //------------>
                "B       loc_FFD2C1BC\n"
"loc_FFD2C188:\n"                           
                                        
                "BL      sub_FFD2CD6C\n"
                "B       loc_FFD2C1BC\n"
"loc_FFD2C190:\n"                           
                                        
                "BL      sub_FFD2CB90\n"
                "B       loc_FFD2C1BC\n"
"loc_FFD2C198:\n"                           
                                        
                "BL      sub_FFD2CF78\n"
                "B       loc_FFD2C1BC\n"
"loc_FFD2C1A0:\n"                           
                                        
                "BL      sub_FFD2D13C\n"
                "B       loc_FFD2C1BC\n"
"loc_FFD2C1A8:\n"                           
                                        
                "BL      sub_FFD2CE2C\n"
                "B       loc_FFD2C1BC\n"
"loc_FFD2C1B0:\n"                           
                                        
                "BL      sub_FFD2CF0C\n"
                "B       loc_FFD2C1BC\n"
"loc_FFD2C1B8:\n"                           
                                        
                "BL      sub_FFD2CBE0\n"
"loc_FFD2C1BC:\n"                           
                                        
                "LDR     R1, [SP]\n"
"loc_FFD2C1C0:\n"                           
                                        
                "LDR     R3, =0x738B8\n"
                "MOV     R2, #0\n"
                "STR     R2, [R1]\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFC1046C\n"
"loc_FFD2C1D4:\n"                           
                "LDR     R3, =0x738B4\n"
                "MOV     R1, R4\n"
                "LDR     R0, [R3]\n"
                "MOV     R2, #0\n"
                "BL      sub_FFC10054\n"
                "LDR     R0, [SP]\n"
                "LDR     R12, [R0]\n"
                "CMP     R12, #0xC\n"
                "MOV     R1, R0\n"
                "BNE     loc_FFD2C124\n"
                "LDR     R3, =0x738AC\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFC10E28\n"
                "BL      sub_FFC115F0\n"
                "ADD     SP, SP, #4\n"
                "LDMFD   SP!, {R4,PC}\n"

 );
}



void __attribute__((naked,noinline)) sub_FFD2C918_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"
                "LDR     R5, =0x739A4\n"
                "SUB     SP, SP, #0x34\n"
                "LDR     R3, [R5]\n"
                "CMP     R3, #3\n"
                "MOV     R4, R0\n"
                "MOVEQ   R3, #4\n"
                "STREQ   R3, [R5]\n"
                "LDR     R3, =0x73A4C\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R3]\n"
                "LDR     R2, [R5]\n"
                "CMP     R2, #4\n"
                "BNE     loc_FFD2CAC4\n"
                "ADD     R0, SP, #0x30\n"
                "ADD     R1, SP, #0x2C\n"
                "ADD     R2, SP, #0x28\n"
                "ADD     R3, SP, #0x24\n"
                "BL      sub_FFD2E0D8_my\n"   //------------>
                "CMP     R0, #0\n"
                "BNE     loc_FFD2C994\n"
                "LDR     R3, =0x73990\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #1\n"
                "BNE     loc_FFD2C9A8\n"
                "LDR     R2, =0x739E0\n"
                "LDR     R1, =0x739B8\n"
                "LDR     R12, [R2]\n"
                "LDR     R3, [R1]\n"
                "CMP     R12, R3\n"
                "BCC     loc_FFD2C9A8\n"
"loc_FFD2C994:\n"                           
                "BL      sub_FFD2CB08\n"
                "BL      sub_FFD2CD3C\n"
                "MOV     R3, #5\n"
                "STR     R3, [R5]\n"
                "B       loc_FFD2CAC4\n"
"loc_FFD2C9A8:\n"                           
                                        
                "LDR     R12, =0x739E8\n"
                "LDR     R11, =0x739F4\n"
                "LDMIB   R4, {R0-R2}\n"
                "LDR     R10, [R12]\n"
                "LDR     R7, [R11]\n"
                "LDR     R4, [SP,#0x2C]\n"
                "LDR     R5, [SP,#0x28]\n"
                "LDR     R6, [SP,#0x24]\n"
                "LDR     R8, =0x73994\n"
                "LDR     R3, [SP,#0x30]\n"
                "ADD     R12, SP, #0x20\n"
                "ADD     LR, SP, #0x1C\n"
                "MOV     R9, #1\n"
                "STMEA   SP, {R4-R6,R12}\n"
                "STR     R10, [SP,#0x10]\n"
                "STR     R7, [SP,#0x14]\n"
                "STR     LR, [SP,#0x18]\n"
                "STR     R9, [R8]\n"
                "BL      sub_FFC8428C\n"
                "LDR     R3, =0x738AC\n"
                "MOV     R1, #0x3E8\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFC10C40\n"
                "CMP     R0, #9\n"
                "BNE     loc_FFD2CA1C\n"
                "BL      sub_FFD2E898\n"
                "LDR     R3, =0x739A4\n"
                "LDR     R0, =0xFFD2C900\n"
                "B       loc_FFD2CA34\n"
"loc_FFD2CA1C:\n"                           
                "LDR     R5, [SP,#0x1C]\n"
                "CMP     R5, #0\n"
                "BEQ     loc_FFD2CA40\n"
                "BL      sub_FFD2E898\n"
                "LDR     R3, =0x739A4\n"
                "LDR     R0, =0xFFD2C90C\n"
"loc_FFD2CA34:\n"                           
                "STR     R9, [R3]\n"
                "BL      sub_FFD41C74\n"
                "B       loc_FFD2CAC4\n"
"loc_FFD2CA40:\n"                           
                "BL      sub_FFC84400\n"
                "LDR     R0, [SP,#0x30]\n"
                "LDR     R1, [SP,#0x20]\n"
                "BL      sub_FFD2E5BC\n"
                "LDR     R4, =0x739E0\n"
                "LDR     R3, [R4]\n"
                "ADD     R3, R3, #1\n"
                "LDR     R0, [SP,#0x20]\n"
                "MOV     R1, R11\n"
                "STR     R3, [R4]\n"
                "MOV     R2, R5\n"
                "BL      sub_FFD2D4A0_my\n"  //------------>
                "LDR     R3, =0x739CC\n"
                "LDR     R4, [R4]\n"
                "LDR     R1, [R3]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFEB88D4\n"
                "CMP     R0, #0\n"
                "BEQ     loc_FFD2CAA0\n"
                "LDR     R6, =0x73998\n"
                "LDR     R3, [R6]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FFD2CAB8\n"
                "B       loc_FFD2CAA4\n"
"loc_FFD2CAA0:\n"                           
                "LDR     R6, =0x73998\n"
"loc_FFD2CAA4:\n"                           
                "MOV     R0, R4\n"
                "LDR     R3, =0x73A28\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R3]\n"
                "STR     R5, [R6]\n"
"loc_FFD2CAB8:\n"                           
                "LDR     R2, =0x73994\n"
                "MOV     R3, #0\n"
                "STR     R3, [R2]\n"
"loc_FFD2CAC4:\n"                           
                                        
                "ADD     SP, SP, #0x34\n"
                "LDMFD   SP!, {R4-R11,PC}\n"

 );
}


void __attribute__((naked,noinline)) sub_FFD2E0D8_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"
                "LDR     R5, =0x73CF4\n"
                "SUB     SP, SP, #0x14\n"
                "LDR     LR, [R5]\n"
                "LDR     R12, =0x73D0C\n"
                "ADD     LR, LR, #1\n"
                "LDR     R4, [R12]\n"
                "STR     LR, [R5]\n"
                "LDR     R12, =0x73D88\n"
                "STR     R0, [SP,#0x10]\n"
                "STR     R1, [SP,#0xC]\n"
                "STR     R2, [SP,#8]\n"
                "STR     R3, [SP,#4]\n"
                "CMP     LR, R4\n"
                "LDR     R11, [R12]\n"
                "MOVHI   R0, #0x80000001\n"
                "BHI     loc_FFD2E570\n"
                "LDR     R3, =0x73D70\n"
                "MOV     R0, LR\n"
                "LDR     R1, [R3]\n"
                "BL      sub_FFEB88D4\n"
                "CMP     R0, #1\n"
                "BNE     loc_FFD2E2F8\n"
                "LDR     R0, =0x73D90\n"
                "LDR     R1, =0x73CE0\n"
                "LDR     R3, [R0]\n"
                "LDR     R2, [R1]\n"
                "CMP     R3, R2\n"
                "LDREQ   R3, =0x73D8C\n"
                "LDREQ   R5, [R3]\n"
                "MOVNE   R5, R2\n"
                "LDR     R3, =0x73CF4\n"
                "LDR     R2, =0x73D70\n"
                "LDR     R0, [R3]\n"
                "LDR     R1, [R2]\n"
                "BL      sub_FFEB8244\n"
                "LDR     R3, =0x73CE8\n"
                "ADD     R0, R0, #1\n"
                "AND     R0, R0, #1\n"
                "STR     R5, [R3,R0,LSL#2]\n"
                "LDR     R3, =0x73CDC\n"
                "LDR     R2, [R3]\n"
                "CMP     R5, R2\n"
                "BHI     loc_FFD2E1A8\n"
                "LDR     R4, =0x73D2C\n"
                "LDR     R3, [R4]\n"
                "ADD     R3, R5, R3\n"
                "ADD     R3, R3, #8\n"
                "CMP     R2, R3\n"
                "BCS     loc_FFD2E1AC\n"
"loc_FFD2E1A0:\n"                           
                                        
                "MOV     R0, #0x80000003\n"
                "B       loc_FFD2E570\n"
"loc_FFD2E1A8:\n"                           
                "LDR     R4, =0x73D2C\n"
"loc_FFD2E1AC:\n"                           
                "LDR     R3, [R4]\n"
                "LDR     R2, =0x73D90\n"
                "ADD     R1, R5, R3\n"
                "LDR     R3, [R2]\n"
                "ADD     R2, R1, #8\n"
                "CMP     R2, R3\n"
                "BLS     loc_FFD2E1F8\n"
                "LDR     R2, =0x73D8C\n"
                "LDR     R0, =0x73CDC\n"
                "RSB     R3, R3, R1\n"
                "LDR     R1, [R2]\n"
                "ADD     R3, R3, #8\n"
                "LDR     R2, [R0]\n"
                "ADD     R1, R1, R3\n"
                "CMP     R2, R1\n"
                "BCC     loc_FFD2E1A0\n"
                "LDR     R3, =0x73CE0\n"
                "STR     R1, [R3]\n"
                "B       loc_FFD2E200\n"
"loc_FFD2E1F8:\n"                           
                "LDR     R3, =0x73CE0\n"
                "STR     R2, [R3]\n"
"loc_FFD2E200:\n"                           
                "LDR     R3, [R4]\n"
                "LDR     R12, =0x73D40\n"
                "ADD     R3, R3, #0x18\n"
                "LDR     R2, [R12,#4]\n"
                "MOV     R0, R3\n"
                "MOV     R1, #0\n"
                "CMP     R1, R2\n"
                "BHI     loc_FFD2E444\n"
                "BNE     loc_FFD2E230\n"
                "LDR     R3, [R12]\n"
                "CMP     R0, R3\n"
                "BHI     loc_FFD2E444\n"
"loc_FFD2E230:\n"                           
                "LDR     R4, [R4]\n"
                "LDR     LR, =0x73D48\n"
                "STR     R4, [SP]\n"
                "LDR     R12, =0x73D40\n"
                "LDR     R3, =0x73CF4\n"
                "LDMIA   LR, {R7,R8}\n"
                "LDMIA   R12, {R5,R6}\n"
                "LDR     R10, [R3]\n"
                "LDR     R2, =0x73D70\n"
                "MOV     R3, R4\n"
                "MOV     R4, #0\n"
                "ADDS    R7, R7, R3\n"
                "ADC     R8, R8, R4\n"
                "LDR     R9, [R2]\n"
                "SUBS    R5, R5, R3\n"
                "SBC     R6, R6, R4\n"
                "MVN     R2, #0\n"
                "MVN     R1, #0x17\n"
                "ADDS    R5, R5, R1\n"
                "MOV     R4, #0\n"
                "MOV     R3, #0x18\n"
                "ADC     R6, R6, R2\n"
                "ADDS    R7, R7, R3\n"
                "ADC     R8, R8, R4\n"
                "STMIA   R12, {R5,R6}\n"
                "SUB     R0, R10, #1\n"
                "MOV     R1, R9\n"
                "STMIA   LR, {R7,R8}\n"
                "BL      sub_FFEB8244\n"
                "CMP     R10, #1\n"
                "MLA     R0, R9, R0, R0\n"
                "BEQ     loc_FFD2E2F8\n"
                "SUB     R3, R0, #1\n"
                "MOV     R3, R3,LSL#4\n"
                "ADD     R4, R11, #0x10\n"
                "ADD     R5, R11, #0x14\n"
                "LDR     R1, [R5,R3]\n"
                "LDR     R2, [R4,R3]\n"
                "LDR     LR, =0x62773130\n"
                "ADD     R2, R2, R1\n"
                "MOV     R3, R0,LSL#4\n"
                "ADD     R2, R2, #8\n"
                "MOV     R0, #0\n"
                "ADD     R12, R11, #0xC\n"
                "ADD     R1, R11, #8\n"
                "STR     LR, [R1,R3]\n"
                "STR     R0, [R12,R3]\n"
                "STR     R2, [R4,R3]\n"
                "LDR     R0, [SP]\n"
                "STR     R0, [R5,R3]\n"
"loc_FFD2E2F8:\n"                           
                                        
                "LDR     R2, =0x73CE0\n"
                "LDR     R3, =0x73D90\n"
                "LDR     R1, [R2]\n"
                "LDR     R0, [R3]\n"
                "ADD     R3, R1, #9\n"
                "CMP     R3, R0\n"
                "BLS     loc_FFD2E334\n"
                "LDR     R2, =0x73D8C\n"
                "LDR     R3, [R2]\n"
                "ADD     R3, R3, R1\n"
                "RSB     R3, R0, R3\n"
                "LDR     R0, [SP,#0x10]\n"
                "ADD     R3, R3, #8\n"
                "STR     R3, [R0]\n"
                "B       loc_FFD2E340\n"
"loc_FFD2E334:\n"                           
                "ADD     R3, R1, #8\n"
                "LDR     R1, [SP,#0x10]\n"
                "STR     R3, [R1]\n"
"loc_FFD2E340:\n"                           
                "LDR     R2, [SP,#0x10]\n"
                "LDR     R1, =0x73D3C\n"
                "LDR     R3, =0x73D90\n"
                "LDR     R12, [R2]\n"
                "LDR     R2, [R1]\n"
                "LDR     R0, [R3]\n"
                "ADD     R3, R12, R2\n"
                "CMP     R3, R0\n"
                "BLS     loc_FFD2E394\n"
                "LDR     R2, [SP,#0xC]\n"
                "RSB     R0, R12, R0\n"
                "STR     R0, [R2]\n"
                "LDR     R2, =0x73D8C\n"
                "LDR     R3, [R1]\n"
                "LDR     R1, [R2]\n"
                "RSB     R3, R0, R3\n"
                "LDR     R0, [SP,#8]\n"
                "STR     R1, [R0]\n"
                "LDR     R1, [SP,#4]\n"
                "STR     R3, [R1]\n"
                "B       loc_FFD2E3B0\n"
"loc_FFD2E394:\n"                           
                "LDR     R0, [SP,#0xC]\n"
                "STR     R2, [R0]\n"
                "LDR     R1, [SP,#4]\n"
                "MOV     R3, #0\n"
                "STR     R3, [R1]\n"
                "LDR     R2, [SP,#8]\n"
                "STR     R3, [R2]\n"
"loc_FFD2E3B0:\n"                           
                "LDR     R0, =0x73CE0\n"
                "LDR     R1, =0x73CDC\n"
                "LDR     R3, [R0]\n"
                "LDR     R2, [R1]\n"
                "CMP     R3, R2\n"
                "BHI     loc_FFD2E3DC\n"
                "LDR     R0, [SP,#0xC]\n"
                "LDR     R3, [R0]\n"
                "ADD     R3, R12, R3\n"
                "CMP     R2, R3\n"
                "BCC     loc_FFD2E1A0\n"
"loc_FFD2E3DC:\n"                           
                "LDR     R1, [SP,#8]\n"
                "LDR     R2, [R1]\n"
                "CMP     R2, #0\n"
                "BEQ     loc_FFD2E410\n"
                "LDR     R3, =0x73CDC\n"
                "LDR     R1, [R3]\n"
                "CMP     R2, R1\n"
                "BHI     loc_FFD2E410\n"
                "LDR     R0, [SP,#4]\n"
                "LDR     R3, [R0]\n"
                "ADD     R3, R2, R3\n"
                "CMP     R1, R3\n"
                "BCC     loc_FFD2E1A0\n"
"loc_FFD2E410:\n"                           
                                        
                "LDR     R3, =0x73D3C\n"
                "LDR     R0, =0x73D40\n"
                "LDR     R2, [R3]\n"
                "LDR     R3, [R0,#4]\n"
                "ADD     R2, R2, #0x18\n"
                "MOV     R1, R2\n"
                "MOV     R2, #0\n"
                "CMP     R2, R3\n"
                "BHI     loc_FFD2E444\n"
                "BNE     loc_FFD2E44C\n"
                "LDR     R3, [R0]\n"
                "CMP     R1, R3\n"
                "BLS     loc_FFD2E44C\n"
"loc_FFD2E444:\n"                           
                                        
                "MOV     R0, #0x80000005\n"
                "B       loc_FFD2E570\n"
"loc_FFD2E44C:\n"                           
                                        
                "LDR     R1, =0x73D24\n"
                "LDR     R0, =0x73D70\n"
                "LDR     R3, [R1]\n"
                "LDR     R2, [R0]\n"
                "ADD     R3, R3, R2,LSL#4\n"
                "ADD     R3, R3, R3,LSL#2\n"
                "LDR     R12, =0x73D40\n"
                "MOV     R3, R3,LSL#1\n"
                "ADD     R3, R3, #0xA0\n"
                "LDR     R2, [R12,#4]\n"
                "MOV     R0, R3\n"
                "MOV     R1, #0\n"
                "CMP     R1, R2\n"
                "BHI     loc_FFD2E494\n"
                "BNE     loc_FFD2E4B8\n"
                "LDR     R3, [R12]\n"
                "CMP     R0, R3\n"
                "BLS     loc_FFD2E4B8\n"
"loc_FFD2E494:\n"                           
                "LDR     R4, =0x73D58\n"
                "LDR     R1, [R4]\n"
                "CMP     R1, #0\n"
                "BNE     loc_FFD2E4B8\n"
                "MOV     R0, #0x3140\n"
                "ADD     R0, R0, #8\n"
                "BL      sub_FFD45E4C\n"
                "MOV     R3, #1\n"
                "STR     R3, [R4]\n"
"loc_FFD2E4B8:\n"                           
                                        
                "LDR     R1, =0x73D24\n"
                "LDR     R0, =0x73D70\n"
                "LDR     R2, [R1]\n"
                "LDR     R3, [R0]\n"
                "LDR     R0, =0x73D48\n"
                "ADD     R2, R2, R3,LSL#4\n"
                "MVN     R3, #0x9F\n"
                "ADD     R2, R2, R2,LSL#2\n"
                "ADD     R3, R3, #0x40000000\n"
                "SUB     R3, R3, R2,LSL#1\n"
                "LDR     R1, [R0,#4]\n"
                "MOV     R4, R3\n"
                "MOV     R5, #0\n"
                "CMP     R1, R5\n"
                "BHI     loc_FFD2E504\n"
                "BNE     loc_FFD2E528\n"
                "LDR     R3, [R0]\n"
                "CMP     R3, R4\n"
                "BLS     loc_FFD2E528\n"
"loc_FFD2E504:\n"                           
                "LDR     R4, =0x73D58\n"
                "LDR     R1, [R4]\n"
                "CMP     R1, #0\n"
                "BNE     loc_FFD2E528\n"
                "MOV     R0, #0x3140\n"
                "ADD     R0, R0, #8\n"
                "BL      sub_FFD45E4C\n"
                "MOV     R3, #1\n"
                "STR     R3, [R4]\n"
"loc_FFD2E528:\n"                           
                                        
                "LDR     R3, =0x73D48\n"
                "LDR     R12, =0x73D3C\n"
                "LDMIA   R3, {R1,R2}\n"
                "LDR     R0, [R12]\n"
                "MOV     R4, #0\n"
                "MOV     R3, #0x18\n"
                "ADDS    R1, R1, R0\n"
                "ADC     R2, R2, #0\n"
                "ADDS    R1, R1, R3\n"
                "ADC     R2, R2, R4\n"
                "CMP     R2, #0\n"
                "BHI     loc_FFD2E564\n"
                "BNE     loc_FFD2E56C\n"
                "CMP     R1, #0x40000000\n"
//              "BLS     loc_FFD2E56C\n"   // - 
                "B       loc_FFD2E56C\n"     //+

"loc_FFD2E564:\n"                           
                "MOV     R0, #0x80000007\n"
                "B       loc_FFD2E570\n"
"loc_FFD2E56C:\n"                           
                                        
                "MOV     R0, #0\n"
"loc_FFD2E570:\n"                           
                                        
                "ADD     SP, SP, #0x14\n"
                "LDMFD   SP!, {R4-R11,PC}\n"

 );
}

        

void __attribute__((naked,noinline)) sub_FFD2D4A0_my(){
 asm volatile(
                "CMP     R2, #1\n"
                "STMFD   SP!, {R4-R7,LR}\n"
                "MOV     R7, R0\n"
                "MOV     R6, R1\n"
                "MOVEQ   R3, #0x79\n"
                "STREQ   R3, [R6]\n"
                "LDMEQFD SP!, {R4-R7,PC}\n"
                "LDR     R12, =0x73A58\n"
                "LDR     R0, [R12]\n"
                "LDR     R3, =0x73A60\n"
                "CMP     R0, #0\n"
                "LDR     R1, [R3]\n"
                "BEQ     loc_FFD2D4E8\n"
                "LDR     R2, =0x73A64\n"
                "LDR     R3, [R2]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FFD2D4FC\n"
                "B       loc_FFD2D4EC\n"
"loc_FFD2D4E8:\n"                           
                "LDR     R2, =0x73A64\n"
"loc_FFD2D4EC:\n"                           
                "MOV     R3, #0\n"
                "STR     R3, [R2]\n"
                "STR     R7, [R12]\n"
                "B       loc_FFD2D5B0\n"
"loc_FFD2D4FC:\n"                           
                "LDR     R3, =0x73A5C\n"
                "LDR     R2, [R3]\n"
                "LDR     R5, =table1\n" //+ 0xFFD2D308
                "MOV     LR, R2,LSL#2\n"
                "LDR     R3, [R5,LR]\n"
                "LDR     R4, =table2\n" //+ 0xFFD2D344
                "RSB     R12, R3, R0\n"
                "LDR     R2, [R4,LR]\n"
                "CMP     R12, #0\n"
                "RSB     R0, R2, R0\n"
                "BLE     loc_FFD2D55C\n"
                "ADD     R3, R5, #0x14\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R12\n"
                "ADDGE   R1, R1, #1\n"
                "BGE     loc_FFD2D550\n"
                "ADD     R3, R5, #0x28\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R12\n"
                "ADDGE   R1, R1, #2\n"
                "ADDLT   R1, R1, #3\n"
"loc_FFD2D550:\n"                           
           //   "CMP     R1, #0xE\n"  //-
           //   "MOVGE   R1, #0xE\n"  //-
                "CMP     R1, #0x1A\n" //+
                "MOVGE   R1, #0x1A\n" //+

                "B       loc_FFD2D594\n"
"loc_FFD2D55C:\n"                           
                "CMP     R0, #0\n"
                "BGE     loc_FFD2D594\n"
                "ADD     R3, R4, #0x14\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R0\n"
                "SUBLE   R1, R1, #1\n"
                "BLE     loc_FFD2D58C\n"
                "ADD     R3, R4, #0x28\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R0\n"
                "SUBLE   R1, R1, #2\n"
                "SUBGT   R1, R1, #3\n"
"loc_FFD2D58C:\n"                           
                "CMP     R1, #0\n"
                "MOVLT   R1, #0\n"
"loc_FFD2D594:\n"                           
                                        
                "LDR     R0, =0x73A60\n"
                "LDR     R3, [R0]\n"
                "CMP     R1, R3\n"
                "LDRNE   R2, =0x73A64\n"
                "MOVNE   R3, #1\n"
                "STRNE   R1, [R0]\n"
                "STRNE   R3, [R2]\n"
"loc_FFD2D5B0:\n"                           
                "LDR     R3, =0x73A60\n"
           //   "LDR     R1, =0x6CBC\n"  // -
                "LDR     R1, =video_mode\n"  //+
                "LDR     R0, [R3]\n"
                "LDR     R2, =CompressionRateTable\n" // + 0xFFD2D2CC
                "LDR     R12, [R1]\n"
                "LDR     R12, [R12]\n"    //+
                "LDR     LR, [R2,R0,LSL#2]\n"
                "LDR     R3, =0x73A58\n"
                "CMP     R12, #1\n"
                "STR     R7, [R3]\n"
                "STR     LR, [R6]\n"
//              "MOVEQ   R3, #0xB\n"    // -

                "LDREQ   R3, =video_quality\n"   // +
                "LDREQ   R3, [R3]\n"             // +
                "LDREQ   R3, [R3]\n"             // +

                "STREQ   R3, [R6]\n"
                "LDMFD   SP!, {R4-R7,PC}\n"

 );
}
