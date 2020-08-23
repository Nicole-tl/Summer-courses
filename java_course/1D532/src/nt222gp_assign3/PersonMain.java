package nt222gp_assign3;

public class PersonMain {
	// Main method to call and create the objects
	public static void main(String[] args) {
		// Create objects from classes and subclasses.
		// Person
		System.out.println("Person: \n");
		Person p1 = new Person("Mikaela Solrosson", 
								"Rosgatan 3, Ostron 342 12", 
								"0762447289", 
								"Mikaela.S@gmail.com");
		System.out.print(p1 + "\n\n");
		
		// Employee
		System.out.println("Employee: \n");
		Person e1 = new Employee("Mikaela Solrosson", 
				"Rosgatan 3, Ostron 342 12", 
				"0762447289", 
				"Mikaela.S@gmail.com",
				"50 000",
				"19.02.10");
		System.out.print(e1 + "\n\n");
		
		// Student
		System.out.println("Student: \n");
		Person s1 = new Student("Mikaela Solrosson", 
				"Rosgatan 3, Ostron 342 12", 
				"0762447289", 
				"Mikaela.S@gmail.com",
				"Mechanical Engineering");
		System.out.print(s1 + "\n\n");
		
		// Faculty
		System.out.println("Faculty: \n");
		Person f1 = new Faculty("Mikaela Solrosson", 
				"Rosgatan 3, Ostron 342 12", 
				"0762447289", 
				"Mikaela.S@gmail.com",
				"50 000",
				"19.02.10",
				"8h",
				"1");
		System.out.print(f1 + "\n\n");
		
		
		// Staff
		System.out.println("Staff: \n");
		Person st1 = new Staff("Mikaela Solrosson", 
				"Rosgatan 3, Ostron 342 12", 
				"0762447289", 
				"Mikaela.S@gmail.com",
				"50 000",
				"19.02.10",
				"CEO");
		System.out.print(st1 + "\n\n");
	}

}
