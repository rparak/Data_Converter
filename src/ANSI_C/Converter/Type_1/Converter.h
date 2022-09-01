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

#ifndef HEADER_FILE_CONVERTER
#define HEADER_FILE_CONVERTER

/** < Include B&R Automation libraries (declarations for B&R ANSI C extensions) */
#include <bur/plctypes.h>

/**
Description:
	 Library to converts base data types to an array of bytes, and an array of bytes to base data types as well as 
	 byte to an array of bits, and an array of bits to byte.
	
	 Note: 
	     A byte is a unit of storage in a computer which contains 8-bits and can store 256 different values: 0 to 255. 
 */

typedef struct Convert_Multiple_BYTES_To_UINT
{
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (UINT - 16-bit).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BYTES_To_UINT
	 * INPUT VARIABLES
 	 */
	unsigned char IN_BYTE[2];
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BYTES_To_UINT
	 * OUTPUT VARIABLES
 	 */
	UINT OUT_UINT;
} Convert_Multiple_BYTES_To_UINT_typ;

typedef struct Convert_Multiple_BYTES_To_UDINT
{
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (UDINT - 32-bit).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BYTES_To_UDINT
	 * INPUT VARIABLES
 	 */
	unsigned char IN_BYTE[4];
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BYTES_To_UDINT
	 * OUTPUT VARIABLES
 	 */
	UDINT OUT_UDINT;
} Convert_Multiple_BYTES_To_UDINT_typ;

typedef struct Convert_UINT_To_Multiple_BYTES
{
	/**
	Description:
		Conversion of input value (UINT - 16-bit) into a vector of values (BYTES).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_UINT_To_Multiple_BYTES
	 * INPUT VARIABLES
 	 */
	UINT IN_UINT;
	
	/**
 	 * FUNCTION BLOCK: Convert_UINT_To_Multiple_BYTES
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE[2];
} Convert_UINT_To_Multiple_BYTES_typ;

typedef struct Convert_UDINT_To_Multiple_BYTES
{
	/**
	Description:
		Conversion of input value (UDINT - 32-bit) into a vector of values (BYTES).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_UDINT_To_Multiple_BYTES
	 * INPUT VARIABLES
 	 */
	UDINT IN_UDINT;
	
	/**
 	 * FUNCTION BLOCK: Convert_UDINT_To_Multiple_BYTES
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE[4];
} Convert_UDINT_To_Multiple_BYTES_typ;

typedef struct Convert_Multiple_BITS_To_Byte
{
	/**
	Description:
		Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BITS_To_Byte
	 * INPUT VARIABLES
 	 */
	BOOL IN_BIT[8];
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BITS_To_Byte
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE;
} Convert_Multiple_BITS_To_Byte_typ;

typedef struct Convert_BYTE_To_Multiple_BITS
{
	/**
	Description:
		Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_BYTE_To_Multiple_BITS
	 * INPUT VARIABLES
 	 */
	unsigned char IN_BYTE;
	
	/**
 	 * FUNCTION BLOCK: Convert_BYTE_To_Multiple_BITS
	 * OUTPUT VARIABLES
 	 */
	BOOL OUT_BIT[8];
} Convert_BYTE_To_Multiple_BITS_typ;

/**
 * Declaration of function blocks for conversion between different types.
 */
_BUR_PUBLIC void Convert_Multiple_BYTES_To_UINT(struct Convert_Multiple_BYTES_To_UINT* inst);
_BUR_PUBLIC void Convert_Multiple_BYTES_To_UDINT(struct Convert_Multiple_BYTES_To_UDINT* inst);
_BUR_PUBLIC void Convert_UINT_To_Multiple_BYTES(struct Convert_UINT_To_Multiple_BYTES* inst);
_BUR_PUBLIC void Convert_UDINT_To_Multiple_BYTES(struct Convert_UDINT_To_Multiple_BYTES* inst);
_BUR_PUBLIC void Convert_Multiple_BITS_To_Byte(struct Convert_Multiple_BITS_To_Byte* inst);
_BUR_PUBLIC void Convert_BYTE_To_Multiple_BITS(struct Convert_BYTE_To_Multiple_BITS* inst);

void Convert_Multiple_BYTES_To_UINT(struct Convert_Multiple_BYTES_To_UINT* inst){
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (UINT - 16-bit).

	Args:
		(1) IN_BYTE[0 .. 1] [BYTE (USINT) ARRAY]: Input multiple bytes.
		
	Returns:
		(1) OUT_UINT [UINT]: Output uint (2 BYTEs).
	
	Example:
	     // Read inputs
		 inst->IN_BYTE[0] = possible values range from 0 to 255
		 inst->IN_BYTE[1] = possible values range from 0 to 255
		 // Call Function Block
		 Convert_Multiple_BYTES_To_UINT(&inst);
		 // Write outputs
		 inst->OUT_UINT = Result calculation from inst->IN_BYTE[0 .. 1] {possible values range from 0 to 65535}
	*/
	
	memcpy(&inst->OUT_UINT, inst->IN_BYTE, sizeof(inst->OUT_UINT));
}

void Convert_Multiple_BYTES_To_UDINT(struct Convert_Multiple_BYTES_To_UDINT* inst){
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (UDINT - 32-bit).

	Args:
		(1) IN_BYTE[0 .. 3] [BYTE (USINT) ARRAY]: Input multiple bytes.
		
	Returns:
		(1) OUT_UDINT [UDINT]: Output udint (4 BYTEs).
	
	Example:
	     // Read inputs
		 inst->IN_BYTE[0] = possible values range from 0 to 255
		 ...
		 inst->IN_BYTE[3] = possible values range from 0 to 255
		 // Call Function Block
		 Convert_Multiple_BYTES_To_UDINT(&inst);
		 // Write outputs
		 inst->OUT_UDINT = Result calculation from inst->IN_BYTE[0 .. 3] {possible values range from 0 to 4294967295}
	*/
	
	memcpy(&inst->OUT_UDINT, inst->IN_BYTE, sizeof(inst->OUT_UDINT));
}

void Convert_UINT_To_Multiple_BYTES(struct Convert_UINT_To_Multiple_BYTES* inst){
	/**
	Description:
		Conversion of input value (UINT - 16-bit) into a vector of values (BYTES).

	Args:
		(1) IN_UINT[UINT]: Input uint (2 BYTEs).
		
	Returns:
		(1) OUT_BYTE[0 .. 1] [BYTE (USINT) ARRAY]: Output multiple bytes.
	
	Example:
	     // Read inputs
		 inst->IN_INT = possible values range from 0 to 65535
		 // Call Function Block
		 Convert_UINT_To_Multiple_BYTES(&inst);
		 // Write outputs
		 inst->OUT_BYTE[0] = Result calculation from inst->IN_INT {Part 1: 0 .. 255} 
		 inst->OUT_BYTE[1] = Result calculation from inst->IN_INT {Part 2: 0 .. 255}
	*/
	
	unsigned char i;
	for(i = 0; i < (unsigned char)(sizeof(inst->OUT_BYTE)/sizeof(inst->OUT_BYTE[0])); i++){
		inst->OUT_BYTE[i] = ((unsigned char*)&inst->IN_UINT)[i];
	}
}

void Convert_UDINT_To_Multiple_BYTES(struct Convert_UDINT_To_Multiple_BYTES* inst){
	/**
	Description:
		Conversion of input value (UDINT - 32-bit) into a vector of values (BYTES).

	Args:
		(1) IN_UDINT [UDINT]: Input udint (4 BYTEs).
		
	Returns:
		(1) OUT_BYTE[0 .. 3] [BYTE (USINT) ARRAY]: Output multiple bytes.
	
	Example:
	     // Read inputs
		 inst->IN_UDINT = possible values range from 0 to 4294967295
		 // Call Function Block
		 Convert_UDINT_To_Multiple_BYTES(&inst);
		 // Write outputs
		 inst->OUT_BYTE[0] = Result calculation from inst->IN_UDINT {Part 1: 0 .. 255}
		 ...
		 inst->OUT_BYTE[3] = Result calculation from inst->IN_UDINT {Part 4: 0 .. 255}
	*/
	
	unsigned char i;
	for(i = 0; i < (unsigned char)(sizeof(inst->OUT_BYTE)/sizeof(inst->OUT_BYTE[0])); i++){
		inst->OUT_BYTE[i] = ((unsigned char*)&inst->IN_UDINT)[i];
	}
}

void Convert_Multiple_BITS_To_Byte(struct Convert_Multiple_BITS_To_Byte* inst){
	/**
	Description:
		Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans).
	
		Note:
			1 BYTE [0 - 255] = 8 BITs [0 - 1]

	Args:
		(1) IN_BIT[0 .. 7] [BIT (BOOL) ARRAY]: Input multiple bits (1 BYTE).
		
	Returns:
		(1) OUT_BYTE [BYTE (USINT)]: Output byte.
	
	Example:
	     // Read inputs
		 inst->IN_BIT[0]  = possible values range from 0 (false) to 1 (true)
	     ...
		 inst->IN_BIT[7]  = possible values range from 0 (false) to 1 (true)
		 // Call Function Block
		 Convert_Multiple_BITS_To_Byte(&inst);
		 // Write outputs
		 inst->OUT_BYTE = Result calculation from inst->IN_BIT[0 .. 7] {Part: 0 .. 255}
	*/
	
	unsigned char aux_byte = 0;

	unsigned char i;
	for(i = 0; i < (unsigned char)(sizeof(inst->IN_BIT)/sizeof(inst->IN_BIT[0])); i++){
		if(inst->IN_BIT[i] == 1){
			aux_byte += i > 0 ? 2<<(i-1): 1;
		}
	}
	
	inst->OUT_BYTE = aux_byte;
}

void Convert_BYTE_To_Multiple_BITS(struct Convert_BYTE_To_Multiple_BITS* inst){
	/**
	Description:
		Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE).
	
		Note:
			8 BITs [0 - 1] = 1 BYTE [0 - 255]

	Args:
		(1) IN_BYTE [BYTE]: Input byte.
		
	Returns:
		(1) OUT_BIT[0 .. 7] [BIT (BOOL) ARRAY]: Output multiple bits (1 BYTE).
	
	Example:
	     // Read inputs
		 inst->IN_BYTE  = possible values range from 0 to 255
		 // Call Function Block
		 Convert_BYTE_To_Multiple_BITS(&inst);
		 // Write outputs
		 inst->OUT_BIT[0] = Result calculation from inst->IN_BYTE {Part 1: 0 (false) / 1 (true)}
		 ...
		 inst->OUT_BIT[7] = Result calculation from inst->IN_BYTE {Part 1: 0 (false) / 1 (true)}
	*/
	
	unsigned char aux_byte = inst->IN_BYTE;
	
	unsigned char i;
	for(i = 0; i < (unsigned char)(sizeof(inst->OUT_BIT)/sizeof(inst->OUT_BIT[0])); i++){
		inst->OUT_BIT[i] = aux_byte % 2;
		aux_byte = aux_byte/2;
	}
}

#endif
