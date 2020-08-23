package nt222gp_assign2;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;
import java.text.DecimalFormat;



public class Pizza {
	// Data members
	private String size;
	private int numCheese;
	private int numPepp;
	private int numHam;
	
	// Constructor
	public Pizza(String s, int c, int p, int h) {
		size = s;
		numCheese = c;
		numPepp = p;
		numHam = h;
	}
	public Pizza() { }
	
	// Member method
	
	// Size
	// setSize - set the size data  
	public void setSize(String newSize) {
		size = newSize;
	}
	// getSize - get the size data
	public String getSize() {
		return size;
	}
	
	// Number of cheese
	// setNumCheese - set the # of cheese
	public void setNumCheese(int newCheese) {
		numCheese = newCheese;
	}
	// getNumCheese - get the # of cheese
	public int getNumCheese() {
		return numCheese;
	}
	
	// Number of pepparoni
	// setNumPepparoni - set the # of pepparoni
	public void setNumPepparoni(int newPepp) {
		numPepp = newPepp;
	}
	// getNumPepparoni - get the # of cheese
	public int getNumPepparoni() {
		return numPepp;
	}
	
	// Number of ham
	// setNumHam - set the # of ham
	public void setNumHam(int newHam) {
		numHam = newHam;
	}
	// getNumHam - get the # of ham
	public int getNumHam() {
		return numHam;
	}
	
	// calcCost - calculates the total cost of the pizza
	public double calcCost() {
		// define the decimal form
		DecimalFormat df2 = new DecimalFormat("#.##");
		
		// create a variable for the total cost
		// type: double to be able to have decimals "#.##"
		double totCost = 0;
		
		// totTopp is # of toppings
		int totTopp;
		totTopp = numCheese + numPepp + numHam;
		
		// if-statement -
		if (size.equals("small") || size.equals("Small")) {
			// if the size is small then the cost is 10kr + cost for the toppings
			totCost += 10 + totTopp*3;
		}
		else if (size.equals("medium") || size.equals("Medium") ) {
			// if the size is medium then the cost is 15kr + cost for the toppings
			totCost += 15 + totTopp*2.5;
		}
		else {
			// if the size is large then the cost is 20kr + cost for the toppings
			totCost += 20 + totTopp*2;
		}
		
		return totCost;
	}
	
	// getDescription - return which topping the user has chosen
	// it will return the description of the chosen pizza.
	// The if-statement uses to get the chosen topping
	public String getDescription() {
		String topping;
		
		if (numPepp != 0) {
			topping = "pepparoni";
		}
		else if (numCheese != 0) {
			topping = "cheese";
		}
		else if (numHam != 0) {
			topping = "ham";
		}
		else {
			topping = "no";
		}
		String descString= "You ordered a " + size + " pizza with " + topping + " toppings. Your bill is " + calcCost() + " kr.";
		return  descString;
	}
}
