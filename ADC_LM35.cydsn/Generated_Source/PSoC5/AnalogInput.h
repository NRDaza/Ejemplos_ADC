/*******************************************************************************
* File Name: AnalogInput.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_AnalogInput_H) /* Pins AnalogInput_H */
#define CY_PINS_AnalogInput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AnalogInput_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AnalogInput__PORT == 15 && ((AnalogInput__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AnalogInput_Write(uint8 value);
void    AnalogInput_SetDriveMode(uint8 mode);
uint8   AnalogInput_ReadDataReg(void);
uint8   AnalogInput_Read(void);
void    AnalogInput_SetInterruptMode(uint16 position, uint16 mode);
uint8   AnalogInput_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AnalogInput_SetDriveMode() function.
     *  @{
     */
        #define AnalogInput_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AnalogInput_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AnalogInput_DM_RES_UP          PIN_DM_RES_UP
        #define AnalogInput_DM_RES_DWN         PIN_DM_RES_DWN
        #define AnalogInput_DM_OD_LO           PIN_DM_OD_LO
        #define AnalogInput_DM_OD_HI           PIN_DM_OD_HI
        #define AnalogInput_DM_STRONG          PIN_DM_STRONG
        #define AnalogInput_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AnalogInput_MASK               AnalogInput__MASK
#define AnalogInput_SHIFT              AnalogInput__SHIFT
#define AnalogInput_WIDTH              1u

/* Interrupt constants */
#if defined(AnalogInput__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AnalogInput_SetInterruptMode() function.
     *  @{
     */
        #define AnalogInput_INTR_NONE      (uint16)(0x0000u)
        #define AnalogInput_INTR_RISING    (uint16)(0x0001u)
        #define AnalogInput_INTR_FALLING   (uint16)(0x0002u)
        #define AnalogInput_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AnalogInput_INTR_MASK      (0x01u) 
#endif /* (AnalogInput__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AnalogInput_PS                     (* (reg8 *) AnalogInput__PS)
/* Data Register */
#define AnalogInput_DR                     (* (reg8 *) AnalogInput__DR)
/* Port Number */
#define AnalogInput_PRT_NUM                (* (reg8 *) AnalogInput__PRT) 
/* Connect to Analog Globals */                                                  
#define AnalogInput_AG                     (* (reg8 *) AnalogInput__AG)                       
/* Analog MUX bux enable */
#define AnalogInput_AMUX                   (* (reg8 *) AnalogInput__AMUX) 
/* Bidirectional Enable */                                                        
#define AnalogInput_BIE                    (* (reg8 *) AnalogInput__BIE)
/* Bit-mask for Aliased Register Access */
#define AnalogInput_BIT_MASK               (* (reg8 *) AnalogInput__BIT_MASK)
/* Bypass Enable */
#define AnalogInput_BYP                    (* (reg8 *) AnalogInput__BYP)
/* Port wide control signals */                                                   
#define AnalogInput_CTL                    (* (reg8 *) AnalogInput__CTL)
/* Drive Modes */
#define AnalogInput_DM0                    (* (reg8 *) AnalogInput__DM0) 
#define AnalogInput_DM1                    (* (reg8 *) AnalogInput__DM1)
#define AnalogInput_DM2                    (* (reg8 *) AnalogInput__DM2) 
/* Input Buffer Disable Override */
#define AnalogInput_INP_DIS                (* (reg8 *) AnalogInput__INP_DIS)
/* LCD Common or Segment Drive */
#define AnalogInput_LCD_COM_SEG            (* (reg8 *) AnalogInput__LCD_COM_SEG)
/* Enable Segment LCD */
#define AnalogInput_LCD_EN                 (* (reg8 *) AnalogInput__LCD_EN)
/* Slew Rate Control */
#define AnalogInput_SLW                    (* (reg8 *) AnalogInput__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AnalogInput_PRTDSI__CAPS_SEL       (* (reg8 *) AnalogInput__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AnalogInput_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AnalogInput__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AnalogInput_PRTDSI__OE_SEL0        (* (reg8 *) AnalogInput__PRTDSI__OE_SEL0) 
#define AnalogInput_PRTDSI__OE_SEL1        (* (reg8 *) AnalogInput__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AnalogInput_PRTDSI__OUT_SEL0       (* (reg8 *) AnalogInput__PRTDSI__OUT_SEL0) 
#define AnalogInput_PRTDSI__OUT_SEL1       (* (reg8 *) AnalogInput__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AnalogInput_PRTDSI__SYNC_OUT       (* (reg8 *) AnalogInput__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AnalogInput__SIO_CFG)
    #define AnalogInput_SIO_HYST_EN        (* (reg8 *) AnalogInput__SIO_HYST_EN)
    #define AnalogInput_SIO_REG_HIFREQ     (* (reg8 *) AnalogInput__SIO_REG_HIFREQ)
    #define AnalogInput_SIO_CFG            (* (reg8 *) AnalogInput__SIO_CFG)
    #define AnalogInput_SIO_DIFF           (* (reg8 *) AnalogInput__SIO_DIFF)
#endif /* (AnalogInput__SIO_CFG) */

/* Interrupt Registers */
#if defined(AnalogInput__INTSTAT)
    #define AnalogInput_INTSTAT            (* (reg8 *) AnalogInput__INTSTAT)
    #define AnalogInput_SNAP               (* (reg8 *) AnalogInput__SNAP)
    
	#define AnalogInput_0_INTTYPE_REG 		(* (reg8 *) AnalogInput__0__INTTYPE)
#endif /* (AnalogInput__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AnalogInput_H */


/* [] END OF FILE */
