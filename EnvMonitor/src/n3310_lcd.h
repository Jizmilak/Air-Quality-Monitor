#ifndef __3310_LCD_H
#define __3310_LCD_H


#define SPI_MOSI PORTB3
#define SPI_SCK PORTB5
#define SPI_SS PORTB2

#define LCD_RST PORTD3
#define SPI_CS  PORTD4
#define LCD_DC  PORTD5
#define LCD_BL  PORTD6


//display mode -- normal / highlight
#define MENU_NORMAL	0
#define MENU_HIGHLIGHT 1

void LCD_init(void);
unsigned char LCD_write_byte(unsigned char dat, unsigned char dat_type);
void LCD_draw_bmp_pixel(unsigned char X,unsigned char Y,unsigned char *map,
                  unsigned char Pix_x,unsigned char Pix_y);
void LCD_write_string(unsigned char X,unsigned char Y,char *s, char mode);                  
void LCD_write_string_big ( unsigned char X,unsigned char Y, char *string, char mode );
void LCD_write_char_big (unsigned char X,unsigned char Y, unsigned char ch, char mode);
void LCD_write_char(unsigned char c, char mode);
void LCD_set_XY(unsigned char X, unsigned char Y);
void LCD_clear(void);
void LCD_OFF(void);
                  
#endif   // __3310_LCD_H
