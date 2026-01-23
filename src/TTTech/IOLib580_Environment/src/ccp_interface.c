#ifndef __CCP_INTERFACE_H__
#define __CCP_INTERFACE_H__

#include "ccp.h"
#include "ccp_config.h"
#include "IO_Driver.h"
#include "IO_CAN.h"

#if CCP_ENABLED == 1

#define DTO_FRAME_LENGTH 8
//corresponding to approx. 100kBaud:
#define MAX_ATTEMPTS 200

void ccpSend( CCP_BYTEPTR msg )
{
 static bool b_initialized = false;
 static ubyte2 handle_ccp_DTO = 0;
 IO_CAN_DATA_FRAME can_frame = {0};
 ubyte1 cnt;

 /* CAN_Write buffer initialization */
 if (!b_initialized) {
     IO_CAN_ConfigMsg(&handle_ccp_DTO,
                    CCP_CAN_CHANNEL,
                    IO_CAN_MSG_WRITE,
                    CCP_ID_FORMAT,
                    0,
                    0);
     b_initialized = true;
 }
 else { // initialization done
 /* CAN_write function from TTC500 IO-Driver */
//	 for(i=0;i<DTO_FRAME_LENGTH;i++){
//	 can_frame.data[i] = msg[i];
//	 }
	memcpy((void *)&(can_frame.data),(ubyte1*)msg,DTO_FRAME_LENGTH);
	can_frame.length = DTO_FRAME_LENGTH;
	can_frame.id_format = CCP_ID_FORMAT;
	can_frame.id = CCP_DTO_ID;
    cnt=0;
    while( (IO_CAN_MsgStatus(handle_ccp_DTO) != IO_E_OK) && (++cnt<=MAX_ATTEMPTS));
	IO_CAN_WriteMsg(handle_ccp_DTO,&can_frame);
    
 } /* else */
} 

/*----------------------------------------------------------------------------*/
/* Convert a memory address from CCP 8/32bit into a C pointer */

CCP_MTABYTEPTR ccpGetPointer( CCP_BYTE addr_ext, CCP_DWORD addr )
{

 CCP_MTABYTEPTR MemoryAdressPtr;

 (void)addr_ext; /* avoid compiler warnings about unused parameter */
 MemoryAdressPtr = (CCP_MTABYTEPTR)(addr);
 return MemoryAdressPtr;

}

/*----------------------------------------------------------------------------*/
/* CCP Callbacks */

void ccpUserBackground( void )
{
}
#endif

#endif
