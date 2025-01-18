import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


class Result {

	
	private static final int MOD = 1000000007;
	private static final int MOD_10_8 = (int)(Math.pow(10, 8)+7);
	
    public static void numberBST(List<Integer> numbers) {
    	
    	for(int i=0;i<numbers.size();i++){
    		int numNodesTmp = numbers.get(i);

    		System.out.println(Result.totalNumberBTS(numNodesTmp));
    		
    	}
    	
    }
    
    static Map<Integer, Integer> memoization = new HashMap<Integer, Integer>();
    
    /**
     * The recursive function employing memoization estrategy.
     * 
     * Lets define t(n) as total number of BST combinations for n nodes as next:
     * t(n) = sum(t(i-1)*t(n-i)) being 1<=i<=n and n=numberOfNodes 
     * 
     * The formula means that i is the root in turn of the BinarySearchTree (BST), and i has to take the value of each of the n nodes.
     * To the left of i there are t(i-1) BST combinations in which all nodes are less (equal) than i.
     * To the right of i there are t(n-i) BST combinations in which all nodes are greater (equal) than i.
     * 
     * NOTE1:
     * the nodes have to be in order, but as we ony receive the number of nodes n and we iterate over them we do it in order.
     * 
     * NOTE2:
     * the problem specifies to use modulo 10^8+7 instead of 10^9+7, its very possible its an error in the problem specification.
     * 
     * @param numNodes
     * @return
     */
    public static int totalNumberBTS(int numNodes){
    	
    	if(memoization.containsKey(numNodes)){
    		return memoization.get(numNodes);
    	}
    	if(numNodes==0){
    		return 1;
    	}
    	if(numNodes==1){
    		return 1;
    	}
    	
		long combinaciones = 0;
		for(int j=1;j<=numNodes;j++){

			//combinaciones = (combinaciones + ((long)Result.totalNumberBTS(j-1)*Result.totalNumberBTS(numNodes-j))%(Result.MOD))%(Result.MOD);
			
			//We use 10^8+7 instead of 10^9+7, its very possible its an error in the problem specification
			combinaciones = (combinaciones + ((long)Result.totalNumberBTS(j-1)*Result.totalNumberBTS(numNodes-j))%(Result.MOD_10_8))%(Result.MOD_10_8);
			
		}
		memoization.put(numNodes,(int)combinaciones);
    	return (int)combinaciones;
    	
    }
    
    
}

public class Solution {
    public static void main(String[] args) throws IOException {
        //BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader bufferedReader = new BufferedReader(new FileReader("in_bst.txt"));
        
        int numbersCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> numbers = new ArrayList<>();

        for (int i = 0; i < numbersCount; i++) {
            int numbersItem = Integer.parseInt(bufferedReader.readLine().trim());
            numbers.add(numbersItem);
        }

        Result.numberBST(numbers);

        bufferedReader.close();
    }
}