MODULE Module1
    ! ## =========================================================================== ## 
    ! MIT License
    ! Copyright (c) 2021 Roman Parak
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
    
    ! Description:                             !
    !   Program Main Cycle:                    !
    !       Type        : Semistatic or Normal !
    !       TrustLeve   : No Safety or N/A     !
    !       Motion Task : N/A or YES           ! 
    PROC Main()
        ! TODO
    ENDPROC
    
    PROC convert_uint_to_multiple_bytes(num IN_UINT, INOUT num OUT_BYTE{*})
        ! Description:                                                             !
        !   Procedure for converting uint (unsigned int 16-bit) to multiple bytes. !
        !                                                                          !
        ! IN:                                                                      !
        ! [1] IN_UINT [num]: Input uint (2 BYTEs).                                 !
        ! OUT:                                                                     !
        ! [1] OUT_BYTE [num array{2}]: Output multiple bytes.                      !
        ! EXAMPLE:                                                                 !
        !   Read Inputs:                                                           !
        !       IN_UINT := possible values range from 0 to 65535                   !
        !   Call Procedure:                                                        !
        !       convert_uint_to_multiple_bytes IN_UINT, OUT_BYTE                   !
        !   Write Outputs:                                                         !
        !       OUT_UDINT{1 .. 2} := possible values range from 0 to 255           !
        
        OUT_BYTE{1} := IN_UINT MOD 256;
        OUT_BYTE{2} := Trunc(IN_UINT/256\Dec:=0) MOD 256;
    ENDPROC

    PROC convert_multiple_bytes_to_uint(num IN_BYTE{*}, INOUT num OUT_UINT)
        ! Description:                                                                !
        !   Procedure for converting multiple bytes to an uint (unsigned int 16-bit). !
        !                                                                             !
        ! IN:                                                                         !
        ! [1] IN_BYTE [num array{2}]: Input multiple bytes.                           !
        ! OUT:                                                                        !
        ! [1] OUT_UINT [num]: Output uint (2 BYTEs).                                  !
        ! EXAMPLE:                                                                    !
        !   Read Inputs:                                                              !
        !       IN_BYTE{1 .. 2} := possible values range from 0 to 255                !
        !   Call Procedure:                                                           !
        !       convert_multiple_bytes_to_uint IN_BYTE, OUT_UINT                      !
        !   Write Outputs:                                                            !
        !       OUT_UDINT := possible values range from 0 to 65535                    !
 
        OUT_UINT := IN_BYTE{1} + IN_BYTE{2} * Pow(256,1);
    ENDPROC
    
    PROC convert_udint_to_multiple_bytes(num IN_UDINT, INOUT num OUT_BYTE{*})
        ! Description:                                                              !
        !   Procedure for converting udint (unsigned int 32-bit) to multiple bytes. !
        !                                                                           !
        ! IN:                                                                       !
        ! [1] IN_UINT [num]: Input uint (4 BYTEs).                                  !
        ! OUT:                                                                      !
        ! [1] OUT_BYTE [num array{4}]: Output multiple bytes.                       !
        ! EXAMPLE:                                                                  !
        !   Read Inputs:                                                            !
        !       IN_UINT := possible values range from 0 to 4294967295               !
        !   Call Procedure:                                                         !
        !       convert_udint_to_multiple_bytes IN_UDINT, OUT_BYTE                  !
        !   Write Outputs:                                                          !
        !       OUT_UDINT{1 .. 4} := possible values range from 0 to 255            !
        
        OUT_BYTE{1} := IN_UDINT MOD 256;
        OUT_BYTE{2} := Trunc(IN_UDINT/256\Dec:=0) MOD 256;
        OUT_BYTE{3} := Trunc(Trunc(IN_UDINT/256\Dec:=0)/256\Dec:=0) MOD 256;
        OUT_BYTE{4} := Trunc(Trunc(Trunc(IN_UDINT/256\Dec:=0)/256\Dec:=0)/256\Dec:=0) MOD 256;
    ENDPROC
    
    PROC convert_multiple_bytes_to_udint(num IN_BYTE{*}, INOUT num OUT_UDINT)
        ! Description:                                                                 !
        !   Procedure for converting multiple bytes to an udint (unsigned int 32-bit). !
        !                                                                              !
        ! IN:                                                                          !
        ! [1] IN_BYTE [num array{4}]: Input multiple bytes.                            !
        ! OUT:                                                                         !
        ! [1] OUT_UDINT [num]: Output udint (4 BYTEs).                                 !
        ! EXAMPLE:                                                                     !
        !   Read Inputs:                                                               !
        !       IN_BYTE{1..4} := possible values range from 0 to 255                   !
        !   Call Procedure:                                                            !
        !       convert_multiple_bytes_to_udint IN_BYTE, OUT_UDINT                     !
        !   Write Outputs:                                                             ! 
        !       OUT_UDINT := possible values range from 0 to 4294967295                !
        
        OUT_UDINT := IN_BYTE{1} + IN_BYTE{2} * Pow(256,1) + IN_BYTE{3} * Pow(256,2) + IN_BYTE{4} * Pow(256,3);
    ENDPROC

    PROC convert_multiple_bits_to_byte(num IN_BIT{*}, INOUT num OUT_BYTE)
        ! Description:                                              !
        !   Procedure for converting multiple bits to byte.         !
        !                                                           !
        ! IN:                                                       !
        ! [1] IN_BIT [num array{8}]: Input multiple bits (1 BYTE).  !
        ! OUT:                                                      !
        ! [1] OUT_BYTE [num]: Output byte.                          !
        ! EXAMPLE:                                                  !
        !   Read Inputs:                                            !
        !       IN_BIT{1 .. 8} := possible values range from 0 to 1 !
        !   Call Procedure:                                         !
        !       convert_multiple_bits_to_byte IN_BIT, OUT_BYTE      !
        !   Write Outputs:                                          !
        !       OUT_BYTE := possible values range from 0 to 255     !
        
        ! Create auxiliary variable
        VAR num out_var;
        
        ! Convert multiple Booleans (BITs) to decimal number (BYTE)
	    !   Note: 8 BITs [0 - 1] = 1 BYTE [0 - 255]
        FOR i FROM 1 TO 8 DO
            IF IN_BIT{i} = 1 THEN
                out_var := out_var + Pow(2,i-1);
            ENDIF
        ENDFOR
        
        OUT_BYTE := out_var;
    ENDPROC

    PROC convert_byte_to_multiple_bits(num IN_BYTE, INOUT num OUT_BIT{*})
        ! Description:                                                !
        !   Procedure for converting byte to multiple bits.           !
        !                                                             !
        ! IN:                                                         !
        ! [1] IN_BYTE [num]: Input byte.                              !
        ! OUT:                                                        !
        ! [1] OUT_BYTE [num array{8}]: Output multiple bits (1 BYTE). !
        ! EXAMPLE:                                                    !
        !   Read Inputs:                                              !
        !       IN_BYTE := possible values range from 0 to 255        !
        !   Call Procedure:                                           !
        !       convert_byte_to_multiple_bits IN_BYTE, OUT_BIT        !
        !   Write Outputs:                                            !
        !       OUT_BIT{1 .. 8} := possible values range from 0 to 1  !
        
        ! Create auxiliary variables
        VAR num in_var;
        VAR num out_var{8};
        
        in_var := IN_BYTE;
        
	   ! Convert decimal number (BYTE) to multiple Booleans (BITs)
	   !    Note: 1 BYTE [0 - 255] = 8 BITs [0 - 1]
        FOR i FROM 1 TO 8 DO
            IF in_var > 0 THEN
                out_var{i} := in_var MOD 2;
                in_var := Trunc(in_var/2\Dec:=0);
            ELSE
                out_var{i} := 0;
            ENDIF
        ENDFOR
        
        OUT_BIT := out_var;
    ENDPROC
ENDMODULE