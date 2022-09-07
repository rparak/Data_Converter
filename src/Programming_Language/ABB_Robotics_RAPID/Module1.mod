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
    VAR num OUT_BYTE_t1{2};
    VAR dnum OUT_UINT_t1;
    
    ! Test no. 2:
    VAR dnum IN_UDINT_t2 := 1234567;
    VAR num OUT_BYTE_t2{4};
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

    ! Description:                                                                   !
    !   Library to converts base data types to an array of bytes, and an array       !
    !   of bytes to base data types as well as byte to an array of bits, and an      !
    !   array of bits to byte.                                                       !
    !                                                                                !
    !	 Note 1:                                                                     !
    !	     A byte is a unit of storage in a computer which contains 8-bits         !
    !        and can store 256 different values: 0 to 255.                           !
    !                                                                                !
    !	 Note 2:                                                                     !
    !        BOOL (Bit)  : Boolean               [0, 1]          | 1-bit  | 0-Byte | !
    !        USINT (Byte): Unsigned char         [0, 255]        | 8-bit  | 1-Byte | !
    !        UINT        : Unsigned INT          [0, 65535]      | 16-bit | 2-Byte | !
    !        UDINT       : Unsigned (double) INT [0, 4294967295] | 32-bit | 4-Byte | !
    !                                                                                !
    !   Note 3:                                                                      !
    !       Function BitOr(byte, byte), BitOrDnum(dnum, dnum):                       !
    !           Logical bitwise OR {Symbol - |}.                                     !
    !                                                                                !
    !       Function BitAnd(byte, byte), BitAndDnum(dnum, dnum):                     !
    !           Logical bitwise AND {Symbol - &}.                                    !
    !                                                                                !
    !       Function BitLSh(byte, num), BitLShDnum(dnum, num):                       !
    !           Logical bitwise LEFT SHIFT {Symbol - <<}.                            !
    !                                                                                !
    !       Function BitRSh(byte, num), BitRShDnum(dnum, num):                       !  
    !           Logical bitwise RIGHT SHIFT {Symbol - >>}.                           !

    PROC Convert_UINT_To_USINT_Array(dnum INPUT, INOUT num OUTPUT{*})
        ! Description:                                                                 !
        !   Conversion of input value (UINT - 16-bit) into a vector of values (BYTES). !
        !                                                                              !
        ! Args:                                                                        !
        !   [1] INPUT [dnum]: A real number greater than or equal to zero.             !         
        !                                                                              !
        ! Returns:                                                                     !
        !   [1] OUTPUT [num array{2}]: Vector of values (BYTES).                       !
        !                                                                              !
        ! EXAMPLE:                                                                     !
        !   Read Inputs:                                                               !
        !       INPUT := possible values range from 0 to 65535                         !
        !   Call Procedure:                                                            !
        !       Convert_UINT_To_Multiple_BYTES IN_UINT, OUT_BYTE                       !
        !   Write Outputs:                                                             !
        !       OUTPUT{1 .. 2} := possible values range from 0 to 255                  !
        
        OUTPUT{1} := DnumToNum(BitAndDnum(BitRShDnum(INPUT, 0), 255));
	    OUTPUT{2} := DnumToNum(BitAndDnum(BitRShDnum(INPUT, 8), 255));
    ENDPROC

    PROC Convert_USINT_Array_To_UINT(num INPUT{*}, INOUT dnum OUTPUT)
        ! Description:                                                           !
        !   Conversion of a vector of values (BYTES) to a value (UINT - 16-bit). !
        !                                                                        !
        ! Args:                                                                  !
        !   [1] INPUT [dnum array{2}]: Vector of values (BYTES).                 !
        !                                                                        !
        ! Returns:                                                               !
        !   [1] OUTPUT [num]: A real number greater than or equal to zero.       !
        !                                                                        !
        ! EXAMPLE:                                                               !
        !   Read Inputs:                                                         !
        !       INPUT{1 .. 2} := possible values range from 0 to 255             !
        !   Call Procedure:                                                      !
        !       Convert_Multiple_BYTES_To_UINT IN_BYTE, OUT_UINT                 !
        !   Write Outputs:                                                       !
        !       OUTPUT := possible values range from 0 to 65535                  !
 
        OUTPUT := BitOrDnum(BitLShDnum(NumToDnum(INPUT{1}), 0), BitLShDnum(NumToDnum(INPUT{2}), 8));
    ENDPROC
    
    PROC Convert_UDINT_To_USINT_Array(dnum INPUT, INOUT num OUTPUT{*})
        ! Description:                                                                  !
        !   Conversion of input value (UDINT - 32-bit) into a vector of values (BYTES). !
        !                                                                               !
        ! Args:                                                                         !
        ! [1] INPUT [num]: A real number greater than or equal to zero.                 !
        !                                                                               !
        ! Returns:                                                                      !
        ! [1] OUTPUT [num array{4}]: Vector of values (BYTES).                          ! 
        !                                                                               !
        ! EXAMPLE:                                                                      !
        !   Read Inputs:                                                                !
        !       INPUT := possible values range from 0 to 4294967295                     !
        !   Call Procedure:                                                             !
        !       Convert_UDINT_To_Multiple_BYTES IN_UDINT, OUT_BYTE                      !
        !   Write Outputs:                                                              !
        !       OUTPUT{1 .. 4} := possible values range from 0 to 255                   !
        
        OUTPUT{1} := DnumToNum(BitAndDnum(BitRShDnum(INPUT, 0), 255));
	    OUTPUT{2} := DnumToNum(BitAndDnum(BitRShDnum(INPUT, 8), 255));
        OUTPUT{3} := DnumToNum(BitAndDnum(BitRShDnum(INPUT, 16), 255));
	    OUTPUT{4} := DnumToNum(BitAndDnum(BitRShDnum(INPUT, 24), 255));
    ENDPROC
    
    PROC Convert_USINT_Array_To_UDINT(num INPUT{*}, INOUT dnum OUTPUT)
        ! Description:                                                            !
        !   Conversion of a vector of values (BYTES) to a value (UDINT - 32-bit). !
        !                                                                         !
        ! Args:                                                                   !
        ! [1] INPUT [num array{4}]: Vector of values (BYTES).                     !   
        !                                                                         !
        ! Returns:                                                                !
        ! [1] OUTPUT [num]: A real number greater than or equal to zero.          !
        !                                                                         !
        ! EXAMPLE:                                                                !
        !   Read Inputs:                                                          !
        !       INPUT{1..4} := possible values range from 0 to 255                !
        !   Call Procedure:                                                       !
        !       Convert_Multiple_BYTES_To_UDINT IN_BYTE, OUT_UDINT                !
        !   Write Outputs:                                                        ! 
        !       OUTPUT := possible values range from 0 to 4294967295              !
        
        OUTPUT := BitOrDnum(BitLShDnum(NumToDnum(INPUT{1}), 0), 
                  BitOrDnum(BitLShDnum(NumToDnum(INPUT{2}), 8), 
                  BitOrDnum(BitLShDnum(NumToDnum(INPUT{3}), 16), BitLShDnum(NumToDnum(INPUT{4}), 24))));
    ENDPROC

    PROC Convert_BOOL_Array_To_USINT(byte INPUT{*}, INOUT byte OUTPUT)
        ! Description:                                                                          !
        !   Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans). !
        !                                                                                       !
        !   Note:                                                                               !
        !       1 BYTE [0 - 255] = 8 BITs [0 - 1]                                               !
        !                                                                                       !
        ! Args:                                                                                 !
        ! [1] INPUT [num array{8}]: Vector of bits (1 BYTE)                                     !
        !                                                                                       !
        ! Returns:                                                                              !
        ! [1] OUTPUT [num]: A real number greater than or equal to zero.                        !
        !                                                                                       !
        ! EXAMPLE:                                                                              !
        !   Read Inputs:                                                                        !
        !       IN_BIT{1 .. 8} := possible values range from 0 to 1                             !
        !   Call Procedure:                                                                     !
        !       Convert_Multiple_BITS_To_BYTE IN_BIT, OUT_BYTE                                  !
        !   Write Outputs:                                                                      !
        !       OUTPUT := possible values range from 0 to 255                                   !
        
        OUTPUT := BitOr(BitLSh(INPUT{1}, 0), 
                  BitOr(BitLSh(INPUT{2}, 1),
                  BitOr(BitLSh(INPUT{3}, 2),
                  BitOr(BitLSh(INPUT{4}, 3),
                  BitOr(BitLSh(INPUT{5}, 4),
                  BitOr(BitLSh(INPUT{6}, 5),
                  BitOr(BitLSh(INPUT{7}, 6), BitLSh(INPUT{8}, 7))))))));
    ENDPROC

    PROC Convert_USINT_To_BOOL_Array(byte INPUT, INOUT byte OUTPUT{*})
        ! Description:                                                                    !
        !   Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE). !
        !                                                                                 !
        !   Note:                                                                         !
        !       8 BITs [0 - 1] = 1 BYTE [0 - 255]                                         !
        !                                                                                 !
        ! Args:                                                                           !
        ! [1] INPUT [num]: A real number greater than or equal to zero.                   !
        !                                                                                 !
        ! Returns:                                                                        !
        ! [1] OUTPUT [num array{8}]: Vector of bits (1 BYTE)                              !
        !                                                                                 !
        ! EXAMPLE:                                                                        !
        !   Read Inputs:                                                                  !
        !       IN_BYTE := possible values range from 0 to 255                            !
        !   Call Procedure:                                                               !
        !       Convert_BYTE_To_Multiple_BITS IN_BYTE, OUT_BIT                            !
        !   Write Outputs:                                                                !
        !       OUTPUT{1 .. 8} := possible values range from 0 to 1                       !
        
        OUTPUT{1} := BitAnd(BitRSh(INPUT, 0), 1);
        OUTPUT{2} := BitAnd(BitRSh(INPUT, 1), 1);
        OUTPUT{3} := BitAnd(BitRSh(INPUT, 2), 1);
        OUTPUT{4} := BitAnd(BitRSh(INPUT, 3), 1);
        OUTPUT{5} := BitAnd(BitRSh(INPUT, 4), 1);
        OUTPUT{6} := BitAnd(BitRSh(INPUT, 5), 1);
        OUTPUT{7} := BitAnd(BitRSh(INPUT, 6), 1);
        OUTPUT{8} := BitAnd(BitRSh(INPUT, 7), 1);
    ENDPROC
ENDMODULE
