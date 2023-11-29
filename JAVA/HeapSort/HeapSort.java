import java.io.*;
// Java program for implementation of Heap Sort
public class HeapSort {
    public void sort(int arr[])
    {
        int n = arr.length;
  
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
  
        for (int i=n-1; i>=0; i--)
        {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
  
            heapify(arr, i, 0);
        }
    }
  
    void heapify(int arr[], int n, int i)
    {
        int largest = i;  // Initialize largest as root
        int l = 2*i + 1;  // left = 2*i + 1
        int r = 2*i + 2;  // right = 2*i + 2
  
        if (l < n && arr[l] > arr[largest])
            largest = l;
  
        if (r < n && arr[r] > arr[largest])
            largest = r;
  
        if (largest != i)
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
  
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
/*  
    // A utility function to print array of size n 
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
*/
    // Driver program
    public static void main(String args[])
    {
        //int arr[] = {12, 11, 13, 5, 6, 7};
        //int n = arr.length;
  
        HeapSort ob = new HeapSort();
        File archivo = null;
        FileReader fr = null;
        BufferedReader br = null;
        int tam=100000;
        long rpt[];
        rpt = new long[10];
        int m=0;
        
        for(int i=tam; i<=1000000; i=i+100000){
            int array[];
            array = new int[i];
            try {
                archivo = new File ("numeros_aleatorios.txt");
                fr = new FileReader (archivo);
                br = new BufferedReader(fr);
    
                // Lectura del fichero
                String linea;
                //while((linea=br.readLine())!=null)
                //   System.out.println(linea);
  
                for (int j=0; j<i; ++j){
                    linea=br.readLine();
                    array[j]=Integer.valueOf(linea);
                    //System.out.println(array[i]);
                }
            }
            catch(Exception e){
                e.printStackTrace();
            }finally{
                try{                    
                    if( null != fr ){   
                    fr.close();     
                    }                  
                }catch (Exception e2){ 
                    e2.printStackTrace();
                }
    
            }

            long startTime = System.currentTimeMillis();
            ob.sort(array);
            //System.out.println("Sorted array is");
            //printArray(array);
            long endTime = System.currentTimeMillis();
            long total = endTime-startTime;
            System.out.println("Duracion: " + (total)/1000.0 + " ms");

            rpt[m]=total;
            m++;
        }

        try {
            PrintWriter writer = new PrintWriter("resultadosHeapSort.txt", "UTF-8");
            for(int k=0; k< rpt.length; k++){
                writer.println(String.valueOf(rpt[k]/1000.0));
            }
            
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}