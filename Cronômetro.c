#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca usada para adicionar acentua��o.
#include <conio.h>  //Biblioteca para usar a fun��o kbhit()
#include <windows.h>    //Biblioteca para usar a fun��o Sleep()

//Vari�veis globais
int h = 0, min = 0, sec = 0;

//Fun��o que l� uma tecla pressionada, sem pausar um loop.
char tecla_presisonada(){
    if (_kbhit())   //"Se uma tecla for pressionada..."
        return _getch();    //"...retorna a tecla pressionada"
    else
        return -1;
}

//Fun��o que cronometra o tempo e exibe na tela.
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
        Sleep(1000);    //Espera 1000 milisegundos para adicionar 1 � vari�vel "sec"(segundos);
    }while((ativo = tecla_presisonada()) != 'p');   //Enquanto a tecla de pausa n�o for pressionada, o ciclo vai continuar rodando.
}

//Fun��o que zera o cronometro.
void zerar_cronometro(void){
    h = 0;
    min = 0;
    sec = 0;
}

int main()
{
    setlocale(LC_ALL,"");   //Adiciona acentua��o.

    system("title Cron�metro"); //Coloca um t�tulo no programa.
    printf("Cron�metro by Bielespart\n");
    Sleep(5000);    //Espera 5000 milisegundos at� a mensagem desaparecer.

    char ativo = 'a', opc = 'i';    //ativo = vari�vel para ativar o cron�metro | opc = var�avel que l� qual op��o foi selecionada.
    do{
        do{
            system("clear||cls");   //Limpa a tela a cada ciclo executado.
            printf("\n\t\t\t%.2d : %.2d : %.2d\n\n", h, min, sec);
            printf("Aperte i para iniciar o cronometro.\n");
            printf("Aperte z para zerar o cronometro.\n");
            printf("Aperte x para sair do cronometro.\n");
            opc = tecla_presisonada();  //"opc" recebe qual tecla foi pressionada.
        }while((opc != 'i') && (opc != 'z') && (opc != 'x'));   //O ciclo vai ser executado enquanto n�o for selecionada uma op��o v�lida.

        switch(opc){ //O switch l� qual op��o foi selecionada e realiza uma a��o de acordo com a op��o.
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
            printf ("Op��o inv�lida.\n");
            break;
        }
    }while(opc != 'x'); //O programa vai ser executado enquanto a tecla sair n�o for pressionada.
return 0;
}
