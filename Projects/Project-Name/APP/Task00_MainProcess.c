/**
  ******************************************************************************
  * @file    Task00.c 
  * @author  Windy Albert
  * @date    08-April-2017
  * @brief   Task to handle application main process.
  ******************************************************************************
  */

/** Includes ----------------------------------------------------------------**/
#include "stm32f4xx_app.h"
#include  <os.h>                                /** Header file for uCOS-III **/




/** Private functions[ @static ] --------------------------------------------**/


/**
  * @brief      Task to [ @see head of file ].
  * @param      None
  * @retval     None
  */
void Task00(void *p_arg)
{
    OS_ERR      err;
    GPIO_InitTypeDef  GPIO_InitStructure;
    
    /** Task Initialize *******************************************************/
    (void)p_arg;
	
    

    /* GPIOF Peripheral clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    
    
    /** Task Body *************************************************************/
    while (DEF_TRUE) {
        //TODO:
        
        
        *GPO_BB(GPIOB_BASE, 5)^=1;
        
        
        
        OSTimeDly( 200 , OS_OPT_TIME_DLY , &err);
    }
}

/******************* (C) COPYRIGHT 2017 Windy Albert ***********END OF FILE****/
