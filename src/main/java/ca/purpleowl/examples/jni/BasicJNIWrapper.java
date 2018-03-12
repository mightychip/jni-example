package ca.purpleowl.examples.jni;

/**
 * This is a super simple JNI implementation.  I wanted to get an example out there that was at least somewhat recent.
 * Nothing seems to really have changed in recent years with JNI, but given that the native plugin is now using
 * deprecated commands, there's probably some changes coming in the next version of Java.
 *
 * The native methods are used with javac -h to generate a header.  That header is implemented in C++ with some very
 * simple code.  This is enough to show you how JNI works and to get you up and running.
 */
public class BasicJNIWrapper implements Runnable {

    //These stubs are used to generate the header and automagically link to the native implementation of that header
    //as long as you load the library that implementation was compiled into.
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

