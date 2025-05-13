import java.util.Queue;
import java.util.LinkedList;

class MyStack {

    private Queue<Integer> mainQueue;
    private Queue<Integer> temporaryQueue;

    public MyStack() {
        mainQueue = new LinkedList<>();
        temporaryQueue = new LinkedList<>();
    }

    public void push(int x) {
        temporaryQueue.offer(x);
        
        while (!mainQueue.isEmpty()) {
            temporaryQueue.offer(mainQueue.poll());
        }
        
        Queue<Integer> temp = mainQueue;
        mainQueue = temporaryQueue;
        temporaryQueue = temp;
    }

    public int pop() {
        return mainQueue.poll(); 
    }

    public int top() {
        return mainQueue.peek(); 
    }

    public boolean empty() {
        return mainQueue.isEmpty();  
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
