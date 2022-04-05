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
#define TOG_BIT(REG,BIT)                       (REG^=(1<<BIT))
#define SET_PortValue(REG,VALUE)                (REG|=VALUE)
#define CLR_PortValue(REG,VALUE)                (REG&=~VALUE)
#define TOG_PortValue(REG,VALUE)                (REG^=VALUE)
#define GET_PortValue(REG,VALUE)                (REG&VALUE)

#define SET_NibbleLittlePORT(REG)               (REG|=0x0f)
#define CLR_NibbleLittlePORT(REG)               (REG&=~0x0f)
#define TOG_NibbleLittlePORT(REG)               (REG^=0x0f)
#define GET_NibbleLittlePORT(REG)               (REG&0x0f)

#define SET_NibbleMostPORT(REG)                 (REG|=0xf0)
#define CLR_NibbleMostPORT(REG)                 (REG&=~0xf0)
#define TOG_NibbleMostPORT(REG)                 (REG^=0xf0)
#define GET_NibbleMostPORT(REG)                 (REG&0xf0)
#define SET_BitValue(REG,BIT,VALUE)             (VALUE==0?(REG&=~(1<<BIT)):(REG|=(1<<BIT)))

#endif
