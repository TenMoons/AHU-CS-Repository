/**
 *  A concrete subject
 */
import java.util.*;
import java.io.*;

public class ConcreteSubject implements Subject {
    private LinkedList observerList;
    private Vector strVector;
    
    public ConcreteSubject() {
        observerList =  new LinkedList();
        strVector = new Vector();
    }
    public void attach(Observer o) {
        observerList.add(o);
    }
    public void detach(Observer o) {
        observerList.remove(o);
    }
    public void sendNotify() {
        for(int i = 0; i < observerList.size(); i++) {
            ((Observer)observerList.get(i)).update(this);   
        }
    }
    public void setState(String act, String str) {
        if(act.equals("ADD")) {
            strVector.add(str);
        } else if(act.equals("DEL")) {
            strVector.remove(str);
        }
    }
    public Vector getState() {
        return strVector;
    }
}