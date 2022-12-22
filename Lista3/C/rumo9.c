#include <stdio.h>

int soma = 0;
int quantidadeDigitos = 0;
int grauN = 0;
char numero[1001];

int somadorString(char *num)
{
    if (num[0] == '\0')
        return 0;

    if (num[0] != '\0')
    {
        soma += (num[0] - '0');
    }
    somadorString(&num[1]);
}

int soma_digito(int num)
{
    int a, b;
    a = num % 10;
    b = (num - a) / 10;

    quantidadeDigitos++;

    if (b <= 0)
    {
        return a;
    }
    else
    {
        return a + soma_digito(b);
    }
}
int main()
{

    while (scanf("%s", numero))
    {
        soma = 0;
        quantidadeDigitos = 0;
        grauN = 0;

        if (numero[0] == '0')
        {
            return 0;
        }
        else
        {
            somadorString(numero); // DESCOBRIR A SOMA DA STRING, RETORNA *SOMA*
            grauN++;
            if (soma % 9 == 0)
            {
                if (soma_digito(soma) == 9)
                {
                    if (quantidadeDigitos > 1)
                    {
                        grauN++;
                    }
                    printf("%s is a multiple of 9 and has 9-degree %d.\n", numero, grauN);
                }

                if(soma_digito(soma) != 9){
                    while (quantidadeDigitos > 1)
                    {
                        soma = soma_digito(soma);
                        quantidadeDigitos = 0;
                        soma_digito(soma);
                        grauN++;
                    }
                    printf("%s is a multiple of 9 and has 9-degree %d.\n", numero, grauN);
                }

            }
            else
            {
                printf("%s is not a multiple of 9.\n", numero);
            }
        }
    }
    return 0;
}