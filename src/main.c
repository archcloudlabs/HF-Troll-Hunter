#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

/**
 *@brief get a random value via seed from /dev/urandom.
 *@param N/A
 *@return integer value
 */
int roll() 
{
    char *buff = (char *) malloc(100);
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd, buff, 100);
    close(fd);

    srand( (int) buff);
    int val = rand();
    free(buff);

    return val;
}

/**
 *@brief XoR decode and print of char pointer
 *@param [val] char pointer 
 *@return N/A
 */
void decode(char *val) {
    
    for (int i = 0; i < 22; i++) {
        printf("%c",(val[i] ^ 51)); 
    }
    printf("\n");

}

int main(int argc, char *argv[])
{

    char *title = 
    "██████╗ ██╗   ██╗███╗   ██╗ ██████╗ ███████╗ ██████╗ ███╗   ██╗███████╗       ██╗       ██╗  ██╗ █████╗  ██████╗██╗  ██╗███████╗██████╗ ███████╗\n"
    "██╔══██╗██║   ██║████╗  ██║██╔════╝ ██╔════╝██╔═══██╗████╗  ██║██╔════╝       ██║       ██║  ██║██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗██╔════╝\n"
    "██║  ██║██║   ██║██╔██╗ ██║██║  ███╗█████╗  ██║   ██║██╔██╗ ██║███████╗    ████████╗    ███████║███████║██║     █████╔╝ █████╗  ██████╔╝███████╗\n"
    "██║  ██║██║   ██║██║╚██╗██║██║   ██║██╔══╝  ██║   ██║██║╚██╗██║╚════██║    ██╔═██╔═╝    ██╔══██║██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗╚════██║\n"
    "██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████╗╚██████╔╝██║ ╚████║███████║    ██████║      ██║  ██║██║  ██║╚██████╗██║  ██╗███████╗██║  ██║███████║\n"
    "╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝    ╚═════╝      ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝\n";
    printf("%s",title);
    printf("\t\t\t\t\t\t\t[==== D&H Adventure Simulator - 3000 ====]\n");
    printf("\t\t\t\t\t\t\t[=====     Troll Hunter Edition     =====]\n");

    char hostname[200];
    gethostname(hostname, 200);

    //char *flag = "flag{troll_destroyer_!!}";
    char *flag="U_RTHGA\\__lWV@GA\\JVAlN";
    char *story = "You're venturing through the woods of memes. Suddenly a "\
        "troll appears!\nA troll throws a mighty fist at your skull!\nAuto" \
        "rolling to dodge!\n";

    printf("[*] Welcome mighty challenger who hails from %s!\n", hostname);
    printf("%s", story);

    char buffer[10];
    int num = roll(); // Value you're going to try to modify via r2
    num = num % 20;

    printf("\nClick to roll> ");
    gets(buffer);
    printf("\nYou auto rolled a %d!", num);

    char *winning = "\nWith a mighty swing of your sword, you defeat the troll!";
    char *you_win = "[+] You win!!\n";
    char *losing= "\nThe troll swings his club and knocks you into next Tuesday!";


    if (num != 9000)  {
        printf("%s", losing);
        printf("\n[!] Oh dear, you died! Better luck next time friend.");
        exit(31337);
    }
    else {
        printf("%s", winning);
        printf("%s", you_win);
        decode(flag);
        return 0;
    }
    return 1;
}
