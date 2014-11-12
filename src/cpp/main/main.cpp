/* 
 * File:   main.cpp
 * Author: jeremy
 *
 * Created on 30 octobre 2014, 21:24
 */

#include <cstdlib>
#include "../../include/menu/MenuPrinc.h"
using namespace std;

int main() {
    
 /*   MenuPrinc menu;
    menu.menu();
  * */
    Anagram an;
    an.sortWord("abc");
    an.sortWord("acb");
    
    return 0;
}