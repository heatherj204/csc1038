#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

    // <type> *<pointerName> = (<type>*)malloc(<number_of_bytes_allocated>);
    int *pNumber = (int*)malloc(200);

    // checking to see if dynamic allocation worked
    if (!pNumber){
        printf("Failed to allocate memory");
    }

    // releasing dynamically allocated memory
    free(pNumber);
    pNumber = NULL;

}
