/**
 *  Subject interface
 *  In this interface , we can only declare top 3 function, 
 *  other function we can define in an abstract class which implements
 *  this interface
 */
import java.util.*;

public interface Subject  {
    public abstract void attach(Observer o);
    public abstract void detach(Observer o);
    public abstract void sendNotify();

    public abstract Vector getState();
    public abstract void setState(String act, String str);
}