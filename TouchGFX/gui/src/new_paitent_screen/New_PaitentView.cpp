#include <gui/new_paitent_screen/New_PaitentView.hpp>
#include <touchgfx/Color.hpp>
#include <string.h>


Unicode::UnicodeChar keyboardBuffer[5][18]; 
uint8_t keyboardSelection = 0; 
bool test = false;

New_PaitentView::New_PaitentView() :

		name(""),
		weight(0),
		age(0),
		height(0),
		gender(0)
{

}

void New_PaitentView::setupScreen()
{
	SetupDisplayMode();
    New_PaitentViewBase::setupScreen();
}

void New_PaitentView::tearDownScreen()
{
    New_PaitentViewBase::tearDownScreen();
}

void New_PaitentView::keyboardSelected(uint8_t value)
{
	keyboardSelection = value;
}

void New_PaitentView::updateScreen()
{
	if (Unicode::strlen(keyboardBuffer[0]) > 0)
	{
		for (int i = 0; i < Unicode::strlen(keyboardBuffer[0]); i++)
		{
			if (!((('A' <= keyboardBuffer[0][i]) && ('z' >= keyboardBuffer[0][i]))) && (!(keyboardBuffer[0][i] == ' ')))
			{
				test = true;
				touchgfx_printf(" error : %c\n", keyboardBuffer[0][i]);
				break;
			}
			else
				test = false;
		}
		if (!test) 
		{

			button.setTouchable(true);
			boxWithBorderName.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
			
		}
		else
		{
			button.setTouchable(false);
			boxWithBorderName.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(200, 0, 0));
		}
		memset(&textAreaNameBuffer, 0, TEXTAREANAME_SIZE);/* Reset the memory bloc */
		memset(name, 0, 18);
		Unicode::toUTF8(keyboardBuffer[0], (uint8_t*)name, 18);
		Unicode::strncpy(textAreaNameBuffer, keyboardBuffer[0], TEXTAREANAME_SIZE - 1);
		textAreaNameBuffer[TEXTAREANAME_SIZE - 1] = '\0'; // make sure last index is null
		textAreaName.invalidate();
		boxWithBorderName.invalidate();

	}
	if (Unicode::strlen(keyboardBuffer[1]) > 0)
	{	
		for (int i = 0; i < Unicode::strlen(keyboardBuffer[1]); i++)
		{
			if (!(('0' <= keyboardBuffer[1][i]) && ('9' >= keyboardBuffer[1][i])))
			{
				test = true;
				touchgfx_printf(" error : %c\n", keyboardBuffer[1][i]);
				break;
			}
			else
				test = false;
		}
		if (!test)
		{
			button.setTouchable(true);
			boxWithBorderWeight.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		}
		else
		{
			button.setTouchable(false);
			boxWithBorderWeight.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(200, 0, 0));
		}
		memset(&textAreaWeightBuffer, 0, TEXTAREAWEIGHT_SIZE);
		weight = Unicode::atoi(keyboardBuffer[1]);
		Unicode::strncpy(textAreaWeightBuffer, keyboardBuffer[1], TEXTAREAWEIGHT_SIZE - 1);
		textAreaWeightBuffer[TEXTAREAWEIGHT_SIZE - 1] = '\0'; // make sure last index is null
		textAreaWeight.invalidate();
		boxWithBorderWeight.invalidate();
	}
	if (Unicode::strlen(keyboardBuffer[2]) > 0)
	{
		for (int i = 0; i < Unicode::strlen(keyboardBuffer[2]); i++)
		{
			if (!(('0' <= keyboardBuffer[2][i]) && ('9' >= keyboardBuffer[2][i])))
			{
				test = true;
				touchgfx_printf(" error : %c\n", keyboardBuffer[2][i]);
				break;
			}
			else
				test = false;
		}
		if (!test)
		{
			button.setTouchable(true);
			boxWithBorderAge.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		}
		else
		{
			button.setTouchable(false);
			boxWithBorderAge.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(200, 0, 0));
		}
		memset(&textAreaAgeBuffer, 0, TEXTAREAAGE_SIZE);
		age = Unicode::atoi(keyboardBuffer[2]);
		Unicode::strncpy(textAreaAgeBuffer, keyboardBuffer[2], TEXTAREAAGE_SIZE - 1);
		textAreaAgeBuffer[TEXTAREAAGE_SIZE - 1] = '\0'; // make sure last index is null
		textAreaAge.invalidate();
		boxWithBorderAge.invalidate();
	}
	if (Unicode::strlen(keyboardBuffer[3]) > 0)
	{
		for (int i = 0; i < Unicode::strlen(keyboardBuffer[3]); i++)
		{
			if (!(('0' <= keyboardBuffer[3][i]) && ('9' >= keyboardBuffer[3][i])))
			{
				test = true;
				touchgfx_printf(" error : %c\n", keyboardBuffer[3][i]);
				break;
			}
			else
				test = false;
		}
		if (!test)
		{
			button.setTouchable(true);
			boxWithBorderHeight.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		}
		else
		{
			button.setTouchable(false);
			boxWithBorderHeight.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(200, 0, 0));
		}
		memset(&textAreaHeightBuffer, 0, TEXTAREAHEIGHT_SIZE);
		height = Unicode::atoi(keyboardBuffer[3]);
		Unicode::strncpy(textAreaHeightBuffer, keyboardBuffer[3], TEXTAREAHEIGHT_SIZE - 1);
		textAreaHeightBuffer[TEXTAREAHEIGHT_SIZE - 1] = '\0'; // make sure last index is null
		textAreaHeight.invalidate();
		boxWithBorderHeight.invalidate();
	}
	if (New_PaitentView::getgender())
	{
			memset(&textAreaGenderBuffer, 0, TEXTAREAGENDER_SIZE);
			gender = New_PaitentView::getgender();
			switch (gender)
			{
			case 2:
				Unicode::strncpy(textAreaGenderBuffer, "Male", TEXTAREAGENDER_SIZE - 1);
				break;
			case 1:
				Unicode::strncpy(textAreaGenderBuffer, "Female", TEXTAREAGENDER_SIZE - 1);
				break;
			default:
				break;
			}
			boxWithBorderGender.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		textAreaGenderBuffer[TEXTAREAGENDER_SIZE - 1] = '\0'; // make sure last index is null
		textAreaGender.invalidate();
		boxWithBorderGender.invalidate();
	}
}

uint8_t New_PaitentView::getgender()
{
	return presenter->getgender();
}

void New_PaitentView::savepatientdata()
{
		presenter->savepatientheight(height);

		presenter->savepatientweight(weight);

		presenter->savepatientage(age);

		presenter->savepatientgender(gender);

		presenter->savepatientname(name, strlen(name));

	presenter->savepatient();
}

void New_PaitentView::SetupDisplayMode(void)
{
	if (presenter->GetdisplayMode() == 1)
	{
		backend.setVisible(0);
		BackendBlack.setVisible(1);
		BackendChildren.setVisible(0);
	}
	else if (presenter->GetdisplayMode() == 2)
	{
		backend.setVisible(0);
		BackendBlack.setVisible(0);
		BackendChildren.setVisible(2);
	}
	else
	{
		backend.setVisible(1);
		BackendBlack.setVisible(0);
		BackendChildren.setVisible(0);
	}
}

void New_PaitentView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}

