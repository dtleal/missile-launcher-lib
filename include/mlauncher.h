#ifndef _LIBMLAUNCHER_H
#define _LIBMLAUNCHER_H
#include<stdio.h>
#include<stdlib.h>
#include<usb.h>
#include<string.h>

#define MISSILE_ID_VENDOR  0x2123
#define MISSILE_ID_PRODUCT 0x1010

/* Funcoes */
int missile_init(struct usb_dev_handle *launcher);
int send_launcher_command(int command, struct usb_dev_handle *launcher);

#endif

