package nt222gp_assign4.polygons;

public class EquilateralTriangle implements RegularPolygon {
	// Data members
	int sideLength;
	
	// Constructor
	public EquilateralTriangle() {}
	public EquilateralTriangle(int a) {
		sideLength = a;
	}
	
	// Methods
	// setSidelength - set the side length
	public void setSideLength(int a) {
		sideLength = a;
	}
	
	// Abstract methods
	// return the number of sides
	public int getNumSides() {
		return 3;
	}
	
	// return the side length
	public int getSideLength() {
		return sideLength;
	}
}
