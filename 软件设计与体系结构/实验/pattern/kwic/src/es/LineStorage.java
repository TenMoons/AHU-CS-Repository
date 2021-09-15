// -*- Java -*-
/*
 * 
 * 
 * <file>
 * 
 *  Name:    LineStorage.java
 * 
 *  Purpose: LineStorage holds all input lines and provides a public interface to manipulate the lines.
 * 
 *  Created: 05 Nov 
 * 
 *  $Id$
 * 
 *  Description:
 *    
 * </file>
*/

package es;

/*
 * $Log$
*/

import java.util.ArrayList;

/**
 *  An object of the LineStorage class holds a number of lines and provides a number of public methods
 *  to manipulate the lines. A line is defined as a set of words, and a word consists of a number of
 *  characters. Methods defined by the LineStorage class allow objects of other classes to:
 *  <ul>
 *  <li>set, read and delete a character from a particular word in a particular line
 *  <li>add a new character to a particular word in a particular line
 *  <li>obtain the number of characters in a particular word in a particular line
 *  <li>set, read and delete a word from a particular line
 *  <li>add a new word to a particular line
 *  <li>add an empty word to a particular line
 *  <li>obtain words count in a particular line
 *  <li>set, read and delete a particular line
 *  <li>add a new line
 *  <li>add an empty line
 *  <li>obtain lines count
 *  </ul>
 *  
 *  @version $Id$
*/

public class LineStorage{

//----------------------------------------------------------------------
/**
 * Fields
 *
 */
//----------------------------------------------------------------------

/**
 * ArrayList holding all lines. Each line itself is represeneted as an 
 * Arraylist object holding all words from that line. The ArrayList class is a
 * standard Java Collection class, which  implements the typical buffer 
 * functionality, i.e., it keeps its objects in an array of a fix capacity. 
 * When the current capacity is exceeded, ArrayList object resizes its array 
 * automatically, and copies the elements of the old array into the new one.
 */

  private ArrayList lines_ = new ArrayList();

//----------------------------------------------------------------------
/**
 * This method sets a new character on the specified index of 
 * a particular word in a particular line.
 * @param c new character
 * @param position character index in the word
 * @param word word index in the line
 * @param line line index
 * @see #getChar
 * @see #addChar
 * @see #deleteChar
 */

  public void setChar(char c, int position, int word, int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    String current_word = (String) current_line.get(word);
    char[] chars = current_word.toCharArray();
    chars[position] = c;
    current_word = new String(chars);
    current_line.set(word, current_word);
  }

//----------------------------------------------------------------------
/**
 * Gets the character from the specified position in the specified word 
 * in a particular line.
 * @param position character index in the word
 * @param word word index in the line
 * @param line line index
 * @return char
 * @see #setChar
 * @see #addChar
 * @see #deleteChar
 */

  public char getChar(int position, int word, int line){
    return ((String) ((ArrayList) lines_.get(line)).get(word)).charAt(position);
  }

//----------------------------------------------------------------------
/**
 * Adds a character at the end of the specified word in a particular line.
 * @param c new character
 * @param word word index in the line
 * @param line line index
 * @see #setChar
 * @see #getChar
 * @see #deleteChar
 */

  public void addChar(char c, int word, int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    String current_word = (String) current_line.get(word);
    char[] chars = new char[current_word.length() + 1];
    current_word.getChars(0, chars.length - 1, chars, 0);
    chars[chars.length - 1] = c;
    current_word = new String(chars);
    current_line.set(word, current_word);
  }

//----------------------------------------------------------------------
/**
 * Deletes the character from the specified position in the specified word 
 * in a particular line.
 * @param position character index in the word
 * @param word word index in the line
 * @param line line index
 * @see #setChar
 * @see #getChar
 * @see #addChar
 */

  public void deleteChar(int position, int word, int line){
	//System.out.println("DD");
    ArrayList current_line = (ArrayList) lines_.get(line);
    String current_word = (String) current_line.get(word);
    char[] chars = new char[current_word.length() - 1];
    current_word.getChars(0, position, chars, 0);
    current_word.getChars(position + 1, chars.length + 1, chars, position);
    current_word = new String(chars);
    current_line.set(word, current_word);    
  }

//----------------------------------------------------------------------
/**
 * Gets the number of characters in this particular word.
 * @param word word index in the line
 * @param line line index
 * @return int
 */

  public int getCharCount(int word, int line){
    return ((String) ((ArrayList) lines_.get(line)).get(word)).length();
  }

//----------------------------------------------------------------------
/**
 * This method sets a new word on the specified index of a particular line.
 * Character array is taken as an argument for the word.
 * @param chars new word
 * @param word word index in the line
 * @param line line index
 * @see #getWord
 * @see #addWord
 * @see #addEmptyWord
 * @see #deleteWord
 */
  
  public void setWord(char[] chars, int word, int line){
    setWord(new String(chars), word, line);
  }

//----------------------------------------------------------------------
/**
 * This method sets a new word on the specified index of a particular line.
 * String is taken as an argument for the word.
 * @param chars new word
 * @param word word index in the line
 * @param line line index
 * @see #getWord
 * @see #addWord
 * @see #addEmptyWord
 * @see #deleteWord
 */
  
  public void setWord(String chars, int word, int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    current_line.set(word, chars);
  }

//----------------------------------------------------------------------
/**
 * Gets the word from the specified position in a particular line
 * String representing the word is returned.
 * @param word word index in the line
 * @param line line index
 * @return String
 * @see #setWord
 * @see #addWord
 * @see #addEmptyWord
 * @see #deleteWord
 */
  
  public String getWord(int word, int line){
    return (String) ((ArrayList) lines_.get(line)).get(word);
  }

//----------------------------------------------------------------------
/**
 * Adds a word at the end of the specified line.
 * The method takes a character array as an argument.
 * @param chars new word
 * @param line line index
 * @see #addEmptyWord
 * @see #setWord
 * @see #getWord
 * @see #deleteWord
 */
 
  public void addWord(char[] chars, int line){
    addWord(new String(chars), line);
  }

//----------------------------------------------------------------------
/**
 * Adds a word at the end of the specified line.
 * The method takes a string as an argument.
 * @param chars new word
 * @param line line index
 * @see #addEmptyWord
 * @see #setWord
 * @see #getWord
 * @see #deleteWord
 */
  
  public void addWord(String chars, int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    current_line.add(chars);
  }

//----------------------------------------------------------------------
/**
 * Adds an empty word at the end of the specified line.
 * @param line line index
 * @see #setWord
 * @see #getWord
 * @see #addWord
 * @see #deleteWord
 */
  
  public void addEmptyWord(int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    current_line.add(new String());
  }

//----------------------------------------------------------------------
/**
 * Deletes the word from the specified position in a particular line.
 * @param word word index in the line
 * @param line line index
 * @see #setWord
 * @see #getWord
 * @see #addWord
 * @see #addEmptyWord
 */
  
  public void deleteWord(int word, int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    current_line.remove(word);
  }

//----------------------------------------------------------------------
/**
 * Gets the number of words in this particular line.
 * @param line line index
 * @return int
 */
  
  public int getWordCount(int line){
    return ((ArrayList) lines_.get(line)).size();
  }

//----------------------------------------------------------------------
/**
 * This method sets a new line on the specified index.
 * This method takes two dimensional character array as an argument
 * for the line.
 * @param words new line
 * @param line line index
 * @see #getLine
 * @see #getLineAsString
 * @see #addLine
 * @see #addEmptyLine
 * @see #deleteLine
 */
 
  public void setLine(char[][] words, int line){
    String[] tmp = new String[words.length];
    for(int i = 0; i < words.length; i++)
      tmp[i] = new String(words[i]);
    setLine(tmp, line);
  }

//----------------------------------------------------------------------
/**
 * This method sets a new line on the specified index.
 * This method takes a string array as argument.
 * @param words new line
 * @param line line index
 * @see #getLine
 * @see #getLineAsString
 * @see #addLine
 * @see #addEmptyLine
 * @see #deleteLine
 */
 
  public void setLine(String[] words, int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    current_line.clear();
    for(int i = 0; i < words.length; i++)
      current_line.add(words[i]);
  }

//----------------------------------------------------------------------
/**
 * This method inserts a new line on the specified index.
 * This method takes two dimensional character array as an argument
 * for the line.
 * @param words new line
 * @param line line index
 * @see #getLine
 * @see #getLineAsString
 * @see #addLine
 * @see #addEmptyLine
 * @see #deleteLine
 */
 
  public void insertLine(char[][] words, int line){
    String[] tmp = new String[words.length];
    for(int i = 0; i < words.length; i++)
      tmp[i] = new String(words[i]);
    insertLine(tmp, line);
  }

//----------------------------------------------------------------------
/**
 * This method inserts a new line on the specified index.
 * This method takes a string array as argument.
 * @param words new line
 * @param line line index
 * @see #getLine
 * @see #getLineAsString
 * @see #addLine
 * @see #addEmptyLine
 * @see #deleteLine
 */

  public void insertLine(String[] words, int line){
    ArrayList current_line = new ArrayList();
    for(int i = 0; i < words.length; i++)
      current_line.add(words[i]);
    lines_.add(line, current_line);
  }

//----------------------------------------------------------------------
/**
 * Gets the line from the specified position.
 * String array representing the line is returned.
 * @param line line index
 * @return String[]
 * @see #setLine
 * @see #getLineAsString
 * @see #addLine
 * @see #addEmptyLine
 * @see #deleteLine
 */

  public String[] getLine(int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    String[] tmp = new String[current_line.size()];
    for(int i = 0; i < tmp.length; i++)
      tmp[i] = (String) current_line.get(i);
    return tmp;
  }

//----------------------------------------------------------------------
/**
 * Gets the line from the specified position.
 * A single String representing the line is returned.
 * @param line line index
 * @return String
 * @see #setLine
 * @see #getLine
 * @see #addLine
 * @see #addEmptyLine
 * @see #deleteLine
 */
  public String getLineAsString(int line){
    ArrayList current_line = (ArrayList) lines_.get(line);
    
    int size = current_line.size();
    int length = 0;
    for(int i = 0; i < size; i++)
      length += getWord(i, line).length();
    length += size - 1;

    char[] tmp = new char[length];
    int count = 0;
    for(int i = 0; i < size; i++){
      getWord(i, line).getChars(0, getWord(i, line).length(), tmp, count);
      count += getWord(i, line).length();
      if(i != (size - 1))
        tmp[count++] = ' ';
    }
  //  System.out.println("DD   " + new String(tmp).toString());
    return new String(tmp);
      }
  

//----------------------------------------------------------------------
/**
 * Adds a line at the end of the line array.
 * Two dimensional array is the argument for the new line
 * @param words new line
 * @see #addEmptyLine
 * @see #setLine
 * @see #getLine
 * @see #deleteLine
 */

  public void addLine(char[][] words){
    String[] tmp = new String[words.length];
    for(int i = 0; i < words.length; i++)
      tmp[i] = new String(words[i]);
    addLine(tmp);
  }

//----------------------------------------------------------------------
/**
 * Adds a line at the end of the line array.
 * String array is the argument for the new line.
 * @param words new line
 * @see #addEmptyLine
 * @see #setLine
 * @see #getLine
 * @see #deleteLine
 */

  public void addLine(String[] words){
    ArrayList current_line = new ArrayList();
    for(int i = 0; i < words.length; i++)
      current_line.add(words[i]);
    lines_.add(current_line);
  }

//----------------------------------------------------------------------
  /**
   * get the line number accord to the String.
   * Two dimensional array is the argument for the new line
   * @param words new line
   * @see #addEmptyLine
   * @see #setLine
   * @see #getLine
   * @see #deleteLine
   */
  public int getLineNumByString(String strInput){
	  String strOld = new String();
	  for(int i =0;i<lines_.size();i++){
		  strOld = getLineAsString(i);
		  if (strInput.equals(strOld)){
			  return i;
		  }
	  }
	  return -1;
  }
  
  public void deletLinebyArray(String[] strInput){
	 String strTemp = new String();
	 strTemp=getLAsString(strInput);
	 int inttemp = getLineNumByString(strTemp);
	 //System.out.println("DELT    "+inttemp);
	 if (inttemp!=-1){
		 deleteLine(inttemp);
	 }
  }
  public String getLAsString(String[] strInput){
	  String strtemp = new String();
	  int i=0;
	  for(i =0;i<strInput.length-1;i++){
		  strtemp = strtemp+strInput[i];
		  strtemp =strtemp+" ";
	  }
	  strtemp = strtemp+strInput[i];
	 // System.out.println(strtemp);
	  return strtemp;
  }
  
  
//----------------------------------------------------------------------------
/**
 * Adds an empty line at the end of the lines array.
 * @see #setLine
 * @see #getLine
 * @see #getLineAsString
 * @see #addLine
 * @see #deleteLine
 */

  public void addEmptyLine(){
    ArrayList current_line = new ArrayList();
    lines_.add(current_line);
  }

  
//-------------------------------------------------------------------------
/**
 * Deletes the line from the specified position.
 * @param line line index
 * @see #setLine
 * @see #getLine
 * @see #getLineAsString
 * @see #addLine
 * @see #addEmptyLine
 */
  public void deleteLine(int line){
	  lines_.remove(line);
  }

//----------------------------------------------------------------------
/**
 * Gets the number of lines.
 * @return int
 */

  public int getLineCount(){
    return lines_.size();
  }

//----------------------------------------------------------------------
/**
 * Inner classes
 *
 */
//----------------------------------------------------------------------

}
