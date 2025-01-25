package docs.Java.src.main;

public class Dog implements Animal {
    // 定义方法,这是一种方法的重写
    @Override
    public void introduce() {
        System.out.println("I am a dog.");
    }
    // 定义方法
    @Override
    public void eat(String food) {
        System.out.println("The dog is eating " + food);
    }
    public void sleep() {
        System.out.println("The dog is sleeping.");
    }
    public void sleep(int time) {
        System.out.println("The dog is sleeping for " + time + " hours.");
    }
}
