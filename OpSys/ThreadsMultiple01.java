/*
 ThreadsMultiple01.java
 This codes shows one way to create multiple threads of one type.
 This code extends Thread instead of Runnable.
 It extends the class Thread and overrides the public run method with
 the code for the new thread, creates an instance of the Thread subclass,
 and calls its start method.
 10/30/17 by drt
 */

// NetBeans likes this

import java.util.concurrent.Semaphore;

/**
 *
 * @author drt
 */
public class ThreadsMultiple01 {
    private static int numInCriticalSection = 1;

    // create the semaphore set to numInCriticalSection;
    private static Semaphore semaphore = new Semaphore(numInCriticalSection);

    static class MyThread extends Thread{

        private String name = "";

        public MyThread(String name) {
            this.name = name;
        }

        @Override
        public void run() {
            try {
                // acquire semaphore
                System.out.println(name + " : available Semaphore slots before: " + semaphore.availablePermits());
                System.out.println(name + " : acquiring lock.");
                semaphore.acquire();
                System.out.println(name + " : got the free slot!");

                // sleep for 1 second to simulate processing
                Thread.sleep(1000);

                // release semaphore
                System.out.println(name + " : releasing lock.");
                semaphore.release();
                System.out.println(name + " : available Semaphore slots after: " + semaphore.availablePermits());
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {

        //List<ThreadsMultiple01> workers = new ArrayList<ThreadsMultiple01>();
        int number = 10;
        int number2 = 5;
        MyThread[] producer = new MyThread[number];
        MyThread[] consumer = new MyThread[number2];

        System.out.println("Semaphore Example");
        System.out.println();
        System.out.println("Total available slots: " + semaphore.availablePermits());

        // create and start 5 threads of one type
        for(int i=0; i < number; i++){
            producer[i] = new MyThread("Producer "+Integer.toString(i));
            producer[i].start();
        }
        for(int i=0; i < number2; i++){
            consumer[i] = new MyThread("Costumer "+Integer.toString(i));
            consumer[i].start();
        }


    }
}
