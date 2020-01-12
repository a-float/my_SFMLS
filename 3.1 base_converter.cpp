#include<iostream>
#include<string>

char znaki[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void reverse(std::string str){
   for(int i=str.length()-1; i>=0; i--)
      std::cout << str[i];
}

std::string base_convert(int a, int b){
   std::string res = "";
   while(a != 0){
      res += znaki[a%b];
      a/=b;
   }
   return(res);
}

int main(){
   int base;
   std::cout<<"Input base 2-16: ";
   std:: cin>>base;
   if(base > 16 || base < 2){
      std::cout<<"wrong base";
      return 0;
   }
   int number;
   std::cin>>number;
   reverse(base_convert(number,base));
   return 0;
}
