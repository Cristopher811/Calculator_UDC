#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char str[100] = "1 + 2 + 3 + 4";
    int suma = 0;
    int numero = 0;

    for(int i = 0; i < strlen(str); i++){
       if(str[i] == '+' || str[i] == ' '){
            numero = atoi(str);
            suma += numero;
    }
        printf("= %d\n", suma);
            

/*    switch (){
        case '+':
        break;
        case '-':
            //function
        break;
        case '*':
            //function
        break;
        case '/':
            //function
        break;
        case '^':
            //function
        break;
        default:
            printf("Unkown operation...\n");
            exit(0);
        break;
    } */
    }
}
