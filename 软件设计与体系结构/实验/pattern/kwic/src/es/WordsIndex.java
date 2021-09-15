package es;

import java.util.ArrayList;

public class WordsIndex {
	private ArrayList<String> Word = new ArrayList();

	private ArrayList<Integer> Nums = new ArrayList();

	public void addWords(String word) {
		if (Word.size() == 0) {
			// System.out.println("AAAA " + words);
			Word.add(word);
			Nums.add(1);
			return;
		}
		Boolean flag = false;
		for (int i = 0; i < Word.size(); i++) {
			if (word.equals(new String(Word.get(i).toString()))) {
				int num = Integer.parseInt(Nums.get(i).toString());
				num = num + 1;

				Nums.set(i, new Integer(num));
				flag = true;
				break;
			}
		}
		if (flag != true) {
			// System.out.println("AAAA " + words);
			Word.add(word);
			Nums.add(1);
		}
	}

	public void addWords(String[] words) {
		for (int i = 0; i < words.length; i++) {
			addWords(words[i]);
		}
		/*for (int i = 0; i < Word.size(); i++) {
			System.out.println(Word.get(i) + " : " + Nums.get(i));
		}
		*/
	}

	public void deleteWords(String[] words) {
		for (int i = 0; i < words.length; i++) {
			deleteWords(words[i]);
		}
		/*for (int i = 0; i < Word.size(); i++) {
			System.out.println(Word.get(i) + " : " + Nums.get(i));
		}*/
	}

	public void deleteWords(String word) {
		int flag = -1;
		for (int i = 0; i < Word.size(); i++) {
			if (word.equals(new String(Word.get(i).toString()))) {
				int num = Integer.parseInt(Nums.get(i).toString());
				num = num - 1;
				if (num != 0)
					Nums.set(i, new Integer(num));
				else
					flag = i;
				break;
			}
		}
		if (flag != -1) {
			// System.out.println("AAAA " + words);
			Word.remove(flag);
			Nums.remove(flag);
		}
	}
	
	public int getIndexCount(){
		return Word.size();
	}
	
	public String getIndexString(int index){
		return new String(Word.get(index) + " : " + Nums.get(index));
	}
}
