/**
  ******************************************************************************
  * @file    readme.c 
  * @author  Windy Albert
  * @version Fault Detection Device V00
  * @date    04-Apirl-2017
  * @brief   �����㱼ģ�壬�������ʼ�����޲���ϵͳ���޸ľ����
  *           stm32f4xx.h line 144
  *          APB1,APB2��Ƶϵ����Ϊ1,���Զ�Ӧ��ʱ��Ϊʱ��Դ��2��[���ο��ֲ�P107]
  *          USE_STDPERIPH_DRIVER,STM32F40_41xxx,HSE_VALUE=24000000,ARM_MATH_CM4
  
  *          ��ֲ����:1.Option For Target -> C/C++ HSE_VALUE=24000000
                                                   VECT_TAB_OFFSET=0x4000
                                          -> Target IROM1 0x8004000
                      2.system_stm32f4xx.c #define PLL_M      24
  ******************************************************************************
  */
/**
********************************************************************************
1.ucos��ʱ��ʾ�����룺

���Ҫ��Ƶѭ��ִ�пɲ��ö�ʱ������ĳ��ʱΪ1000ms���߳��� ����ִ��ĳ������100ms��ʱ
���ö�ʱ��ʵ��

OS_TMR tmr1;
static void tmr1_callback(void);

OSTmrCreate((OS_TMR     *)&tmr1,
            (CPU_CHAR   *)"tmr1",
            (OS_TICK     )20,
            (OS_TICK     )100,
            (OS_OPT      )OS_OPT_TMR_PERIODIC, 
            (OS_TMR_CALLBACK_PTR)tmr1_callback,
            (void       *)0,
            (OS_ERR     *)&err);
            
OSTmrStart( (OS_TMR     *)&tmr1,
            (OS_ERR     *)&err);
********************************************************************************
2.�Ƚ���Ϣ����ʾ������:

���ͣ�

        extern OS_TCB   Task01TCB;//���ý��շ�OS_TCB
        u32 msg;
        //msg �����͵���Ϣ��ַ��2 Ϊ��Ϣ��������շ���Ӧ����Ϣ����Ϊ��ֵ
        OSTaskQPost(&Task01TCB,&msg,2, OS_OPT_POST_FIFO, &err);


���գ�


        u32* p_msg;
        OS_ERR      err;
        OS_MSG_SIZE  msg_size;//��Ϣ���� �˱������������ڴ����
        CPU_TS       ts;//��Ϣ����ʱ��������ÿ��� (CPU_TS *)0



        p_msg = OSTaskQPend(100, OS_OPT_PEND_BLOCKING, &msg_size, &ts, &err);
        
        if(err == OS_ERR_NONE)
        {
            *LED_GREEN ^=1;//�յ���Ϣ
        }
        else if(err == OS_ERR_TIMEOUT)
        {            
            *LED_RED ^= 1;
        }

3.������context�л��Ĵ������� ��SystemInit()  FPU->FPCCR  �ο�uCOS-III cstartup.s�ļ�

            


 **/

//#error "�����Ķ��汾������Ϣ��"       /** �Ķ���汾��Ϣ�����δ��д���     **/

/************************ (C) COPYRIGHT Holley *****************END OF FILE****/
