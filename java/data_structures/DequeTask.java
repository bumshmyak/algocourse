import java.io.*;
import java.util.*;

public class DequeTask {
    public static void main(String args[]) {
        InputReader inputReader = new InputReader(System.in);
        PrintWriter printWriter = new PrintWriter(System.out);
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
        Deque<Integer> q = new ArrayDeque<Integer>(); // Аналог std::deque<int>
        int x = in.nextInt(), y = in.nextInt();
        q.addFirst(x); // Вставка в начало дека
        q.addLast(y); // Вставка в конец дека
        int z = q.pollFirst(); // Удаление элемента из начала дека с его возвратом
        out.println(z);
        z = q.pollLast(); // Удаление элемента из конца дека с его возвратом
        out.println(z);
        q.addFirst(x);
        q.addLast(y);
        z = q.peekFirst(); // Возврат элемента из начала дека
        out.println(z);
        z = q.peekLast(); // Возврат элемента из конца дека
        out.println(z);
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
