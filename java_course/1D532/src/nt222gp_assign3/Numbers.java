package nt222gp_assign3;
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Numbers {
	public static void main(String[] args) {
		// Read the text file
		// name of the file to be read shall be in this project folder
		// and it can be find with "subfolder/sub subfolder.../fileName.txt" as shown below
		String fileName="src/nt222gp_assign3/numbers.txt"; 
        Scanner in = null;
        
        // When scanning the file, it need a try-catch with exceptions
        // in case the file could not be found.
        try {
                in = new Scanner(new FileInputStream(fileName));
        } catch (FileNotFoundException e) {
        	System.out.println("File "+fileName+" was not found"); System.out.println("or could not be opened."); System.exit(0);
        }

        
        // Find how many numbers this text file has. 
        int i = 0;	// count of line/numbers
        // while loop uses hasNext() to return true if it has one more line after this.
        // when it does not have more lines it will return false and stop iterating.
        while (in.hasNext()) {
    		in.nextLine();
        	i++;        	
        }
        in.close();	// close scanning.

        // create a number array (type: Int) with array length as # of number in the file
        int numArr[] = new int[i];

		// Read the text file again
        in = null;
        try {
                in = new Scanner(new FileInputStream(fileName));
        } catch (FileNotFoundException e) {
        	System.out.println("File "+fileName+" was not found"); System.out.println("or could not be opened."); 
        	System.exit(0);
        }
        
        // Store all the data to the array numArr
        for (int j = 0; j<=i-1; j++) {
        	numArr[j] = in.nextInt();
        }
        
        // Calculate the average - add all together to average and then divide it by # of elements
        double average = 0;
        for (int j = 0; j<=i-1; j++) {
        	average += numArr[j];
        }
        average /= i;
        
        // Calculate the std - sqrt(((n1-a)^2+(n2-a)^2+(n3-a)^2...)/#of elements)
        double std = 0;
        for (int j = 0; j<= i-1; j++) {
        	std += Math.pow(numArr[j]-average,2);
        }
        std /= i;
        std = Math.sqrt(std);
        
        System.out.println(average);
        System.out.println(std);
        
        
        // Save to a text-file
        // Open/create the text-file to start writing
        PrintWriter writer = null; 
        FileOutputStream fileOS; 
        try {
        	fileOS = new FileOutputStream("src/nt222gp_assign3/analysis.txt");
        	writer = new PrintWriter(fileOS);
        } catch (FileNotFoundException e) {
        	System.out.println("Error opening the file analysis.txt."); 
        	System.exit(0);
        }
        // Write in the text-file
        writer.println("Average: " + average);
        writer.println("Standard Deviation: " + std);
        writer.close();   
	}
}
