#include "batt.h"
#include "i2c.h"
/**Private fucntion**/
static uint16_t readWord(SBSCommand command){
	uint16_t res;
	uint8_t buffrx[2]={0,0} ;
	if(HAL_SMBUS_Master_Transmit_IT(&hsmbus1, (BATTADDR<<1), (uint8_t*)command, 1, SMBUS_FIRST_FRAME)!=HAL_OK){
		return UnknownError ;
	}

	while(HAL_SMBUS_GetState(&hsmbus1) != HAL_SMBUS_STATE_READY);
	/* receive low byte and high byte*/
	for(int count =0 ;count < 2;count++){

	if(HAL_SMBUS_Master_Receive_IT(&hsmbus1, (BATTADDR<<1), &buffrx[count], 1, SMBUS_LAST_FRAME_NO_PEC)!=HAL_OK)
		{
		return UnknownError ;
		}
	}
	/*2 byte data*/
	res = (uint16_t)(buffrx[1]<<8);
	res|=buffrx[0];
	return res;
}

/** To use function**/

uint16_t voltage(){
	return readWord(Voltage);
}

uint16_t current(){
	return readWord(Current);
}

uint16_t fullChargeCapacity(){
	return readWord(FullChargeCapacity);
}

uint16_t designCapacity(){
	return readWord(DesignCapacity);
}

uint16_t relativeStateOfCharge(){
	return readWord(RelativeStateOfCharge);
}

uint16_t batteryStatus(){
	return readWord(BatteryStatus);
}

uint16_t serialNumber() {
	return readWord(SerialNumber);
}
uint16_t runtimetoempty(){
	return readWord(RunTimeToEmpty);
}
float temperature() {
	return (readWord(Temperature) * 0.1) - 273.15;
}









