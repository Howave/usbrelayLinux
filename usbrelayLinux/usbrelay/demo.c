#include<unistd.h>
#include "usbrelay.h"

libusb_device_handle *devh = NULL;
int main(int argc, char *argv[]) 
{
    devh = USBRELAY_Open(1);
    if (devh != NULL) {
        printf("Open Success\n");
    }
    else {
        printf("Open Fail\n");
        return -1;
    }
    if (USBRELAY_SetRelay(devh, 1, 1) == 0) {
        printf("SetRelay1 Success\n");
    }
    else {
        printf("SetRelay1 Fail\n");
    }
    usleep(1000000); //500ms
    if (USBRELAY_SetRelay(devh, 1, 0) == 0) {
        printf("SetRelay1 Success\n");
    }
    else {
        printf("SetRelay1 Fail\n");
    }
    if (USBRELAY_Close(devh) == 0) {
        printf("Close Success\n");
    }
    else {
        printf("Close Fail\n");
    }
    return 0;
}
