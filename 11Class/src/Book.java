/**
 * Created by Georgi on 8/9/2015.
 */
public class Book {
    private String name;
    private String author;
    private String maker;
    private int year;
    private long iban;

    public Book(String name, String author, String maker, int year, long iban) {
        this.name = name;
        this.author = author;
        this.maker = maker;
        this.year = year;
        this.iban = iban;
    }

    public String getName() {
        return name;
    }

    public String getAuthor() {
        return author;
    }

    public String getMaker() {
        return maker;
    }

    public int getYear() {
        return year;
    }

    public long getIban() {
        return iban;
    }

    public void setName(String name) {

        this.name = name;
    }
}
