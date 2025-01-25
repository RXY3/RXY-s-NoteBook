package docs.Java.src.main;

public class Cat implements Animal {
    // 定义方法
    @Override
    public void introduce() {
        System.out.println("I am a cat.");
    }
    // 定义方法
    @Override
    public void eat(String food) {
        System.out.println("The cat is eating " + food);
    }
    public void sleep() {
        System.out.println("The cat is sleeping.");
    }
    public void sleep(int time) {
        System.out.println("The cat is sleeping " + time + " hours.");
    }
}