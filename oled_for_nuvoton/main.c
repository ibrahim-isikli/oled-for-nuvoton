/****************************************************************************
 * @file     main.c
 * @version  V1.01
 * $Revision: 1 $
 * $Date: 2019/05/02 8:05p $
 * @brief    oled_for_nuvoton Sample
 * @note
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include "oled_for_nuvoton.h"
#include "ssd1306.h"

#if defined(__GNUC__) && !defined(__ARMCC_VERSION) && defined(OS_USE_SEMIHOSTING)
    extern void initialise_monitor_handles(void);
#endif

extern void Periph_Init(void);
extern void Clock_Init(void);
extern void Pin_Init(void);

void System_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    Clock_Init();
    Pin_Init();
    Periph_Init();

    /* Lock protected registers */
    SYS_LockReg();
}

int32_t main(void)
{
    /* Init System, IP clock, multi-function I/O and Peripheral*/
    System_Init();

    SSD1306_Init();

    SSD1306_GotoXY (44,0);
    SSD1306_Puts ("oled", &Font_11x18, 0x01);
    SSD1306_GotoXY (54, 16);
    SSD1306_Puts ("for", &Font_11x18, 0x01);
    SSD1306_GotoXY (30, 42);
    SSD1306_Puts ("NUVOTON", &Font_11x18, 0x00);
    SSD1306_UpdateScreen();
    CLK_SysTickDelay(1000*1000*3);
    SSD1306_ScrollRight(5,7);
    //SSD1306_Stopscroll();


    while (1);

}
