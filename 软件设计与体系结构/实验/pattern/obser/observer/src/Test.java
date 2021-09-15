/**
 *  A test client
 */
public class Test  {
    public static void main(String[] args) {
        Subject mySub = new ConcreteSubject();
        ObserverA myObserverA = new ObserverA(mySub);
        ObserverB myObserverB = new ObserverB();
        mySub.attach(myObserverA);
        mySub.attach(myObserverB);

        mySub.setState("ADD", "ÂèÂèOne --- 1");
        mySub.setState("ADD", "Tow --- 2");
        mySub.sendNotify();

        myObserverA.change("DEL", "Tow --- 2");
        myObserverA.change("ADD", "Three --- 3");
        myObserverA.change("ADD", "Four --- 4");
        myObserverA.notifySub();  
    }
}