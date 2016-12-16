import java.util.*;
import java.lang.*;

class Main
{
	public static void mergeArrays(int[] left, int[] right, int[] input){
		int i = 0, j = 0, k = 0;
		while(i < left.length && j < right.length){
			if(left[i]>right[j]){
				input[k] = right[j];
				j++;
			}
			else{
				input[k] = left[i];
				i++;
			}
			k++;
		}
		if(i > left.length-1){	
			while(j<=right.length-1){
				input[k]=right[j];
				j++;
				k++;
			}
		}
		else if(j > right.length-1){	
			while(i<=left.length-1){
				input[k]=left[i];
				i++;
				k++;
			}
		}
	}
	public static void mergeSort(int[] input){
		if(input.length<2)
			return;
		int mid = input.length/2;
		int[] left = new int[mid];
		int[] right = new int[input.length-mid];
		for(int i = 0; i<=mid-1; i++){
			left[i] = input[i];
		}
		for(int i = mid; i<=input.length-1; i++){
			right[i-mid] = input[i];
		}
		mergeSort(left);
		mergeSort(right);
		mergeArrays(left, right, input);

	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t > 0){
			
			int numOfParticipants = s.nextInt();
			long sum = 0;
			
			int[] men = new int[numOfParticipants];
			int[] women = new int[numOfParticipants];
			for(int i = 0; i < numOfParticipants; i++){
				men[i] = s.nextInt();
			}
			
			for(int i = 0; i < numOfParticipants; i++){
				women[i] = s.nextInt();
			}
			mergeSort(men);
			mergeSort(women);
			for(int i = 0; i < numOfParticipants; i++){
				sum = sum+(men[i]*women[i]);
			}
			
			System.out.println(sum);
			t--;
		}
	}
}