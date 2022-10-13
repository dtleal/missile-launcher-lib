#include "mlauncher.h"

int missile_init(struct usb_dev_handle *launcher)
{
    int ret=0, claimed=0;
    struct usb_bus *bus;
    struct usb_device *dev;

    usb_init();
    usb_find_busses();
    usb_find_devices();

    for (bus = usb_busses; bus; bus = bus->next) {
        for (dev = bus->devices; dev; dev = dev->next){
            if (dev->descriptor.idVendor == MISSILE_ID_VENDOR &&
                dev->descriptor.idProduct == MISSILE_ID_PRODUCT)
            {
                launcher = usb_open(dev);
                if (launcher == NULL)
                    return -1;
                else
                    return 0;
            }
        }
    }
}

int send_launcher_command(int command, struct usb_dev_handle *launcher)
{
    int ret=0;
    char msg[8]={};

    switch(command) {
        // up 
        case 0x26:
            msg[1] = 2;
            break;

        // down 
        case 0x28:
            msg[1] = 1;
            break;

        // left  
        case 0x25:
            msg[1] = 4;
            break;

        // right
        case 0x27:
            msg[1] = 8;
            break;

        // fire 
        case 0xD:
            msg[1] = 16;
            break;

        // stop
        case 0x8D:
            msg[1] = 0x20;
            break;

        default:
            return 404;
            break;
          
    }

    ret = usb_control_msg(launcher, 0x21, 0x09, 0, 0, (char*)msg, 8,100);
    usleep(100000);
    
    msg[1]=0x20;
    ret = usb_control_msg(launcher, 0x21, 0x09, 0, 0, (char*)msg, 8,100);

    return ret;
}
