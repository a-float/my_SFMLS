#include<iostream>

struct Frac{
    int n;
    int d;

    void simplify(){
        int a = this->n;
        int b = this->d;
        int c;
        while(b!=0){
            c = a%b;
            a = b;
            b = c;
        }
        n = n/a;
        d = d/a;
    }

    public:
    Frac(){}

    void eq(int a, int b){
        if(d==0)throw "Division by zero";
        this->n = a;
        this->d = b;
        simplify();
    }

    Frac(int n, int d){
        eq(n,d);
    }

    Frac operator + (Frac &f){
        return(Frac(n*f.d + f.n*d, d * f.d));
        }
    Frac operator - (Frac &f){
        return(Frac(n*f.d - f.n*d, d * f.d));
    }
    Frac operator * (Frac &f){
        return(Frac(n * f.n, d * f.d));
    }
    Frac operator * (int k){
        return(Frac(n * k, d));
    }
    Frac operator / (Frac &f) {
        if(f.n == 0)throw "Division by zero";
        return(Frac(n * f.d, d * f.n));
    }
    Frac operator / (int k) {
        if(k == 0)throw "Division by zero";
        return(Frac(n, d*k));
    }
    bool operator == (Frac &f) {
        if(n == f.n && d == f.d)return true;
        return false;
    }


};

std::ostream& operator<<(std::ostream& os, const Frac& fr)
    {
        os << fr.n << '/' << fr.d;
        return os;
    }

Frac ob_wyzn(Frac &a, Frac &b, Frac &c,Frac &d){
    return(a*d - b*c);
}

int main(){
    Frac wsp[6];
    for(int i = 0; i < 4; i++){
        int a,b;
        std::cout<<"Podaj wymierny wspolczynnik nr "<<i+1<<std::endl;
        std::cin>>a>>b;
        wsp[i].eq(a,b);
        std::cout<<wsp[i]<<std::endl;
    }
    Frac wyzn  = ob_wyzn(wsp[0],wsp[1],wsp[3],wsp[4]);
    Frac wyznx = ob_wyzn(wsp[2],wsp[5],wsp[3],wsp[4]);
    Frac wyzny = ob_wyzn(wsp[0],wsp[1],wsp[2],wsp[5]);
    if(!wyzn == Frac(0,1){
        std::cout<<"x = "<<wyznx/wyzn<<std::endl;
        std::cout<<"y = "<<wyzny/wyzn<<std::endl;
    }
    else if(wyznx == 0 && wyzny == 0){
        std::cout<<"uklad nieoznaczony"<<std::endl;
    }
    else{
        std::cout<<"uklad sprzeczny"<<std::endl;
    }

return 0;
}
