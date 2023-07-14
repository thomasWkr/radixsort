#include "radixsort.h"

using namespace std;

int main(){
    vector<string> texto_aux; 
    string palavra;

    while(cin >> palavra){
        texto_aux.push_back(palavra);
    }

    int tamanho = texto_aux.size();
    string texto[tamanho];
    for (int i = 0; i < texto_aux.size(); i++)
        texto[i] = texto_aux[i];

    MSD_sort(texto, tamanho);

    for (int i = 0; i < tamanho; i++)
        cout << texto[i] << " ";

    return 0;
}

