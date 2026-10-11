/******************************************************************************
* Copyright (C) 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/
/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_types.h"
#include "xparameters.h"

u32 *GPIO  = (u32 *)  XPAR_XGPIO_0_BASEADDR;
u32 *GPIO1 = (u32 *)  XPAR_XGPIO_1_BASEADDR;
int main()
{
    u32 data_step;
    init_platform();
    
    while(1)
{   
    data_step=GPIO[2];
    GPIO1[0]=data_step;
} 
    print("Hello World\n\r");
    print("Successfully ran Hello World application\n\r");
    cleanup_platform();
    return 0;
}
