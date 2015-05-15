#include<windows.h>
#include<iostream>
#include <fstream>
using namespace std;

int main()
{
    char massiv[5000] = {0};
    ifstream F;
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    hf=FindFirstFile("\*.log", &FindFileData);
    if (hf!=INVALID_HANDLE_VALUE)
    {
        do
        {
                cout << FindFileData.cFileName << endl;
                F.open((FindFileData.cFileName), ios::in);
                while (!F.eof()) {
                    F.getline(massiv, 5000);
                    if (strstr(massiv, "PLS")) {cout << "Have errors" << endl;}
                    if (strstr(massiv, "ORA")) {cout << "Have errors" << endl;}
                    if (strstr(massiv, "ERR")) {cout << "Have errors" << endl;}
                }
                F.close();
        }
        while (FindNextFile(hf,&FindFileData)!=0);
        FindClose(hf);
        F.close();
        system("Pause");
    }
    return 0;
}
