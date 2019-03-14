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


int32 entero, voltaje;
float temp;
char str[16];


int main(void)
{
    

    LCD_Start();
    Opamp_Start();
    Opamp_1_Start();
    ADC_Start();
    
    LCD_Position(0,3);
    LCD_PrintString("LM35");
    
    CyGlobalIntEnable; /* Enable global interrupts. */


    for(;;)
    {
        Mux_FastSelect(0);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        entero=ADC_GetResult32();
        ADC_StopConvert();
        
        voltaje = ADC_CountsTo_mVolts(entero);
        temp= voltaje/10.00;
        
        sprintf(str,"%.1fC" ,temp);
        LCD_Position(1,2);
        LCD_PrintString(str);
        
        
        Mux_FastSelect(1);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        entero=ADC_GetResult32();
        ADC_StopConvert();
        
        voltaje = ADC_CountsTo_mVolts(entero);
        temp= voltaje/10.00;
        
        sprintf(str,"%.1fC" ,temp);
        LCD_Position(1,9);
        LCD_PrintString(str);
        
        //Morado GND, Gris VCC, Cafe Out,
        
        
        //-----------------------------------------------Termistor----------------
    }
}

/* [] END OF FILE */
