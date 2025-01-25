
package docs.Java.src.main;

//导入标准库
import java.util.*;

public class HelloWorld {

    public static void main(String[] args) {
        //使用docs.Java.src.main.Dog类
        Animal animal = new Dog();
        // 调用方法
        animal.introduce();
        animal.eat("meat");
        animal.sleep();
        animal.sleep(1);

        Animal animal2 = (Dog) animal;
        animal2.sleep();
        System.out.println(animal2 == animal);//这是一个比较地址的方法，也就是说animal2是animal的一个浅拷贝
        System.out.println(animal2.equals(animal));

        animal = new Cat();
        animal.introduce();
        animal.eat("fish");
        animal.sleep();
        animal.sleep(1);
    }
    
}
// animal = new Cat();
// animal.introduce();
// animal.eat("fish");
