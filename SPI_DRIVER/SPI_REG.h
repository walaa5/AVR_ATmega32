/*
 * SPI_REG.h
 *
 *  Created on: Nov 1, 2019
 *      Author: ESC
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPCR *((volatile u8 *)0x2D)
#define SPSR *((volatile u8 *)0x2E)
#define SPDR *((volatile u8 *)0x2F)

#define SPSR_SPIF 7
#define SPSR_WCOL 6
#define SPSR_SPI2X 0


#define SPCR_SPIE 7
#define SPCR_SPE 6
#define SPCR_MSTR 4
#define SPCR_SPRO 0
#define SPCR_SPR1 1




#endif /* SPI_REG_H_ */
