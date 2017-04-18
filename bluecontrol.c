// Things to do:
//check file existance
// add help
// check for thinkpad / bluetooth presence
// modify fail handling
// add command line flags!
// make modular


// Version 1.2.1b

#include <stdio.h>
#include <string.h>
int menuchoice = 0;
int flag = 0;
FILE *fp;
char user[5];


int main()
{

        printf("Checking for root privileges...\n");
        fp = popen("whoami", "r");
        fgets(user, sizeof user, fp);
        printf("Current User: %s\n", user);

        if((strcmp (user,"root")) == 0)
        {
                //printf("debug %d\n", strcmp (user,"root")); /* Debug info */

                do
                {
                        system ("clear");
                        printf("\n");
                        printf("Bluecontrol\n\n");
                        printf(" /\\/\\\n");
                        printf("\(*'~')\n");
         printf(" U U\n");
                        printf("\n");
                        printf("Bluetooth chip control for IBM X-Series ThinkPads\(TM)\n");
                        printf("\(C) Michael Cockrem 2009 ~ Version 1.2.1b \(b for eternal Beta)\n");
                        printf("\n");
                        printf("Menu\n----\n\n 0: off\n 1: on\n q: quit\n or h for help\n");
                        printf("Please confirm choice (and press return)\n");
                        printf("\n");

                        scanf("%c", &menuchoice);

                        if(menuchoice == 'q')
                        {
                                printf("Quit Requested:\n");
                                printf("Exiting, Goodbye.\n");
                                flag = 3;
                        }

                        else if(menuchoice == 'h')
                        {
                                printf("Help\n\n");
                                printf("This is a program designed to control the bluetooth module\n");
                                printf("for the IBM X series and others with built in bluetooth modules\n");
                                printf("(as part of IBM_ACPI) It has been tested on: IBM X31\n");
                                printf("Please email the author with problems, suggestions or if you have\n");
                                printf("used this program on another machine we have not yet tested!\n");
                                printf("mikecockrem@gmail.com - All comments welcome\n");
                                printf("\n\n");
                                printf("Press 0 to disable bluetooth\n");
                                printf("Press 1 to enable bluetooth\n");
                                printf("Press q to quit the program\n");
                                printf("Press h for help \(this screen!)\n");
                                printf("\n");
                                printf("[Enter] to continue\n");
                                getchar();
                                getchar(); //dirty but who knows why it wont stay still: clean up in next version!
                                flag = 0;
                        }
                        else if(menuchoice == '0')
                        {
                                printf("Turning BlueTooth OFF\n");
                                        system ("echo 0 >> /sys/devices/platform/thinkpad_acpi/bluetooth_enable");
                                        printf("Unloading modules, byebye!\n");
                                        system ("rmmod -v btusb");
                                        system ("rmmod -v bluetooth");
                                        flag = 3;
                                }
                                else if(menuchoice == '1')
                                        {
                                                printf("Turning BlueTooth ON\n");
                                                system ("echo 1 >> /sys/devices/platform/thinkpad_acpi/bluetooth_enable");
                                                printf("Loading Modules...\n");
                                                system ("modprobe -v btusb");
                                                system ("modprobe -v bluetooth");
                                                flag = 3;
                                        }
                                        else
                                        {
                                                printf("Error \(#2):\n\a You did not give valid input \(0, 1 or Q)\n Its REALLY not that hard...\n press enter\n");
                                                getchar();
                                                flag = 0;
                                        }


                }while(flag != 3);

        }
        else
        {
                printf("Error \(#3):\n\a You must run this program as root!\n");
        }

        printf("\n");
   printf("All done! Goodbye.\n");
        return(0);
}
