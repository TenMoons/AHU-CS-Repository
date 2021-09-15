// -*- Java -*-
/*
 * 
 * 
 * <file>
 * 
 *  Name:    LineStorageChangeEvent.java
 * 
 *  Purpose: Class representing change events in the system
 * 
 *  Created: 05 Nov 
 * 
 *  $Id$
 * 
 *  Description:
 *    Class representing change events in the system
 * </file>
*/

package es;

/*
 * $Log$
*/

/**
 *  LineStorageChangeEvent class represents a change event occuring in 
 *  a LineStorageWrapper object. Thus, whenever a LineStorageWrapper object
 *  changes its internal state an event object is created (an instance of
 *  LineStorageChangeEvent class) and sent to all observers of that 
 *  LineStorageWrapper object. This event contains all information about 
 *  the change which happened. Thus, the type of the change is described
 *  (e.g. "Add", "Delete", etc.), as well as additional parameters of the
 *  change, which are needed to describe the change completely (e.g. the
 *  deleted line is included into the "Delete" event).
 *  
*/

public class LineStorageChangeEvent{

//----------------------------------------------------------------------
/**
 * Fields
 *
 */
//----------------------------------------------------------------------

/**
 * Constant for ADD change.
 *
 */

  public static final int ADD = 0;

/**
 * Constant for DELETE change.
 *
 */

  public static final int DELETE = 1;

/**
 * Constant for INSERT change.
 *
 */

  public static final int INSERT = 2;
  
  /**
   * Constant for PRINT change
   */
  public static final int PRINT =3;
  
  /**
   * Constant for QUIT change
   */
  public static final int QUIT =4;
  
  /**
   * Constant for INDEX change
   */
  public static final int INDEX =5;
/**
 * The type of the change.
 *
 */
   private int type_;

/**
 * Argument of the change, the line that was involved in the change.
 *
 */

  private String arg_;

//----------------------------------------------------------------------
/**
 * Constructors
 *
 */
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * Creates a new event object with the specified change type.
 * @param type change type
 */

  public LineStorageChangeEvent(int type){
    type_ = type;
  }

//----------------------------------------------------------------------
/**
 * Creates a new event object with the specified change type and
 * the specified argument of the change.
 * @param type change type
 * @param arg change argument
 */

  public LineStorageChangeEvent(int type, String arg){
    type_ = type;
    arg_ = arg;
  }

//----------------------------------------------------------------------
/**
 * Methods
 *
 */
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/**
 * Sets the change type.
 * @param type change type
 * @see #getType
 */

  public void setType(int type){
    type_ = type;
  }

//----------------------------------------------------------------------
/**
 * Gets the change type.
 * @return int
 * @see #setType
 */

  public int getType(){
    return type_;
  }

//----------------------------------------------------------------------
/**
 * Sets the change argument.
 * @param arg change argument
 * @see #getArg
 */

  public void setArg(String arg){
    arg_ = arg;
  }

//----------------------------------------------------------------------
/**
 * Gets the change argument.
 * @return String
 * @see #setArg
 */

  public String getArg(){
    return arg_;
  }

//----------------------------------------------------------------------
/**
 * Inner classes
 *
 */
//----------------------------------------------------------------------

}
