MODULE Module1
    ! ## =========================================================================== ## 
    ! MIT License
    ! Copyright (c) 2022 Roman Parak
    ! Permission is hereby granted, free of charge, to any person obtaining a copy
    ! of this software and associated documentation files (the "Software"), to deal
    ! in the Software without restriction, including without limitation the rights
    ! to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    ! copies of the Software, and to permit persons to whom the Software is
    ! furnished to do so, subject to the following conditions:
    ! The above copyright notice and this permission notice shall be included in all
    ! copies or substantial portions of the Software.
    ! THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    ! IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    ! FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    ! AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    ! LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    ! OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    ! SOFTWARE.
    ! ## =========================================================================== ## 
    ! Author   : Roman Parak
    ! Email    : Roman.Parak@outlook.com
    ! Github   : https://github.com/rparak
    ! File Name: T_ROB1/Module1.mod
    ! ## =========================================================================== ##  
    
    ! Test no. 1:
    VAR dnum IN_UINT_t1 := 12345;
    VAR dnum OUT_BYTE_t1{2};
    VAR dnum OUT_UINT_t1;
    
    ! Test no. 2:
    VAR dnum IN_UDINT_t2 := 1234567;
    VAR dnum OUT_BYTE_t2{4};
    VAR dnum OUT_UDINT_t2;
    
    ! Test no. 3:
    VAR byte IN_BYTE_t3 := 123;
    VAR byte OUT_BIT_t3{8};
    VAR byte OUT_BYTE_t3;
    
    ! Compare results variable.
    VAR bool RES_VAR{3};
    
    ! Description:                             !
    !   Program Main Cycle:                    !
    !       Type        : Semistatic or Normal !
    !       TrustLeve   : No Safety or N/A     !
    !       Motion Task : N/A or YES           ! 
    PROC Main()
        !   Description:                                                                    !
        !       Simple tests to verify the functionality of individual functions to convert !
        !       data from the custom library.                                               !
        
        ! 1\ Test No. 1: UINT <-> BYTE[]
        !   Converting uint (16-bit -> 2-byte) to multiple bytes.
        Convert_UINT_To_USINT_Array IN_UINT_t1, OUT_BYTE_t1;

        ! Check result: 
        !   Converting multiple bytes to an uint (16-bit -> 2-byte).
        Convert_USINT_Array_To_UINT OUT_BYTE_t1, OUT_UINT_t1;
        
        ! Compare results.
        IF IN_UINT_t1 = OUT_UINT_t1 THEN
            RES_VAR{1} := True;
        ELSE
            RES_VAR{1} := False;
        ENDIF
        
        ! 2\ Test No. 2: UDINT <-> BYTE[]
        !   Converting udint (32-bit -> 4-byte) to multiple bytes.
        Convert_UDINT_To_USINT_Array IN_UDINT_t2, OUT_BYTE_t2;
        
        ! Check result: 
        !   Converting multiple bytes to an udint (32-bit -> 4-byte).
        Convert_USINT_Array_To_UDINT OUT_BYTE_t2, OUT_UDINT_t2;
        
        ! Compare results.
        IF IN_UDINT_t2 = OUT_UDINT_t2 THEN
            RES_VAR{2} := True;
        ELSE
            RES_VAR{2} := False;
        ENDIF
        
        ! 3\ Test No. 3:  BYTE <-> BIT[]
        !   Converting byte to multiple bits
        Convert_USINT_To_BOOL_Array IN_BYTE_t3, OUT_BIT_t3;
        
        ! Check result: 
        !   Converting multiple bits to byte.
        Convert_BOOL_Array_To_USINT OUT_BIT_t3, OUT_BYTE_t3;
        
        ! Compare results.
        IF IN_BYTE_t3 = OUT_BYTE_t3 THEN
            RES_VAR{3} := True;
        ELSE
            RES_VAR{3} := False;
        ENDIF
    ENDPROC
ENDMODULE
