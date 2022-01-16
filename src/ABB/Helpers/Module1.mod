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

    FUNC num Sign(num value)
        ! Description:                                                                !
        !   A simple mathematical function that extracts a sign from a digital value. !
        !                                                                             !
        ! IN:                                                                         !
        ! [1] value [num]: Digital Input (1 / 0).                                     !
        ! OUT:                                                                        !
        ! [1] return [num]: Sign (1: Positive {+}, -1: Negative {-}).                 !
        
        IF value = 1 THEN
           RETURN 1;
        ELSE
           RETURN -1;
        ENDIF
    ENDFUNC
    
    FUNC num Rad_To_Deg(num value)
        ! Description:                                       !
        !   Conversion function between radians and degrees. !
        !                                                    !
        ! IN:                                                !
        ! [1] value [num]: Real number (Radian).             !
        ! OUT:                                               !
        ! [1] return [num]: Degree.                          !
        
        RETURN ((value) * 180.0 / M_PI);
    ENDFUNC

    FUNC num Deg_To_Rad(num value)
        ! Description:                                       !
        !   Conversion function between degrees and radians. !
        !                                                    !
        ! IN:                                                !
        ! [1] value [num]: Real number (Degree).             !
        ! OUT:                                               !
        ! [1] return [num]: Radian.                          !
        
        RETURN ((value) * M_PI / 180.0);
    ENDFUNC
ENDMODULE
