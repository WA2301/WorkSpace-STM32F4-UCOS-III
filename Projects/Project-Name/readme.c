/**
  ******************************************************************************
  * @file    readme.c 
  * @author  Windy Albert
  * @version Fault Detection Device V00
  * @date    04-Apirl-2017
  * @brief   工程裸奔模板，无外设初始化，无操作系统。修改晶振见
  *           stm32f4xx.h line 144
  *          APB1,APB2分频系数不为1,所以对应定时器为时钟源的2倍[见参考手册P107]
  *          USE_STDPERIPH_DRIVER,STM32F40_41xxx,HSE_VALUE=24000000,ARM_MATH_CM4
  
  *          移植更改:1.Option For Target -> C/C++ HSE_VALUE=24000000
                                                   VECT_TAB_OFFSET=0x4000
                                          -> Target IROM1 0x8004000
                      2.system_stm32f4xx.c #define PLL_M      24
  ******************************************************************************
  */
/**
********************************************************************************
1.ucos定时器示例代码：

如果要低频循环执行可采用定时器，在某延时为1000ms的线程中 定期执行某动作（100ms）时
可用定时器实现

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
2.內建消息队里示例代码:

发送：

        extern OS_TCB   Task01TCB;//引用接收方OS_TCB
        u32 msg;
        //msg 所发送的消息地址，2 为消息长度与接收方对应，消息长度为传值
        OSTaskQPost(&Task01TCB,&msg,2, OS_OPT_POST_FIFO, &err);


接收：


        u32* p_msg;
        OS_ERR      err;
        OS_MSG_SIZE  msg_size;//消息长度 此变量必填，否则会内存溢出
        CPU_TS       ts;//消息接收时间戳，不用可填 (CPU_TS *)0



        p_msg = OSTaskQPend(100, OS_OPT_PEND_BLOCKING, &msg_size, &ts, &err);
        
        if(err == OS_ERR_NONE)
        {
            *LED_GREEN ^=1;//收到消息
        }
        else if(err == OS_ERR_TIMEOUT)
        {            
            *LED_RED ^= 1;
        }

3.浮点数context切换寄存器启动 见SystemInit()  FPU->FPCCR  参考uCOS-III cstartup.s文件

            


 **/

//#error "请先阅读版本更迭信息。"       /** 阅读完版本信息后屏蔽此行代码     **/

/************************ (C) COPYRIGHT Holley *****************END OF FILE****/
