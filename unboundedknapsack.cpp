#include<iostream>
using namespace std;

void instancesUsed(int items[],int weights[],int capacity,int size) {
   int k = capacity;
   int instances[size];
   int i;
   for(i=0;i<size;i++)
      instances[i] = 0;

   while(k >= 0) {
      int x = items[k];
      if(x == -1) break;
      instances[x] += 1;
      k -= weights[items[k]];
   }
   cout<<"\nBarang yang diambil : \n";
   for(i=0;i<size;i++)
      cout << "Barang dengan berat " << weights[i] << " diambil " << instances[i] << endl;
}

int findMaxValue(int weight[],int values[],int items[],int n,int capacity) {

   int knapsack[capacity+1];
   knapsack[0] = 0;
   items[0] = -1;
   int i,j;

   for(j=1;j<=capacity;j++) {
      items[j] = items[j-1];

      int max = knapsack[j-1];
      for(i=0;i<n;i++) {
         int x = j-weight[i];
         if(x >= 0 && (knapsack[x] + values[i]) > max) {
            max = knapsack[x] + values[i];
            items[j] = i;
         }

         knapsack[j] = max;

      }
   }
   return knapsack[capacity];
}

// main
int main() {

   int weight[10];      //Harus sama dengan values
   int values[10];      //Harus sama dengan weight
   int bnyk_barang;
   int capacity = 100; // kapasitas knapsack
   int size = sizeof(weight)/sizeof(weight[0]);


   //Opsional untuk menentukan banyak barang
   //Banyak barang harus sama dengan array-nya

   cout << "Masukkan berapa banyaknya barang : ";
   cin >> bnyk_barang;

   //Eror Handle
   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        if(bnyk_barang > size){
        cout << endl << "Jenis barang terlalu banyak" << endl;
        return 0;
        }

        if(bnyk_barang < size){
        cout << endl << "Jenis barang terlalu sedikit" << endl;
        return 0;
        }

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   cout << endl << "Masukkan berat barang dan harganya" << endl;

   for(int i=0; i < bnyk_barang; i++){
        cout << "Berat barang ke " << i + 1 << " = "; cin >> weight[i];
        cout << "Harganya = "; cin >> values[i];
        cout << endl;
   }


   cout << size;

   int items[capacity+1];
   int val = findMaxValue(weight,values,items,size,capacity);
   cout << endl << "Harga maksimum yang diperoleh : " << val << endl;
   instancesUsed(items,weight,capacity,size);
   cout << endl;
   return 0;
}
