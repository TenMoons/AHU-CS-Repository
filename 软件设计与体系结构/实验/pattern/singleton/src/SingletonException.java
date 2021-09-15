/**
 *  A user defined exception
 */
public class SingletonException extends RuntimeException {
    public SingletonException() {
        super();
    }
    
    public SingletonException(String s) {
        super(s);
    }
    
}