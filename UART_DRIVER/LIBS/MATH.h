/*
 * MATH.h
 *
 *  Created on: Aug 23, 2019
 *      Author: ESC
 */

#ifndef LIBS_MATH_H_
#define LIBS_MATH_H_

#define set_bit(reg , bit_no) reg |= (1 << bit_no)

#define clr_bit(reg , bit_no) reg &= (~(1 << bit_no))

#define toggle_bit(reg , bit_no) reg ^= (1 << bit_no)

#define read_bit(reg , bit_no) ((reg >> bit_no) & 0x01)

#endif /* LIBS_MATH_H_ */
