#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

#define NAIPE 4
#define CARTA 13

void limpaBaralho(char **x)
{
    for(int i=0; i<NAIPE; ++i)
    {
        for(int j=0; j<CARTA; ++j)
        {
            x[i][j] = '.';
        }
    }
}

void distribuiCarta(char **x, int y)
{
    int i, j;
    
    srand(time(0));
    do
    {
        i = rand() % (3+1-0)+0;
        j = rand() % (12+1-0)+0;
    } while (x[i][j] != '.');
    x[i][j] = '#';
    cout << i+1 << '-' << setw(2) << j+1 << '-' << y << " | ";

}

void distribuiMao(char **x, char **y, int vezes)
{
    int k;
    srand(time(0));

    for (int i = 0; i < vezes; i++)
    {
        k = rand() % (2+1-1)+1;
        if (k == 1)
        {
            distribuiCarta(x, 1);
        }
        else
        {
            distribuiCarta(y, 2);
        }
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    char **b1;
    char **b2;

    //Inicializacao do baralho 1
    b1 = new char*[NAIPE];
    for(int i=0; i<NAIPE; ++i)
    {
        b1[i] = new char[CARTA];
    }
    //Inicializacao do baralho 2
    b2 = new char*[NAIPE];
    for(int i=0; i<NAIPE; ++i)
    {
        b2[i] = new char[CARTA];
    }
    limpaBaralho(b1);
    limpaBaralho(b2);
    cout << "Jogador 1: ";
    distribuiMao(b1, b2, 11);
    cout << "Jogador 2: ";
    distribuiMao(b1, b2, 11);
    cout << "Jogador 3: ";
    distribuiMao(b1, b2, 11);
    cout << "Jogador 4: ";
    distribuiMao(b1, b2, 11);
    return 0;
}
