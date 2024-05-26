#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//inclui os outros arquivos do projeto e unifica o todo
#include "Model.h"
#include "View.h"
#include "Controller.h"


int main(){
    
    //cria a array pecas
    PECA pecas[28]; 

    menu(pecas); //acessa o controller
   
    return 0;
}
