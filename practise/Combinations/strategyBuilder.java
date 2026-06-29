package practise.Combinations;

import java.util.*;

class Order {
    protected String cName;
    protected String rName;
    protected ArrayList<String> foodItems = new ArrayList<>();
    protected int km;
    protected double basePrice;
    protected double packagingCharge;
    protected double tip;
    protected String couponCode;

    static class Builder {

        protected String cName;
        protected String rName;
        protected ArrayList<String> foodItems = new ArrayList<>();
        protected int km;
        protected double basePrice;
        protected double packagingCharge;
        protected double tip;
        protected String couponCode;

        public Builder setCustomerName(String name) {
            this.cName = name;
            return this;
        }

        public Builder setRestaurantName(String name) {
            this.rName = name;
            return this;
        }

        public Builder addFoodItem(String item) {
            this.foodItems.add(item);
            return this;
        }

        public Builder setDistance(int km) {
            this.km = km;
            return this;
        }

        public Builder setBasePrice(double price) {
            this.basePrice = price;
            return this;
        }

        public Builder setPackagingCharge(double charge) {
            this.packagingCharge = charge;
            return this;
        }

        public Builder setTip(double tip) {
            this.tip = tip;
            return this;
        }

        public Builder setCouponCode(String code) {
            this.couponCode = code;
            return this;
        }

        public Order build() {
            if (cName == null || cName.isBlank()) {
                throw new IllegalStateException("Customer name is required.");
            }

            if (rName == null || rName.isBlank()) {
                throw new IllegalStateException("Restaurant name is required.");
            }

            if (foodItems.isEmpty()) {
                throw new IllegalStateException("At least one food item is required.");
            }

            if (km <= 0) {
                throw new IllegalStateException("Distance must be greater than 0.");
            }

            if (basePrice <= 0) {
                throw new IllegalStateException("Base price must be greater than 0.");
            }
            Order order = new Order();
            order.cName = this.cName;
            order.rName = this.rName;
            order.foodItems = this.foodItems;
            order.km = this.km;
            order.basePrice = this.basePrice;
            order.packagingCharge = this.packagingCharge;
            order.tip = this.tip;
            order.couponCode = this.couponCode;
            return order;
        }
    }
}

interface PricingStrategy {
    double processPrice(Order order);
}

class Regular implements PricingStrategy {
    public double processPrice(Order order) {
        return (order.basePrice + order.packagingCharge + order.tip);
    }
}

class Festival implements PricingStrategy {
    public double processPrice(Order order) {
        return ((0.2 * order.basePrice) + order.packagingCharge + order.tip);
    }
}

class Premium implements PricingStrategy {
    public double processPrice(Order order) {
        return (order.basePrice);
    }
}

class Coupon implements PricingStrategy {
    public double processPrice(Order order) {
        if (order.basePrice - 150 < 0) {
            return 0;
        } else {
            return (order.basePrice - 150);
        }
    }
}

class StrategyProcessor {
    private PricingStrategy ps;

    public StrategyProcessor(PricingStrategy ps) {
        this.ps = ps;
    }

    public void setStrategy(PricingStrategy ps) {
        this.ps = ps;
    }

    double process(Order order) {
        return ps.processPrice(order);
    }
}

public class strategyBuilder {
    public static void main(String[] args) {
        Order order = new Order.Builder()
                .setCustomerName("Mudit")
                .setRestaurantName("Dominos")
                .addFoodItem("Pizza")
                .addFoodItem("Garlic Bread")
                .setDistance(10)
                .setBasePrice(500)
                .setPackagingCharge(30)
                .setTip(50)
                .setCouponCode("SAVE150")
                .build();
        PricingStrategy ps = new Festival();
        PricingStrategy ps2 = new Regular();
        StrategyProcessor sProcessor = new StrategyProcessor(ps);
        sProcessor.setStrategy(ps2);
        System.out.println(sProcessor.process(order));
    }

}
