
public class Factory {
    public Window CreateWindow (String type) {
        if(type.equals("Big")) {
            return new WindowBig();
        } else if(type.equals("Small")) {
            return new WindowSmall();
        } else {
            return new WindowBig();
        }
    }

    // The Main function only for our test
    public static void main(String[] args) {
        Factory myFactory = new Factory();
        Window myBigWindow = myFactory.CreateWindow("Big");
        myBigWindow.func();

        Window mySmallWindow = myFactory.CreateWindow("Small");
        mySmallWindow.func();
    }
}