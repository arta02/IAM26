#include <iostream>
#include <fstream>

using namespace std;

int main() {

ifstream fin("data.txt");
ofstream fout("sums.txt");

int a, b;

for (int i=0;i<234;i++){
fin>>a>>b;

fout<<a+b<<endl;
}
fin.close();
fout.close();

return 0;
}

