/**
 * NestedForLoopDemo.java
 * Author: Nadeem Abbas
 */

package dv532.step1;
/*
 * A program that demonstrates nested for loop
 */
class NestedForLoopDemo {
   public static void main(String[] args) {
      
      int rows = 5;
      
      for(int i = 1; i <= rows; ++i)
      {
          for(int j = 1; j <= i; ++j)
          {
             System.out.print(j + " ");
          }
          System.out.println("");
      }
   }
}