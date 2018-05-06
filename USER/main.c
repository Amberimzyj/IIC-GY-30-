#include "stm32f10x.h"
#include "sys.h"
#include "usart.h"
#include "led.h"
#include "delay.h"
#include "myiic.h"
#include "GY-30.h"


int main(void)
{
//    u16 t;
//    u16 len;
    u16 times = 0;
    u16 time2 = 0;
    u16  data;
    float data1;     //光照数据
    delay_init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //设置NVIC中断分组2
    usart_init(115200);    //串口初始化波特率
    LED_Init();       //LED端口初始化
    IIC_Init();    //初始化IIC
    GY_30_Init();  //初始化GY-30
    delay_ms(100);


    while (1)
    {


        GY_30_SendMode(0x01);  //上电
        GY_30_SendMode(0x10);  //设置为连续高分辨率模式
        delay_ms(180);  //最多延时180ms

        //将读取的数据转换为光强
        data = GY_30_Read();
        data1 = data / 1.2;

        times++;
        if (times % 1 == 0)
        {
            LED0 = !LED0;
            times = 0;
        }
        time2++;
        if (time2 % 10 == 0)
        {
            printf("\r\n当前光强为：%glx\r\n", data1);
        }

    }

}

