/**
  ******************************************************************************
  * @file    Task01.c 
  * @author  Windy Albert
  * @date    08-April-2017
  * @brief   Task to ....
  ******************************************************************************
  */

/** Includes ----------------------------------------------------------------**/
#include  "stm32f4xx_app.h"
#include  <os.h>                                /** Header file for uCOS-III **/
#include  <arm_math.h>

/** Private macros ----------------------------------------------------------**/
#define LED_RED         GPO_BB(GPIOF_BASE, 9)
#define LED_GREEN       GPO_BB(GPIOF_BASE,10)
#define TEST_PIN        GPO_BB(GPIOF_BASE,11)

/** Private functions[ @static ] --------------------------------------------**/
uint16_t i;
uint32_t sum32,temp32;

float sumf,tempf = PI;


/**
  * @brief      Task to [ @see head of file ].
  * @param      None
  * @retval     None
  */
void Task01(void *p_arg)
{
    OS_ERR      err;
    
    /** Task Initialize *******************************************************/
    (void)p_arg;
    
    
    
    
	
    
    /** Task Body *************************************************************/
    while (DEF_TRUE) {
        //TODO:
        
        *TEST_PIN = 0;
        for(i=0;i<100;i++)
        {
//            sumf = sqrt(tempf);
            arm_sqrt_f32(tempf,&sumf);
        }

        *TEST_PIN = 1;
        
        
//        *LED_RED ^=1;
        *LED_GREEN ^=1;
        OSTimeDly( 50 , OS_OPT_TIME_DLY , &err);
    }
}


/******************* (C) COPYRIGHT 2017 Windy Albert ***********END OF FILE****/
