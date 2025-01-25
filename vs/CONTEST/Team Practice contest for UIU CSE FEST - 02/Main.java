import com.sun.source.tree.Tree;

import java.io.*;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
    public static final int MOD = 1_000_000_007;
    public static final int INF = Integer.MAX_VALUE;

    static InputReader scanner;
    static PrintWriter out;

    public static void main(String[] args) {
        scanner = new InputReader(System.in);
        out = new PrintWriter(System.out);

        int t = scanner.nextInt();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        final int n = scanner.nextInt();
        final int[] arr = take(n);

        boolean isValid = true;

        for(int i=1; i<n; i++){
            if(Math.abs(arr[i]-arr[i-1]) != 5 && Math.abs(arr[i]-arr[i-1]) != 7){
                isValid = false;
                break;
            }
        }

        out.println(isValid ? "YES" : "NO");
    }

    private static int[] take(int n){
        final int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        return arr;
    }

    static class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object obj) {
            if(this == obj) return true;

            if(obj == null || getClass() != obj.getClass()) return false;

            Pair pair = (Pair) obj;
            return first == pair.first && second == pair.second;
        }

        @Override
        public String toString() {
            return first+" "+second;
        }

        @Override
        public int compareTo(Pair o) {
            if(first == o.first) return Integer.compare(second, o.second);
            return Integer.compare(first, o.first);
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong(){ return Long.parseLong(next()); }
        public double nextDouble(){ return Double.parseDouble(next()); }
    }
}
