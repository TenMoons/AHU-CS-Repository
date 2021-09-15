/**
 *  Test for our Singleton registry
 */
public class TestB  {
    public static void main(String[] args) {
        // First we get a instance from SingletonB
        SingletonB instance1 = SingletonB.GetInstance("Sub1");
        if(instance1 == null) {
            System.out.println("There is no such instance in registry !");
        } else {
            System.out.println(instance1.getClass());
        }
        
        // Then we register a new instance
        try {
            SingletonB instance2 = new SubSingletonB();
            System.out.println("We had created a new instance named \"Sub1\" now");
        } catch (SingletonException e) {
            System.out.println(e.getMessage());
        }
        
        // To get instance again
        instance1 = SingletonB.GetInstance("Sub1");
        if(instance1 == null) {
            System.out.println("There is no such instance in registry !");
        } else {
            System.out.println(instance1.getClass());
        }

        // Finally we create a new instance again
        try {
            SingletonB instance3 = new SubSingletonB();
            System.out.println("We had created a new instance named \"Sub1\" now");
        } catch (SingletonException e) {
            System.out.println(e.getMessage());
        }
        
    }
}