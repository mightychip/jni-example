package ca.purpleowl.examples.jni;

/**
 * TODO Add some JavaDoc.
 */
public class BasicJNIWrapper implements Runnable {

    private native String genericHello();
    private native String personalHello(String name);
    private native int addNumbers(int numOne, int numTwo);
    private native int subtractNumbers(int numOne, int numTwo);
    private native String concatenateMe(String[] words);

    public BasicJNIWrapper() {
        //You'll want to edit this accordingly.
        System.load("/Users/thismustbeyou/Development/Java/Examples/jni-example/src/main/resources/libcpp.dylib");
    }

    public void run() {
        String result = genericHello();
        System.out.println(result);
        result = personalHello("Chip");
        System.out.println(result);
        System.out.println("Result is: " + addNumbers(1, 2));
        System.out.println("Result is: " + subtractNumbers(5, 1));
        System.out.println("This is an assembled sentence: " + concatenateMe(new String[]{"Cats", "are", "the", "best", "pets"}));
    }

    public static void main(String... args) {
        BasicJNIWrapper me = new BasicJNIWrapper();
        me.run();
    }
}

