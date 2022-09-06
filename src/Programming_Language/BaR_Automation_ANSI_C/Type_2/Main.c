/**
 * MIT License
 * Copyright(c) 2022 Roman Parak
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * Author   : Roman Parak
 * Email    : Roman.Parak@outlook.com
 * File Name: Converter.h
 * Github   : https://github.com/rparak
 */

/** < Include B&R Automation libraries (declarations for B&R ANSI C extensions) */
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

/** < Custom Lib.: Base conversion between data. */
#include <Converter.h>

/** < Local Variables:  */
// Function blocks for conversion between different types.
_LOCAL struct Convert_USINT_Array_To_INT C_USINT_Arr_To_INT_1;
_LOCAL struct Convert_USINT_Array_To_REAL C_USINT_Arr_To_REAL_1;
_LOCAL struct Convert_INT_To_USINT_Array C_INT_To_USINT_Arr_1;
_LOCAL struct Convert_REAL_To_USINT_Array C_REAL_To_USINT_Arr_1;
_LOCAL struct Convert_BOOL_Array_To_USINT C_BOOL_Arr_To_USINT_1;
_LOCAL struct Convert_USINT_To_BOOL_Array C_USINT_To_BOOL_Arr_1;

// Compare results variable.
_LOCAL BOOL RES_VAR[3];

/**
 * Program Intitialization
 */
void _INIT ProgramInit(void)
{
	// Test no. 1: Input
	C_INT_To_USINT_Arr_1.INPUT  = -12345;
	// Test no. 2: Input
	C_REAL_To_USINT_Arr_1.INPUT = 123456.78;
	// Test no. 3: Input
	C_USINT_To_BOOL_Arr_1.INPUT = 123; 
}

/**
 * Program Cyclic 
 * 
 * Duration (Cycle Time): 10000 [ms] 
 * Tolerance            : 10000 [ms]
 */
void _CYCLIC ProgramCyclic(void)
{
	/**
	* 1\ Test No. 1: INT <-> USINT[]
	*/
	// Converting INT (16-bit -> 2-byte) to multiple bytes.
	Convert_INT_To_USINT_Array(&C_INT_To_USINT_Arr_1);
	
	// Check result:
	// 	Converting multiple bytes to an INT (16-bit -> 2-byte).
	C_USINT_Arr_To_INT_1.INPUT[0] = C_INT_To_USINT_Arr_1.OUTPUT[0];
	C_USINT_Arr_To_INT_1.INPUT[1] = C_INT_To_USINT_Arr_1.OUTPUT[1]; 
	Convert_USINT_Array_To_INT(&C_USINT_Arr_To_INT_1);
	
	// Compare results.
	if(C_INT_To_USINT_Arr_1.INPUT == C_USINT_Arr_To_INT_1.OUTPUT){
		RES_VAR[0] = 1;
	}else{
		RES_VAR[0] = 0;
	}
	
	/**
	* 2\ Test No. 2: REAL <-> USINT[]
	*/
	// Converting REAL (32-bit -> 4-byte) to multiple bytes.
	Convert_REAL_To_USINT_Array(&C_REAL_To_USINT_Arr_1);
	
	// Check result:
	// 	Converting multiple bytes to an REAL (32-bit -> 4-byte).
	C_USINT_Arr_To_REAL_1.INPUT[0] = C_REAL_To_USINT_Arr_1.OUTPUT[0];
	C_USINT_Arr_To_REAL_1.INPUT[1] = C_REAL_To_USINT_Arr_1.OUTPUT[1]; 
	C_USINT_Arr_To_REAL_1.INPUT[2] = C_REAL_To_USINT_Arr_1.OUTPUT[2]; 
	C_USINT_Arr_To_REAL_1.INPUT[3] = C_REAL_To_USINT_Arr_1.OUTPUT[3]; 
	Convert_USINT_Array_To_REAL(&C_USINT_Arr_To_REAL_1);
	
	// Compare results.
	if(C_REAL_To_USINT_Arr_1.INPUT == C_USINT_Arr_To_REAL_1.OUTPUT){
		RES_VAR[1] = 1;
	}else{
		RES_VAR[1] = 0;
	}
	
	/**
	* 3\ Test No. 3:  USINT <-> BOOL[]
	*/
	// Converting byte to multiple bits.
	Convert_USINT_To_BOOL_Array(&C_USINT_To_BOOL_Arr_1);
	
	// Check result:
	// 	Converting multiple bits to byte.
	C_BOOL_Arr_To_USINT_1.INPUT[0] = C_USINT_To_BOOL_Arr_1.OUTPUT[0];
	C_BOOL_Arr_To_USINT_1.INPUT[1] = C_USINT_To_BOOL_Arr_1.OUTPUT[1];
	C_BOOL_Arr_To_USINT_1.INPUT[2] = C_USINT_To_BOOL_Arr_1.OUTPUT[2];
	C_BOOL_Arr_To_USINT_1.INPUT[3] = C_USINT_To_BOOL_Arr_1.OUTPUT[3];
	C_BOOL_Arr_To_USINT_1.INPUT[4] = C_USINT_To_BOOL_Arr_1.OUTPUT[4];
	C_BOOL_Arr_To_USINT_1.INPUT[5] = C_USINT_To_BOOL_Arr_1.OUTPUT[5];
	C_BOOL_Arr_To_USINT_1.INPUT[6] = C_USINT_To_BOOL_Arr_1.OUTPUT[6];
	C_BOOL_Arr_To_USINT_1.INPUT[7] = C_USINT_To_BOOL_Arr_1.OUTPUT[7];
	Convert_BOOL_Array_To_USINT(&C_BOOL_Arr_To_USINT_1);
	
	// Compare results.
	if(C_USINT_To_BOOL_Arr_1.INPUT == C_BOOL_Arr_To_USINT_1.OUTPUT){
		RES_VAR[2] = 1;
	}else{
		RES_VAR[2] = 0;
	}
}
