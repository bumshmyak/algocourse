import java.io.*;
import java.util.*;

public class FileIO {
    public static void main(String args[]) {
        InputReader inputReader;
        PrintWriter printWriter;
        try {
            inputReader = new InputReader(new FileReader("input.txt"));
            printWriter = new PrintWriter(new FileWriter("output.txt"));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        TaskSolver solver = new TaskSolver(inputReader, printWriter);
        solver.solve();
        printWriter.close();
    }
}

class TaskSolver {
    private InputReader in;
    private PrintWriter out;

    public TaskSolver(InputReader inputReader, PrintWriter printWriter) {
        in = inputReader;
        out = printWriter;
    }

    public void solve() {
        
    }
}

class InputReader {
    protected BufferedReader reader;
    protected StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public InputReader(FileReader fileReader) {
        reader = new BufferedReader(fileReader);
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

    public char readChar() {
        try {
            return (char) reader.read();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public String readLine() {
        try {
            return reader.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public boolean ready() {
        try {
            return reader.ready() || 
                    tokenizer != null && tokenizer.hasMoreTokens();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
