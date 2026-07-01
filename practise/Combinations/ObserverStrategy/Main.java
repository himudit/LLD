package practise.Combinations.ObserverStrategy;

import java.util.*;

interface Observer {
    void update(int temperature);
}

class MobileDisplay implements Observer {
    private AlertStrategy as;

    public MobileDisplay(AlertStrategy as) {
        this.as = as;
    }

    public void setStrategy(AlertStrategy as) {
        this.as = as;
    }

    public void update(int t) {
        as.showAlert(t);
    }
}

class TVDisplay implements Observer {
    private AlertStrategy as;

    public TVDisplay(AlertStrategy as) {
        this.as = as;
    }

    public void setStrategy(AlertStrategy as) {
        this.as = as;
    }

    public void update(int t) {
        as.showAlert(t);
    }
}

class SmartDisplay implements Observer {
    private AlertStrategy as;

    public SmartDisplay(AlertStrategy as) {
        this.as = as;
    }

    public void setStrategy(AlertStrategy as) {
        this.as = as;
    }

    public void update(int t) {
        as.showAlert(t);
    }
}

interface WeatherStation {
    public void register(Observer obs);

    public void updateTemperature(int t);

    public void notifyDevices();
}

class station1 implements WeatherStation {
    private ArrayList<Observer> list = new ArrayList<>();
    private int temperature = 25;

    public void register(Observer obs) {
        list.add(obs);
    }

    public void updateTemperature(int t) {
        this.temperature = t;
        notifyDevices();
    }

    public void notifyDevices() {
        list.forEach(observer -> {
            observer.update(temperature);
        });

    }
}

interface AlertStrategy {
    void showAlert(int t);
}

class Normal implements AlertStrategy {
    public void showAlert(int t) {
        System.out.println("Temperature: " + t);
    }
}

class Loud implements AlertStrategy {
    public void showAlert(int t) {
        System.out.println("⚠️⚠️ " + t);
    }
}

class Minimal implements AlertStrategy {
    public void showAlert(int t) {
        System.out.println(t);
    }
}

public class Main {
    public static void main(String[] args) {
        AlertStrategy as1 = new Normal();
        AlertStrategy as2 = new Loud();
        AlertStrategy as3 = new Minimal();

        MobileDisplay mobileUser = new MobileDisplay(as1);
        TVDisplay tvUser = new TVDisplay(as2);
        SmartDisplay smartUser = new SmartDisplay(as3);

        WeatherStation s1 = new station1();
        s1.register(mobileUser);
        s1.register(tvUser);
        s1.register(smartUser);
        s1.notifyDevices();
        s1.updateTemperature(40);

        mobileUser.setStrategy(as3);
        tvUser.setStrategy(as2);
        smartUser.setStrategy(as1);
        s1.notifyDevices();
        s1.updateTemperature(50);

    }
}
