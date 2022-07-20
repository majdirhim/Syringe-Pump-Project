#ifndef __TS_I2C_H_
#define __TS_I2C_H_

#include "stm32h7xx_hal.h"
#include "DEV_Config.h"

#define SET_SDA()     DEV_Digital_Write(DEV_SDA_PIN,GPIO_PIN_SET)    
#define CLR_SDA()     DEV_Digital_Write(DEV_SDA_PIN,GPIO_PIN_RESET)  

#define SET_CLK()     DEV_Digital_Write(DEV_SCL_PIN,GPIO_PIN_SET)    
#define CLR_CLK()     DEV_Digital_Write(DEV_SCL_PIN,GPIO_PIN_RESET)

#define READ_SDA()    DEV_Digital_Read(DEV_SDA_PIN)



void I2C_Init(void);		 
void I2C_Start(void);				
void I2C_Stop(void);	  			
void I2C_Send_Byte(uint8_t txd);		
uint8_t I2C_Read_Byte(uint8_t ack);	
uint8_t I2C_Wait_Ack(void); 				
void TS_Ack(void);					
void TS_NAck(void);				
void I2C_ReadReg(uint8_t I2c_Addr,uint8_t reg,uint8_t *buf,uint8_t len);
uint8_t I2C_WriteReg(uint8_t I2c_Addr,uint8_t reg,uint8_t *buf,uint8_t len);


#endif /*__CAP_I2C_H_*/
