/**
  ******************************************************************************
  * @file    main.c 
  * @author  Windy Albert
  * @version V1.0
  * @date    26-April-2017
  * @brief   Main program body.
  ******************************************************************************
  */

/** Includes ----------------------------------------------------------------**/
#include "stm32f4xx.h"
#include  <os.h>                                /** Header file for uCOS-III **/


/*************** Task00 Configuration *****************************************/
#define          TASK00_STK_SIZE                     128u
#define          TASK00_PRIO                           2u
static  OS_TCB   Task00TCB;
static  CPU_STK  Task00Stk[
                 TASK00_STK_SIZE];
        void     Task00 (void *p_arg);

/*************** End of Task Configuration ************************************/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
    static RCC_ClocksTypeDef  rcc_clocks;
    OS_ERR  err;

    /** Prepare for OS. *******************************************************/
    CPU_IntDis();                         /* Disable all interrupts.          */

    OSInit(&err);                         /* Init uC/OS-III.                  */

    CPU_Init();                           /* Initialize the uC/CPU services   */
    
    RCC_GetClocksFreq(&rcc_clocks);/* Init uC/OS periodic time src (SysTick). */
    OS_CPU_SysTickInit(((CPU_INT32U)rcc_clocks.HCLK_Frequency) / \
                        (CPU_INT32U)OSCfg_TickRate_Hz);

    //SysTick_Config(((CPU_INT32U)rcc_clocks.HCLK_Frequency)/(CPU_INT32U)OSCfg_TickRate_Hz);
    
    
    
    /**************************************************************************/
    /********************* Create Task00 **************************************/
    OSTaskCreate((OS_TCB       *)&Task00TCB,    (CPU_CHAR     *)"",
                 (OS_TASK_PTR   ) Task00,       (void         *)0u,
                 (OS_PRIO       ) TASK00_PRIO,
                 (CPU_STK      *)&Task00Stk[0u],
                 (CPU_STK_SIZE  ) Task00Stk[
                                  TASK00_STK_SIZE / 10u],
                 (CPU_STK_SIZE  ) TASK00_STK_SIZE,
                 (OS_MSG_QTY    )0u,
                 (OS_TICK       )0u,
                 (void         *)0u,
                 (OS_OPT        )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR |
                                  OS_OPT_TASK_SAVE_FP),
                 (OS_ERR       *)&err);

                 
    OSStart(&err);    /* Start multitasking (i.e. give control to uC/OS-III). */

    (void)&err;

    return (0u);
}


/******************* (C) COPYRIGHT 2017 Windy Albert************END OF FILE****/
