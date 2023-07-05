#include <iostream>
#include <vector>

using namespace std;
void print(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
void merge(vector<int>& arr, int left, int middle, int right) {//CORE DUMPED ???
  int n1 = middle - left + 1;
  int n2 = right - middle;
  vector<int> L(n1);
  vector<int> R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[middle + 1 + j];
  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
int kMinor(vector<int> V,int a){
  if(a<1 || a>V.size()){
    return 0;
  }
  vector<int> V_(V.size());
  for(auto i=0;i<V.size();i++){
    V_[i]=V[i];
  }
  mergeSort(V_, 0,V_.size()-1);
  cout<<"Menor valor número "<<a<<" es: "<<V_[a-1];
  return V_[a-1];
}
// Función para imprimir el vector

int main() {
    vector<int> V={4,2,6,7,3,1,8};
    print(V);
    kMinor(V,5);
    return 0;
}