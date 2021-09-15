// -*- Java -*-
/*
 * 
 * 
 * <file>
 * 
 *  Name:    CircularShifter.java
 * 
 *  Purpose: Produces circular shifts of input lines
 * 
 *  Created: 05 Nov 
 * 
 *  $Id$
 * 
 *  Description:
 *    Produces circular shifts of input lines
 * </file>
 */

package es;

/*
 * $Log$
 */

import java.util.Observable;
import java.util.Observer;
import java.util.ArrayList;
import java.util.StringTokenizer;

import java.util.StringTokenizer;
import java.util.ArrayList;

/**
 * CircularShifter class implemets the "Observer" part of the standard
 * "Observable"-"Observer" mechanism. Thus, an instance of CircularShifter class
 * declares its interest in tracking changes in an object of LineStorage class,
 * which holds the original lines read from a KWIC input file. Any event
 * produced and sent by that LineStorageWrapper object (e.g. whenever a new line
 * has been added) is catched by CircularShiter object. In turn, this leads to
 * production of circular shifts for the newly added line. Circular shifts are
 * kept within an CircularShifter object again in the form of a
 * LineStorageWrapper object.
 * 
 * 
 * @version $Id$
 */

public class CircularShifter implements Observer {

	// ----------------------------------------------------------------------
	/**
	 * Fields
	 * 
	 */
	// ----------------------------------------------------------------------
	/**
	 * LineStorageWrapper for circular shifts
	 * 
	 */

	private LineStorageWrapper shifts_;

	// ----------------------------------------------------------------------
	/**
	 * Constructors
	 * 
	 */
	// ----------------------------------------------------------------------
	// ----------------------------------------------------------------------
	/**
	 * Defualt constructor.
	 * 
	 * @param shifts
	 *            storage for shifted lines
	 */

	public CircularShifter(LineStorageWrapper shifts) {
		shifts_ = shifts;
	}

	// ----------------------------------------------------------------------
	/**
	 * Methods
	 * 
	 */
	// ----------------------------------------------------------------------
	// ----------------------------------------------------------------------
	/**
	 */

	public void update(Observable observable, Object arg) {
		LineStorageWrapper lines = (LineStorageWrapper) observable;
		LineStorageChangeEvent event = (LineStorageChangeEvent) arg;
		String[] line;

		switch (event.getType()) {
		case LineStorageChangeEvent.ADD:
			line = lines.getLine(lines.getLineCount() - 1);
			for (int i = 0; i < line.length; i++) {
				ArrayList words = new ArrayList();
				for (int j = i; j < (line.length + i); j++)
					words.add(line[j % line.length]);
				String[] line_rep = new String[words.size()];
				for (int k = 0; k < line_rep.length; k++)
					line_rep[k] = (String) words.get(k);
				shifts_.addLine(line_rep);
				if (i == 0) {
					shifts_.addIndex(line_rep);
				}

			}
			break;
		case LineStorageChangeEvent.DELETE:
			String delStr = event.getArg();
			StringTokenizer tokenizer = new StringTokenizer(delStr); // whitespaces
			// delimiters
			ArrayList word = new ArrayList();
			if (tokenizer.countTokens() > 0) {
				while (tokenizer.hasMoreTokens())
					word.add(tokenizer.nextToken());
			}
			line = new String[word.size()];
			for (int i = 0; i < line.length; i++)
				line[i] = (String) word.get(i);
			for (int i = 0; i < line.length; i++) {
				ArrayList words = new ArrayList();
				for (int j = i; j < (line.length + i); j++)
					words.add(line[j % line.length]);
				String[] line_rep = new String[words.size()];
				for (int k = 0; k < line_rep.length; k++) {
					line_rep[k] = (String) words.get(k);
				}
				shifts_.deletLinebyArray(line_rep);
				// System.out.println("KKKK Index");
				if (i == 0)
					shifts_.deleteWords(line_rep);
			}
			break;
		case LineStorageChangeEvent.PRINT:
			Output output = new Output();
			output.print(shifts_);
			break;
		case LineStorageChangeEvent.INDEX:
			Output outputs = new Output();
			outputs.printIndex(shifts_);
			// System.out.println("KKKK Index");
			break;
		case LineStorageChangeEvent.QUIT:
			break;
		default:
			break;
		}
	}

	// ----------------------------------------------------------------------
	/**
	 * Inner classes
	 * 
	 */
	// ----------------------------------------------------------------------
}
