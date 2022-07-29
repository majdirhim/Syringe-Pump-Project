#include "Sim7600.h"

extern UART_HandleTypeDef huart1;

HAL_StatusTypeDef SendAtCommand(char command[]) {
	return (HAL_UART_Transmit(&huart1, (uint8_t*) command, strlen(command), 200));
}

HAL_StatusTypeDef ReceiveAck(char expectedACK[]) {
	char buff[50];
	HAL_StatusTypeDef status = HAL_UART_Receive(&huart1, (uint8_t*) buff,
			sizeof(buff), 500);
	if (status == HAL_OK && (strcmp(buff, expectedACK) == 0))
		return HAL_OK;
	else
		return HAL_ERROR;
}

HAL_StatusTypeDef HTTPSPUT(char URL[], char jsondata[]) {
	char URLBuff[200], Databuff[30];
	if (!(SendAtCommand("AT+HTTPINIT") & ReceiveAck("OK")
			& SendAtCommand("AT+HTTPPARA=\"CONTENT\",\"application/json\"")
			& ReceiveAck("OK"))) {
		sprintf(URLBuff, "AT+HTTPPARA = \"URL\",%s", URL);
		if (SendAtCommand(URLBuff) == HAL_OK && ReceiveAck("OK") == HAL_OK) {
			sprintf(Databuff, "AT+HTTPDATA=%d,1000", strlen(jsondata));
			if (!(SendAtCommand(Databuff) & ReceiveAck("DOWNLOAD")
					& SendAtCommand(jsondata)& SendAtCommand("AT+HTTPACTION=4"))) {
				return (SendAtCommand("AT+HTTPTERM"));
			}

		}
	}
	return HAL_ERROR;
}

