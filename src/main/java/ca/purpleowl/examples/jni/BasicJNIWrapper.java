package ca.purpleowl.examples.jni;

public class BasicJNIWrapper implements Runnable {

    private native String genericHello();
    private native String personalHello(String name);
    private native int addNumbers(int numOne, int numTwo);
    private native int subtractNumbers(int numOne, int numTwo);
    private native int oneMore(int oneMore);

    public BasicJNIWrapper() {
        System.load("/Users/thismustbeyou/Development/Java/Examples/jni-example/src/main/resources/libcpp.dylib");
    }

    public void run() {
        String result = genericHello();
        System.out.println(result);
        result = personalHello("Chip");
        System.out.println(result);
        System.out.println("Result is: " + addNumbers(1, 2));
        System.out.println("Result is: " + subtractNumbers(5, 1));
    }

    public static void main(String... args) {
        BasicJNIWrapper me = new BasicJNIWrapper();
        me.run();
    }
}

