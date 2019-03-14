/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"

int main(void)
{
    int32 output;
    char str[12];
    float ADCvoltaje;
    
    LCD_Start();
    LCD_Position(0,5);
    LCD_PrintString("Voltaje");
    ADC_Start();
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    
    
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        output = ADC_GetResult32();
       // ADCvoltaje = ADC_CountsTo_Volts();//funciona para conversion menor a 20 bits
        ADCvoltaje = (5.00000/1048576)*output;
        LCD_Position(1,3);
        sprintf(str,"%.7f",ADCvoltaje);
        LCD_PrintString(str);
       //built settings, linker, use nanolib float..,true,,, system ,heap size 0x200
    }
}

/* [] END OF FILE */
