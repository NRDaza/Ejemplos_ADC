/*******************************************************************************
* File Name: PinAnalog.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PinAnalog_ALIASES_H) /* Pins PinAnalog_ALIASES_H */
#define CY_PINS_PinAnalog_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define PinAnalog_0			(PinAnalog__0__PC)
#define PinAnalog_0_INTR	((uint16)((uint16)0x0001u << PinAnalog__0__SHIFT))

#define PinAnalog_INTR_ALL	 ((uint16)(PinAnalog_0_INTR))

#endif /* End Pins PinAnalog_ALIASES_H */


/* [] END OF FILE */
