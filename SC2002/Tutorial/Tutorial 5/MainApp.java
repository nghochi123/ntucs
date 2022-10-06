class MainApp {

  public static void main(String[] args) {
    ClassF z = new ClassF();
    ClassC c = new ClassD();
    // ClassA a = new ClassC();
    ClassA a = new ClassF();
    z.print(9);
    z.print(2, "CX2002"); // A
    z.print("Object"); // E
    z.print("OODP", "Java"); // C
    c.print("Hello", "There"); // Class D
    // a.print("Hellow", "There"); // Compile Error
    // z.print("OODP", 2002); // Compile Error
    // ClassE e = c; // Compile error, cannot be converted
    // a.print(12, "there");
    // a.print(88);
    // ClassG g = (ClassG) a;
    // g.print("Hello", "There");
    ClassC f = (ClassC) a;
    f.print(88, "there");
  }
}
