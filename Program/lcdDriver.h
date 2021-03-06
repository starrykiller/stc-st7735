#ifndef LCDDRIVER_H
#define LCDDRIVER_H

#include "RGBConvert.h"
#include "stc12c5a.h"

sbit	cs=P2^1;	// 模拟SPI的CS口
sbit	rs=P2^0; // 模拟SPI的RS口, 部分屏幕可能为A0(AO)
sbit	sda=P0^1;	// 模拟SPI的SDA口
sbit	scl=P0^0;	// 模拟SPI的SCL口, 部分屏幕可能为SCK
sbit	reset=P1^0;   // RESET口, 可简写为RST
sbit	bl=P0^2;	// 屏幕的背光口, BL或者LED-

// 可直接接3V常亮, 也可以控制

//测试程序横竖屏切换，横屏请开启此宏，竖屏请屏蔽
#define USE_LANDSCAPE 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 160


// 常用颜色的定义

#define RED 0x001f
#define GREEN 0x07e0
#define ORANGE 0x059f
#define BLUE 0xf800
#define WHITE 0xffff
#define BLACK 0x0000
#define YELLOW 0x07ff
#define GRAY0 0xEF7D   
#define GRAY1 0x8410              
#define GRAY2 0x4208   
#define PURPLE 0xb299
#define SKYBLUE 0x8f7d
#define MIDDLEGRAY 0x31A7
char *reverse(char *s);
char *itoa(int n);
void output_Pixel(unsigned int x,unsigned int y); // 输出一个像素
void LCD_ShowChar(int x, int y, int fontSize, char p, int mode, int fgColor, int bgColor);
void LCD_ShowString(int x, int y, int fontSize, char* p, int mode, int fgColor, int bgColor);
void LCD_DrawPoint(unsigned int x,unsigned int y, unsigned int color);
void delay_ms(unsigned int time); // 延迟x毫秒
void SPI_WriteData(unsigned char Data); // 向SPI总线传输一个8位数据
void LCD_WriteIndex(unsigned char Data); // 向屏幕写入一个8位指令
void LCD_WriteData(unsigned char Data); // 向屏幕写入一个8位数据
void LCD_WriteData_16Bit(unsigned int Data); // 向屏幕写入一个16位数据
void LCD_Reset(); // 重置屏幕
void LCD_Init(); // 初始化LCD, 必须调用
void LCD_SetRegion(unsigned int startX, unsigned int startY, unsigned int endX, unsigned int endY); // 设置显示区域，在此区域写数据自动换行
void putPixel(unsigned int x, unsigned int y, unsigned int color); // 将一个像素设为指定颜色
void displaySingleColour(int color); // 单色填充屏幕
void LCD_DrawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color);
void LCD_ShowPicture(unsigned int x,unsigned int y,unsigned int length,unsigned int width);
void LCD_DrawRectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2,unsigned int color);
void LCD_DrawCircle(unsigned int x0,unsigned int y0,unsigned int r,unsigned int color);
void LCD_Fill(unsigned int startX,unsigned int startY,unsigned int endX,unsigned int endY,unsigned int color);
unsigned char code picture1[];
unsigned char code picture2[];
#endif