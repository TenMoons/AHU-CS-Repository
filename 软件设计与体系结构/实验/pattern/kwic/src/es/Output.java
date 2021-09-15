// -*- Java -*-
/*
 *
 * 
 * <file>
 * 
 *  Name:    Output.java
 * 
 *  Purpose: Output prints sorted lines in a nice format
 * 
 *  Created: 05 Nov 
 * 
 *  $Id$
 * 
 *  Description:
 *    Output prints sorted lines in a nice format
 * </file>
*/

package es;

/*
 * $Log$
*/

/**
 *  An instance of the Output class prints sorted lines in nice format.
 *  
 *  @version $Id$
*/

public class Output{

//----------------------------------------------------------------------
/**
 * Fields
 *
 */
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * Constructors
 *
 */
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * Methods
 *
 */
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * Prints the lines at the standard output.
 * @param shift_storage sorted shifts
 */

  public void print(LineStorageWrapper shift_storage){
    for(int i = 0; i < shift_storage.getLineCount(); i++){
        // System.out.println("K  ");
         System.out.println(shift_storage.getLineAsString(i));
    }
  }
  
  public void printIndex(LineStorageWrapper shift_storage){
	    for(int i = 0; i < shift_storage.getIndexCount(); i++){
	        // System.out.println("K  ");
	         System.out.println(shift_storage.getIndexString(i));
	    }
	  }

//----------------------------------------------------------------------
/**
 * Inner classes
 *
 */
//----------------------------------------------------------------------

}
