/*
ThreadsTwoDifferent01.java
Demonstrates how to create two different types of threads.
This is another way to implement threads with Runnable interface.
Implement the Runnable interface in a class with a public run method,
create an instance of the class, and pass a reference to that object to
the Thread constructor.
10/30/17
drt
 */
import java.util.Random;

class Producer implements Runnable{
    private final static Random generator = new Random();

    public void run(){
        try{
            // sleep 0 to .5 seconds
            Thread.sleep(generator.nextInt(500));
        }
        catch(InterruptedException exception){
            exception.printStackTrace();
        }
        System.out.println("Worker1");
    }
}

class Consumer implements Runnable{
    private final static Random generator = new Random();

    public void run(){
        try{
            // sleep 0 to .5 seconds
            Thread.sleep(generator.nextInt(500));
        }
        catch(InterruptedException exception){
            exception.printStackTrace();
        }
        System.out.println("Worker2");
    }
}
class ThreadsMultiple01 {
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
  }


public class ThreadsTwoDifferent01{

    public static void main(String[] args) {
        // create 2 Worker1 threads and one Worker2 thread
        Runnable task1 = new Worker1();
        Runnable task2 = new Worker1();
        Runnable task3 = new Worker2();

        Thread t1 = new Thread(task1, "t1");
        Thread t2 = new Thread(task2, "t2");
        Thread t3 = new Thread(task3, "t3");

        //List<ThreadsMultiple01> workers = new ArrayList<ThreadsMultiple01>();
        int number = 10;
        MyThread[] threads = new MyThread[number];

        System.out.println("Semaphore Example");
        System.out.println();
        System.out.println("Total available slots: " + semaphore.availablePermits());

        // create and start 5 threads of one type
        for(int i=0; i < number; i++){
            threads[i] = new MyThread("Costumer "+Integer.toString(i));
            threads[i].start();
        }


        t1.start();
        t2.start();
        t3.start();

    }

}
