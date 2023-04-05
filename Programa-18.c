#include <stdio.h>
int CountYear (int ano, int mes){                   //Retorna a quantidade de dias entre 1600 e x
    int bi, x=0, i;
    for(i=ano ; i>=1600 ; i--){                     //Laco que conta a quantidade de bissextos
        if (i%400==0) x++;
        else if (i%100!=0 && i%4==0) x++;
    }
    bi=((ano-1600)*365)+x;                          //Converte em dias os anos e soma aos dias bissextos
    if (mes == 2 || mes < 2) bi--;                  //Decrementa um dia bissexto, caso seja antes de fevereiro.
    return bi;
}

int CountDay (int mes){                             //Retorna o total de dias dos meses dos anos nao-bissextos
    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) return 31;
    if (mes==4 || mes==6 || mes==9 || mes==11) return 30;
    if (mes==2) return 28;
}

int CountMes (int mes){                             //Retorna o total de dias ate o mes digitado
    int i, total=0;
    for(i=1 ; i<=mes ; i++){total += CountDay(i);}  //Laco que conta a quantidade de dias ate o mes 
    return total;
}

int main (){
    int dia, mes, ano;
    printf("Insira uma data valida:\n");
    scanf("%d %d %d", &dia, &mes, &ano);
        while(dia <= CountDay(mes) && (mes < 12 || mes > 1)){
            printf("%d\n", CountMes(mes)+CountYear(ano, mes)-(CountDay(mes)-dia)); //Ex: 30 + 365 - (28 - 6)
            scanf("%d %d %d",&dia, &mes, &ano); // Dias do ano + dias do mes - (diferenca do mes x ate o dia x)
        }
    printf("Data invalida! Programa encerrado.\n");
}

