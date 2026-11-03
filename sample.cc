#include <iostream>
#include<fstream>
#include <cmath>

using namespace std;

int main(){
ifstream fin("sums.txt");

double a;
double sum=0;
int n = 0;

while (fin >> a) {
  sum += a;
  ++n;
}
fin.close();

double mean=sum/n;
cout<<mean<<endl;

ifstream fin2("sums.txt");
double var=0;
while (fin2>>a){

 var+=(a-mean)*(a-mean);
}
fin2.close();

double variance=var/n;

cout<<variance<<endl;

double sigma=sqrt(variance);
cout<<sigma<<endl;

return 0;
}
