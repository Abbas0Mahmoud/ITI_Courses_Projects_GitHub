#ifndef     BIT_MATH_H
#define     BIT_MATH_H

#define     SET_REG_BIT(REG_NAME,BIT_NUM)		    (REG_NAME |= (1 << BIT_NUM))
#define     SET_REG_BITS(REG_NAME,BITS_VALUE) 	    (REG_NAME = BITS_VALUE)
#define     SET_REG_ALLBITS(REG_NAME) 			    (REG_NAME = 0XFF)

#define     CLR_REG_BIT(REG_NAME,BIT_NUM) 		    (REG_NAME &= ~(1 << BIT_NUM))
#define     CLR_REG_BITS(REG_NAME,BITS_VALUE)	    (REG_NAME = BITS_VALUE)
#define     CLR_REG_ALLBITS(REG_NAME) 			    (REG_NAME = 0X00)

#define     GET_BIT(REG_NAME,BIT_NUM)			    ((REG_NAME >> BIT_NUM) & 1)

#define     TOGGLE_BIT(REG_NAME,BIT_NUM)		    (REG_NAME ^= (1 << BIT_NUM))

#endif