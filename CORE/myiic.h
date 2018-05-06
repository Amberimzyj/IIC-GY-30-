#ifndef __MYIIC__H
#define __MYIIC__H
#include "sys.h"

//IO方向设置
//#define SDA_IN() Set_SDA_IN()
//#define SDA_OUT() Set_SDA_OUT()

//IO操作函数
#define IIC_SCL PAout(5) //SCL
#define IIC_SDA PAout(6) //SDA
#define READ_SDA  PAin(6) //输入SDA
#define GY30_ADDR  PAout(7) //输出ADDR

//IIC所有操作函数
void IIC_Init(void);  //初始化IIC的IO口
void IIC_Start(void);  //发送IIC开始信号
void IIC_Stop(void);  //发送IIC停止信号
void IIC_Send_Byte(u8 txd);  //IIC发送一个字节
u8 IIC_Read_Byte(unsigned char ack);  //IIC读取一个字节
u8 IIC_Wait_Ack(void);  //IIC等待ACK信号
void IIC_Ack(void);  //IIC发送ACK信号
void IIC_NAck(void);  //IIC不发生ACK信号
void SDA_IN(void);
void SDA_OUT(void);

void IIC_Write_One_Byte(u8 daddr, u8 addr, u8 data);
u8 IIC_Read_One_Byte(u8 daddr, u8 addr);
#endif
