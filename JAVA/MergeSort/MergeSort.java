import java.io.*;
/* Java program for Merge Sort */
class MergeSort 
{
    void merge(int arr[], int l, int m, int r)
    {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;
  
        /* Create temp arrays */
        int L[] = new int[n1];
        int R[] = new int[n2];
  
        /*Copy data to temp arrays*/
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];
  
        /* Merge the temp arrays */
  
        // Initial indexes of first and second subarrays
        int i = 0, j = 0;
  
        // Initial index of merged subarray array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
  
        /* Copy remaining elements of L[] if any */
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
  
        /* Copy remaining elements of R[] if any */
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
  
    // Main function that sorts arr[l..r] using
    // merge()
    void sort(int arr[], int l, int r)
    {
        if (l < r) {
            // Find the middle point
            int m =l+ (r-l)/2;
  
            // Sort first and second halves
            sort(arr, l, m);
            sort(arr, m + 1, r);
  
            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }
/*  
    // A utility function to print array of size n 
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
*/  
    // Driver code
    public static void main(String args[])
    {
        //int arr[] = { 12, 11, 13, 5, 6, 7 };
        MergeSort ob = new MergeSort();
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
            ob.sort(array, 0, array.length - 1);
            //System.out.println("\nSorted array");
            //printArray(array);
            long endTime = System.currentTimeMillis();
            long total = endTime-startTime;
            System.out.println("Duracion: " + (total)/1000.0 + " ms");

            rpt[m]=total;
            m++;
        }

        try {
            PrintWriter writer = new PrintWriter("resultadosMergeSort.txt", "UTF-8");
            for(int k=0; k< rpt.length; k++){
                writer.println(String.valueOf(rpt[k]/1000.0));
            }
            
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
