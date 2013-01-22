import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        try {
            InputReader reader = new InputReader(System.in);
            PrintWriter writer = new PrintWriter(System.out);
            Thread thread = new Thread(null, new Solver(reader, writer), "", 128 * 1024 * 1024);
            thread.start();
            thread.join();
            writer.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}

class Solver implements Runnable {
    private InputReader in;
    private PrintWriter out;

    public Solver(InputReader reader, PrintWriter writer) {
        in = reader;
        out = writer;
    }

    @Override
    public void run() {

    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public InputReader(FileReader fileReader) {
        reader = new BufferedReader(fileReader);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String readLine() {
        try {
            return reader.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public char readChar() {
        try {
            return (char) reader.read();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
