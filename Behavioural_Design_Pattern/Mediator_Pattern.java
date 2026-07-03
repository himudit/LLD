package Behavioural_Design_Pattern;

import java.util.*;

interface ChatMediator {
    void sendMessage(String message, String userName);
}

class SimpleChatMediator implements ChatMediator {
    public void sendMessage(String message, String userName) {
        System.out.println(userName + " says: " + message);
    }
}

interface OrderMediator {
    void placeOrder(String userName, String product);
}

class SimpleOrderMediator implements OrderMediator {

    @Override
    public void placeOrder(String userName, String product) {

        System.out.println("Checking Inventory...");
        System.out.println("Processing Payment...");
        System.out.println("Shipping Product...");

        System.out.println(userName + " ordered " + product);
    }
}

class User {
    private String name;
    private ChatMediator chatMediator;
    private OrderMediator orderMediator;

    public User(String name,
            ChatMediator chatMediator,
            OrderMediator orderMediator) {

        this.name = name;
        this.chatMediator = chatMediator;
        this.orderMediator = orderMediator;
    }

    public void sendMessage(String message) {
        chatMediator.sendMessage(message, name);
    }

    public void buyProduct(String product) {
        orderMediator.placeOrder(name, product);
    }
}

public class Mediator_Pattern {
    public static void main(String[] args) {
        ChatMediator chatMediator = new SimpleChatMediator();
        OrderMediator orderMediator = new SimpleOrderMediator();

        User user = new User(
                "Rahul",
                chatMediator,
                orderMediator);
        user.sendMessage("Hello Everyone!");

        System.out.println();

        user.buyProduct("Laptop");
    }
}

// Instead of objects talking directly to each other, they all talk to one
// central object (Mediator).