// Sebastian Vivo 010849203
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;
import java.util.concurrent.Semaphore;

public class ProducerConsumer {

	public static class Goods {

  	ArrayList<Integer> list = new ArrayList<>();
		int capacity = 100;
		Random item = new Random();

		public void produce() throws InterruptedException
		{
			while (true) {
				synchronized (this)
				{
					while (list.size() == capacity)
						wait();

					list.add(item.nextInt(100000));
					System.out.println("Producer produced: " + list.get(list.size() - 1));

					notify();

					Thread.sleep(item.nextInt(500));
				}
			}
		}

		public void consume() throws InterruptedException
		{
			while (true) {
				synchronized (this)
				{
					while (list.size() == 0)
						wait();

          int value = list.get(0);
          list.remove(0);

					System.out.println("Consumer consumed: " + value);

					notify();

					Thread.sleep(item.nextInt(500));
				}
			}
		}
	}
  public static void main(String[] args)
		throws InterruptedException
	{
		int time = Integer.parseInt(args[0]);
		int p = Integer.parseInt(args[1]);
		int c = Integer.parseInt(args[2]);
		System.out.println("time = " + time + " Producers = " + p + " Consumers = " + c + ".\n");
		Thread pro[] = new Thread[p];
		Thread con[] = new Thread[c];
		final Goods goods = new Goods();

		// Create producer threads
		for(int i = 0; i < p; i++){
			pro[i] = new Thread(new Runnable() {
				@Override
				public void run()
				{
					try {
						goods.produce();
					}
					catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			});
			pro[i].start();
		}
		// Create consumer threads
		for(int i = 0; i < c; i++){
			con[i] = new Thread(new Runnable() {
				@Override
				public void run()
				{
					try {
						goods.consume();
					}
					catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			});
			con[i].start();
		}
		System.out.println("done #1");
		for(int i = 0; i < p; i++){
			pro[i].join();
			System.out.println("joining ps");
		}
		for(int i = 0; i < c; i++){
			System.out.println("joining cs");
			con[i].join();
		}
		System.out.println("done #2");
	}
}
