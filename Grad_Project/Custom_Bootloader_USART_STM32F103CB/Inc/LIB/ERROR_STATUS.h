#ifndef LIB_ERROR_STATUS_H_
#define LIB_ERROR_STATUS_H_

typedef enum
{
	NoError,
	OutofRange,
	FPEC_UnlockFailedError,
	FPEC_ProgrammingError,
	FPEC_WriteProtectionError,
	FPEC_FailedToErasePageError,
}ErrorStatus_t;

#endif /* LIB_ERROR_STATUS_H_ */
