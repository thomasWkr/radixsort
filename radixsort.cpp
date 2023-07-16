#include "radixsort.h"

using namespace std;

int main(){
    static string texto[1000000];
    static dicionario cont[100000];
    int qtd_palavras = 0;
    int palavras_dif = 0;

    while(cin >> texto[qtd_palavras]){
        qtd_palavras++;
    }

    MSD_sort(texto, qtd_palavras);

    //for (int i = 0; i < qtd_palavras; i++)
    //    cout << texto[i] << "\n";  

    palavras_dif = contar(cont, texto, qtd_palavras);

    for (int i = 0; i < palavras_dif; i++)
        cout << cont[i].palavra << " " << cont[i].ocorrencias << "\n";

    return 0;
}

