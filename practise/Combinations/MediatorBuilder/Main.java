package practise.Combinations.MediatorBuilder;

import java.util.*;

// interface Observer {
//     void update(String event);
// }

// class Employee implements Observer {
//     public void update() {

//     }
// }

// interface Subject {
//     void attach(Observer obs);

//     void detach(Observer obs);

//     void notify(String msg);
// }

interface Mediator {
    void placeOrder(Order o);
}

class OrderMediator implements Mediator {
    private Kitchen kitchen = new Kitchen();
    private Billing billing = new Billing();
    private Delivery delivery = new Delivery();

    public void placeOrder(Order o) {
        kitchen.takeOrder(o);

        int bill = billing.processBill(o);

        delivery.takeOrder(o, bill);

        System.out.println("Order Completed");
    }
}

class Kitchen {
    // protected Order order;

    public boolean takeOrder(Order order) {
        System.out.println("took the order");
        // this.order = order;
        return true;
    }
}

class Billing {
    public int processBill(Order order) {
        System.out.println("Total Bill to pay: 40rs");
        return 40;
    }
}

class Delivery {
    protected Order order;

    public boolean takeOrder(Order order, int billAmount) {
        System.out.println("Delivering to location");
        this.order = order;
        return true;
    }
}

class Order {
    protected ArrayList<String> items = new ArrayList<>();
    protected boolean coke;
    protected boolean dessert;

    static class Builder {
        protected ArrayList<String> items = new ArrayList<>();
        protected boolean coke;

        public Builder setItems(String item) {
            this.items.add(item);
            return this;
        }

        public Builder setCoke(boolean coke) {
            this.coke = coke;
            return this;
        }

        public Order build() {
            if (items.size() == 0) {
                throw new IllegalStateException("Please select atleast one item");
            }
            Order order = new Order();
            order.items = this.items;
            order.coke = this.coke;
            return order;
        }
    }

}

public class Main {
    public static void main(String[] args) {
        Order order = new Order.Builder().setItems("Pizza").setCoke(true).build();

        Mediator mediator = new OrderMediator();
        mediator.placeOrder(order);
    }
}
