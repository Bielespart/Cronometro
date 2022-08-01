#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca usada para adicionar acentuação.
#include <conio.h>  //Biblioteca para usar a função kbhit()
#include <windows.h>    //Biblioteca para usar a função Sleep()

//Variáveis globais
int h = 0, min = 0, sec = 0;

//Função que lê uma tecla pressionada, sem pausar um loop.
char tecla_presisonada(){
    if (_kbhit())   //"Se uma tecla for pressionada..."
        return _getch();    //"...retorna a tecla pressionada"
    else
        return -1;
}

//Função que cronometra o tempo e exibe na tela.
void cronometro(char ativo){
    do{
        ++sec;
        system("clear||cls");   //Limpa a tela a cada ciclo executado.
        printf("\n\t\t\t%.2d : %.2d : %.2d\n\n", h, min, sec);
        printf("Aperte p para parar o cronometro.\n");
        if(sec == 60){
            sec = 0;
            min++;
        }
        if(min == 60){
            min = 0;
            h++;
        }
        if(h == 24){
            h = 0;
        }
        Sleep(1000);    //Espera 1000 milisegundos para adicionar 1 á variável "sec"(segundos);
    }while((ativo = tecla_presisonada()) != 'p');   //Enquanto a tecla de pausa não for pressionada, o ciclo vai continuar rodando.
}

//Função que zera o cronometro.
void zerar_cronometro(void){
    h = 0;
    min = 0;
    sec = 0;
}

int main()
{
    setlocale(LC_ALL,"");   //Adiciona acentuação.

    system("title Cronômetro"); //Coloca um título no programa.
    printf("Cronômetro by Bielespart\n");
    Sleep(5000);    //Espera 5000 milisegundos até a mensagem desaparecer.

    char ativo = 'a', opc = 'i';    //ativo = variável para ativar o cronômetro | opc = varíavel que lê qual opção foi selecionada.
    do{
        do{
            system("clear||cls");   //Limpa a tela a cada ciclo executado.
            printf("\n\t\t\t%.2d : %.2d : %.2d\n\n", h, min, sec);
            printf("Aperte i para iniciar o cronometro.\n");
            printf("Aperte z para zerar o cronometro.\n");
            printf("Aperte x para sair do cronometro.\n");
            opc = tecla_presisonada();  //"opc" recebe qual tecla foi pressionada.
        }while((opc != 'i') && (opc != 'z') && (opc != 'x'));   //O ciclo vai ser executado enquanto não for selecionada uma opção válida.

        switch(opc){ //O switch lê qual opção foi selecionada e realiza uma ação de acordo com a opção.
        case 'i':
            cronometro(ativo);  //Ativa o cronometro.
            break;
        case 'z':
            zerar_cronometro(); //Zera o cronometro
            break;
        case 'x':
            exit(1);    //Sai do programa.
            break;
        default:
            printf ("Opção inválida.\n");
            break;
        }
    }while(opc != 'x'); //O programa vai ser executado enquanto a tecla sair não for pressionada.
return 0;
}
