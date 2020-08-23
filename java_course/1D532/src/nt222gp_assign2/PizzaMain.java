package nt222gp_assign2;

import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class PizzaMain {
	// the main string
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String addSize, addTopp;
		int numTopp = 0;
		Pizza newOrder = new Pizza();
		
		// Find today's date and convert it to int with the format
		// Sun Jun 23 17:26:55 CEST 2019
		ZonedDateTime today = ZonedDateTime.now(); // ZonedDataTime to includes zoneID 
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("EEE LLL dd kk:mm:ss z yyyy");
        String dateTodayString = today.format(formatter);
		System.out.println(dateTodayString + "\n\n");
        
		
		
		System.out.println("Wellcome to pizzeria LNU! \n\n");
		
		// ask for the size
		System.out.println("Please enter size of your pizza [small, medium, or large]: ");
		addSize = in.next();
		newOrder.setSize(addSize.toLowerCase());
		
		// ask for the topping
		System.out.println("Please enter type of topping [cheese, pepperoni, ham, none]: ");
		addTopp = in.next();
		
		// if the user did chose a topping, ask for the #
		if (!addTopp.toLowerCase().equals("none")) {
			System.out.println("Please enter number of toppings you want: ");
			numTopp = in.nextInt();	
			
			// set the # to the data
			if (addTopp.toLowerCase().equals("cheese")) {
				newOrder.setNumCheese(numTopp);
			}
			else if (addTopp.toLowerCase().equals("pepparoni")) {
				newOrder.setNumPepparoni(numTopp);
			}
			else if (addTopp.toLowerCase().equals("ham")) {
				newOrder.setNumHam(numTopp);
			}
		}
		
		// return string and description and cost
		System.out.println("Thank you, " + newOrder.getDescription() + "\n");
		System.out.println("Enjoy your food!");


	}

}
