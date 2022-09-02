"""
input_var = 12345

print([(input_var & (0xff << pos*8)) >> pos*8 for pos in range(2)])
print([(input_var >> i*0x08) & 0xff for i in range(2)])

in_byte_arr = [57, 48]; out_num = 0
for i, in_byte_arr_i in enumerate(in_byte_arr):
    #out_num += (in_byte_arr_i << i*0x08) | out_num
    #print(in_byte_arr_i * (256**i) + out_num)
    #print((in_byte_arr_i << i*0x08) | out_num)
    out_num |= in_byte_arr_i << i*0x08

print(57 << 0 | 48 << 8)
print(out_num)

"""

input_var = 73
print([(input_var & (0x1 << pos*1)) >> pos*1 for pos in range(8)])
print([(input_var >> i*0x01) & 0x01 for i in range(8)])
in_bit_arr = [1, 0, 0, 1, 0, 0, 1, 0]
out_byte = 0; 
for i, in_bit_arr_i in enumerate(in_bit_arr):
    #out_byte = (out_byte << 1) | i if in_bit_arr_i == 1 else 0
    out_byte |= in_bit_arr_i << i*0x01 if in_bit_arr_i == 1 else 0

print(out_byte)


"""
unsigned char zero = 0x00;    // 00000000
unsigned char one = 0x01;     // 00000001
unsigned char allOnes = 0xFF; // 11111111
"""
