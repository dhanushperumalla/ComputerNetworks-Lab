#include <stdio.h>
#include <conio.h>

main(){
    int i = 0,count=0;
    char databits[80];
    printf("Enter data bits: ");
    scanf("%s",databits);
    printf("Databits before bit stuffing: %s",databits);
    printf("\nDatabits after bit stuffing: ");
    for (i=0;i<strlen(databits);i++){
        if(databits[i]=='1')
        count++;
        else{
            count=0;
        }
        printf("%c",databits[i]);
        if(count == 5){
            printf("0");
            count=0;
        }
    }
    return 0;
}

