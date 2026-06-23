#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

struct alunotas {
    int codigo;
    int notas[10];
};

bool compara(int a,int b) {
    return a>b;
}

int main() {
    int notas[]={11,5,14,20,16};
    int n=sizeof(notas)/sizeof(notas[0]);
    vector<int> vnotas;
    cout << vnotas.size() << endl;

    vnotas.insert(vnotas.begin(),notas,notas+n);
    vnotas.push_back(20);
    cout << vnotas.size() << endl;
    vnotas.erase(vnotas.begin()+1);
    sort(vnotas.begin(),vnotas.end(),compara);
    for (int i = 0; i < vnotas.size(); i++)
        cout << vnotas[i] << " ";
    ///////////////////////////////////////////////
    list<int>lnotas;
    for (int i=0;i<n;i++)
        lnotas.push_back(notas[i]);
    cout <<endl<<"Ahora imprimo mi lista"<<endl;
    for (list<int>::iterator it=lnotas.begin();
        it!=lnotas.end(); it++)
        cout << *it <<" ";
    //////////////////////////////////////////
    alunotas registro[] {{20221918,{9,19,8,10,2}},
     {20240929,{12,13,9,10,3}},
     {20230817,{4,5,12,13,18}}
    };
    int m=sizeof(registro)/sizeof(registro[0]);
    map<int,double>mnotas;
    for (int i=0;i<m;i++) {
        double prom;
        int sum=0;
        for (int j=0;j<5;j++)
            sum+=registro[i].notas[j];
        prom=sum/5;
        mnotas[registro[i].codigo]=prom;
    }
    cout <<endl;
    for (map<int,double>::iterator it=mnotas.begin();
        it!=mnotas.end(); it++)
        cout << it->first <<" "<<it->second<<endl;

        map<int,vector<int>>mvnotas;
        for (int i=0;i<m;i++) {
            vnotas.clear();
            vnotas.insert(vnotas.begin(),registro[i].notas,registro[i].notas+5);
            mvnotas[registro[i].codigo]=vnotas;
        }
    cout <<endl;
    for (map<int,vector<int>>::iterator it=mvnotas.begin();
        it!=mvnotas.end(); it++) {
        cout << it->first<<": ";
        for (int j=0;j<it->second.size();j++)
            cout << it->second[j]<<" ";
        cout <<endl;
    }


    return 0;
}
