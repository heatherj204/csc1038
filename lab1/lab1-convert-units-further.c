/*
 convert-units-further
 author Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    int i;
    // loop for being within the bounrdies
    for(i = 30; i < 50; i++){
        int cm = i;
        // initilising the variable to hold to valuse of an inch in cm
        float cmInInch = 2.54;
        // initilising the varibale to see the converted inches
        float inches = cm / cmInInch;
        // printing the inces to two decimal places if needed 
        printf("%.2f ", inches);
        if (cm != 30){
            if ((cm+1)%5 == 0){
                printf("\n");
            }
        }
    }
    return 0;
}
