import java.io.*;
  
// Java program for implementation of QuickSort
class QuickSort
{
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high]; 
        int i = (low-1); // index of smaller element
        for (int j=low; j<high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
  
        // swap arr[i+1] and arr[high] (or pivot)
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
  
        return i+1;
    }
  
    void sort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);

            sort(arr, low, pi-1);
            sort(arr, pi+1, high);
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
        //int arr[] = {10, 7, 8, 9, 1, 5};
        QuickSort ob = new QuickSort();

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
            ob.sort(array, 0, array.length-1);
            //System.out.println("sorted array");
            //printArray(array);
            long endTime = System.currentTimeMillis();
            long total = endTime-startTime;
            System.out.println("Duracion: " + (total)/1000.0 + " ms");
            
            //int aux = (int) total;
            rpt[m]=total;
            m++;
        }

        try {
            PrintWriter writer = new PrintWriter("resultadosQuickSort.txt", "UTF-8");
            for(int k=0; k< rpt.length; k++){
                writer.println(String.valueOf(rpt[k]/1000.0));
            }
            
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}