/**
 * MIT License
 * Copyright(c) 2021 Roman Parak
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

typedef struct Convert_Multiple_BYTES_To_INT
{
	/**
	Description:
		Function block (FB) for converting multiple bytes to an integer.
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BYTES_To_INT
	 * INPUT VARIABLES
 	 */
	unsigned char IN_BYTE[2];
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BYTES_To_INT
	 * OUTPUT VARIABLES
 	 */
	INT OUT_INT;
} Convert_Multiple_BYTES_To_INT_typ;

typedef struct Convert_Multiple_BYTES_To_REAL
{
	/**
	Description:
		Function block (FB) for converting multiple bytes to a real (float).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BYTES_To_REAL
	 * INPUT VARIABLES
 	 */
	unsigned char IN_BYTE[4];
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BYTES_To_REAL
	 * OUTPUT VARIABLES
 	 */
	REAL OUT_REAL;
} Convert_Multiple_BYTES_To_REAL_typ;

typedef struct Convert_INT_To_Multiple_BYTES
{
	/**
	Description:
		Function block (FB) for converting integer to multiple bytes.
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_INT_To_Multiple_BYTES
	 * INPUT VARIABLES
 	 */
	INT IN_INT;
	
	/**
 	 * FUNCTION BLOCK: Convert_INT_To_Multiple_BYTES
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE[2];
} Convert_INT_To_Multiple_BYTES_typ;

typedef struct Convert_REAL_To_Multiple_BYTES
{
	/**
	Description:
		Function block (FB) for converting real (float) to multiple bytes.
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_REAL_To_Multiple_BYTES
	 * INPUT VARIABLES
 	 */
	REAL IN_REAL;
	
	/**
 	 * FUNCTION BLOCK: Convert_REAL_To_Multiple_BYTES
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE[4];
} Convert_REAL_To_Multiple_BYTES_typ;

typedef struct Convert_Multiple_BITS_To_BYTE
{
	/**
	Description:
		Function block (FB) for converting multiple bits to byte.
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BITS_To_BYTE
	 * INPUT VARIABLES
 	 */
	BOOL IN_BIT[8];
	
	/**
 	 * FUNCTION BLOCK: Convert_Multiple_BITS_To_BYTE
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE;
} Convert_Multiple_BITS_To_BYTE_typ;

typedef struct Convert_BYTE_To_Multiple_BITS
{
	/**
	Description:
		Function block (FB) for converting byte to multiple bits.
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
_BUR_PUBLIC void Convert_Multiple_BYTES_To_INT(struct Convert_Multiple_BYTES_To_INT* inst);
_BUR_PUBLIC void Convert_Multiple_BYTES_To_REAL(struct Convert_Multiple_BYTES_To_REAL* inst);
_BUR_PUBLIC void Convert_INT_To_Multiple_BYTES(struct Convert_INT_To_Multiple_BYTES* inst);
_BUR_PUBLIC void Convert_REAL_To_Multiple_BYTES(struct Convert_REAL_To_Multiple_BYTES* inst);
_BUR_PUBLIC void Convert_Multiple_BITS_To_BYTE(struct Convert_Multiple_BITS_To_BYTE* inst);
_BUR_PUBLIC void Convert_BYTE_To_Multiple_BITS(struct Convert_BYTE_To_Multiple_BITS* inst);

void Convert_Multiple_BYTES_To_INT(struct Convert_Multiple_BYTES_To_INT* inst){
	/**
	Description:
		Function block (FB) for converting multiple bytes to an integer.

	Args:
		(1) IN_BYTE[0 .. 1] [BYTE (USINT) ARRAY]: Input multiple bytes.
		
	Returns:
		(1) OUT_INT [INT]: Output integer (2 BYTEs).
	
	Example:
	     // Read inputs
		 inst->IN_BYTE[0] = possible values range from 0 to 255
		 inst->IN_BYTE[1] = possible values range from 0 to 255
		 // Call Function Block
		 Convert_Multiple_BYTES_To_INT(&inst);
		 // Write outputs
		 inst->OUT_INT = Result calculation from inst->IN_BYTE[0 .. 1] {possible values range from -32.768 to 32.767}
	*/
	
	memcpy(&inst->OUT_INT, inst->IN_BYTE, sizeof inst->OUT_INT);
}

void Convert_Multiple_BYTES_To_REAL(struct Convert_Multiple_BYTES_To_REAL* inst){
	/**
	Description:
		Function block (FB) for converting multiple bytes to a real (float).

	Args:
		(1) IN_BYTE[0 .. 3] [BYTE (USINT) ARRAY]: Input multiple bytes.
		
	Returns:
		(1) OUT_REAL [REAL]: Output real (4 BYTEs).
	
	Example:
	     // Read inputs
		 inst->IN_BYTE[0] = possible values range from 0 to 255
		 ...
		 inst->IN_BYTE[3] = possible values range from 0 to 255
		 // Call Function Block
		 Convert_Multiple_BYTES_To_REAL(&inst);
		 // Write outputs
		 inst->OUT_REAL = Result calculation from inst->IN_BYTE[0 .. 3] {possible values range from -3.4E38 to +3.4E38}
	*/
	
	memcpy(&inst->OUT_REAL, inst->IN_BYTE, sizeof inst->OUT_REAL);
}

void Convert_INT_To_Multiple_BYTES(struct Convert_INT_To_Multiple_BYTES* inst){
	/**
	Description:
		Function block (FB) for converting integer to multiple bytes.

	Args:
		(1) IN_INT [INT]: Input integer (2 BYTEs).
		
	Returns:
		(1) OUT_BYTE[0 .. 1] [BYTE (USINT) ARRAY]: Output multiple bytes.
	
	Example:
	     // Read inputs
		 inst->IN_INT = possible values range from -32.768 to 32.767
		 // Call Function Block
		 Convert_INT_To_Multiple_BYTES(&inst);
		 // Write outputs
		 inst->OUT_BYTE[0] = Result calculation from inst->IN_INT {Part 1: 0 .. 255} 
		 inst->OUT_BYTE[1] = Result calculation from inst->IN_INT {Part 2: 0 .. 255}
	*/
	
	unsigned char i;
	for(i = 0; i < (unsigned char)(sizeof(inst->OUT_BYTE)/sizeof(inst->OUT_BYTE[0])); i++){
		inst->OUT_BYTE[i] = ((unsigned char*)&inst->IN_INT)[i];
	}
}

void Convert_REAL_To_Multiple_BYTES(struct Convert_REAL_To_Multiple_BYTES* inst){
	/**
	Description:
		Function block (FB) for converting real (float) to multiple bytes.

	Args:
		(1) IN_REAL [REAL]: Input real (4 BYTEs).
		
	Returns:
		(1) OUT_BYTE[0 .. 3] [BYTE (USINT) ARRAY]: Output multiple bytes.
	
	Example:
	     // Read inputs
		 inst->IN_REAL = possible values range from -3.4E38 to +3.4E38
		 // Call Function Block
		 Convert_REAL_To_Multiple_BYTES(&inst);
		 // Write outputs
		 inst->OUT_BYTE[0] = Result calculation from inst->IN_REAL {Part 1: 0 .. 255}
		 ...
		 inst->OUT_BYTE[3] = Result calculation from inst->IN_REAL {Part 4: 0 .. 255}
	*/
	
	unsigned char i;
	for(i = 0; i < (unsigned char)(sizeof(inst->OUT_BYTE)/sizeof(inst->OUT_BYTE[0])); i++){
		inst->OUT_BYTE[i] = ((unsigned char*)&inst->IN_REAL)[i];
	}
}

void Convert_Multiple_BITS_To_BYTE(struct Convert_Multiple_BITS_To_BYTE* inst){
	/**
	Description:
		Function block (FB) for converting multiple bits to byte.

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
		 Convert_Multiple_BITS_To_BYTE(&inst);
		 // Write outputs
		 inst->OUT_BYTE = Result calculation from inst->IN_BIT[0 .. 7] {Part: 0 .. 255}
	*/
	
	/// Create aux. variable
	unsigned char aux_byte = 0;
	
	/**
	  Convert multiple Booleans (BITs) to decimal number (BYTE)
	  Note: 8 BITs [0 - 1] = 1 BYTE [0 - 255]
	 */
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
		Function block (FB) for converting byte to multiple bits.

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
	
	/// Create aux. variable
	unsigned char aux_byte = inst->IN_BYTE;
	
	/**
	  Convert decimal number (BYTE) to multiple Booleans (BITs)
	  Note: 1 BYTE [0 - 255] = 8 BITs [0 - 1]
	 */
	unsigned char i;
	for(i = 0; i < (unsigned char)(sizeof(inst->OUT_BIT)/sizeof(inst->OUT_BIT[0])); i++){
		if(aux_byte > 0){
			inst->OUT_BIT[i] = aux_byte % 2;
			aux_byte = aux_byte/2;
		}else{
			inst->OUT_BIT[i] = 0;
		}
	}
}

#endif
