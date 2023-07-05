#include <bits/stdc++.h>

using namespace std;
bool SortByPeso(float a,float b) {
    return (a < b);
}


float mochila_buque(int M, int N, vector<float> p){
  bool (*funcion[1]) (float,float)={SortByPeso};
  vector<float> ListValues;
  for(int i=0;i<N;i++){
    ListValues.push_back(p[i]);
  }    
  sort(ListValues.begin(),ListValues.end(),funcion[0]);
  float pesSum=0;
  float valSum=0;
  for(int i=0;i<N;i++){
    if(pesSum<M){
      if(pesSum+ListValues[i]<=M){
        pesSum+=ListValues[i];
        valSum+=ListValues[i];
      }else{
        break;
      }
    }
    else if(pesSum==M){
      break;
    }else{
      cout<<"\nERROR CRÍTICO\n";
      return 0;
    }
  }
  /*cout<<endl;*/
  return valSum;
}
int main() {
  int T = 20; //TONELADAS
  vector<float>  p={18,15,12,23,4,534,10};  
  int n = p.size();
  if (T==0 || n==0)
        return 0;
  float x=mochila_buque(T,n,p);
  cout<<"PESOS POR ELEMENTO: "<<endl;
  for(int i=0;i<n;i++){
    if(i==n-1){
      cout<<p[i];
      break;
    }
    cout<<p[i]<<", ";
  }
  cout<<endl;
  cout << "El peso máximo posible calculado a cargar por el buque con máxima capacidad de "<<T<<" toneladas es: "<<x<<endl;
  return 0;
} //WRONG ANSWER