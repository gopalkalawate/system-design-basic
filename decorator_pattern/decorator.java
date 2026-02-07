interface Coffee{
    String getDescription();
    double getCost();
};

class PlainCoffee implements Coffee{
    @Override
    public String getDescription(){
        return "Plain Coffee";
    }
    @Override
    public double getCost(){
        return 1.0;
    }
};

abstract class CoffeeDecorator implements Coffee{
    protected Coffee coffee;
    public CoffeeDecorator(Coffee coffee){
        this.coffee = coffee;
    }
    @Override
    public String getDescription(){
        return coffee.getDescription();
    }
    @Override 
    public double getCost(){
        return coffee.getCost();
    }
};

class WhippedCream extends CoffeeDecorator {
    public WhippedCream(Coffee coffee) {
        super(coffee); // Calls the CoffeeDecorator constructor
    }

    @Override
    public String getDescription() {
        return super.getDescription() + ", Whipped Cream";
    }

    @Override
    public double getCost() {
        return super.getCost() + 0.75;
    }
}

// 5. Another Decorator for variety
class Milk extends CoffeeDecorator {
    public Milk(Coffee coffee) {
        super(coffee);
    }

    @Override
    public String getDescription() {
        return super.getDescription() + ", Milk";
    }

    @Override
    public double getCost() {
        return super.getCost() + 0.50;
    }
}



class decorator{
    public static void main(String []args){
        // Create a plain coffee
        Coffee myOrder = new PlainCoffee();
        
        // Wrap it in Milk
        myOrder = new Milk(myOrder);
        
        // Wrap it in Whipped Cream
        myOrder = new WhippedCream(myOrder);

        System.out.println("Order: " + myOrder.getDescription());
        System.out.println("Total Cost: $" + myOrder.getCost());
    }
}