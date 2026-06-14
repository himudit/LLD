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
