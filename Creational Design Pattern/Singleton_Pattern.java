class Logger {
    private static Logger instance;

    private Logger() {
    }

    public static synchronized Logger getInstance() {
        if (instance == null) {
            synchronized (Logger.class) {
                if (instance == null) {
                    instance = new Logger();
                }
            }
        }
        return instance;
    }

    public void log(String msg) {
        System.out.println(msg);
    }
}

class Singleton_Pattern {
    public static void main(String[] args) {
        Logger logger = Logger.getInstance();
        logger.log("Hello");
    }
}