import java.io.*;
// Java program for implementation of Bubble Sort

class BubbleSort
{
    void bubbleSort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                {
                    // swap arr[j+1] and arr[j]
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }
/* 
    // Prints the array 
    void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
*/ 
    // Driver method to test above
    public static void main(String [] arg) {
        BubbleSort ob = new BubbleSort();
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
            ob.bubbleSort(array);
            //System.out.println("Sorted array");
            //ob.printArray(array);
            long endTime = System.currentTimeMillis();
            long total = endTime-startTime;
            System.out.println("Duracion: " + (total)/1000.0 + " ms");

            rpt[m]=total;
            m++;
        }

        try {
            PrintWriter writer = new PrintWriter("resultadosBubbleSort.txt", "UTF-8");
            for(int k=0; k< rpt.length; k++){
                writer.println(String.valueOf(rpt[k]/1000.0));
            }
            
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
   }
}