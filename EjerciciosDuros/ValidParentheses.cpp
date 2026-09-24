//Sacado de => https://leetcode.com/problems/valid-parentheses/description/
//Written And Directed By Alvorak:

//Enunciado
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/
#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char, char> cierre = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
};

class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> pila;

        for (char caracter : s)
        {
            // Si es un carácter de apertura
            if (cierre.find(caracter) != cierre.end())
            {
                // Guardamos el carácter de cierre que esperamos
                pila.push(cierre[caracter]);
            }
            else
            {
                // Si llega un cierre y no había nada abierto
                if (pila.empty())
                {
                    return false;
                }

                // Si el cierre no coincide con el esperado
                if (pila.top() != caracter)
                {
                    return false;
                }

                // Cierre correcto
                pila.pop();
            }
        }

        // Si queda algo en la pila, faltaron cierres
        return pila.empty();
    }
};
