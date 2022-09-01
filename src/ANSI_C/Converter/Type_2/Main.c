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
_LOCAL struct Convert_Multiple_BYTES_To_INT CM_BYTES_To_INT_1;
_LOCAL struct Convert_Multiple_BYTES_To_REAL CM_BYTES_To_REAL_1;
_LOCAL struct Convert_INT_To_Multiple_BYTES C_INT_To_M_BYTES_1;
_LOCAL struct Convert_REAL_To_Multiple_BYTES C_REAL_To_M_BYTES_1;
_LOCAL struct Convert_Multiple_BITS_To_Byte CM_BITS_To_Byte_1;
_LOCAL struct Convert_BYTE_To_Multiple_BITS C_BYTE_To_M_BITS_1;


// Compare results variable.
_LOCAL BOOL RES_VAR[3];

/**
 * Program Intitialization
 */
void _INIT ProgramInit(void)
{
	// Test no. 1: Input
	C_INT_To_M_BYTES_1.IN_INT = 12345;
	// Test no. 2: Input
	C_REAL_To_M_BYTES_1.IN_REAL = 123456.78;
	// Test no. 3: Input
	C_BYTE_To_M_BITS_1.IN_BYTE = 123; 
}

/**
 * Program Cyclic 
 * 
 * Duration (Cycle Time): 10000 [µs] 
 * Tolerance            : 10000 [µs]
 */
void _CYCLIC ProgramCyclic(void)
{
	// Note: Copy Array
	// 	memcpy(CM_BYTES_To_INT_1.IN_BYTE, C_INT_To_M_BYTES_1.OUT_BYTE, sizeof(C_INT_To_M_BYTES_1.OUT_BYTE));
	
	/**
	* 1\ Test No. 1: INT <-> BYTE[]
	*/
	// Converting int to multiple bytes.
	Convert_INT_To_Multiple_BYTES(&C_INT_To_M_BYTES_1);
	
	// Check result:
	// 	Converting multiple bytes to an int.
	CM_BYTES_To_INT_1.IN_BYTE[0] = C_INT_To_M_BYTES_1.OUT_BYTE[0];
	CM_BYTES_To_INT_1.IN_BYTE[1] = C_INT_To_M_BYTES_1.OUT_BYTE[1]; 
	Convert_Multiple_BYTES_To_INT(&CM_BYTES_To_INT_1);
	
	// Compare results.
	if(C_INT_To_M_BYTES_1.IN_INT == CM_BYTES_To_INT_1.OUT_INT){
		RES_VAR[0] = 1;
	}else{
		RES_VAR[0] = 0;
	}
	
	/**
	* 2\ Test No. 2: REAL <-> BYTE[]
	*/
	// Converting real to multiple bytes.
	Convert_REAL_To_Multiple_BYTES(&C_REAL_To_M_BYTES_1);
	
	// Check result:
	// 	Converting multiple bytes to an real.
	CM_BYTES_To_REAL_1.IN_BYTE[0] = C_REAL_To_M_BYTES_1.OUT_BYTE[0];
	CM_BYTES_To_REAL_1.IN_BYTE[1] = C_REAL_To_M_BYTES_1.OUT_BYTE[1]; 
	CM_BYTES_To_REAL_1.IN_BYTE[2] = C_REAL_To_M_BYTES_1.OUT_BYTE[2]; 
	CM_BYTES_To_REAL_1.IN_BYTE[3] = C_REAL_To_M_BYTES_1.OUT_BYTE[3]; 
	Convert_Multiple_BYTES_To_REAL(&CM_BYTES_To_REAL_1);
	
	// Compare results.
	if(C_REAL_To_M_BYTES_1.IN_REAL == CM_BYTES_To_REAL_1.OUT_REAL){
		RES_VAR[1] = 1;
	}else{
		RES_VAR[1] = 0;
	}
	
	/**
	* 3\ Test No. 3:  BYTE <-> BIT[]
	*/
	// Converting byte to multiple bits.
	Convert_BYTE_To_Multiple_BITS(&C_BYTE_To_M_BITS_1);
	
	// Check result:
	// 	Converting multiple bits to byte.
	CM_BITS_To_Byte_1.IN_BIT[0] = C_BYTE_To_M_BITS_1.OUT_BIT[0];
	CM_BITS_To_Byte_1.IN_BIT[1] = C_BYTE_To_M_BITS_1.OUT_BIT[1];
	CM_BITS_To_Byte_1.IN_BIT[2] = C_BYTE_To_M_BITS_1.OUT_BIT[2];
	CM_BITS_To_Byte_1.IN_BIT[3] = C_BYTE_To_M_BITS_1.OUT_BIT[3];
	CM_BITS_To_Byte_1.IN_BIT[4] = C_BYTE_To_M_BITS_1.OUT_BIT[4];
	CM_BITS_To_Byte_1.IN_BIT[5] = C_BYTE_To_M_BITS_1.OUT_BIT[5];
	CM_BITS_To_Byte_1.IN_BIT[6] = C_BYTE_To_M_BITS_1.OUT_BIT[6];
	CM_BITS_To_Byte_1.IN_BIT[7] = C_BYTE_To_M_BITS_1.OUT_BIT[7];
	Convert_Multiple_BITS_To_Byte(&CM_BITS_To_Byte_1);
	
	// Compare results.
	if(C_BYTE_To_M_BITS_1.IN_BYTE == CM_BITS_To_Byte_1.OUT_BYTE){
		RES_VAR[2] = 1;
	}else{
		RES_VAR[2] = 0;
	}
}
