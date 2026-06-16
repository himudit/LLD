package Behavioural_Design_Pattern;

abstract class PaymentStrategy {
    abstract void processPayment(double amount);
}

class CrediCard extends PaymentStrategy {
    void processPayment(double amount) {
        System.out.println("Payment of " + amount + "done by Credit Card");
    }
}

class UPI extends PaymentStrategy {
    void processPayment(double amount) {
        System.out.println("Payment of " + amount + "done by UPI");
    }
}

class PaymentProcessor {
    PaymentStrategy ps;

    PaymentProcessor(PaymentStrategy ps) {
        this.ps = ps;
    }

    void process(double amount) {
        ps.processPayment(amount);
    }
}

public class Strategy_Pattern {
    public static void main(String[] args) {
        PaymentStrategy credit = new CrediCard();
        PaymentProcessor pp = new PaymentProcessor(credit);
        pp.process(40);
    }
}
