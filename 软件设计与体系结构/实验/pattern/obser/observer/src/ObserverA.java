/**
 *  A concrete observer
 *  This concrete observer can change subject through call
 *  a concrete subject setState function
 */
import java.io.*;
import java.util.*;
 
public class ObserverA implements Observer {
    private Vector strVector;
    private Subject sub;
    public ObserverA(Subject s) {
        sub = s;
        //strVector = new Vector();
    }
    public void update(Subject subject) {
        strVector = subject.getState();
        System.out.println("----- ObserverA will be updated -----");
        for(int i = 0; i < strVector.size(); i++) {
            System.out.println("Num " + i + " is :" + (String)strVector.get(i));
        }
    }
    public void change(String action, String str) {
        sub.setState(action, str);
        //we can auto update
        //sub.sendNotify();
    }
    public void notifySub() {
        sub.sendNotify();
    }
}