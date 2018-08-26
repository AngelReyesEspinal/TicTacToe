/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Angge
 *
 * Created on 23 de enero de 2018, 22:57
 */

#include <cstdlib>
#include <iostream>

using namespace std;

char tablero[3][3] = 
{
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
};

bool turnoDeX = true;

bool hayGanador()
{
    for(int i = 0; i < 3 ; i++)
    {
        if(tablero[i][0] != '_' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
        {
            return true;
        }
    }
    
    /*validacion vertical*/
    for(int i = 0; i < 3 ; i++)
    {
        if(tablero[0][i] != '_' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
        {
            return true;
        }
    }
    
    /*validacion diagonal, izquierda a derecha*/
    if(tablero[1][1] != '_' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] )
    {
        return true;
    }
    
    /*validacion diagonal, derecha a izquierda*/
    if(tablero[1][1] != '_' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
    {
        return true;
    }
    
    return false;
}

bool hayEmpate()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(tablero[i][j] == '_' )
            {
                return false;
            }
        }
    }
    return true;
}

void mostrarTablero()
{
    char jugador = turnoDeX ? 'X' : '0';
    
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout << tablero[i][j] << "\t";
        }
        cout << endl;
    }
    
    int fila = 0;
    int columna = 0;
    
    cout << "Es turno de " << jugador<<endl;
    
    cout << "Introduce la fila a jugar" << endl;
    cin >> fila;
    
    if(fila > 2 || fila < 0)
    {
        cout << "posición incorrecta, intente de nuevo entre 0 y 2" << endl;
        cin >> fila;    
    } 
    
    cout << "Introduce la columna a jugar " << endl;
    cin >> columna;
    
    if(columna > 2 || columna < 0)
    {
        cout << "posición incorrecta, intente de nuevo entre 0 y 2" << endl;
        cin>> columna;    
    }
    
    tablero[fila][columna] = jugador;
    
    if(hayGanador())
    {
        cout<<"Felicidades ha ganado "<<jugador;
        exit (0);
    }
    
    if(hayEmpate())
    {
        cout<<"Hay empate"<<endl;
        exit(0);
    }
    
    turnoDeX = !turnoDeX;
}

int main(int argc, char** argv) {
    while(true){    
        mostrarTablero();
    }
    return 0;
}

