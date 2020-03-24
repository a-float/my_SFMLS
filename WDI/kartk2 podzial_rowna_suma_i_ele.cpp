#include <iostream>
using namespace std;

int check( int tab[], int s1, int s2, int c1, int c2, int s, int e){
    if(s == e)return false;
    if(s1 == s2 && s1 != 0 && c1 == c2){    //taka sama suma, ilosc i nie sa puste
        cout<<s1<<" "<<c1<<endl;
        return true;
    }
    return(check(tab, s1+tab[s], s2, c1+1, c2, s+1, e) ||       //wszystkie opcja
           check(tab, s1, s2+tab[s], c1, c2+1, s+1, e) ||
           check(tab, s1, s2, c1, c2, s+1, e));
}

int main()
{
    int tab[6] = {1,3,5,2,4,6};
    cout<<check(tab, 0,0,0,0,0,6);
    return 0;
}

