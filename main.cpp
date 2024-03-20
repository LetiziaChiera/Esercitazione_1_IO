#include<iostream>
#include<math.h>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

// funzione cambio intervallo : prende valore oldValue e restituisce newValue
double mappaValue(double oldValue)
{
    double newValue = 0.75*oldValue-1.75;
    return newValue;
}

int main()
{
    string nameFile = "data.csv";
    ifstream ifs(nameFile); // apre file modalità lettura
    if (!ifs.is_open()) // se il file non viene trovato
    {
        cerr<< "Impossibile aprire il file" << endl;
        return 1;
    }
    else
    {
        ofstream outputFile("result.csv"); // file di output
        outputFile<< "#N mean" << endl;

    //inizializzo i
    unsigned int i= 0;
    double sum = 0;
    double value;
    while(ifs >> value)
    // legge i valori in fstr e li memorizza nella variabile value: restituisce true (lettura riuscita) o false (altrimenti)
    {
        i++; // i = i+1
        value = mappaValue(value);
        sum += value;
        double mean = sum/i; // calcola la media dei primi i valori mappati
        outputFile << i << " " << scientific<< setprecision(15)<< mean << endl;
    }
    outputFile.close();
    }
    ifs.close();
    return 0;
}

