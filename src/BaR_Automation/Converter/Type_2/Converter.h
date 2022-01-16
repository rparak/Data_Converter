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

typedef struct convert_multiple_bytes_to_int
{
	/**
	Description:
		Function block (FB) for converting multiple bytes to an integer.
	*/
	
	/**
 	 * FUNCTION BLOCK: convert_multiple_bytes_to_int
	 * INPUT VARIABLES
 	 */
	unsigned char IN_BYTE[2];
	
	/**
 	 * FUNCTION BLOCK: convert_multiple_bytes_to_int
	 * OUTPUT VARIABLES
 	 */
	INT OUT_INT;
} convert_multiple_bytes_to_int_typ;

typedef struct convert_multiple_bytes_to_real
{
	/**
	Description:
		Function block (FB) for converting multiple bytes to a real (float).
	*/
	
	/**
 	 * FUNCTION BLOCK: convert_multiple_bytes_to_real
	 * INPUT VARIABLES
 	 */
	unsigned char IN_BYTE[4];
	
	/**
 	 * FUNCTION BLOCK: convert_multiple_bytes_to_real
	 * OUTPUT VARIABLES
 	 */
	REAL OUT_REAL;
} convert_multiple_bytes_to_real_typ;

typedef struct convert_int_to_multiple_bytes
{
	/**
	Description:
		Function block (FB) for converting integer to multiple bytes.
	*/
	
	/**
 	 * FUNCTION BLOCK: convert_int_to_multiple_bytes
	 * INPUT VARIABLES
 	 */
	INT IN_INT;
	
	/**
 	 * FUNCTION BLOCK: convert_int_to_multiple_bytes
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE[2];
} convert_int_to_multiple_decimal_typ;

typedef struct convert_real_to_multiple_bytes
{
	/**
	Description:
		Function block (FB) for converting real (float) to multiple bytes.
	*/
	
	/**
 	 * FUNCTION BLOCK: convert_real_to_multiple_bytes
	 * INPUT VARIABLES
 	 */
	REAL IN_REAL;
	
	/**
 	 * FUNCTION BLOCK: convert_real_to_multiple_bytes
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE[4];
} convert_real_to_multiple_decimal_typ;

typedef struct convert_multiple_bits_to_byte
{
	/**
	Description:
		Function block (FB) for converting multiple bits to byte.
	*/
	
	/**
 	 * FUNCTION BLOCK: convert_multiple_bits_to_byte
	 * INPUT VARIABLES
 	 */
	BOOL IN_BIT[8];
	
	/**
 	 * FUNCTION BLOCK: convert_multiple_bits_to_byte
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUT_BYTE;
} convert_multiple_bits_to_typ;

typedef struct convert_byte_to_multiple_bits
{
	/**
	Description:
		Function block (FB) for converting byte to multiple bits.
	*/
	
	/**
 	 * FUNCTION BLOCK: convert_byte_to_multiple_bits
	 * INPUT VARIABLES
 	 */
	unsigned char IN_BYTE;
	
	/**
 	 * FUNCTION BLOCK: convert_byte_to_multiple_bits
	 * OUTPUT VARIABLES
 	 */
	BOOL OUT_BIT[8];
} convert_byte_to_multiple_bits_typ;

/**
 * Declaration of function blocks for conversion between different types.
 */
_BUR_PUBLIC void convert_multiple_bytes_to_int(struct convert_multiple_bytes_to_int* inst);
_BUR_PUBLIC void convert_multiple_bytes_to_real(struct convert_multiple_bytes_to_real* inst);
_BUR_PUBLIC void convert_int_to_multiple_bytes(struct convert_int_to_multiple_bytes* inst);
_BUR_PUBLIC void convert_real_to_multiple_bytes(struct convert_real_to_multiple_bytes* inst);
_BUR_PUBLIC void convert_multiple_bits_to_byte(struct convert_multiple_bits_to_byte* inst);
_BUR_PUBLIC void convert_byte_to_multiple_bits(struct convert_byte_to_multiple_bits* inst);

void convert_multiple_bytes_to_int(struct convert_multiple_bytes_to_int* inst){
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
		 convert_multiple_bytes_to_int(&inst);
		 // Write outputs
		 inst->OUT_INT = Result calculation from inst->IN_BYTE[0 .. 1] {possible values range from -32.768 to 32.767}
	*/
	
	memcpy(&inst->OUT_INT, inst->IN_BYTE, sizeof inst->OUT_INT);
}

void convert_multiple_bytes_to_real(struct convert_multiple_bytes_to_real* inst){
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
		 convert_multiple_bytes_to_real(&inst);
		 // Write outputs
		 inst->OUT_REAL = Result calculation from inst->IN_BYTE[0 .. 3] {possible values range from -3.4E38 to +3.4E38}
	*/
	
	memcpy(&inst->OUT_REAL, inst->IN_BYTE, sizeof inst->OUT_REAL);
}

void convert_int_to_multiple_bytes(struct convert_int_to_multiple_bytes* inst){
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
		 convert_int_to_multiple_bytes(&inst);
		 // Write outputs
		 inst->OUT_BYTE[0] = Result calculation from inst->IN_INT {Part 1: 0 .. 255} 
		 inst->OUT_BYTE[1] = Result calculation from inst->IN_INT {Part 2: 0 .. 255}
	*/
	
	unsigned char i;
	for(i = 0; i < (unsigned char)(sizeof(inst->OUT_BYTE)/sizeof(inst->OUT_BYTE[0])); i++){
		inst->OUT_BYTE[i] = ((unsigned char*)&inst->IN_INT)[i];
	}
}

void convert_real_to_multiple_bytes(struct convert_real_to_multiple_bytes* inst){
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
		 convert_int_to_multiple_bytes(&inst);
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

void convert_multiple_bits_to_byte(struct convert_multiple_bits_to_byte* inst){
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
		 convert_int_to_multiple_bytes(&inst);
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

void convert_byte_to_multiple_bits(struct convert_byte_to_multiple_bits* inst){
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
		 convert_int_to_multiple_bytes(&inst);
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


