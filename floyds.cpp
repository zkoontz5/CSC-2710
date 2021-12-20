/*
    Zach Koontz
    CSC - 2710
    Program 2
 
    Floyds Algoritm Program
 
    How to compile:
    g++ -Wall algoPrg2.cpp -o lfg
 
    How to execute:
    ./lfg
*/


#include <iostream>
#include <fstream>

void floyds(int** info, int** P_info, int sizeall);
void print(int** info, int sizeall);
int** cMatrix(int** zach, int &sizeall);
void path(int** info, int v1, int v2);
void fill(int** info, int sizeall);
void empty(int** info, int sizeall);
int** mMatrix(int sizeall);

using namespace std;

#define INFINITY 4000

int main()
{
    int sizeall;
    string fileN;
    int edge;
    
    string vert1, vert2;
    int v1, v2;
    int ball;
    int number = 0;
    
    int** matrix1;
    int** matrix2;
    int** matrix3;
    
    cout << "Enter the file name(gfw1.dat or gfw2.dat): " << endl;
    cin >> fileN;

    ifstream file(fileN);
    file >> sizeall >> edge;
    matrix1 = new int*[sizeall];
    
    for(std::size_t i = 0; i < sizeall; i++) {
        matrix1[i] = new int[sizeall];
    }
    fill(matrix1, sizeall);

    for(int i = 0; i < edge; i++) {
        file >> vert1 >> vert2 >> ball;
        v1 = static_cast<int>(vert1[1] - '0');
        v2 = static_cast<int>(vert2[1] - '0');
        matrix1[v1 - 1][v2 - 1] = ball;
    }

    file >> number;
    matrix2 = cMatrix(matrix1, sizeall);
    matrix3 = mMatrix(sizeall);
    floyds(matrix2, matrix3, sizeall);

    cout << "Matrix 1" << endl;
    print(matrix1, sizeall);
    cout << "\np Matrix" << endl;
    print(matrix2, sizeall);
    cout << "\nP Matrix" << endl;
    print(matrix3, sizeall);
    cout << "\n" << endl;
    
    for(int i = 0; i < number; i++) {
        file >> vert1 >> vert2;
        
        v1 = static_cast<int>(vert1[1] - '0');
        v2 = static_cast<int>(vert2[1] - '0');

        if( matrix3[v1-1][v2-1] != 0 ) {
            cout << vert1 << " ";
            path(matrix3, v1, v2-1);
            cout << vert2 << "\n";
        
        } else {
            cout << "No path." << endl;
        }

    }

    return 0;
}

void floyds(int** info, int** P_info, int sizeall) {
    for(int k = 0; k < sizeall; k++) {
    for(int i = 0; i < sizeall; i++) {
    for(int j = 0; j < sizeall; j++) {
        if(info[i][k] + info[k][j] < info[i][j]) {
            P_info[i][j] = k+1;
            info[i][j] = info[i][k] + info[k][j];
       }
      }
     }
    }
   }

void print(int** info, int sizeall) {

    cout << "\n";
    for(int i = 0; i < sizeall; i++) {
    for(int j = 0; j < sizeall; j++) {
        if(info[i][j] == INFINITY)
            cout << "INF" << "\t";
        else
            cout << info[i][j] << endl;
        }
    }
}

int** cMatrix(int** zach, int &sizeall) {
    int** info = new int*[sizeall];
    for(std::size_t i = 0; i < sizeall; i++) {
        info[i] = new int[sizeall];
    }
    for(std::size_t i = 0; i < sizeall; i++) {
    for(std::size_t j = 0; j < sizeall; j++) {
        info[i][j] = zach[i][j];
        }
    }
    return info;
}

void path(int** info, int v1, int v2) {
   
     if (info[v1][v2] != 0) {
        path(info, v1, info[v1][v2]-1);
        cout << 'v' << info[v1][v2] << ' ';
        path(info, info[v1][v2]-1, v2);
    }
}

void fill(int** info, int sizeall) {
    for(int i = 0; i < sizeall; i++) {
    for(int j = 0; j < sizeall; j++) {
        if(i == j)
                info[i][j] = 0;
        else
                info[i][j] = INFINITY;
        }
    }
}

void empty(int** info, int sizeall) {
    for(int i = 0; i < sizeall; i++) {
    for(int j = 0; j < sizeall; j++) {
        info[i][j] = 0;
        }
    }
}


int** mMatrix(int sizeall) {
    int** info = new int*[sizeall];
    for(std::size_t i = 0; i < sizeall; i++) {
        info[i] = new int[sizeall];
    }
    empty(info, sizeall);
    return info;
}

