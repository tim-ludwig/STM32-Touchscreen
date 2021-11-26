//*******************************************************************
/*!
\file   Lib/Example/Device/config.h
\author Thomas Breuer
\date   31.01.2013
\brief  Configuration file
*/

//*******************************************************************
#include "lib.h"
#include "Peripheral/Disp_OTM8009A.h"
#include "Src/FMC.h"

//*******************************************************************
#include "Com/Hardware/Display/Font/Font_8x12.h"

//*******************************************************************
cSystem sys;

cHwPinConfig::MAP cHwPinConfig::table[] =
{
	// UART
	USART1_RX_PA_10,
	USART1_TX_PA_9,

	// I2C
	I2C4_SCL_PD_12,
	I2C4_SDA_PB_7,

	// ETH
	ETH_MDIO_PA_2,
	ETH_MII_RX_CLK_PA_1,
	ETH_MII_RX_DV_PA_7,
	ETH_MII_TX_EN_PG_11,
	ETH_MII_TXD0_PG_13,
	ETH_MII_TXD1_PG_14,
	ETH_MII_RXD0_PC_4,
	ETH_MII_RXD1_PC_5,

	// USB
	OTG_FS_DM_PA_11,
	OTG_FS_DP_PA_12,

	//FMC
	FMC_D0_PD_14,  
	FMC_D1_PD_15,  
	FMC_D2_PD_0, 
	FMC_D3_PD_1,
	FMC_D4_PE_7,
	FMC_D5_PE_8, 
	FMC_D6_PE_9, 
	FMC_D7_PE_10, 
	FMC_D8_PE_11, 
	FMC_D9_PE_12, 
	FMC_D10_PE_13, 
	FMC_D11_PE_14, 
	FMC_D12_PE_15,
	FMC_D13_PD_8,  
	FMC_D14_PD_9,
	FMC_D15_PD_10,  
	FMC_D16_PH_8,
	FMC_D17_PH_9,
	FMC_D18_PH_10,
	FMC_D19_PH_11,
	FMC_D20_PH_12,
	FMC_D21_PH_13,
	FMC_D22_PH_14,
	FMC_D23_PH_15,
	FMC_D24_PI_0,
	FMC_D25_PI_1,
	FMC_D26_PI_2,
	FMC_D27_PI_3,
	FMC_D28_PI_6,
	FMC_D29_PI_7,
	FMC_D30_PI_9,
	FMC_D31_PI_10,

	FMC_A0_PF_0,
	FMC_A1_PF_1,
	FMC_A2_PF_2,
	FMC_A3_PF_3,
	FMC_A4_PF_4,
	FMC_A5_PF_5,
	FMC_A6_PF_12,
	FMC_A7_PF_13,
	FMC_A8_PF_14,
	FMC_A9_PF_15,
	FMC_A10_PG_0,
	FMC_A11_PG_1,
	FMC_A12_PG_2,
	FMC_A13_PG_3,
	FMC_A14_PG_4,
	FMC_A15_PG_5,

	FMC_SDCLK_PG_8,
	FMC_SDNCAS_PG_15,
	FMC_SDCKE0_PH_2,
	FMC_SDNE0_PH_3,
	FMC_SDNWE_PH_5,
	FMC_SDNRAS_PF_11,
	FMC_NBL0_PE_0,
	FMC_NBL1_PE_1, 
	FMC_NBL2_PI_4,
	FMC_NBL3_PI_5,

	END_OF_TABLE
};


cHwPort_N            portA        ( cHwPort_N::PA );
cHwPort_N            portB        ( cHwPort_N::PB );
cHwPort_N            portC        ( cHwPort_N::PC );
cHwPort_N            portD        ( cHwPort_N::PD );
cHwPort_N            portE        ( cHwPort_N::PE );
cHwPort_N            portI        ( cHwPort_N::PI );      
cHwPort_N            portJ        ( cHwPort_N::PJ );
	
cHwTimer_N           timer        ( cHwTimer_N::TIM_3, 10000 );

cHwUART_N            uart         ( cHwUART_N::USART_1,
                                    cHwUART::BR_115200,
                                    255,
                                    255 );

cHwRTC_0 rtc(cHwRTC_0::LSI);

//*******************************************************************
cHwPort::Pin     LD1       ( portJ, 13 );
cHwPort::Pin     LD2       ( portJ,  5 );

cHwPort::Pin     B1        ( portA, 0 );

//*******************************************************************
// UART (via USB)
//*******************************************************************
cDevTextIO_UART com ( uart, 255, 255 );

//*******************************************************************
// LCD
//*******************************************************************
cHwFMC              fmc        ( cHwFMC::SDRAM_Bank1 );  
cHwDSI              hwDSI      ( fmc.startAddr()     );
cHwPort::Pin        lcdResetPin( portJ, 15 );
                         
cHwDisp_OTM8009Aram disp       ( hwDSI,lcdResetPin, 
                                 cHwDisp_OTM8009A::LANDSCAPE_90, 
                                 fontFont_8x12, 2 );
cDevDisplayGraphic  lcd        ( disp );

//*******************************************************************
// Touch
//*******************************************************************
cHwI2Cmaster_N      i2c        ( cHwI2Cmaster_N::I2C_4,
                                 cHwI2Cmaster::CR_400kHz );

//EOF
