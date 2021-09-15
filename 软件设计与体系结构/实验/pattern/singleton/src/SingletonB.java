/**
 *  A new Singleton use registry
 */
import java.util.*;

public class SingletonB  {
    static private Hashtable registry = new Hashtable();
    //static private SingletonB instance;
    
    public static void Register(String name, SingletonB aInstance) {
        registry.put(name, aInstance);
    }
    public static SingletonB GetInstance(String name) {
        return LookUp(name);
    }
    
    protected static SingletonB LookUp(String name) {
        return (SingletonB)registry.get(name);
    }
}