package practise.Combinations;

abstract class EmailMessage {
    protected String to;
    protected String subject;
    protected String body;
    protected String CC;
    protected String BCC;

    public abstract void send();
}

abstract class SMSMessage {
    protected String phoneNumber;
    protected String message;
    protected String senderId;
    protected String scheduleTime;

    public abstract void send();
}

class SendGrid extends EmailMessage {
    public void send() {
        System.out.println("Email by SendGrid");
    }

    class Builder {
        private String to;
        private String subject;
        private String body;
        private String CC;
        private String BCC;

        private boolean ToSet = false;
        private boolean SubjectSet = false;
        private boolean BodySet = false;

        public Builder setTo(String to) {
            this.to = to;
            ToSet = true;
            return this;
        }

        public Builder setSubject(String to) {
            this.subject = to;
            SubjectSet = true;
            return this;
        }

        public Builder setBody(String to) {
            this.body = to;
            BodySet = true;
            return this;
        }

        public Builder setCC(String to) {
            this.CC = to;
            return this;
        }

        public Builder setBCC(String to) {
            this.BCC = to;
            BodySet = true;
            return this;
        }

        public SendGrid build() {
            if (!ToSet || !SubjectSet || !BodySet) {
                throw new Error("Fill Required Field");
            }
            SendGrid email = new SendGrid();

            email.to = to;
            email.subject = subject;
            email.body = body;
            email.CC = CC;
            email.BCC = BCC;

            return email;
        }
    };
}

class Twilio extends SMSMessage {
    public void send() {
        System.out.println("SMS by Twilio");
    }
}

abstract class EmailBuilder {
    EmailMessage email;

    public abstract EmailBuilder setSubject(String message);

    public abstract EmailBuilder setBody(String message);

    public abstract EmailBuilder setFooter(String message);

    public abstract EmailBuilder setUnsubscribleLink(String message);

    public abstract EmailBuilder setDiscountCode(String message);

}

class SendGridBuilder extends EmailBuilder {
    public SendGridBuilder() {
        reset();
    }

    public void reset() {
        email = new SendGrid();
    }

    public EmailBuilder setSubject(String message) {
        email.subject = message;
        return this;
    }

    public EmailBuilder setBody(String message) {
        email.body = message;
        return this;
    }

    public EmailBuilder setFooter(String message) {
        email.footer = message;
        return this;
    }

    public EmailBuilder setUnsubscribleLink(String message) {
        email.unS = message;
        return this;
    }

    public EmailBuilder setDiscountCode(String message) {
        email.subject = message;
        return this;
    }

}

abstract class SMSBuilder {
    SMSMessage builder;

    public abstract SMSBuilder setSubject(String message);

    public abstract SMSBuilder setBody(String message);

    public abstract SMSBuilder setFooter(String message);

    public abstract SMSBuilder setUnsubscribleLink(String message);

    public abstract SMSBuilder setDiscountCode(String message);

}

public class abstractBuilder {
    public static void main(String[] args) {

    }
}
