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
    float data1;     //��������
    delay_init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //����NVIC�жϷ���2
    usart_init(115200);    //���ڳ�ʼ��������
    LED_Init();       //LED�˿ڳ�ʼ��
    IIC_Init();    //��ʼ��IIC
    GY_30_Init();  //��ʼ��GY-30
    delay_ms(100);


    while (1)
    {


        GY_30_SendMode(0x01);  //�ϵ�
        GY_30_SendMode(0x10);  //����Ϊ�����߷ֱ���ģʽ
        delay_ms(180);  //�����ʱ180ms

        //����ȡ������ת��Ϊ��ǿ
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
            printf("\r\n��ǰ��ǿΪ��%glx\r\n", data1);
        }

    }

}

