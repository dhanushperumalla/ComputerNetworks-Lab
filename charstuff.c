#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char frame[50], temp[100] = "DLESTX";
    int i, j = 6; 
    
    printf("Enter input characters: ");
    scanf("%s", frame);
    
    for (i = 0; frame[i] != '\0'; i++) {
        if ((frame[i] == 'D' && frame[i+1] == 'L' && frame[i+2] == 'E') || frame[i] == ' ') {
            strcat(temp, "DLE");
            j += 3; 
        }
        temp[j++] = frame[i];
    }
    
    strcat(temp, "DLESTX");
    printf("The stuffed frame is: ");
    puts(temp);
    
    return 0;
}
