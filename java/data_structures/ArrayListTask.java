import java.io.*;
import java.util.*;

public class ArrayListTask {
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
        /* Документация http://docs.oracle.com/javase/7/docs/api/ */
        ArrayList<Integer> a = new ArrayList<Integer>(); // Аналог std::vector<int>
        for (int i = 0; i < 10; i++) {
            a.add(i); // Добавление в конец, аналог push_back
        }
        out.println(a.get(5)); // Вывод элемента по индексу
        a.set(5, 100); // Изменение элемента по индексу
        out.println(a.get(5));
        out.println(a.size()); // Взятие размера ArrayList
        a.add(5, 178); // Добавление на нужное место, при этом все элементы с этого места сдвигаются
        out.println(a.get(5) + " " + a.size());
        // Полный перечень методов динамического массива в документации
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
