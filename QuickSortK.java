public class QuickSortK{
        public static void main(String arg[]){
                int[] arr ={23,4,6,7,6,88};
                quicksort(arr,0,arr.length-1);
        }
        public static void quicksort(int arr[],int low ,int hi){
                if(low>hi){
                        return;
                }
                int s = low;
                int e = hi;
                int pivot = s+(e-s)/2;

                while(s<e){
                        while(s<pivot){
                                s++;
                        }
                        while(e>pivot){
                                e--;
                        }
                        if(s<=e){
                                int temp = arr[s];
                                arr[s]=arr[e];
                                arr[e]=temp;
                                s++;
                                e--;
                        }
                }
                quicksort(arr,low,e);
                quicksort(arr,s,hi);
}
}