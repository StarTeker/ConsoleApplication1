#include <windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
 
void choicesSort(int*, int); 
void insertionSort(int*, int);
void bubbleSort(int*, int);
void ShellSort(int *, int);
void Sort (int *,int);
void prostavubirka(int *,int );
int main(int argc, char* argv[])
{	setlocale(LC_ALL,"Russian");
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    cout << "array_size ? : ";
    int size_array; 
    cin >> size_array;
 
    int *sorted_array = new int [size_array]; 
    for (int counter = 0; counter < size_array; counter++)
    {
        sorted_array[counter] = rand() % 100; 
        cout << setw(2) << sorted_array[counter] << "  "; 
    }
    cout << "\n\n";
 
    //choicesSort(sorted_array, size_array); 
    //insertionSort(sorted_array,size_array);
    //bubbleSort(sorted_array,size_array);
    //ShellSort(sorted_array,size_array);
   //Sort(sorted_array,size_array);
     prostavubirka(sorted_array,size_array);
    for (int counter = 0; counter < size_array; counter++)
    {
        cout <<sorted_array[counter] << "  "; 
    }
    cout << "\n";
    delete [] sorted_array; 
    system("pause");
    return 0;
}
 
void choicesSort(int* arrayPtr, int length_array) 
{
    for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
    {
        int temp = arrayPtr[0]; 
        for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
        {
            if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
            {
                temp = arrayPtr[repeat_counter];
                arrayPtr[repeat_counter] = arrayPtr[element_counter];
                arrayPtr[element_counter] = temp;
            }
        }
    }
}

void insertionSort(int *arrayPtr, int length) 
{
    int temp, 
        item; 
    for (int counter = 1; counter < length; counter++)
    {
        temp = arrayPtr[counter]; 
        item = counter-1; 
        while(item >= 0 && arrayPtr[item] > temp) 
        {
            arrayPtr[item + 1] = arrayPtr[item]; 
            arrayPtr[item] = temp;
            item--;
        }
    }
}


void bubbleSort(int* arrayPtr, int length_array) 
{
 int temp = 0; 
 bool exit = false; 
 
 while (!exit) 
 {
  exit = true;
  for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) 
    
   
    if (arrayPtr[int_counter] > arrayPtr[int_counter + 1]) 
    {
     
     temp = arrayPtr[int_counter];
     arrayPtr[int_counter] = arrayPtr[int_counter + 1];
     arrayPtr[int_counter + 1] = temp;
     exit = false; 
    }
  }
}
 
 
 void ShellSort(int *arrayPtr, int length_array)
{
    int i, j, step;
    int tmp;
    for (step = length_array / 2; step > 0; step /= 2)
        for (i = step; i < length_array; i++)
        {
            tmp = arrayPtr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arrayPtr[j - step])
                    arrayPtr[j] = arrayPtr[j - step];
                else
                    break;
            }
            arrayPtr[j] = tmp;
        }
}
спавпав

void Sort (int *a,int N)
{
	int i, j, k, t;
	for ( i=1; i<N; i++ )  
	{
		
		t = a[i];  
		j = i-1;  
		
		while ((j >= 0) && (a[j]>t))
			a[j+1] = a[j--];  
			
		a[j+1] = t;  
	};
}

void Swap(int & a, int & b)
{
	int tmp = a; a = b; b = tmp;
}

void prostavubirka(int *a,int N)
{
	int i, j, m;
	for (i=0; i<N-1; i++)			
	{
		m = i;
		for (j=i+1; j<N; j++)		
        if ( a[j] < a[m] )
				m = j;
				if ( !(i == m) )
			Swap(a[i], a[m]);
	}
}




