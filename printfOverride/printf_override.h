/*
 * printf_override.h
 *
 *  Created on: 27 déc. 2020
 *      Author: radhwen.zorgui
 */

#ifndef PRINTF_OVERRIDE_H_
#define PRINTF_OVERRIDE_H_


typedef void* ComHandlerType;
typedef enum ComType_e
{
	COM_UART, COM_USB
}ComType;

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE;


Bool printf_init();
Bool printf_changeCom(ComType _comtype, ComHandlerType _comHandler);


#endif /* PRINTF_OVERRIDE_H_ */
