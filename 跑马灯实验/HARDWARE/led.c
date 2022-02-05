#include "led.h"
#include "sys.h"


void Init_Led()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);//使能B,E系列的时钟io口
	
	
	/*
		首先配置CRL|CRH寄存器（每个系列都有一样的寄存器）   一共有32个位 CRL配置1-8  CRH配置9-16
						CRL前四个为是PA1 后面类似PA2 主要配置输入输出方式和速度（输出有三个速度，输入无速度选择）
	
	*/
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //推挽输出 需要电流为推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;				//PB5输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//输出速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);					//将设置好的模式等存入该函数进行初始化，该函数就会调节相应的寄存器为我们设置好的样子
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //推挽输出 需要电流为推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;				//PB5输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//输出速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);					//将设置好的模式等存入该函数进行初始化，该函数就会调节相应的寄存器为我们设置好的样子
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	/*
	IDR寄存器，该寄存器为只读寄存器  用来读取当前口的io状态
	要使用到的函数是  GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5); 
	*/
	
	/*
	ODR寄存器  该寄存器为输出数据寄存器  用来读写相应口的电平状态，只用低16位
	
	BSRR寄存器 高16位和低16位都有作用    也是设置高低电平

	一般我们对io端口的状态设置都是用这2个函数 GPIO_SetBits(GPIOB, GPIO_Pin_5);设置为1 高电平
																	GPIO_ResetBits (GPIOB, GPIO_Pin_5);设置为0		 低电平
	
	*/
	
	
	
	
	
	
}

