package nt222gp_assign4.polygons;

public class Square implements RegularPolygon {
	// Data members
		int sideLength;
		
		// Constructor
		public Square() {}
		public Square(int a) {
			sideLength = a;
		}
		
		// Methods
		// setSidelength
		public void setSideLength(int a) {
			sideLength = a;
		}
		
		// Abstract methods
		// return the number of sides
		public int getNumSides() {
			return 4;
		}
		
		// return the sidelength
		public int getSideLength() {
			return sideLength;
		}
}
