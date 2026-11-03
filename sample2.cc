#include <iostream>
#include<fstream>
#include <cmath>

using namespace std;

int main(){
ifstream fin("sums.txt");
ifstream fin2("sums.txt");

ofstream fout1("means.txt");
ofstream fout2("variances.txt");

double a;
double sumeans=0;
double sumvar=0;
double sumcvar=0;

for (int j=0;j<26;j++){
double sum=0;
int n=0;

while (n <9&&fin>>a) {
  sum += a;
  ++n;
}

double mean=sum/n;
fout1<<mean<<endl;
sumeans+=mean;

double var=0;
int m=0;
while (m<9&&fin2>>a){

 var+=(a-mean)*(a-mean);
++m;
}

double variance=var/m;
fout2<<variance<<endl;
sumvar+=variance;
double cvar=var/(m-1);
sumcvar+=cvar;
}
double meanofmeans=sumeans/26;
double meanofvar=sumvar/26;
double meanofcvar=sumcvar/26;

cout<<"Mean of means: "<<meanofmeans<<endl;
cout<<"Mean of variances: "<<meanofvar<<endl;
cout<<"Mean of corrected variances: "<<meanofcvar<<endl;

fin.close();
fin2.close();

fout1.close();
fout2.close();

ifstream finMeans("means.txt");

double groupmean;
double varmeans=0;
int count=0;

while (finMeans>>groupmean){
varmeans+=(groupmean-meanofmeans)*(groupmean-meanofmeans);
++count;
}
finMeans.close();
double Means=sqrt(varmeans/count);
cout<<"Standard deviation of means: "<<Means<<endl;
return 0;
}
