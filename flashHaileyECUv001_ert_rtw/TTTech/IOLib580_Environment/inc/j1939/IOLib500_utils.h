/*
 * Copyright (C) 2015 TTTech Computertechnik AG. All rights reserved
 * Schönbrunnerstraße 7, A--1040 Wien, Austria. office@tttech.com
 *
 * Puropse: Public declaration of Files for the IOLib_TTC580
 */

#ifndef INC_IOLIB500_UTILS_H_
#define INC_IOLIB500_UTILS_H_

#ifdef MATLAB_MEX_FILE
#include "simstruc.h"
#else
#include "rtwtypes.h"
#include <string.h>
#endif //MATLAB_MEX_FILE
#include "j1939/dm_layer.h"

//J1939: FMI [0..31]
#define FMI_INACTIVE_MARKER			0x3FU
extern const uint16_T FMI_map[];   //j1939 mapping of ErrorCodes -> FMI : defined in IOLib500_FMI_map.c
extern const uint16_T sizeof_FMI_map; //defined in IOLib500_FMI_map.c


void bit_packing(real64_T , uint32_T *const , uint8_T ,uint8_T ,uint8_T ,uint8_T ,uint8_T , real64_T , real64_T );
void bit_unpacking(const uint32_T *const , real64_T *const , uint8_T  ,uint8_T  ,uint8_T  ,uint8_T  ,uint8_T, real64_T, real64_T );
uint16_T crc32(uint8_T *const , uint32_T *const , uint16_T ,uint16_T );
uint16_T DM1_IO_Block_handler(const uint16_T *const , const uint16_T *const , FAULT_T *const ,bool *const, uint32_T, uint8_T, uint8_T, uint8_T, uint8_T, uint8_T, uint8_T, uint8_T, uint8_T);

#endif  /* INC_IOLIB500_UTILS_H_ */


