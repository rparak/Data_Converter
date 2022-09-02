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
_LOCAL struct Convert_Multiple_BYTES_To_UINT CM_BYTES_To_UINT_1;
_LOCAL struct Convert_Multiple_BYTES_To_UDINT CM_BYTES_To_UDINT_1;
_LOCAL struct Convert_UINT_To_Multiple_BYTES C_UINT_To_M_BYTES_1;
_LOCAL struct Convert_UDINT_To_Multiple_BYTES C_UDINT_To_M_BYTES_1;
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
	C_UINT_To_M_BYTES_1.IN_UINT = 12345;
	// Test no. 2: Input
	C_UDINT_To_M_BYTES_1.IN_UDINT = 12345678;
	// Test no. 3: Input
	C_BYTE_To_M_BITS_1.IN_BYTE = 123; 
}

/**
 * Program Cyclic 
 * 
 * Duration (Cycle Time): 10000 [�s] 
 * Tolerance            : 10000 [�s]
 */
void _CYCLIC ProgramCyclic(void)
{
	// Note: Copy Array
	// 	memcpy(CM_BYTES_To_UINT_1.IN_BYTE, C_UINT_To_M_BYTES_1.OUT_BYTE, sizeof(C_UINT_To_M_BYTES_1.OUT_BYTE));
	
	/**
	* 1\ Test No. 1: UINT <-> BYTE[]
	*/
	// Converting uint (16-bit -> 2-byte) to multiple bytes.
	Convert_UINT_To_Multiple_BYTES(&C_UINT_To_M_BYTES_1);
	
	// Check result:
	// 	Converting multiple bytes to an uint (16-bit -> 2-byte).
	CM_BYTES_To_UINT_1.IN_BYTE[0] = C_UINT_To_M_BYTES_1.OUT_BYTE[0];
	CM_BYTES_To_UINT_1.IN_BYTE[1] = C_UINT_To_M_BYTES_1.OUT_BYTE[1]; 
	Convert_Multiple_BYTES_To_UINT(&CM_BYTES_To_UINT_1);
	
	// Compare results.
	if(C_UINT_To_M_BYTES_1.IN_UINT == CM_BYTES_To_UINT_1.OUT_UINT){
		RES_VAR[0] = 1;
	}else{
		RES_VAR[0] = 0;
	}
	
	/**
	* 2\ Test No. 2: UDINT <-> BYTE[]
	*/
	// Converting udint (32-bit -> 4-byte) to multiple bytes.
	Convert_UDINT_To_Multiple_BYTES(&C_UDINT_To_M_BYTES_1);
	
	// Check result:
	// 	Converting multiple bytes to an udint (32-bit -> 4-byte).
	CM_BYTES_To_UDINT_1.IN_BYTE[0] = C_UDINT_To_M_BYTES_1.OUT_BYTE[0];
	CM_BYTES_To_UDINT_1.IN_BYTE[1] = C_UDINT_To_M_BYTES_1.OUT_BYTE[1]; 
	CM_BYTES_To_UDINT_1.IN_BYTE[2] = C_UDINT_To_M_BYTES_1.OUT_BYTE[2]; 
	CM_BYTES_To_UDINT_1.IN_BYTE[3] = C_UDINT_To_M_BYTES_1.OUT_BYTE[3]; 
	Convert_Multiple_BYTES_To_UDINT(&CM_BYTES_To_UDINT_1);
	
	// Compare results.
	if(C_UDINT_To_M_BYTES_1.IN_UDINT == CM_BYTES_To_UDINT_1.OUT_UDINT){
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