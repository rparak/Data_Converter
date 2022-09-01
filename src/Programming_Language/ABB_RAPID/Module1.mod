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
    VAR num IN_UINT_t1;
    VAR num OUT_BYTE_t1{2};
    VAR num OUT_UINT_t1;
    
    ! Test no. 2:
    VAR num IN_UDINT_t2;
    VAR num OUT_BYTE_t2{4};
    VAR num OUT_UDINT_t2;
    
    ! Test no. 3:
    VAR num IN_BYTE_t3;
    VAR num OUT_BIT_t3{8};
    VAR num OUT_BYTE_t3;
    
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
        !       data from your own library.                                                 !
        
        ! 1\ Test No. 1: UINT <-> BYTE[]
        !   Converting uint (16-bit -> 2-byte) to multiple bytes.
        IN_UINT_t1 := 12345;
        Convert_UINT_To_Multiple_BYTES IN_UINT_t1, OUT_BYTE_t1;
        
        ! Check result: 
        !   Converting multiple bytes to an uint (16-bit -> 2-byte).
        Convert_Multiple_BYTES_To_UINT OUT_BYTE_t1, OUT_UINT_t1;
        
        ! Compare results.
        IF IN_UINT_t1 = OUT_UINT_t1 THEN
            RES_VAR{1} := True;
        ELSE
            RES_VAR{1} := False;
        ENDIF
        
        ! 2\ Test No. 2: UDINT <-> BYTE[]
        !   Converting udint (32-bit -> 4-byte) to multiple bytes.
        IN_UDINT_t2 := 1234567;
        Convert_UDINT_To_Multiple_BYTES IN_UDINT_t2, OUT_BYTE_t2;
        
        ! Check result: 
        !   Converting multiple bytes to an udint (32-bit -> 4-byte).
        Convert_Multiple_BYTES_To_UDINT OUT_BYTE_t2, OUT_UDINT_t2;
        
        ! Compare results.
        IF IN_UDINT_t2 = OUT_UDINT_t2 THEN
            RES_VAR{2} := True;
        ELSE
            RES_VAR{2} := False;
        ENDIF
        
        ! 3\ Test No. 3:  BYTE <-> BIT[]
        !   Converting byte to multiple bits
        IN_BYTE_t3 := 123;
        Convert_BYTE_To_Multiple_BITS IN_BYTE_t3, OUT_BIT_t3;
        
        ! Check result: 
        !   Converting multiple bits to byte.
        Convert_Multiple_BITS_To_BYTE OUT_BIT_t3, OUT_BYTE_t3;
        
        ! Compare results.
        IF IN_BYTE_t3 = OUT_BYTE_t3 THEN
            RES_VAR{3} := True;
        ELSE
            RES_VAR{3} := False;
        ENDIF
    ENDPROC


    ! Description:                                                              !
    !   Library to converts base data types to an array of bytes, and an array  !
    !   of bytes to base data types as well as byte to an array of bits, and an !
    !   array of bits to byte.                                                  !
    !
    !   Note:
    !       A byte is a unit of storage in a computer which contains 8-bits and !
    !       can store 256 different values: 0 to 255.                           !

    PROC Convert_UINT_To_Multiple_BYTES(num IN_UINT, INOUT num OUT_BYTE{*})
        ! Description:                                                                 !
        !   Conversion of input value (UINT - 16-bit) into a vector of values (BYTES). !
        !                                                                              !
        ! Args:                                                                        !
        !   [1] IN_UINT [num]: Input uint (2 BYTEs).                                   !         
        !                                                                              !
        ! Returns:                                                                     !
        !   [1] OUT_BYTE [num array{2}]: Output multiple bytes.                        !
        !                                                                              !
        ! EXAMPLE:                                                                     !
        !   Read Inputs:                                                               !
        !       IN_UINT := possible values range from 0 to 65535                       !
        !   Call Procedure:                                                            !
        !       Convert_UINT_To_Multiple_BYTES IN_UINT, OUT_BYTE                       !
        !   Write Outputs:                                                             !
        !       OUT_UDINT{1 .. 2} := possible values range from 0 to 255               !
        
        OUT_BYTE{1} := IN_UINT MOD 256;
        OUT_BYTE{2} := Trunc(IN_UINT/256\Dec:=0) MOD 256;
    ENDPROC

    PROC Convert_Multiple_BYTES_To_UINT(num IN_BYTE{*}, INOUT num OUT_UINT)
        ! Description:                                                           !
        !   Conversion of a vector of values (BYTES) to a value (UINT - 16-bit). !
        !                                                                        !
        ! Args:                                                                  !
        !   [1] IN_BYTE [num array{2}]: Input multiple bytes.                    !
        !                                                                        !
        ! Returns:                                                               !
        !   [1] OUT_UINT [num]: Output uint (2 BYTEs).                           !
        !                                                                        !
        ! EXAMPLE:                                                               !
        !   Read Inputs:                                                         !
        !       IN_BYTE{1 .. 2} := possible values range from 0 to 255           !
        !   Call Procedure:                                                      !
        !       Convert_Multiple_BYTES_To_UINT IN_BYTE, OUT_UINT                 !
        !   Write Outputs:                                                       !
        !       OUT_UDINT := possible values range from 0 to 65535               !
 
        OUT_UINT := IN_BYTE{1} + IN_BYTE{2} * Pow(256,1);
    ENDPROC
    
    PROC Convert_UDINT_To_Multiple_BYTES(num IN_UDINT, INOUT num OUT_BYTE{*})
        ! Description:                                                                  !
        !   Conversion of input value (UDINT - 32-bit) into a vector of values (BYTES). !
        !                                                                               !
        ! Args:                                                                         !
        ! [1] IN_UINT [num]: Input uint (4 BYTEs).                                      !
        !                                                                               !
        ! Returns:                                                                      !
        ! [1] OUT_BYTE [num array{4}]: Output multiple bytes.                           ! 
        !                                                                               !
        ! EXAMPLE:                                                                      !
        !   Read Inputs:                                                                !
        !       IN_UINT := possible values range from 0 to 4294967295                   !
        !   Call Procedure:                                                             !
        !       Convert_UDINT_To_Multiple_BYTES IN_UDINT, OUT_BYTE                      !
        !   Write Outputs:                                                              !
        !       OUT_UDINT{1 .. 4} := possible values range from 0 to 255                !
        
        OUT_BYTE{1} := IN_UDINT MOD 256;
        OUT_BYTE{2} := Trunc(IN_UDINT/256\Dec:=0) MOD 256;
        OUT_BYTE{3} := Trunc(Trunc(IN_UDINT/256\Dec:=0)/256\Dec:=0) MOD 256;
        OUT_BYTE{4} := Trunc(Trunc(Trunc(IN_UDINT/256\Dec:=0)/256\Dec:=0)/256\Dec:=0) MOD 256;
    ENDPROC
    
    PROC Convert_Multiple_BYTES_To_UDINT(num IN_BYTE{*}, INOUT num OUT_UDINT)
        ! Description:                                                            !
        !   Conversion of a vector of values (BYTES) to a value (UDINT - 32-bit). !
        !                                                                         !
        ! Args:                                                                   !
        ! [1] IN_BYTE [num array{4}]: Input multiple bytes.                       !   
        !                                                                         !
        ! Returns:                                                                !
        ! [1] OUT_UDINT [num]: Output udint (4 BYTEs).                            !
        !                                                                         !
        ! EXAMPLE:                                                                !
        !   Read Inputs:                                                          !
        !       IN_BYTE{1..4} := possible values range from 0 to 255              !
        !   Call Procedure:                                                       !
        !       Convert_Multiple_BYTES_To_UDINT IN_BYTE, OUT_UDINT                !
        !   Write Outputs:                                                        ! 
        !       OUT_UDINT := possible values range from 0 to 4294967295           !
        
        OUT_UDINT := IN_BYTE{1} + IN_BYTE{2} * Pow(256,1) + IN_BYTE{3} * Pow(256,2) + IN_BYTE{4} * Pow(256,3);
    ENDPROC

    PROC Convert_Multiple_BITS_To_BYTE(num IN_BIT{*}, INOUT num OUT_BYTE)
        ! Description:                                                                          !
        !   Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans). !
        !                                                                                       !
        !   Note:                                                                               !
        !       1 BYTE [0 - 255] = 8 BITs [0 - 1]                                               !
        !                                                                                       !
        ! Args:                                                                                 !
        ! [1] IN_BIT [num array{8}]: Input multiple bits (1 BYTE).                              !
        !                                                                                       !
        ! Returns:                                                                              !
        ! [1] OUT_BYTE [num]: Output byte.                                                      !
        !                                                                                       !
        ! EXAMPLE:                                                                              !
        !   Read Inputs:                                                                        !
        !       IN_BIT{1 .. 8} := possible values range from 0 to 1                             !
        !   Call Procedure:                                                                     !
        !       Convert_Multiple_BITS_To_BYTE IN_BIT, OUT_BYTE                                  !
        !   Write Outputs:                                                                      !
        !       OUT_BYTE := possible values range from 0 to 255                                 !
        
        VAR num out_var;
        FOR i FROM 1 TO Dim(IN_BIT, 1) DO
            IF IN_BIT{i} = 1 THEN
                out_var := out_var + Pow(2,i-1);
            ENDIF
        ENDFOR
        
        OUT_BYTE := out_var;
    ENDPROC

    PROC Convert_BYTE_To_Multiple_BITS(num IN_BYTE, INOUT num OUT_BIT{*})
        ! Description:                                                                    !
        !   Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE). !
        !                                                                                 !
        !   Note:                                                                         !
        !       8 BITs [0 - 1] = 1 BYTE [0 - 255]                                         !
        !                                                                                 !
        ! Args:                                                                           !
        ! [1] IN_BYTE [num]: Input byte.                                                  !
        !                                                                                 !
        ! Returns:                                                                        !
        ! [1] OUT_BYTE [num array{8}]: Output multiple bits (1 BYTE).                     !
        !                                                                                 !
        ! EXAMPLE:                                                                        !
        !   Read Inputs:                                                                  !
        !       IN_BYTE := possible values range from 0 to 255                            !
        !   Call Procedure:                                                               !
        !       Convert_BYTE_To_Multiple_BITS IN_BYTE, OUT_BIT                            !
        !   Write Outputs:                                                                !
        !       OUT_BIT{1 .. 8} := possible values range from 0 to 1                      !
        
        VAR num in_var;
        VAR num out_var{8};
        
        in_var := IN_BYTE;
        FOR i FROM 1 TO Dim(out_var, 1) DO
            out_var{i} := in_var MOD 2;
            in_var := Trunc(in_var/2\Dec:=0);
        ENDFOR
        
        OUT_BIT := out_var;
    ENDPROC
ENDMODULE
