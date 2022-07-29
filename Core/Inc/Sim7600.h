#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"
#include "stdio.h"


 HAL_StatusTypeDef SendAtCommand(char command[]); // sends At command via UART

 HAL_StatusTypeDef ReceiveAck(char expectedACK[]); // Receive and compare ACK

 HAL_StatusTypeDef HTTPSPUT(char URL[],char jsondata[]); // Init HTTPS and send json data



#ifdef __cplusplus
  }
#endif
