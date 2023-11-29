import java.io.*;
// Java implementation of SelectionSort
class SelectionSort
{
    void sort(int arr[])
    {
        int n = arr.length;
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
 
            // Swap the found minimum element with the first element
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
/* 
    // Prints the array
    void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
*/ 
    // Driver code to test above
    public static void main(String args[])
    {
        //int arr[] = {64,25,12,22,11};
        SelectionSort ob = new SelectionSort();
        
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
            //System.out.println("Sorted array");
            //ob.printArray(array);
            long endTime = System.currentTimeMillis();
            long total = endTime-startTime;
            System.out.println("Duracion: " + (total)/1000.0 + " ms");
            
            rpt[m]=total;
            m++;
        }

        try {
            PrintWriter writer = new PrintWriter("resultadosSelectionSort.txt", "UTF-8");
            for(int k=0; k< rpt.length; k++){
                writer.println(String.valueOf(rpt[k]/1000.0));
            }
            
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}

