#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


void print(string* str, int n)
{
    for (int i = 0; i < n; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
}
 
int char_at(string str, int d)
{
    if (str.size() <= d)
        return -1;
    else
        return str.at(d);
}

void MSD_sort_aux(string* str, int lo, int hi, int pos)
{
    if (hi <= lo) {
        return;
    }
 
    int count[256 + 2] = { 0 };

    unordered_map<int, string> temp;
    
    //contando ocorrência de cada caractere
    for (int i = lo; i <= hi; i++) {
        int c = char_at(str[i], pos);
        count[c+2]++;
    }
 
    // fase de acumulação
    for (int r = 0; r < 256 + 1; r++)
        count[r + 1] += count[r];
 
    // constroi o vetor temporario
    for (int i = lo; i <= hi; i++) {
        int c = char_at(str[i], pos);
        temp[count[c+1]++] = str[i];
    }

    for (int i = lo; i <= hi; i++)
        str[i] = temp[i - lo];
 
    // chamada recursiva
    for (int r = 0; r < 256; r++)
        MSD_sort_aux(str, lo + count[r], lo + count[r + 1] - 1,
                 pos + 1);
}
 
void MSD_sort(string* str, int n) {

    MSD_sort_aux(str, 0, n - 1, 0);

}