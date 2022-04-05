#ifndef     BIT_MATH_H
#define     BIT_MATH_H

#define     SET_BIT(REG_NAME,BIT_NUM)		                            (REG_NAME |= (1 << BIT_NUM))
#define     SET_BITS(REG_NAME,BITS_VALUE) 	                            (REG_NAME = BITS_VALUE)
#define     SET_ALLBITS(REG_NAME) 			                            (REG_NAME = 0XFF)
#define     SET_UPPER_NIPPLE(REG_NAME,NIPPLE_VALUE)                     (REG_NAME = ((REG_NAME & 0X0F) | (NIPPLE_VALUE << 4 )))
#define     SET_LOWER_NIPPLE(REG_NAME,NIPPLE_VALUE)                     (REG_NAME = ((REG_NAME & 0XF0) | (NIPPLE_VALUE))

#define     CLR_BIT(REG_NAME,BIT_NUM) 		                            (REG_NAME &= ~(1 << BIT_NUM))
#define     CLR_BITS(REG_NAME,BITS_VALUE)	                            (REG_NAME = BITS_VALUE)
#define     CLR_ALLBITS(REG_NAME) 			                            (REG_NAME = 0X00)

#define     GET_BIT(REG_NAME,BIT_NUM)			                        ((REG_NAME >> BIT_NUM) & 1)
#define     GET_UPPER_NIPPLE(REG_NAME)                                  ((REG_NAME >> 4))
#define     GET_LOWER_NIPPLE(REG_NAME)                                  ((REG_NAME & 0X0F))

#define     TOGGLE_BIT(REG_NAME,BIT_NUM)		                        (REG_NAME ^= (1 << BIT_NUM))

#endif
