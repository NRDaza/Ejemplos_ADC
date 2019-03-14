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
    CyGlobalIntEnable; /* Enable global interrupts. */
    int32 enteros[3];
    float voltajes[3];
    int ciclo_util;
    char str[12];
    
    ADC_Start();
    PWM_Start();
    LCD_Start();
    AMux_Start();


    for(;;)
    {
    AMux_FastSelect(0);
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    enteros[0] = ADC_GetResult32();;    
    ADC_StopConvert();
    
    voltajes[0] = ADC_CountsTo_Volts(enteros[0]);
    sprintf(str,"%.4f",voltajes[0]);
    LCD_Position(0,0);
    LCD_PrintString("A0");
    LCD_Position(1,0);
    LCD_PrintString(str);
    
    
    AMux_FastSelect(1);
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    enteros[1] = ADC_GetResult32();;    
    ADC_StopConvert();
    
    voltajes[1] = ADC_CountsTo_Volts(enteros[1]);
    sprintf(str,"%.4f",voltajes[1]);
    LCD_Position(0,5);
    LCD_PrintString("A1");
    LCD_Position(1,5);
    LCD_PrintString(str);
    
    
    AMux_FastSelect(2);
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    enteros[2] = ADC_GetResult32();;    
    ADC_StopConvert();
    
    voltajes[2] = ADC_CountsTo_Volts(enteros[2]);
    sprintf(str,"%.4f",voltajes[2]);
    LCD_Position(0,10);
    LCD_PrintString("A2");
    LCD_Position(1,10);
    LCD_PrintString(str);
    
    ciclo_util=(voltajes[1]*255)/5;
    PWM_WriteCompare(ciclo_util);
    
    
      
    }
}

/* [] END OF FILE */
