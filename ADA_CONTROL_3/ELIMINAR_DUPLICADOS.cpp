//DADO UN VECTOR CON ELEMENTOS DUPLICADOS, DISEÑE UN ALGORITMO O(N LOGN) QUE PERMITA ELIMINAR TODOS LOS ELEMENTOS DUPLICADOS V= 4 2 4 6 8 7 3 2 1 8
#include <bits/stdc++.h>
using namespace std;
void lock_dups(vector<int>& V){
  /*map<int,int> a;
  for(int i=0;i<V.size();i++){
    a[V[i]]++;
  }*/
  map<int,int> counter;
  for(int i=0;i<V.size();i++){
    counter[V[i]]++;
    if(counter[V[i]]>1){
      auto it=V.begin()+i;
      auto it2=V.begin()+i+1;
      V.erase(it,it2);
      counter[V[i]]--;
    }
  }
}
void print(vector<int> V){
  cout<<"Vector = {";
  for(auto a:V)
    cout<<a<<" ";
  cout<<"}\n";
}
void redux(){};
int main() {
  vector<int> V={4,2,4,6,8,7,3,2,1,8};
  print(V);
  cout<<"BORRAMOS DUPLICADOS\n";
  lock_dups(V);
  print(V);
  
}