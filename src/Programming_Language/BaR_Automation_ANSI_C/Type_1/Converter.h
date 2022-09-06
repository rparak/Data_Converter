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
	
	 Note 1: 
	     A byte is a unit of storage in a computer which contains 8-bits and can store 256 different values: 0 to 255. 

	 Note 2:
		BOOL (Bit)  : Boolean               [0, 1]          | 1-bit
        USINT (Byte): Unsigned char         [0, 255]        | 8-bit 
        UINT        : Unsigned INT          [0, 65535]      | 16-bit
        UDINT       : Unsigned (double) INT [0, 4294967295] | 32-bit
 */

typedef struct Convert_USINT_Array_To_UINT
{
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (UINT - 16-bit).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_Array_To_UINT
	 * INPUT VARIABLES
 	 */
	USINT INPUT[2];
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_Array_To_UINT
	 * OUTPUT VARIABLES
 	 */
	UINT OUTPUT;
} Convert_USINT_Array_To_UINT_typ;

typedef struct Convert_USINT_Array_To_UDINT
{
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (UDINT - 32-bit).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_Array_To_UDINT
	 * INPUT VARIABLES
 	 */
	USINT INPUT[4];
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_Array_To_UDINT
	 * OUTPUT VARIABLES
 	 */
	UDINT OUTPUT;
} Convert_USINT_Array_To_UDINT_typ;

typedef struct Convert_UINT_To_USINT_Array
{
	/**
	Description:
		Conversion of input value (UINT - 16-bit) into a vector of values (BYTES).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_UINT_To_USINT_Array
	 * INPUT VARIABLES
 	 */
	UINT INPUT;
	
	/**
 	 * FUNCTION BLOCK: Convert_UINT_To_USINT_Array
	 * OUTPUT VARIABLES
 	 */
	USINT OUTPUT[2];
} Convert_UINT_To_USINT_Array_typ;

typedef struct Convert_UDINT_To_USINT_Array
{
	/**
	Description:
		Conversion of input value (UDINT - 32-bit) into a vector of values (BYTES).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_UDINT_To_Byte_Array
	 * INPUT VARIABLES
 	 */
	UDINT INPUT;
	
	/**
 	 * FUNCTION BLOCK: Convert_UDINT_To_Byte_Array
	 * OUTPUT VARIABLES
 	 */
	USINT OUTPUT[4];
} Convert_UDINT_To_USINT_Array_typ;

typedef struct Convert_BOOL_Array_To_USINT
{
	/**
	Description:
		Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_BOOL_Array_To_USINT
	 * INPUT VARIABLES
 	 */
	BOOL INPUT[8];
	
	/**
 	 * FUNCTION BLOCK: Convert_BOOL_Array_To_USINT
	 * OUTPUT VARIABLES
 	 */
	USINT OUTPUT;
} Convert_BOOL_Array_To_USINT_typ;

typedef struct Convert_USINT_To_BOOL_Array
{
	/**
	Description:
		Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_To_BOOL_Array
	 * INPUT VARIABLES
 	 */
	USINT INPUT;
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_To_BOOL_Array
	 * OUTPUT VARIABLES
 	 */
	BOOL OUTPUT[8];
} Convert_USINT_To_BOOL_Array_typ;

/**
 * Declaration of function blocks for conversion between different types.
 */
_BUR_PUBLIC void Convert_USINT_Array_To_UINT(struct Convert_USINT_Array_To_UINT* inst);
_BUR_PUBLIC void Convert_USINT_Array_To_UDINT(struct Convert_USINT_Array_To_UDINT* inst);
_BUR_PUBLIC void Convert_UINT_To_USINT_Array(struct Convert_UINT_To_USINT_Array* inst);
_BUR_PUBLIC void Convert_UDINT_To_USINT_Array(struct Convert_UDINT_To_USINT_Array* inst);
_BUR_PUBLIC void Convert_BOOL_Array_To_USINT(struct Convert_BOOL_Array_To_USINT* inst);
_BUR_PUBLIC void Convert_USINT_To_BOOL_Array(struct Convert_USINT_To_BOOL_Array* inst);

void Convert_USINT_Array_To_UINT(struct Convert_USINT_Array_To_UINT* inst){
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (UINT - 16-bit).

	Args:
		(1) INPUT[0 .. 1] [BYTE (USINT) ARRAY]: Input multiple bytes.
		
	Returns:
		(1) OUTPUT [UINT]: Output uint (2 BYTEs).
	
	Example:
	     // Read inputs
		 inst->INPUT[0] = possible values range from 0 to 255
		 inst->INPUT[1] = possible values range from 0 to 255
		 // Call Function Block
		 Convert_USINT_Array_To_UINT(&inst);
		 // Write outputs
		 inst->OUTPUT = Result calculation from inst->IN_BYTE[0 .. 1] {possible values range from 0 to 65535}
	*/
	
	inst->OUTPUT = inst->INPUT[0] << 0x00 | 
		           inst->INPUT[1] << 0x08;
}

void Convert_USINT_Array_To_UDINT(struct Convert_USINT_Array_To_UDINT* inst){
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (UDINT - 32-bit).

	Args:
		(1) INPUT[0 .. 3] [BYTE (USINT) ARRAY]: Input multiple bytes.
		
	Returns:
		(1) OUTPUT [UDINT]: Output udint (4 BYTEs).
	
	Example:
	     // Read inputs
		 inst->INPUT[0] = possible values range from 0 to 255
		 ...
		 inst->INPUT[3] = possible values range from 0 to 255
		 // Call Function Block
		 Convert_USINT_Array_To_UDINT(&inst);
		 // Write outputs
		 inst->OUTPUT = Result calculation from inst->IN_BYTE[0 .. 3] {possible values range from 0 to 4294967295}
	*/
	
	inst->OUTPUT = inst->INPUT[0] << 0x00 | 
		           inst->INPUT[1] << 0x08 |
		           inst->INPUT[2] << 0x10 |
		           inst->INPUT[3] << 0x18;
}

void Convert_UINT_To_USINT_Array(struct Convert_UINT_To_USINT_Array* inst){
	/**
	Description:
		Conversion of input value (UINT - 16-bit) into a vector of values (BYTES).

	Args:
		(1) INPUT[UINT]: Input uint (2 BYTEs).
		
	Returns:
		(1) OUTPUT[0 .. 1] [BYTE (USINT) ARRAY]: Output multiple bytes.
	
	Example:
	     // Read inputs
		 inst->INPUT = possible values range from 0 to 65535
		 // Call Function Block
		 Convert_UINT_To_USINT_Array(&inst);
		 // Write outputs
		 inst->OUTPUT[0] = Result calculation from inst->IN_INT {Part 1: 0 .. 255} 
		 inst->OUTPUT[1] = Result calculation from inst->IN_INT {Part 2: 0 .. 255}
	*/
	
	inst->OUTPUT[0] = (inst->INPUT >> 0x00) & 0xff;
	inst->OUTPUT[1] = (inst->INPUT >> 0x08) & 0xff;
}

void Convert_UDINT_To_USINT_Array(struct Convert_UDINT_To_USINT_Array* inst){
	/**
	Description:
		Conversion of input value (UDINT - 32-bit) into a vector of values (BYTES).

	Args:
		(1) INPUT [UDINT]: Input udint (4 BYTEs).
		
	Returns:
		(1) OUTPUT[0 .. 3] [BYTE (USINT) ARRAY]: Output multiple bytes.
	
	Example:
	     // Read inputs
		 inst->INPUT = possible values range from 0 to 4294967295
		 // Call Function Block
		 Convert_UDINT_To_USINT_Array(&inst);
		 // Write outputs
		 inst->OUTPUT[0] = Result calculation from inst->IN_UDINT {Part 1: 0 .. 255}
		 ...
		 inst->OUTPUT[3] = Result calculation from inst->IN_UDINT {Part 4: 0 .. 255}
	*/
	
	inst->OUTPUT[0] = (inst->INPUT >> 0x00) & 0xff;
	inst->OUTPUT[1] = (inst->INPUT >> 0x08) & 0xff;
	inst->OUTPUT[2] = (inst->INPUT >> 0x10) & 0xff;
	inst->OUTPUT[3] = (inst->INPUT >> 0x18) & 0xff;
}

void Convert_BOOL_Array_To_USINT(struct Convert_BOOL_Array_To_USINT* inst){
	/**
	Description:
		Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans).
	
		Note:
			1 BYTE [0 - 255] = 8 BITs [0 - 1]

	Args:
		(1) INPUT[0 .. 7] [BIT (BOOL) ARRAY]: Input multiple bits (1 BYTE).
		
	Returns:
		(1) OUTPUT [BYTE (USINT)]: Output byte.
	
	Example:
	     // Read inputs
		 inst->INPUT[0]  = possible values range from 0 (false) to 1 (true)
	     ...
		 inst->INPUT[7]  = possible values range from 0 (false) to 1 (true)
		 // Call Function Block
		 Convert_BOOL_Array_To_USINT(&inst);
		 // Write outputs
		 inst->OUTPUT = Result calculation from inst->IN_BIT[0 .. 7] {Part: 0 .. 255}
	*/
	
	inst->OUTPUT = inst->INPUT[0] << 0x00 |
		           inst->INPUT[1] << 0x01 |
		           inst->INPUT[2] << 0x02 |
		           inst->INPUT[3] << 0x03 |
		           inst->INPUT[4] << 0x04 |
		           inst->INPUT[5] << 0x05 |
		           inst->INPUT[6] << 0x06 |
		           inst->INPUT[7] << 0x07;
}

void Convert_USINT_To_BOOL_Array(struct Convert_USINT_To_BOOL_Array* inst){
	/**
	Description:
		Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE).
	
		Note:
			8 BITs [0 - 1] = 1 BYTE [0 - 255]

	Args:
		(1) INPUT [BYTE]: Input byte.
		
	Returns:
		(1) OUTPUT[0 .. 7] [BIT (BOOL) ARRAY]: Output multiple bits (1 BYTE).
	
	Example:
	     // Read inputs
		 inst->INPUT  = possible values range from 0 to 255
		 // Call Function Block
		 Convert_USINT_To_BOOL_Array(&inst);
		 // Write outputs
		 inst->OUTPUT[0] = Result calculation from inst->IN_BYTE {Part 1: 0 (false) / 1 (true)}
		 ...
		 inst->OUTPUT[7] = Result calculation from inst->IN_BYTE {Part 1: 0 (false) / 1 (true)}
	*/
	
	inst->OUTPUT[0] = (inst->INPUT >> 0x00) & 0x01;
	inst->OUTPUT[1] = (inst->INPUT >> 0x01) & 0x01;
	inst->OUTPUT[2] = (inst->INPUT >> 0x02) & 0x01;
	inst->OUTPUT[3] = (inst->INPUT >> 0x03) & 0x01;
	inst->OUTPUT[4] = (inst->INPUT >> 0x04) & 0x01;
	inst->OUTPUT[5] = (inst->INPUT >> 0x05) & 0x01;
	inst->OUTPUT[6] = (inst->INPUT >> 0x06) & 0x01;
	inst->OUTPUT[7] = (inst->INPUT >> 0x07) & 0x01;
}

#endif