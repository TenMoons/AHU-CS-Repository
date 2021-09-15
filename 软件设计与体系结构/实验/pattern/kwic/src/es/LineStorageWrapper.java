// -*- Java -*-
/*
 * 
 * 
 * <file>
 * 
 *  Name:    LineStorageWrapper.java
 * 
 *  Purpose: Wraps LineStorage class providing Observable functionality to it
 * 
 *  Created: 05 Nov  
 * 
 *  $Id$
 * 
 *  Description:
 *    LineStorageWrapper class wraps LineStorage class in order to extend
 *  its functionality.
 * </file>
 */

package es;

/*
 * $Log$
 */

import java.util.Observable;

/**
 * LineStorageWrapper class wraps LineStorage class in order to extend its
 * functionality. The added functionality allows objects of the LineStorageClass
 * to be "observed" by other objects in the system. The "observation" mechanism
 * works as follows. Whenever an object of LineStorageWrapper class changes, it
 * generates and sends a message (event) to all other objects, which have
 * registered with the observed object. The LineStorageWrapper class applies the
 * "observation" mechanism from the java.util package. Thus, the class of
 * "observed" objects is a sub-class of java.util.Observable class, whereas the
 * class of "observer" objects implements java.util.Observer interface.
 * 
 * 
 * @see kwic.es.LineStorage
 */

public class LineStorageWrapper extends Observable {

	// ----------------------------------------------------------------------
	/**
	 * Fields
	 * 
	 */
	// ----------------------------------------------------------------------
	/**
	 * Wrapped line storage
	 * 
	 */

	private LineStorage lines_ = new LineStorage();

	private WordsIndex Index_ = new WordsIndex();

	// ----------------------------------------------------------------------
	/**
	 * Constructors
	 * 
	 */
	// ----------------------------------------------------------------------
	// ----------------------------------------------------------------------
	/**
	 * Methods
	 * 
	 */
	// ----------------------------------------------------------------------
	// ----------------------------------------------------------------------
	/**
	 * Adds a new line to this line storage wrapper. The line is added at the
	 * end of the storage. After adding the line all observers of this object
	 * are notified about the change.
	 * 
	 * @param words
	 *            new line to be added
	 * @see #deleteLine
	 * @see #insertLine
	 * @see #getLine
	 */

	public void addLine(String[] words) {
		lines_.addLine(words);
		
		LineStorageChangeEvent event = new LineStorageChangeEvent(
				LineStorageChangeEvent.ADD);
		setChanged();
		notifyObservers(event);
	}

	 public void addIndex(String[] words){
		 Index_.addWords(words);
	 }
	// ----------------------------------------------------------------------
	/**
	 * Inserts a new line to this line storage wrapper. The line is inserted at
	 * the specified index in the storage. After inserting the line all
	 * observers of this object are notified about the change.
	 * 
	 * @param words
	 *            new line to be added
	 * @param index
	 *            position of the new line
	 * @see #deleteLine
	 * @see #addLine
	 * @see #getLine
	 */

	public void insertLine(String[] words, int index) {
		lines_.insertLine(words, index);
		// System.out.println("II " +index);
		String line = lines_.getLineAsString(index);
		LineStorageChangeEvent event = new LineStorageChangeEvent(
				LineStorageChangeEvent.INSERT, line);
		setChanged();
		notifyObservers(event);
	}

	// ----------------------------------------------------------------------
	/**
	 * Deletes a line from this line storage wrapper. The deleted line resides
	 * at the specified index in the storage. After deleting the line all
	 * observers of this object are notified about the change.
	 * 
	 * @param index
	 *            position from where to delete the line
	 * @see #addLine
	 * @see #insertLine
	 * @see #getLine
	 */

	public void deleteLine(int index) {
		// System.out.println("SS " +index);
		String line = lines_.getLineAsString(index);
		lines_.deleteLine(index);
		LineStorageChangeEvent event = new LineStorageChangeEvent(
				LineStorageChangeEvent.DELETE, line);
		setChanged();
		notifyObservers(event);
	}

	public void deleteLines(int index, String[] words) {
		// System.out.println("SS " +index);
		String line = lines_.getLineAsString(index);
		lines_.deleteLine(index);
		//Index_.deleteWords(words);
		LineStorageChangeEvent event = new LineStorageChangeEvent(
				LineStorageChangeEvent.DELETE, line);
		setChanged();
		notifyObservers(event);
	}
    
	public void deleteWords(String[] words){
		
		Index_.deleteWords(words);
	}
	public void PrintLine() {
		// System.out.println("SS " +index);
		// String line = lines_.getLineAsString(index);
		// lines_.deleteLine(index);
		LineStorageChangeEvent event = new LineStorageChangeEvent(
				LineStorageChangeEvent.PRINT);
		setChanged();
		notifyObservers(event);
	}

	public void PrIndex() {
		LineStorageChangeEvent event = new LineStorageChangeEvent(
				LineStorageChangeEvent.INDEX);
		//Index_.addWords(words);
		setChanged();
		notifyObservers(event);
	}

	// ----------------------------------------------------------------------
	/**
	 * Gets the line from the specified index. The line is represented as String
	 * object.
	 * 
	 * @param index
	 *            position from where to get the line
	 * @return String
	 * @see #addLine
	 * @see #insertLine
	 * @see #deleteLine
	 */

	public String getLineAsString(int index) {
		// System.out.println("KK " +index);
		return lines_.getLineAsString(index);
	}

	// ----------------------------------------------------------------------
	/**
	 * get the line number accord to the String. Two dimensional array is the
	 * argument for the new line
	 * 
	 * @param words
	 *            new line
	 * @see #addEmptyLine
	 * @see #setLine
	 * @see #getLine
	 * @see #deleteLine
	 */
	public int getLineNumByString(String strInput) {
		String strOld = new String();
		for (int i = 0; i < lines_.getLineCount(); i++) {
			strOld = getLineAsString(i);
			if (strInput.equals(strOld)) {
				return i;
			}
		}
		return -1;
	}

	public void deletLinebyArray(String[] strInput) {
	
		lines_.deletLinebyArray(strInput);
	}

	// ----------------------------------------------------------------------
	/**
	 * Gets the line from the specified index.
	 * 
	 * @param index
	 *            position from where to get the line
	 * @return String[]
	 * @see #addLine
	 * @see #insertLine
	 * @see #deleteLine
	 */

	public String[] getLine(int index) {
		return lines_.getLine(index);
	}

	// ----------------------------------------------------------------------
	/**
	 * Gets the number of lines.
	 * 
	 * @return int
	 */

	public int getLineCount() {
		return lines_.getLineCount();
	}
    
//	 ----------------------------------------------------------------------
	/**
	 * Gets the number of Index_.
	 * 
	 * @return int
	 */
	public int getIndexCount(){
		return Index_.getIndexCount();
	}
	   public String getIndexString(int i){
		return Index_.getIndexString(i);
	}
	// ----------------------------------------------------------------------
	/**
	 * Inner classes
	 * 
	 */
	// ----------------------------------------------------------------------
}
