#include<stdio.h>
#include<stdlib.h> // Included for exit() function

int main() {
    
    top:
    int current_state = 0;
    char str;
    
    printf("Enter the string: \n");
    while ((str = getchar()) != '\n') {
        if (str != '0' && str != '1') {
            printf("Invalid string\n");
            exit(1); // Exit the program if input is invalid
        } 
        switch (current_state){
            case 0:
                if(str=='0'){
                    current_state =1;
                }else{
                    current_state =3;
                }
                break;
            case 1:
                if(str=='1'){
                    current_state =2;
                }else{
                    current_state =0;
                }
                break;
            case 2:
                if(str=='0'){
                    current_state =3;
                }else{
                    current_state =1;
                }
                break;
            case 3:
                if(str=='1'){
                    current_state =0;
                }else{
                    current_state =2;
                }
                break;
        }

    }
    if(current_state == 0){
        printf("STRING IS ACCEPTED\n");
    }else{
        printf("STRING IS NOT ACCEPTED\n");
    }
    return 0;
}

