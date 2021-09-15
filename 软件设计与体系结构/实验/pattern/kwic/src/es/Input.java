// -*- Java -*-
/*
 * 
 * 
 * <file>
 * 
 *  Name:    Input.java
 * 
 *  Purpose: Input reads and parses the KWIC input file
 * 
 *  Created: 05 Nov 
 * 
 *  $Id$
 * 
 *  Description:
 *    Input reads and parses the KWIC input file
 * </file>
 */

package es;

/*
 * $Log$
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;

import java.util.StringTokenizer;
import java.util.ArrayList;

/**
 * An object of the Input class is responsible for reading and parsing the
 * content of a KWIC input file. The format of the KWIC input file is as
 * follows:
 * <ul>
 * <li>Lines are separated by the line separator character(s) (on Unix '\n', on
 * Windows '\r\n')
 * <li>Each line consists of a number of words. Words are delimited by any
 * number and combination of the space chracter (' ') and the horizontal
 * tabulation chracter ('\t').
 * </ul>
 * The entered data is parsed and stored in memory as an instance of the
 * LineStorageWrapper class. The data is parsed in the following way:
 * <ul>
 * <li>All line separators are removed from the data; for each new line in the
 * file a new line is added to the LineStorageWrapper instance
 * <li>All horizontal tabulation word delimiters are removed
 * <li>All space character word delimiters are removed
 * <li>From characters between any two word delimiters a new string is created;
 * the new string is added to the LineStorageWrapper instance.
 * </ul>
 * 
 * 
 * @version $Id$
 */

public class Input {

	// ----------------------------------------------------------------------
	/**
	 * Fields
	 * 
	 */
	// ----------------------------------------------------------------------
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
	 * This method reads and parses a KWIC input file. If an I/O exception
	 * occurs during the execution of this method, an error message is shown and
	 * program exits.
	 * 
	 * @param file
	 *            name of KWIC input file
	 * @param line_storage
	 *            holds the parsed data
	 */

	public void parse(LineStorageWrapper line_storage) {
		try {
			String c;
			String line = new String();
			int intDelItem = 0;
			BufferedReader dr = new BufferedReader(new InputStreamReader(
					System.in));
			System.out.print("Add, Delete, Print, Quit: ");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					System.in));
			do {
				c = dr.readLine();
				if (c.length() != 0) {
					// a char d =(char) dr.read();
					// System.out.println("C="+c);
					switch (c.charAt(0)) {
					case 'a':
						System.out.print(">");
						line = reader.readLine();
						// System.out.println("line="+line);
						StringTokenizer tokenizer = new StringTokenizer(line);
						if (tokenizer.countTokens() > 0) {
							ArrayList words = new ArrayList();
							while (tokenizer.hasMoreTokens())
								words.add(tokenizer.nextToken());
							String[] line_rep = new String[words.size()];
							for (int i = 0; i < line_rep.length; i++)
								line_rep[i] = (String) words.get(i);
							line_storage.addLine(line_rep);
							line_storage.addIndex(line_rep);
							// System.out.println("LL"+
							// line_storage.getLineCount());
						}
						System.out.print("Add, Delete, Print, Quit:");
						break;
					case 'd':
						System.out.print(">");
						line = reader.readLine();
						StringTokenizer tokenizers = new StringTokenizer(line);
						if (tokenizers.countTokens() > 0) {
							ArrayList words = new ArrayList();
							while (tokenizers.hasMoreTokens())
								words.add(tokenizers.nextToken());
							String[] line_rep = new String[words.size()];
							for (int i = 0; i < line_rep.length; i++)
								line_rep[i] = (String) words.get(i);
							intDelItem = line_storage.getLineNumByString(line);
							if (intDelItem != -1) {
								line_storage.deleteLines(intDelItem, line_rep);
							}
						}
						System.out.print("Add, Delete, Print, Quit:");
						break;
					case 'p':
						System.out.println("------------------------------- ");
						line_storage.PrintLine();
						System.out.println("------------------------------- ");
						System.out.print("Add, Delete, Print, Quit:");
						break;
					case 'i':
						line_storage.PrIndex();
						System.out.print("Add, Delete, Print, Quit:");
						break;
					case 'q':
						break;
					default:
						break;
					}
				}
			} while (c.equals(new String("q")) == false);
			System.out.println();
		} catch (FileNotFoundException exc) {
			exc.printStackTrace();
			// System.err.println("KWIC Error: Could not open " + file +
			// "file.");
			System.exit(1);
		} catch (IOException exc) {
			exc.printStackTrace();
			// System.err.println("KWIC Error: Could not read " + file +
			// "file.");
			System.exit(1);
		}
	}

	// ----------------------------------------------------------------------
	/**
	 * Inner classes
	 * 
	 */
	// ----------------------------------------------------------------------
}
