interface Vehicle {
    public abstract void drive();
}

class Car implements Vehicle {
    public void drive() {
        System.out.println("Driving a Car 🚗");
    }
}

class Bus implements Vehicle {
    public void drive() {
        System.out.println("Driving a Bike 🚌");
    }
}

class VehicleFactory {
    public static Vehicle createVehicle(String type) {
        if ("car".equals(type))
            return new Car();
        if ("bus".equals(type))
            return new Bus();
        return null;
    }
}

public class Factory {
    public static void main(String[] args) {
        Vehicle v1 = VehicleFactory.createVehicle("car");
        v1.drive();
    }
}

// Factory Pattern - The decision of which object to create is seperated from the code that used the object
// When we write new Car() directly in our code, we are hardcoding a dependency. Our code knows it need a Card specifically.The problem gets worse as your codebase grows. Imagine 50 places in your code doing new Car(). Tomorrow the requirement changes — now sometimes it's a Car, sometimes a Bus depending on user type. You now touch 50 files.

// Avoid doing this in main that is why factory pattern is used
// Vehicle v1 = new Car();
// Vehicle v2 = new Bus();