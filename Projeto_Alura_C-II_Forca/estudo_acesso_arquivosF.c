//ARQUIVO DE ESTUDO DE FUNCOES QUE USAM ARQUIVOS

//conhecimentos sobre funcoes F, extras:
//- fscanf retorna o numero de itens devolvidas basta criar uma variavel antes que dira o retorno, por exemplo se coletar dois valors inteiros ele retornara '2':
/*
    '''
    int n1, n2;
    int sucesso = fscanf("%d %d", &n1, &n2);
    if(sucesso == 2) {
        printf("Os dois números: %d e %d", n1, n2);
    }
    else {
        printf("Aconteceu um erro");
    }
    '''
*/
//- feof indica se o ponteiro(cabeca de leitura) esta apontando para o final do arquivo, muito util quando quer ler o arvquivo ate o final
//- fgetc diferente do fscanf o fgetc é utilizado para leitura de caracteres, entao quando usado ele le apenas o proximo 'char'
/*
    '''
    FILE* f;
    char c;

    f = fopen("arquivo.txt", "r");
    while(!feof(f)) {
        c = fgetc(f);    
        printf("Char %c\n", c);
    }
    '''
*/
//- fread e fwrite leem uma quantidade especifica de dados e guardam na estrutura passada, algo muito usado com arrays, variaveis ou structs