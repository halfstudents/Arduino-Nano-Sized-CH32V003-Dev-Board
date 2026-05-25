#include "debug.h"

void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    /* Enable GPIOC clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    /* PC4 as OUTPUT */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    /* LED OFF initially */
    GPIO_ResetBits(GPIOC, GPIO_Pin_3);
}

int main(void)
{
    SystemCoreClockUpdate();
    Delay_Init();

    GPIO_Config();

    while(1)
    {
        /* Toggle LED at PC4 */
        GPIO_SetBits(GPIOC, GPIO_Pin_3);   // LED ON
        Delay_Ms(500);

        GPIO_ResetBits(GPIOC, GPIO_Pin_3); // LED OFF
        Delay_Ms(500);
    }
}
