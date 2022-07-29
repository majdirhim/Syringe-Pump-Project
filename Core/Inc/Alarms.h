#ifdef __cplusplus
 extern "C" {
#endif

#include "SW_common.h"


 void Alarm_Action(uint8_t event);

 void Alerts_Action (uint8_t event);

 void Notifs_Action(uint8_t event);

 void Default_Event_Action(uint8_t event);

 void SyringeStop();

#ifdef __cplusplus
  }
#endif
