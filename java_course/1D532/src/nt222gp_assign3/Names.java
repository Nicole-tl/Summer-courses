package nt222gp_assign3;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Names {
	public static void main(String[] args) {
		String boys[] = new String[1000];
		String girls[] = new String[1000];
		
		String file_b="src/nt222gp_assign3/boynames.txt"; //name of the file for reading
		String file_g="src/nt222gp_assign3/girlnames.txt"; //name of the file for reading
		Scanner in_b = null;
        Scanner in_g = null;

        // Open the text files
        try {
            in_b = new Scanner(new FileInputStream(file_b));
        } catch (FileNotFoundException e) {
        	System.out.println("File "+file_b+" was not found"); System.out.println("or could not be opened."); System.exit(0);
        }	
        try {
            in_g = new Scanner(new FileInputStream(file_g));
        } catch (FileNotFoundException e) {
        	System.out.println("File "+file_g+" was not found"); System.out.println("or could not be opened."); System.exit(0);
        }	
        
        // Save all the elements to two arrays (one for boys and one for girls)
        int i = 0;
        while (in_b.hasNext() && in_g.hasNext()){
        	boys[i] = in_b.nextLine();
        	girls[i] = in_g.nextLine();
        	i++;
        }
        
        // Input name string - ask for a name
		Scanner in = new Scanner(System.in);
		System.out.print("Please enter a name: ");
		String searchName = in.next();
		
		boolean b=false, g=false; // initial boolean for if found.
		
		// Search if the searched  name is in the arrays
		for (int j = 0; j <= i-1; j++) {
			// Compare to boy name
			// Get the ith name from the list (without the rank#)
			int ind = boys[j].indexOf(" ");
			String boysN = boys[j].substring(0,ind);
			// Check if it is are equal to the searched name
			if (searchName.equals(boysN)) {
				String amount = boys[j].substring(ind);
				System.out.println(searchName + " is ranked " + j + " in popularity among boys with" + amount + " namings.");
				b = true;
			}
			 
			// Compare to girl name - same method as for the boys
			int ind_g = girls[j].indexOf(" ");
			String girlsN = girls[j].substring(0,ind_g);
			if (searchName.equals(girlsN)) {
				String amount = girls[j].substring(ind_g);
				System.out.println(searchName + " is ranked " + j + " in popularity among girls with" + amount + " namings.");
				g = true;
			}
		}
		
		//
		if (!b) {
			System.out.println(searchName + " is not ranked among the top 1000 boys names.");
		}
		if (!g) {
			System.out.println(searchName + " is not ranked among the top 1000 girls names.");
		}
    }	
}
