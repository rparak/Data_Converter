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
    BOOL (Bit)  : Boolean               [0, 1]          | 1-bit  | 0-Byte |
    USINT (Byte): Unsigned char         [0, 255]        | 8-bit  | 1-Byte |
    UINT        : Unsigned INT          [0, 65535]      | 16-bit | 2-Byte |
    UDINT       : Unsigned (double) INT [0, 4294967295] | 32-bit | 4-Byte |

Note 3:
    Bitwise Operators:
        &	Bitwise AND
        |	Bitwise OR
        <<	Shift left
        >>	Shift right
*/

typedef struct Convert_USINT_Array_To_INT
{
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (INT).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_Array_To_INT
	 * INPUT VARIABLES
 	 */
	USINT INPUT[2];
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_Array_To_INT
	 * OUTPUT VARIABLES
 	 */
	INT OUTPUT;
} Convert_USINT_Array_To_INT_typ;

typedef struct Convert_USINT_Array_To_REAL
{
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (REAL - Float).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_Array_To_REAL
	 * INPUT VARIABLES
 	 */
	USINT INPUT[4];
	
	/**
 	 * FUNCTION BLOCK: Convert_USINT_Array_To_REAL
	 * OUTPUT VARIABLES
 	 */
	REAL OUTPUT;
} Convert_USINT_Array_To_REAL_typ;

typedef struct Convert_INT_To_USINT_Array
{
	/**
	Description:
		Conversion of input value (INT) into a vector of values (BYTES).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_INT_To_USINT_Array
	 * INPUT VARIABLES
 	 */
	INT INPUT;
	
	/**
 	 * FUNCTION BLOCK: Convert_INT_To_USINT_Array
	 * OUTPUT VARIABLES
 	 */
	USINT OUTPUT[2];
} Convert_INT_To_USINT_Array_typ;

typedef struct Convert_REAL_To_USINT_Array
{
	/**
	Description:
		Conversion of input value (REAL - Float) into a vector of values (BYTES).
	*/
	
	/**
 	 * FUNCTION BLOCK: Convert_REAL_To_USINT_Array
	 * INPUT VARIABLES
 	 */
	REAL INPUT;
	
	/**
 	 * FUNCTION BLOCK: Convert_REAL_To_USINT_Array
	 * OUTPUT VARIABLES
 	 */
	unsigned char OUTPUT[4];
} Convert_REAL_To_USINT_Array_typ;

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
_BUR_PUBLIC void Convert_USINT_Array_To_INT(struct Convert_USINT_Array_To_INT* inst);
_BUR_PUBLIC void Convert_USINT_Array_To_REAL(struct Convert_USINT_Array_To_REAL* inst);
_BUR_PUBLIC void Convert_INT_To_USINT_Array(struct Convert_INT_To_USINT_Array* inst);
_BUR_PUBLIC void Convert_REAL_To_USINT_Array(struct Convert_REAL_To_USINT_Array* inst);
_BUR_PUBLIC void Convert_BOOL_Array_To_USINT(struct Convert_BOOL_Array_To_USINT* inst);
_BUR_PUBLIC void Convert_USINT_To_BOOL_Array(struct Convert_USINT_To_BOOL_Array* inst);

void Convert_USINT_Array_To_INT(struct Convert_USINT_Array_To_INT* inst){
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (INT).

	Args:
		(1) INPUT[0 .. 1] [BYTE (USINT) ARRAY]: Vector of values (BYTES).
		
	Returns:
		(1) OUTPUT [INT]: A real number (positive, negative).
	
	Example:
	     // Read inputs
		 inst->INPUT[0] = possible values range from 0 to 255
		 inst->INPUT[1] = possible values range from 0 to 255
		 // Call Function Block
		 Convert_USINT_Array_To_INT(&inst);
		 // Write outputs
		 inst->OUTPUT = Result calculation from inst->INPUT[0 .. 1] {possible values range from -32.768 to 32.767}
	*/
	
	memcpy(&inst->OUTPUT, inst->INPUT, sizeof inst->OUTPUT);
}

void Convert_USINT_Array_To_REAL(struct Convert_USINT_Array_To_REAL* inst){
	/**
	Description:
		Conversion of a vector of values (BYTES) to a value (REAL - Float).

	Args:
		(1) INPUT[0 .. 3] [BYTE (USINT) ARRAY]: Vector of values (BYTES).
		
	Returns:
		(1) OUTPUT [REAL]: A rational number (positive, negative).
	
	Example:
	     // Read inputs
		 inst->INPUT[0] = possible values range from 0 to 255
		 ...
		 inst->INPUT[3] = possible values range from 0 to 255
		 // Call Function Block
		 Convert_USINT_Array_To_REAL(&inst);
		 // Write outputs
		 inst->OUTPUT = Result calculation from inst->INPUT[0 .. 3] {possible values range from -3.4E38 to +3.4E38}
	*/
	
	memcpy(&inst->OUTPUT, inst->INPUT, sizeof inst->OUTPUT);
}

void Convert_INT_To_USINT_Array(struct Convert_INT_To_USINT_Array* inst){
	/**
	Description:
		Conversion of input value (INT) into a vector of values (BYTES).

	Args:
		(1) INPUT [INT]: A real number (positive, negative).
		
	Returns:
		(1) OUTPUT[0 .. 1] [BYTE (USINT) ARRAY]: Vector of values (BYTES).
	
	Example:
	     // Read inputs
		 inst->INPUT = possible values range from -32.768 to 32.767
		 // Call Function Block
		 Convert_INT_To_USINT_Array(&inst);
		 // Write outputs
		 inst->OUTPUT[0] = Result calculation from inst->INPUT {Part 1: 0 .. 255} 
		 inst->OUTPUT[1] = Result calculation from inst->INPUT {Part 2: 0 .. 255}
	*/
	
	USINT i;
	for(i = 0; i < (USINT)(sizeof(inst->OUTPUT)/sizeof(inst->OUTPUT[0])); i++){
		inst->OUTPUT[i] = ((USINT*)&inst->INPUT)[i];
	}
}

void Convert_REAL_To_USINT_Array(struct Convert_REAL_To_USINT_Array* inst){
	/**
	Description:
		Conversion of input value (REAL - Float) into a vector of values (BYTES).

	Args:
		(1) INPUT [REAL]: A rational number (positive, negative).
		
	Returns:
		(1) OUTPUT[0 .. 3] [BYTE (USINT) ARRAY]: Vector of values (BYTES).
	
	Example:
	     // Read inputs
		 inst->INPUT = possible values range from -3.4E38 to +3.4E38
		 // Call Function Block
		 Convert_REAL_To_USINT_Array(&inst);
		 // Write outputs
		 inst->OUTPUT[0] = Result calculation from inst->INPUT {Part 1: 0 .. 255}
		 ...
		 inst->OUTPUT[3] = Result calculation from inst->INPUT {Part 4: 0 .. 255}
	*/
	
	USINT i;
	for(i = 0; i < (USINT)(sizeof(inst->OUTPUT)/sizeof(inst->OUTPUT[0])); i++){
		inst->OUTPUT[i] = ((USINT*)&inst->INPUT)[i];
	}
}

void Convert_BOOL_Array_To_USINT(struct Convert_BOOL_Array_To_USINT* inst){
	/**
	Description:
		Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans).
	
		Note:
			1 BYTE [0 - 255] = 8 BITs [0 - 1]

	Args:
		(1) INPUT[0 .. 7] [BIT (BOOL) ARRAY]: Vector of bits (1 BYTE). 
		
	Returns:
		(1) OUTPUT [BYTE (USINT)]: A real number greater than or equal to zero.
	
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
		(1) INPUT [BYTE]: A real number greater than or equal to zero.
		
	Returns:
		(1) OUTPUT[0 .. 7] [BIT (BOOL) ARRAY]: Vector of bits (1 BYTE). 
	
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

#endif
