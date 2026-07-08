package practise.Combinations.IteratorMediator;

import java.util.ArrayList;

class Book {
    public String author;
    public String title;

    Book(String a, String t) {
        this.author = a;
        this.title = t;
    }
};

interface Iterator {
    boolean hasNext();

    Book next();
}

class BookIterator implements Iterator {
    private ArrayList<Book> books = new ArrayList<>();
    private int index = 0;

    public BookIterator(ArrayList<Book> books) {
        this.books = books;
        this.index = 0;
    }

    public boolean hasNext() {
        if (index >= books.size()) {
            return false;
        }
        return true;
    }

    public Book next() {
        Book currentBook = books.get(index);
        System.out.println(currentBook.title);
        index++;
        return currentBook;
    }
}

interface IterableCollection {
    Iterator createIterator();
}

class Library implements IterableCollection {
    private ArrayList<Book> books = new ArrayList<>();

    public void addBook(Book book) {
        this.books.add(book);
    }

    public Iterator createIterator() {
        return new BookIterator(books);
    }

}

interface Mediator {
    void borrowBook(Book book);
}

class LibraryMediator implements Mediator {
    private Librarian librarian;
    private PaymentDesk paymentDesk;
    private Notification notification;

    public LibraryMediator() {
        librarian = new Librarian();
        paymentDesk = new PaymentDesk();
        notification = new Notification();
    }

    public void borrowBook(Book book) {

        librarian.issueBook(book);

        paymentDesk.collectPayment();

        notification.sendNotification();

        System.out.println("Borrowing Completed\n");
    }
}

class Librarian {

    public void issueBook(Book book) {
        System.out.println("Book Issued : " + book.title);
    }
}

class PaymentDesk {

    public void collectPayment() {
        System.out.println("Payment Collected");
    }
}

class Notification {

    public void sendNotification() {
        System.out.println("Notification Sent");
    }
}

class Member {

    private String name;
    private Mediator mediator;

    public Member(String name, Mediator mediator) {
        this.name = name;
        this.mediator = mediator;
    }

    public void borrow(Book book) {

        System.out.println(name + " wants to borrow " + book.title);

        mediator.borrowBook(book);
    }
}

public class main {
    public static void main(String[] args) {
        Library library = new Library();
        Book b1 = new Book("author1", "book1");
        Book b2 = new Book("author2", "book2");
        Book b3 = new Book("author3", "book3");
        library.addBook(b1);
        library.addBook(b2);
        library.addBook(b3);
        Iterator it = library.createIterator();
        while (it.hasNext()) {
            it.next();
        }

        Mediator mediator = new LibraryMediator();

        Member member = new Member("Rahul", mediator);

        member.borrow(new Book("Martin", "Clean Code"));
    }
}
