package bookProject;

import java.util.Scanner;
import java.util.Arrays;

public class bookP1 {
    
    public static void main(String[] args) {
    String [] words = {"one","two","tree"};
    int k=2;
    loops(k,3, words,0);
    }
    
    public static void loops(int n,int m, String [] words1,int p){
    	if( p <= m ){
    		 System.out.printf(" %s " , words1[p]);
    		 
    		 
    	}
    	else{
    		return;
    	}
    }
}


