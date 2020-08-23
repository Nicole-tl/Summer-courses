package nt222gp_assign3;
import java.util.Random;

public class Dices {
	public static void main(String[] args) {
	    Random rand = new Random(); //instance of random class
		
	    // Create a list to save count of each dice value 2-12
	    int[] diceCount = new int[11];
		
	    // Create two variables for dice 1 and 2
	    int d1;
	    int d2;
	    
		// for loop to run 10 000 times
		for (int i = 0; i <= 10000-1; i++) {
			d1 = rand.nextInt(6)+1; // random number from 1 to 6
			d2 = rand.nextInt(6)+1;
			
			// save the count of the sum of dice 1 and dice 2 to diceCount
			diceCount[(d1+d2)-2] += 1 ;
		}
		
		// Print the required output
		System.out.println("Frequency table (sum, count) for rolling two dices 10000 times is: ");
		// Print the dice value and its count
		for (int j = 0; j <= 11-1; j++) {
			System.out.println((j+2) + "                 " + diceCount[j]);
		}
				
	}

}
