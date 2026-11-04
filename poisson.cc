#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

double poisson (double mu, int k){ 
return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

int main(){

ifstream fin("sums.txt");

vector<int> counts(11);

int number;
double N=0;
double sum=0;

while (fin>>number){
counts.at(number)+=1;
sum+=number;
++N;
}
fin.close();

double mean=sum/N;

cout<<"N="<<N<<endl;
cout<<"Mean="<<mean<<endl;

for(unsigned int k=0; k<counts.size();++k){
cout<<k<<":"<<counts[k]<<endl;

}
ofstream fout("hist.txt");

for(unsigned int k=0; k<counts.size();++k){
fout<<k<<" "<<counts[k]<<endl;
}
fout.close();

ofstream foutpoi("histpoi.txt");
{
for(unsigned int k=0; k<counts.size();++k){
double prediction=N*poisson(mean,k);

foutpoi<<k<<" "<<counts[k]<<" "<<prediction<<endl;
}
}
foutpoi.close();
return 0;
}
