/*******************************************************************************
* File Name: PinAnalog.h  
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

#if !defined(CY_PINS_PinAnalog_H) /* Pins PinAnalog_H */
#define CY_PINS_PinAnalog_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinAnalog_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinAnalog__PORT == 15 && ((PinAnalog__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinAnalog_Write(uint8 value);
void    PinAnalog_SetDriveMode(uint8 mode);
uint8   PinAnalog_ReadDataReg(void);
uint8   PinAnalog_Read(void);
void    PinAnalog_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinAnalog_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinAnalog_SetDriveMode() function.
     *  @{
     */
        #define PinAnalog_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinAnalog_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinAnalog_DM_RES_UP          PIN_DM_RES_UP
        #define PinAnalog_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinAnalog_DM_OD_LO           PIN_DM_OD_LO
        #define PinAnalog_DM_OD_HI           PIN_DM_OD_HI
        #define PinAnalog_DM_STRONG          PIN_DM_STRONG
        #define PinAnalog_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinAnalog_MASK               PinAnalog__MASK
#define PinAnalog_SHIFT              PinAnalog__SHIFT
#define PinAnalog_WIDTH              1u

/* Interrupt constants */
#if defined(PinAnalog__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinAnalog_SetInterruptMode() function.
     *  @{
     */
        #define PinAnalog_INTR_NONE      (uint16)(0x0000u)
        #define PinAnalog_INTR_RISING    (uint16)(0x0001u)
        #define PinAnalog_INTR_FALLING   (uint16)(0x0002u)
        #define PinAnalog_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinAnalog_INTR_MASK      (0x01u) 
#endif /* (PinAnalog__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinAnalog_PS                     (* (reg8 *) PinAnalog__PS)
/* Data Register */
#define PinAnalog_DR                     (* (reg8 *) PinAnalog__DR)
/* Port Number */
#define PinAnalog_PRT_NUM                (* (reg8 *) PinAnalog__PRT) 
/* Connect to Analog Globals */                                                  
#define PinAnalog_AG                     (* (reg8 *) PinAnalog__AG)                       
/* Analog MUX bux enable */
#define PinAnalog_AMUX                   (* (reg8 *) PinAnalog__AMUX) 
/* Bidirectional Enable */                                                        
#define PinAnalog_BIE                    (* (reg8 *) PinAnalog__BIE)
/* Bit-mask for Aliased Register Access */
#define PinAnalog_BIT_MASK               (* (reg8 *) PinAnalog__BIT_MASK)
/* Bypass Enable */
#define PinAnalog_BYP                    (* (reg8 *) PinAnalog__BYP)
/* Port wide control signals */                                                   
#define PinAnalog_CTL                    (* (reg8 *) PinAnalog__CTL)
/* Drive Modes */
#define PinAnalog_DM0                    (* (reg8 *) PinAnalog__DM0) 
#define PinAnalog_DM1                    (* (reg8 *) PinAnalog__DM1)
#define PinAnalog_DM2                    (* (reg8 *) PinAnalog__DM2) 
/* Input Buffer Disable Override */
#define PinAnalog_INP_DIS                (* (reg8 *) PinAnalog__INP_DIS)
/* LCD Common or Segment Drive */
#define PinAnalog_LCD_COM_SEG            (* (reg8 *) PinAnalog__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinAnalog_LCD_EN                 (* (reg8 *) PinAnalog__LCD_EN)
/* Slew Rate Control */
#define PinAnalog_SLW                    (* (reg8 *) PinAnalog__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinAnalog_PRTDSI__CAPS_SEL       (* (reg8 *) PinAnalog__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinAnalog_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinAnalog__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinAnalog_PRTDSI__OE_SEL0        (* (reg8 *) PinAnalog__PRTDSI__OE_SEL0) 
#define PinAnalog_PRTDSI__OE_SEL1        (* (reg8 *) PinAnalog__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinAnalog_PRTDSI__OUT_SEL0       (* (reg8 *) PinAnalog__PRTDSI__OUT_SEL0) 
#define PinAnalog_PRTDSI__OUT_SEL1       (* (reg8 *) PinAnalog__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinAnalog_PRTDSI__SYNC_OUT       (* (reg8 *) PinAnalog__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinAnalog__SIO_CFG)
    #define PinAnalog_SIO_HYST_EN        (* (reg8 *) PinAnalog__SIO_HYST_EN)
    #define PinAnalog_SIO_REG_HIFREQ     (* (reg8 *) PinAnalog__SIO_REG_HIFREQ)
    #define PinAnalog_SIO_CFG            (* (reg8 *) PinAnalog__SIO_CFG)
    #define PinAnalog_SIO_DIFF           (* (reg8 *) PinAnalog__SIO_DIFF)
#endif /* (PinAnalog__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinAnalog__INTSTAT)
    #define PinAnalog_INTSTAT            (* (reg8 *) PinAnalog__INTSTAT)
    #define PinAnalog_SNAP               (* (reg8 *) PinAnalog__SNAP)
    
	#define PinAnalog_0_INTTYPE_REG 		(* (reg8 *) PinAnalog__0__INTTYPE)
#endif /* (PinAnalog__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinAnalog_H */


/* [] END OF FILE */
